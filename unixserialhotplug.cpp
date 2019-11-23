#include "unixserialhotplug.h"

UnixSerialHotplug::UnixSerialHotplug(PortScanner* scanner, QObject *parent) : QObject(parent), scanner(scanner)
{
    // create a timer
    timer = new QTimer(this);

    // setup signal and slot
    connect(timer, &QTimer::timeout,  this, &UnixSerialHotplug::tick);

    // msec
    timer->start(10);
    for (auto a:QSerialPortInfo::availablePorts()) {
        m_port_list.push_back(a);
        scanner->addPort(a);
    }
}

bool comp(const QSerialPortInfo a, const QSerialPortInfo b)
{
    return a.portName() < b.portName();
}
void UnixSerialHotplug::tick() {
    auto newSp = QSerialPortInfo::availablePorts();
    std::vector<QSerialPortInfo> diff;
    std::sort(m_port_list.begin(), m_port_list.end(), comp);
    std::sort(newSp.begin(), newSp.end(), comp);
    //Ports in new list that aren't in old (connected ports)
    std::set_difference(newSp.begin(), newSp.end(), m_port_list.begin(), m_port_list.end(), std::inserter(diff, diff.begin()), comp);
    for (auto p: diff) {
        if (p.vendorIdentifier() == 0) {
            //Skip ports that have not fully loaded yet.
            newSp.erase(std::remove_if(newSp.begin(), newSp.end(), [p](QSerialPortInfo object){return object.systemLocation() == p.systemLocation();}), newSp.end());
        } else {
            scanner->addPort(p);
        }
    }
    diff.clear();
    //Ports in old list that aren't in new (disconnected ports)
    std::set_difference(m_port_list.begin(), m_port_list.end(), newSp.begin(), newSp.end(), std::inserter(diff, diff.begin()), comp);
    for (auto p: diff) {
        scanner->removePort(p);
    }
    m_port_list = newSp;
}