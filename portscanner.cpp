#include "portscanner.h"
#include <QDebug>

#ifdef Q_OS_WIN
#include <Windows.h>
#include <Dbt.h>
#include <strsafe.h>
#include <ntddser.h>
#endif
#pragma comment(lib, "user32.lib" )
bool PortScanner::nativeEventFilter(const QByteArray &eventType, void *message, long *result)
{
    if (eventType == "windows_generic_MSG") {
        MSG* msg = reinterpret_cast<MSG*>(message);
        auto msgType = msg->message;
        if(msgType == WM_DEVICECHANGE)
        {
            PDEV_BROADCAST_HDR lpdb = reinterpret_cast<PDEV_BROADCAST_HDR>(msg->lParam);
            switch(msg->wParam)
            {
            case DBT_DEVICEARRIVAL:
                if (lpdb -> dbch_devicetype == DBT_DEVTYP_PORT)
                {
                    PDEV_BROADCAST_PORT_W lpdbv = reinterpret_cast<PDEV_BROADCAST_PORT_W>(lpdb);
                    qDebug() << QString(reinterpret_cast<QChar*>(lpdbv->dbcp_name));
                }
                break;
            }
        }
    }
    return false;
}
void PortScanner::init(WId wid) {
    m_winID = wid;
    //On windows, it isn't enough to rely on the port list changing, so we have to use the windows API to work out if a device is hotplugged.
#ifdef Q_OS_WIN
    DEV_BROADCAST_DEVICEINTERFACE NotificationFilter;
    ZeroMemory( &NotificationFilter, sizeof(NotificationFilter) );
    NotificationFilter.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
    NotificationFilter.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
    NotificationFilter.dbcc_classguid = GUID_DEVINTERFACE_COMPORT;
    HWND hw = (HWND)wid;   //Main window handle
    HDEVNOTIFY hDevNotify = RegisterDeviceNotification(hw,&NotificationFilter, DEVICE_NOTIFY_WINDOW_HANDLE );
#endif
}
PortScanner::PortScanner(QObject *parent) : QObject(parent), m_selected(nullptr)
{
    m_model.push_back(new Port(nullptr));
}
void PortScanner::checkPorts() {
    const auto serialPortInfos = QSerialPortInfo::availablePorts();
    for (QObject *obj : m_model) {
        auto port = static_cast<Port*>(obj);
        if (port->getPort() == "searching") continue;
        if (std::find_if(serialPortInfos.begin(), serialPortInfos.end(), [port](const QSerialPortInfo &serialPortInfo){return port->getPort() == serialPortInfo.systemLocation();}) == serialPortInfos.end()) {
            m_model.removeOne(port);
        }
    }
    if (serialPortInfos.length() > 0) {
        m_model.erase(std::remove_if(m_model.begin(), m_model.end(), [](QObject* object){return (static_cast<Port*>(object))->getPort() == "searching";}),m_model.end());
    } else if (m_model.length() == 0) {
        m_model.push_back(new Port());
    }
    for (const QSerialPortInfo &serialPortInfo : serialPortInfos) {
        auto port = new Port(serialPortInfo);
        if (port->getPort() == nullptr) continue;
        auto find = std::find_if(m_model.begin(), m_model.end(), [serialPortInfo](QObject* object){return (static_cast<Port*>(object))->getPort() == serialPortInfo.systemLocation();});
        if (find == m_model.end()) {
            m_model.push_back(port);
            port->open(serialPortInfo);
        }
    }
    emit modelChanged(m_model);
}
