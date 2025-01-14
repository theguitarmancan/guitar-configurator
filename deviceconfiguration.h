
#include <QDebug>
#include <QMetaEnum>
#include <QObject>
#include "ardwiino_defines.h"

#include "submodules/Ardwiino/src/shared/config/config.h"
class DeviceConfiguration : public QObject {
    Q_OBJECT
    Q_PROPERTY(bool hasChanged MEMBER m_hasChanged NOTIFY hasChangedUpdated)
    Q_PROPERTY(bool isGuitar READ isGuitar NOTIFY mainSubTypeUpdated)
    Q_PROPERTY(bool isDrum READ isDrum NOTIFY mainSubTypeUpdated)
    Q_PROPERTY(bool isLiveGuitar READ isLiveGuitar NOTIFY mainSubTypeUpdated)
    Q_PROPERTY(bool isKeyboard READ isKeyboard NOTIFY mainSubTypeUpdated)
    Q_PROPERTY(bool isXInput READ isXInput NOTIFY mainSubTypeUpdated)
    Q_PROPERTY(bool isRB READ isRB NOTIFY mainSubTypeUpdated)
    Q_PROPERTY(bool isWii READ isWii NOTIFY mainInputTypeUpdated)
    Q_PROPERTY(bool isDirect READ isDirect NOTIFY mainInputTypeUpdated)
    Q_PROPERTY(bool isMIDI READ isMIDI NOTIFY mainSubTypeUpdated)
    Q_PROPERTY(bool isMouse READ isMouse NOTIFY mainSubTypeUpdated)
    Q_PROPERTY(bool hasAddressableLEDs READ hasAddressableLEDs NOTIFY mainFretLEDModeUpdated)
    Q_PROPERTY(QVariantList leds READ getLEDs NOTIFY ledsUpdated)
    Q_PROPERTY(QVariantMap ledColours READ getLEDColours NOTIFY ledsUpdated)
    Q_PROPERTY(ArdwiinoDefines::InputType mainInputType READ getMainInputType WRITE setMainInputType NOTIFY mainInputTypeUpdated)
    Q_PROPERTY(ArdwiinoDefines::SubType mainSubType READ getMainSubType WRITE setMainSubType NOTIFY mainSubTypeUpdated)
    Q_PROPERTY(ArdwiinoDefines::TiltType mainTiltType READ getMainTiltType WRITE setMainTiltType NOTIFY mainTiltTypeUpdated)
    Q_PROPERTY(int mainPollRate READ getMainPollRate WRITE setMainPollRate NOTIFY mainPollRateUpdated)
    Q_PROPERTY(ArdwiinoDefines::FretLedMode mainFretLEDMode READ getMainFretLEDMode WRITE setMainFretLEDMode NOTIFY mainFretLEDModeUpdated)
    Q_PROPERTY(bool mainMapLeftJoystickToDPad READ getMainMapLeftJoystickToDPad WRITE setMainMapLeftJoystickToDPad NOTIFY mainMapLeftJoystickToDPadUpdated)
    Q_PROPERTY(bool mainMapStartSelectToHome READ getMainMapStartSelectToHome WRITE setMainMapStartSelectToHome NOTIFY mainMapStartSelectToHomeUpdated)
    Q_PROPERTY(bool mainMapNunchukAccelToRightJoy READ getMainMapNunchukAccelToRightJoy WRITE setMainMapNunchukAccelToRightJoy NOTIFY mainMapNunchukAccelToRightJoyUpdated)
    Q_PROPERTY(ArdwiinoDefines::FirmwareType mainSignature READ getMainSignature WRITE setMainSignature NOTIFY mainSignatureUpdated)
    Q_PROPERTY(int mainVersion READ getMainVersion WRITE setMainVersion NOTIFY mainVersionUpdated)
    Q_PROPERTY(int pinsUp READ getPinsUp WRITE setPinsUp NOTIFY pinsUpUpdated)
    Q_PROPERTY(int pinsDown READ getPinsDown WRITE setPinsDown NOTIFY pinsDownUpdated)
    Q_PROPERTY(int pinsLeft READ getPinsLeft WRITE setPinsLeft NOTIFY pinsLeftUpdated)
    Q_PROPERTY(int pinsRight READ getPinsRight WRITE setPinsRight NOTIFY pinsRightUpdated)
    Q_PROPERTY(int pinsStart READ getPinsStart WRITE setPinsStart NOTIFY pinsStartUpdated)
    Q_PROPERTY(int pinsBack READ getPinsBack WRITE setPinsBack NOTIFY pinsBackUpdated)
    Q_PROPERTY(int pinsLeftStick READ getPinsLeftStick WRITE setPinsLeftStick NOTIFY pinsLeftStickUpdated)
    Q_PROPERTY(int pinsRightStick READ getPinsRightStick WRITE setPinsRightStick NOTIFY pinsRightStickUpdated)
    Q_PROPERTY(int pinsLB READ getPinsLB WRITE setPinsLB NOTIFY pinsLBUpdated)
    Q_PROPERTY(int pinsRB READ getPinsRB WRITE setPinsRB NOTIFY pinsRBUpdated)
    Q_PROPERTY(int pinsHome READ getPinsHome WRITE setPinsHome NOTIFY pinsHomeUpdated)
    Q_PROPERTY(int pinsCapture READ getPinsCapture WRITE setPinsCapture NOTIFY pinsCaptureUpdated)
    Q_PROPERTY(int pinsA READ getPinsA WRITE setPinsA NOTIFY pinsAUpdated)
    Q_PROPERTY(int pinsB READ getPinsB WRITE setPinsB NOTIFY pinsBUpdated)
    Q_PROPERTY(int pinsX READ getPinsX WRITE setPinsX NOTIFY pinsXUpdated)
    Q_PROPERTY(int pinsY READ getPinsY WRITE setPinsY NOTIFY pinsYUpdated)
    Q_PROPERTY(int pinsLt READ getPinsLt WRITE setPinsLt NOTIFY pinsLtUpdated)
    Q_PROPERTY(bool pinsLtInverted READ getPinsLtInverted WRITE setPinsLtInverted NOTIFY pinsLtInvertedUpdated)
    Q_PROPERTY(int pinsRt READ getPinsRt WRITE setPinsRt NOTIFY pinsRtUpdated)
    Q_PROPERTY(bool pinsRtInverted READ getPinsRtInverted WRITE setPinsRtInverted NOTIFY pinsRtInvertedUpdated)
    Q_PROPERTY(int pinsLX READ getPinsLX WRITE setPinsLX NOTIFY pinsLXUpdated)
    Q_PROPERTY(bool pinsLXInverted READ getPinsLXInverted WRITE setPinsLXInverted NOTIFY pinsLXInvertedUpdated)
    Q_PROPERTY(int pinsLY READ getPinsLY WRITE setPinsLY NOTIFY pinsLYUpdated)
    Q_PROPERTY(bool pinsLYInverted READ getPinsLYInverted WRITE setPinsLYInverted NOTIFY pinsLYInvertedUpdated)
    Q_PROPERTY(int pinsRX READ getPinsRX WRITE setPinsRX NOTIFY pinsRXUpdated)
    Q_PROPERTY(bool pinsRXInverted READ getPinsRXInverted WRITE setPinsRXInverted NOTIFY pinsRXInvertedUpdated)
    Q_PROPERTY(int pinsRY READ getPinsRY WRITE setPinsRY NOTIFY pinsRYUpdated)
    Q_PROPERTY(bool pinsRYInverted READ getPinsRYInverted WRITE setPinsRYInverted NOTIFY pinsRYInvertedUpdated)
    Q_PROPERTY(int axisTriggerThreshold READ getAxisTriggerThreshold WRITE setAxisTriggerThreshold NOTIFY axisTriggerThresholdUpdated)
    Q_PROPERTY(int axisJoyThreshold READ getAxisJoyThreshold WRITE setAxisJoyThreshold NOTIFY axisJoyThresholdUpdated)
    Q_PROPERTY(int axisDrumThreshold READ getAxisDrumThreshold WRITE setAxisDrumThreshold NOTIFY axisDrumThresholdUpdated)
    Q_PROPERTY(ArdwiinoDefines::GyroOrientation axisMpu6050Orientation READ getAxisMpu6050Orientation WRITE setAxisMpu6050Orientation NOTIFY axisMpu6050OrientationUpdated)
    Q_PROPERTY(int axisTiltSensitivity READ getAxisTiltSensitivity WRITE setAxisTiltSensitivity NOTIFY axisTiltSensitivityUpdated)
    Q_PROPERTY(int keysUp READ getKeysUp WRITE setKeysUp NOTIFY keysUpUpdated)
    Q_PROPERTY(int keysDown READ getKeysDown WRITE setKeysDown NOTIFY keysDownUpdated)
    Q_PROPERTY(int keysLeft READ getKeysLeft WRITE setKeysLeft NOTIFY keysLeftUpdated)
    Q_PROPERTY(int keysRight READ getKeysRight WRITE setKeysRight NOTIFY keysRightUpdated)
    Q_PROPERTY(int keysStart READ getKeysStart WRITE setKeysStart NOTIFY keysStartUpdated)
    Q_PROPERTY(int keysBack READ getKeysBack WRITE setKeysBack NOTIFY keysBackUpdated)
    Q_PROPERTY(int keysLeftStick READ getKeysLeftStick WRITE setKeysLeftStick NOTIFY keysLeftStickUpdated)
    Q_PROPERTY(int keysRightStick READ getKeysRightStick WRITE setKeysRightStick NOTIFY keysRightStickUpdated)
    Q_PROPERTY(int keysLB READ getKeysLB WRITE setKeysLB NOTIFY keysLBUpdated)
    Q_PROPERTY(int keysRB READ getKeysRB WRITE setKeysRB NOTIFY keysRBUpdated)
    Q_PROPERTY(int keysHome READ getKeysHome WRITE setKeysHome NOTIFY keysHomeUpdated)
    Q_PROPERTY(int keysCapture READ getKeysCapture WRITE setKeysCapture NOTIFY keysCaptureUpdated)
    Q_PROPERTY(int keysA READ getKeysA WRITE setKeysA NOTIFY keysAUpdated)
    Q_PROPERTY(int keysB READ getKeysB WRITE setKeysB NOTIFY keysBUpdated)
    Q_PROPERTY(int keysX READ getKeysX WRITE setKeysX NOTIFY keysXUpdated)
    Q_PROPERTY(int keysY READ getKeysY WRITE setKeysY NOTIFY keysYUpdated)
    Q_PROPERTY(int keysLt READ getKeysLt WRITE setKeysLt NOTIFY keysLtUpdated)
    Q_PROPERTY(int keysRt READ getKeysRt WRITE setKeysRt NOTIFY keysRtUpdated)
    Q_PROPERTY(int keysLXNeg READ getKeysLXNeg WRITE setKeysLXNeg NOTIFY keysLXNegUpdated)
    Q_PROPERTY(int keysLXPos READ getKeysLXPos WRITE setKeysLXPos NOTIFY keysLXPosUpdated)
    Q_PROPERTY(int keysLYNeg READ getKeysLYNeg WRITE setKeysLYNeg NOTIFY keysLYNegUpdated)
    Q_PROPERTY(int keysLYPos READ getKeysLYPos WRITE setKeysLYPos NOTIFY keysLYPosUpdated)
    Q_PROPERTY(int keysRXNeg READ getKeysRXNeg WRITE setKeysRXNeg NOTIFY keysRXNegUpdated)
    Q_PROPERTY(int keysRXPos READ getKeysRXPos WRITE setKeysRXPos NOTIFY keysRXPosUpdated)
    Q_PROPERTY(int keysRYNeg READ getKeysRYNeg WRITE setKeysRYNeg NOTIFY keysRYNegUpdated)
    Q_PROPERTY(int keysRYPos READ getKeysRYPos WRITE setKeysRYPos NOTIFY keysRYPosUpdated)
    Q_PROPERTY(QVariantMap midiType READ getMidiType NOTIFY midiTypeUpdated)
    Q_PROPERTY(QVariantMap midiNote READ getMidiNote NOTIFY midiNoteUpdated)
    Q_PROPERTY(QVariantMap midiChannel READ getMidiChannel NOTIFY midiChannelUpdated)
    Q_PROPERTY(bool rfRfInEnabled READ getRfRfInEnabled WRITE setRfRfInEnabled NOTIFY rfRfInEnabledUpdated)
    Q_PROPERTY(int rfId READ getRfId WRITE setRfId NOTIFY rfIdUpdated)
    Q_PROPERTY(int pinsSP READ getPinsSP WRITE setPinsSP NOTIFY pinsSPUpdated)
    Q_PROPERTY(int axisScaleLtMultiplier READ getAxisScaleLtMultiplier WRITE setAxisScaleLtMultiplier NOTIFY axisScaleLtMultiplierUpdated)
    Q_PROPERTY(int axisScaleLtOffset READ getAxisScaleLtOffset WRITE setAxisScaleLtOffset NOTIFY axisScaleLtOffsetUpdated)
    Q_PROPERTY(int axisScaleLtDeadzone READ getAxisScaleLtDeadzone WRITE setAxisScaleLtDeadzone NOTIFY axisScaleLtDeadzoneUpdated)
    Q_PROPERTY(int axisScaleRtMultiplier READ getAxisScaleRtMultiplier WRITE setAxisScaleRtMultiplier NOTIFY axisScaleRtMultiplierUpdated)
    Q_PROPERTY(int axisScaleRtOffset READ getAxisScaleRtOffset WRITE setAxisScaleRtOffset NOTIFY axisScaleRtOffsetUpdated)
    Q_PROPERTY(int axisScaleRtDeadzone READ getAxisScaleRtDeadzone WRITE setAxisScaleRtDeadzone NOTIFY axisScaleRtDeadzoneUpdated)
    Q_PROPERTY(int axisScaleLXMultiplier READ getAxisScaleLXMultiplier WRITE setAxisScaleLXMultiplier NOTIFY axisScaleLXMultiplierUpdated)
    Q_PROPERTY(int axisScaleLXOffset READ getAxisScaleLXOffset WRITE setAxisScaleLXOffset NOTIFY axisScaleLXOffsetUpdated)
    Q_PROPERTY(int axisScaleLXDeadzone READ getAxisScaleLXDeadzone WRITE setAxisScaleLXDeadzone NOTIFY axisScaleLXDeadzoneUpdated)
    Q_PROPERTY(int axisScaleLYMultiplier READ getAxisScaleLYMultiplier WRITE setAxisScaleLYMultiplier NOTIFY axisScaleLYMultiplierUpdated)
    Q_PROPERTY(int axisScaleLYOffset READ getAxisScaleLYOffset WRITE setAxisScaleLYOffset NOTIFY axisScaleLYOffsetUpdated)
    Q_PROPERTY(int axisScaleLYDeadzone READ getAxisScaleLYDeadzone WRITE setAxisScaleLYDeadzone NOTIFY axisScaleLYDeadzoneUpdated)
    Q_PROPERTY(int axisScaleRXMultiplier READ getAxisScaleRXMultiplier WRITE setAxisScaleRXMultiplier NOTIFY axisScaleRXMultiplierUpdated)
    Q_PROPERTY(int axisScaleRXOffset READ getAxisScaleRXOffset WRITE setAxisScaleRXOffset NOTIFY axisScaleRXOffsetUpdated)
    Q_PROPERTY(int axisScaleRXDeadzone READ getAxisScaleRXDeadzone WRITE setAxisScaleRXDeadzone NOTIFY axisScaleRXDeadzoneUpdated)
    Q_PROPERTY(int axisScaleRYMultiplier READ getAxisScaleRYMultiplier WRITE setAxisScaleRYMultiplier NOTIFY axisScaleRYMultiplierUpdated)
    Q_PROPERTY(int axisScaleRYOffset READ getAxisScaleRYOffset WRITE setAxisScaleRYOffset NOTIFY axisScaleRYOffsetUpdated)
    Q_PROPERTY(int axisScaleRYDeadzone READ getAxisScaleRYDeadzone WRITE setAxisScaleRYDeadzone NOTIFY axisScaleRYDeadzoneUpdated)
    Q_PROPERTY(int debounceButtons READ getDebounceButtons WRITE setDebounceButtons NOTIFY debounceButtonsUpdated)
    Q_PROPERTY(int debounceStrum READ getDebounceStrum WRITE setDebounceStrum NOTIFY debounceStrumUpdated)
    Q_PROPERTY(bool debounceCombinedStrum READ getDebounceCombinedStrum WRITE setDebounceCombinedStrum NOTIFY debounceCombinedStrumUpdated)
    Q_PROPERTY(bool neckWtNeck READ getNeckWtNeck WRITE setNeckWtNeck NOTIFY neckWtNeckUpdated)
    Q_PROPERTY(bool neckGh5Neck READ getNeckGh5Neck WRITE setNeckGh5Neck NOTIFY neckGh5NeckUpdated)
    Q_PROPERTY(bool neckGh5NeckBar READ getNeckGh5NeckBar WRITE setNeckGh5NeckBar NOTIFY neckGh5NeckBarUpdated)
    Q_PROPERTY(bool neckWiiNeck READ getNeckWiiNeck WRITE setNeckWiiNeck NOTIFY neckWiiNeckUpdated)
    Q_PROPERTY(bool neckPs2Neck READ getNeckPs2Neck WRITE setNeckPs2Neck NOTIFY neckPs2NeckUpdated)

public:
    explicit DeviceConfiguration(Configuration_t config, QObject* parent = nullptr);
public slots:
    bool isGuitar() {
        return ArdwiinoDefines::getName(getMainSubType()).toLower().contains("guitar");
    }
    bool isDrum() {
        return ArdwiinoDefines::getName(getMainSubType()).toLower().contains("drum");
    }
    bool isMIDI() {
        return ArdwiinoDefines::getName(getMainSubType()).toLower().contains("midi");
    }
    bool isKeyboard() {
        return getMainSubType() >= ArdwiinoDefines::KEYBOARD_GAMEPAD && getMainSubType() <= ArdwiinoDefines::KEYBOARD_ROCK_BAND_DRUMS;
    }
    bool isMouse() {
        return getMainSubType() == ArdwiinoDefines::MOUSE;
    }
    bool isLiveGuitar() {
        return getMainSubType() == ArdwiinoDefines::XINPUT_LIVE_GUITAR;
    }
    bool isWii() {
        return getMainInputType() == ArdwiinoDefines::WII;
    }
    bool isDirect() {
        return getMainInputType() == ArdwiinoDefines::DIRECT;
    }
    bool isRB() {
        return ArdwiinoDefines::getName(getMainSubType()).toLower().contains("rock");
    }
    bool isXInput() {
        return ArdwiinoDefines::getName(getMainSubType()).toLower().contains("xinput");
    }
    bool hasAddressableLEDs() {
        return getMainFretLEDMode() == ArdwiinoDefines::APA102;
    }
    Configuration_t getConfig() const {
        return m_config;
    }

    ArdwiinoDefines::InputType getMainInputType() const {
        return (ArdwiinoDefines::InputType)m_config.main.inputType;
    }
    void setMainInputType(ArdwiinoDefines::InputType val) {
        if (m_config.main.inputType != (ArdwiinoDefines::InputType)val) {
            m_config.main.inputType = (ArdwiinoDefines::InputType)val;
            emit mainInputTypeUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    ArdwiinoDefines::SubType getMainSubType() const {
        return (ArdwiinoDefines::SubType)m_config.main.subType;
    }
    void setMainSubType(ArdwiinoDefines::SubType val) {
        if (m_config.main.subType != (ArdwiinoDefines::SubType)val) {
            m_config.main.subType = (ArdwiinoDefines::SubType)val;
            emit mainSubTypeUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    ArdwiinoDefines::TiltType getMainTiltType() const {
        return (ArdwiinoDefines::TiltType)m_config.main.tiltType;
    }
    void setMainTiltType(ArdwiinoDefines::TiltType val) {
        if (m_config.main.tiltType != (ArdwiinoDefines::TiltType)val) {
            m_config.main.tiltType = (ArdwiinoDefines::TiltType)val;
            emit mainTiltTypeUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getMainPollRate() const {
        return (uint8_t)m_config.main.pollRate;
    }
    void setMainPollRate(int val) {
        if (m_config.main.pollRate != (uint8_t)val) {
            m_config.main.pollRate = (uint8_t)val;
            emit mainPollRateUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    ArdwiinoDefines::FretLedMode getMainFretLEDMode() const {
        return (ArdwiinoDefines::FretLedMode)m_config.main.fretLEDMode;
    }
    void setMainFretLEDMode(ArdwiinoDefines::FretLedMode val) {
        if (m_config.main.fretLEDMode != (ArdwiinoDefines::FretLedMode)val) {
            m_config.main.fretLEDMode = (ArdwiinoDefines::FretLedMode)val;
            emit mainFretLEDModeUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getMainMapLeftJoystickToDPad() const {
        return m_config.main.mapLeftJoystickToDPad;
    }
    void setMainMapLeftJoystickToDPad(bool val) {
        if (m_config.main.mapLeftJoystickToDPad != val) {
            m_config.main.mapLeftJoystickToDPad = val;
            emit mainMapLeftJoystickToDPadUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getMainMapStartSelectToHome() const {
        return m_config.main.mapStartSelectToHome;
    }
    void setMainMapStartSelectToHome(bool val) {
        if (m_config.main.mapStartSelectToHome != val) {
            m_config.main.mapStartSelectToHome = val;
            emit mainMapStartSelectToHomeUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getMainMapNunchukAccelToRightJoy() const {
        return m_config.main.mapNunchukAccelToRightJoy;
    }
    void setMainMapNunchukAccelToRightJoy(bool val) {
        if (m_config.main.mapNunchukAccelToRightJoy != val) {
            m_config.main.mapNunchukAccelToRightJoy = val;
            emit mainMapNunchukAccelToRightJoyUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    ArdwiinoDefines::FirmwareType getMainSignature() const {
        return (ArdwiinoDefines::FirmwareType)m_config.main.signature;
    }
    void setMainSignature(ArdwiinoDefines::FirmwareType val) {
        if (m_config.main.signature != (ArdwiinoDefines::FirmwareType)val) {
            m_config.main.signature = (ArdwiinoDefines::FirmwareType)val;
            emit mainSignatureUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getMainVersion() const {
        return (uint32_t)m_config.main.version;
    }
    void setMainVersion(int val) {
        if (m_config.main.version != (uint32_t)val) {
            m_config.main.version = (uint32_t)val;
            emit mainVersionUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsUp() const {
        return (uint8_t)m_config.pins.up;
    }
    void setPinsUp(int val) {
        if (m_config.pins.up != (uint8_t)val) {
            m_config.pins.up = (uint8_t)val;
            emit pinsUpUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsDown() const {
        return (uint8_t)m_config.pins.down;
    }
    void setPinsDown(int val) {
        if (m_config.pins.down != (uint8_t)val) {
            m_config.pins.down = (uint8_t)val;
            emit pinsDownUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsLeft() const {
        return (uint8_t)m_config.pins.left;
    }
    void setPinsLeft(int val) {
        if (m_config.pins.left != (uint8_t)val) {
            m_config.pins.left = (uint8_t)val;
            emit pinsLeftUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsRight() const {
        return (uint8_t)m_config.pins.right;
    }
    void setPinsRight(int val) {
        if (m_config.pins.right != (uint8_t)val) {
            m_config.pins.right = (uint8_t)val;
            emit pinsRightUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsStart() const {
        return (uint8_t)m_config.pins.start;
    }
    void setPinsStart(int val) {
        if (m_config.pins.start != (uint8_t)val) {
            m_config.pins.start = (uint8_t)val;
            emit pinsStartUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsBack() const {
        return (uint8_t)m_config.pins.back;
    }
    void setPinsBack(int val) {
        if (m_config.pins.back != (uint8_t)val) {
            m_config.pins.back = (uint8_t)val;
            emit pinsBackUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsLeftStick() const {
        return (uint8_t)m_config.pins.left_stick;
    }
    void setPinsLeftStick(int val) {
        if (m_config.pins.left_stick != (uint8_t)val) {
            m_config.pins.left_stick = (uint8_t)val;
            emit pinsLeftStickUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsRightStick() const {
        return (uint8_t)m_config.pins.right_stick;
    }
    void setPinsRightStick(int val) {
        if (m_config.pins.right_stick != (uint8_t)val) {
            m_config.pins.right_stick = (uint8_t)val;
            emit pinsRightStickUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsLB() const {
        return (uint8_t)m_config.pins.LB;
    }
    void setPinsLB(int val) {
        if (m_config.pins.LB != (uint8_t)val) {
            m_config.pins.LB = (uint8_t)val;
            emit pinsLBUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsRB() const {
        return (uint8_t)m_config.pins.RB;
    }
    void setPinsRB(int val) {
        if (m_config.pins.RB != (uint8_t)val) {
            m_config.pins.RB = (uint8_t)val;
            emit pinsRBUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsHome() const {
        return (uint8_t)m_config.pins.home;
    }
    void setPinsHome(int val) {
        if (m_config.pins.home != (uint8_t)val) {
            m_config.pins.home = (uint8_t)val;
            emit pinsHomeUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsCapture() const {
        return (uint8_t)m_config.pins.capture;
    }
    void setPinsCapture(int val) {
        if (m_config.pins.capture != (uint8_t)val) {
            m_config.pins.capture = (uint8_t)val;
            emit pinsCaptureUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsA() const {
        return (uint8_t)m_config.pins.a;
    }
    void setPinsA(int val) {
        if (m_config.pins.a != (uint8_t)val) {
            m_config.pins.a = (uint8_t)val;
            emit pinsAUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsB() const {
        return (uint8_t)m_config.pins.b;
    }
    void setPinsB(int val) {
        if (m_config.pins.b != (uint8_t)val) {
            m_config.pins.b = (uint8_t)val;
            emit pinsBUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsX() const {
        return (uint8_t)m_config.pins.x;
    }
    void setPinsX(int val) {
        if (m_config.pins.x != (uint8_t)val) {
            m_config.pins.x = (uint8_t)val;
            emit pinsXUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsY() const {
        return (uint8_t)m_config.pins.y;
    }
    void setPinsY(int val) {
        if (m_config.pins.y != (uint8_t)val) {
            m_config.pins.y = (uint8_t)val;
            emit pinsYUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsLt() const {
        return (uint8_t)m_config.pins.lt.pin;
    }
    void setPinsLt(int val) {
        if (m_config.pins.lt.pin != (uint8_t)val) {
            m_config.pins.lt.pin = (uint8_t)val;
            emit pinsLtUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getPinsLtInverted() const {
        return m_config.pins.lt.inverted;
    }
    void setPinsLtInverted(bool val) {
        if (m_config.pins.lt.inverted != val) {
            m_config.pins.lt.inverted = val;
            emit pinsLtInvertedUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsRt() const {
        return (uint8_t)m_config.pins.rt.pin;
    }
    void setPinsRt(int val) {
        if (m_config.pins.rt.pin != (uint8_t)val) {
            m_config.pins.rt.pin = (uint8_t)val;
            emit pinsRtUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getPinsRtInverted() const {
        return m_config.pins.rt.inverted;
    }
    void setPinsRtInverted(bool val) {
        if (m_config.pins.rt.inverted != val) {
            m_config.pins.rt.inverted = val;
            emit pinsRtInvertedUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsLX() const {
        return (uint8_t)m_config.pins.l_x.pin;
    }
    void setPinsLX(int val) {
        if (m_config.pins.l_x.pin != (uint8_t)val) {
            m_config.pins.l_x.pin = (uint8_t)val;
            emit pinsLXUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getPinsLXInverted() const {
        return m_config.pins.l_x.inverted;
    }
    void setPinsLXInverted(bool val) {
        if (m_config.pins.l_x.inverted != val) {
            m_config.pins.l_x.inverted = val;
            emit pinsLXInvertedUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsLY() const {
        return (uint8_t)m_config.pins.l_y.pin;
    }
    void setPinsLY(int val) {
        if (m_config.pins.l_y.pin != (uint8_t)val) {
            m_config.pins.l_y.pin = (uint8_t)val;
            emit pinsLYUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getPinsLYInverted() const {
        return m_config.pins.l_y.inverted;
    }
    void setPinsLYInverted(bool val) {
        if (m_config.pins.l_y.inverted != val) {
            m_config.pins.l_y.inverted = val;
            emit pinsLYInvertedUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsRX() const {
        return (uint8_t)m_config.pins.r_x.pin;
    }
    void setPinsRX(int val) {
        if (m_config.pins.r_x.pin != (uint8_t)val) {
            m_config.pins.r_x.pin = (uint8_t)val;
            emit pinsRXUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getPinsRXInverted() const {
        return m_config.pins.r_x.inverted;
    }
    void setPinsRXInverted(bool val) {
        if (m_config.pins.r_x.inverted != val) {
            m_config.pins.r_x.inverted = val;
            emit pinsRXInvertedUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsRY() const {
        return (uint8_t)m_config.pins.r_y.pin;
    }
    void setPinsRY(int val) {
        if (m_config.pins.r_y.pin != (uint8_t)val) {
            m_config.pins.r_y.pin = (uint8_t)val;
            emit pinsRYUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getPinsRYInverted() const {
        return m_config.pins.r_y.inverted;
    }
    void setPinsRYInverted(bool val) {
        if (m_config.pins.r_y.inverted != val) {
            m_config.pins.r_y.inverted = val;
            emit pinsRYInvertedUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisTriggerThreshold() const {
        return (uint8_t)m_config.axis.triggerThreshold;
    }
    void setAxisTriggerThreshold(int val) {
        if (m_config.axis.triggerThreshold != (uint8_t)val) {
            m_config.axis.triggerThreshold = (uint8_t)val;
            emit axisTriggerThresholdUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisJoyThreshold() const {
        return (uint8_t)m_config.axis.joyThreshold;
    }
    void setAxisJoyThreshold(int val) {
        if (m_config.axis.joyThreshold != (uint8_t)val) {
            m_config.axis.joyThreshold = (uint8_t)val;
            emit axisJoyThresholdUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisDrumThreshold() const {
        return (uint8_t)m_config.axis.drumThreshold;
    }
    void setAxisDrumThreshold(int val) {
        if (m_config.axis.drumThreshold != (uint8_t)val) {
            m_config.axis.drumThreshold = (uint8_t)val;
            emit axisDrumThresholdUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    ArdwiinoDefines::GyroOrientation getAxisMpu6050Orientation() const {
        return (ArdwiinoDefines::GyroOrientation)m_config.axis.mpu6050Orientation;
    }
    void setAxisMpu6050Orientation(ArdwiinoDefines::GyroOrientation val) {
        if (m_config.axis.mpu6050Orientation != (ArdwiinoDefines::GyroOrientation)val) {
            m_config.axis.mpu6050Orientation = (ArdwiinoDefines::GyroOrientation)val;
            emit axisMpu6050OrientationUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisTiltSensitivity() const {
        return (int16_t)m_config.axis.tiltSensitivity;
    }
    void setAxisTiltSensitivity(int val) {
        if (m_config.axis.tiltSensitivity != (int16_t)val) {
            m_config.axis.tiltSensitivity = (int16_t)val;
            emit axisTiltSensitivityUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysUp() const {
        return (uint8_t)m_config.keys.up;
    }
    void setKeysUp(int val) {
        if (m_config.keys.up != (uint8_t)val) {
            m_config.keys.up = (uint8_t)val;
            emit keysUpUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysDown() const {
        return (uint8_t)m_config.keys.down;
    }
    void setKeysDown(int val) {
        if (m_config.keys.down != (uint8_t)val) {
            m_config.keys.down = (uint8_t)val;
            emit keysDownUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysLeft() const {
        return (uint8_t)m_config.keys.left;
    }
    void setKeysLeft(int val) {
        if (m_config.keys.left != (uint8_t)val) {
            m_config.keys.left = (uint8_t)val;
            emit keysLeftUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysRight() const {
        return (uint8_t)m_config.keys.right;
    }
    void setKeysRight(int val) {
        if (m_config.keys.right != (uint8_t)val) {
            m_config.keys.right = (uint8_t)val;
            emit keysRightUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysStart() const {
        return (uint8_t)m_config.keys.start;
    }
    void setKeysStart(int val) {
        if (m_config.keys.start != (uint8_t)val) {
            m_config.keys.start = (uint8_t)val;
            emit keysStartUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysBack() const {
        return (uint8_t)m_config.keys.back;
    }
    void setKeysBack(int val) {
        if (m_config.keys.back != (uint8_t)val) {
            m_config.keys.back = (uint8_t)val;
            emit keysBackUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysLeftStick() const {
        return (uint8_t)m_config.keys.left_stick;
    }
    void setKeysLeftStick(int val) {
        if (m_config.keys.left_stick != (uint8_t)val) {
            m_config.keys.left_stick = (uint8_t)val;
            emit keysLeftStickUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysRightStick() const {
        return (uint8_t)m_config.keys.right_stick;
    }
    void setKeysRightStick(int val) {
        if (m_config.keys.right_stick != (uint8_t)val) {
            m_config.keys.right_stick = (uint8_t)val;
            emit keysRightStickUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysLB() const {
        return (uint8_t)m_config.keys.LB;
    }
    void setKeysLB(int val) {
        if (m_config.keys.LB != (uint8_t)val) {
            m_config.keys.LB = (uint8_t)val;
            emit keysLBUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysRB() const {
        return (uint8_t)m_config.keys.RB;
    }
    void setKeysRB(int val) {
        if (m_config.keys.RB != (uint8_t)val) {
            m_config.keys.RB = (uint8_t)val;
            emit keysRBUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysHome() const {
        return (uint8_t)m_config.keys.home;
    }
    void setKeysHome(int val) {
        if (m_config.keys.home != (uint8_t)val) {
            m_config.keys.home = (uint8_t)val;
            emit keysHomeUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysCapture() const {
        return (uint8_t)m_config.keys.capture;
    }
    void setKeysCapture(int val) {
        if (m_config.keys.capture != (uint8_t)val) {
            m_config.keys.capture = (uint8_t)val;
            emit keysCaptureUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysA() const {
        return (uint8_t)m_config.keys.a;
    }
    void setKeysA(int val) {
        if (m_config.keys.a != (uint8_t)val) {
            m_config.keys.a = (uint8_t)val;
            emit keysAUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysB() const {
        return (uint8_t)m_config.keys.b;
    }
    void setKeysB(int val) {
        if (m_config.keys.b != (uint8_t)val) {
            m_config.keys.b = (uint8_t)val;
            emit keysBUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysX() const {
        return (uint8_t)m_config.keys.x;
    }
    void setKeysX(int val) {
        if (m_config.keys.x != (uint8_t)val) {
            m_config.keys.x = (uint8_t)val;
            emit keysXUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysY() const {
        return (uint8_t)m_config.keys.y;
    }
    void setKeysY(int val) {
        if (m_config.keys.y != (uint8_t)val) {
            m_config.keys.y = (uint8_t)val;
            emit keysYUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysLt() const {
        return (uint8_t)m_config.keys.lt;
    }
    void setKeysLt(int val) {
        if (m_config.keys.lt != (uint8_t)val) {
            m_config.keys.lt = (uint8_t)val;
            emit keysLtUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysRt() const {
        return (uint8_t)m_config.keys.rt;
    }
    void setKeysRt(int val) {
        if (m_config.keys.rt != (uint8_t)val) {
            m_config.keys.rt = (uint8_t)val;
            emit keysRtUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysLXNeg() const {
        return (uint8_t)m_config.keys.l_x.neg;
    }
    void setKeysLXNeg(int val) {
        if (m_config.keys.l_x.neg != (uint8_t)val) {
            m_config.keys.l_x.neg = (uint8_t)val;
            emit keysLXNegUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysLXPos() const {
        return (uint8_t)m_config.keys.l_x.pos;
    }
    void setKeysLXPos(int val) {
        if (m_config.keys.l_x.pos != (uint8_t)val) {
            m_config.keys.l_x.pos = (uint8_t)val;
            emit keysLXPosUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysLYNeg() const {
        return (uint8_t)m_config.keys.l_y.neg;
    }
    void setKeysLYNeg(int val) {
        if (m_config.keys.l_y.neg != (uint8_t)val) {
            m_config.keys.l_y.neg = (uint8_t)val;
            emit keysLYNegUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysLYPos() const {
        return (uint8_t)m_config.keys.l_y.pos;
    }
    void setKeysLYPos(int val) {
        if (m_config.keys.l_y.pos != (uint8_t)val) {
            m_config.keys.l_y.pos = (uint8_t)val;
            emit keysLYPosUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysRXNeg() const {
        return (uint8_t)m_config.keys.r_x.neg;
    }
    void setKeysRXNeg(int val) {
        if (m_config.keys.r_x.neg != (uint8_t)val) {
            m_config.keys.r_x.neg = (uint8_t)val;
            emit keysRXNegUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysRXPos() const {
        return (uint8_t)m_config.keys.r_x.pos;
    }
    void setKeysRXPos(int val) {
        if (m_config.keys.r_x.pos != (uint8_t)val) {
            m_config.keys.r_x.pos = (uint8_t)val;
            emit keysRXPosUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysRYNeg() const {
        return (uint8_t)m_config.keys.r_y.neg;
    }
    void setKeysRYNeg(int val) {
        if (m_config.keys.r_y.neg != (uint8_t)val) {
            m_config.keys.r_y.neg = (uint8_t)val;
            emit keysRYNegUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getKeysRYPos() const {
        return (uint8_t)m_config.keys.r_y.pos;
    }
    void setKeysRYPos(int val) {
        if (m_config.keys.r_y.pos != (uint8_t)val) {
            m_config.keys.r_y.pos = (uint8_t)val;
            emit keysRYPosUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    QVariantMap getMidiType() const {
        QVariantMap l;
        for (auto pin: pins) {
            l[pin] = m_config.midi.type[pins.indexOf(pin)];
        }
        return l;
    }
    void setMidiTypeValueAt(int i, int val) {
        if (m_config.midi.type[i] != (uint8_t)val) {
            m_hasChanged = true;
            m_config.midi.type[i] = (uint8_t)val;
            emit midiTypeUpdated();
            emit hasChangedUpdated();
        }
    }
    void setMidiTypeValue(QString key, int val) {
        if (m_config.midi.type[pins.indexOf(key)] != (uint8_t)val) {
            m_config.midi.type[pins.indexOf(key)] = (uint8_t)val;
            m_hasChanged = true;
            emit midiTypeUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    QVariantMap getMidiNote() const {
        QVariantMap l;
        for (auto pin: pins) {
            l[pin] = m_config.midi.note[pins.indexOf(pin)];
        }
        return l;
    }
    void setMidiNoteValueAt(int i, int val) {
        if (m_config.midi.note[i] != (uint8_t)val) {
            m_hasChanged = true;
            m_config.midi.note[i] = (uint8_t)val;
            emit midiNoteUpdated();
            emit hasChangedUpdated();
        }
    }
    void setMidiNoteValue(QString key, int val) {
        if (m_config.midi.note[pins.indexOf(key)] != (uint8_t)val) {
            m_config.midi.note[pins.indexOf(key)] = (uint8_t)val;
            m_hasChanged = true;
            emit midiNoteUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    QVariantMap getMidiChannel() const {
        QVariantMap l;
        for (auto pin: pins) {
            l[pin] = m_config.midi.channel[pins.indexOf(pin)];
        }
        return l;
    }
    void setMidiChannelValueAt(int i, int val) {
        if (m_config.midi.channel[i] != (uint8_t)val) {
            m_hasChanged = true;
            m_config.midi.channel[i] = (uint8_t)val;
            emit midiChannelUpdated();
            emit hasChangedUpdated();
        }
    }
    void setMidiChannelValue(QString key, int val) {
        if (m_config.midi.channel[pins.indexOf(key)] != (uint8_t)val) {
            m_config.midi.channel[pins.indexOf(key)] = (uint8_t)val;
            m_hasChanged = true;
            emit midiChannelUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getRfRfInEnabled() const {
        return m_config.rf.rfInEnabled;
    }
    void setRfRfInEnabled(bool val) {
        if (m_config.rf.rfInEnabled != val) {
            m_config.rf.rfInEnabled = val;
            emit rfRfInEnabledUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getRfId() const {
        return (uint32_t)m_config.rf.id;
    }
    void setRfId(int val) {
        if (m_config.rf.id != (uint32_t)val) {
            m_config.rf.id = (uint32_t)val;
            emit rfIdUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getPinsSP() const {
        return (uint8_t)m_config.pinsSP;
    }
    void setPinsSP(int val) {
        if (m_config.pinsSP != (uint8_t)val) {
            m_config.pinsSP = (uint8_t)val;
            emit pinsSPUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleLtMultiplier() const {
        return (int16_t)m_config.axisScale.lt.multiplier;
    }
    void setAxisScaleLtMultiplier(int val) {
        if (m_config.axisScale.lt.multiplier != (int16_t)val) {
            m_config.axisScale.lt.multiplier = (int16_t)val;
            emit axisScaleLtMultiplierUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleLtOffset() const {
        return (int16_t)m_config.axisScale.lt.offset;
    }
    void setAxisScaleLtOffset(int val) {
        if (m_config.axisScale.lt.offset != (int16_t)val) {
            m_config.axisScale.lt.offset = (int16_t)val;
            emit axisScaleLtOffsetUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleLtDeadzone() const {
        return (int16_t)m_config.axisScale.lt.deadzone;
    }
    void setAxisScaleLtDeadzone(int val) {
        if (m_config.axisScale.lt.deadzone != (int16_t)val) {
            m_config.axisScale.lt.deadzone = (int16_t)val;
            emit axisScaleLtDeadzoneUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleRtMultiplier() const {
        return (int16_t)m_config.axisScale.rt.multiplier;
    }
    void setAxisScaleRtMultiplier(int val) {
        if (m_config.axisScale.rt.multiplier != (int16_t)val) {
            m_config.axisScale.rt.multiplier = (int16_t)val;
            emit axisScaleRtMultiplierUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleRtOffset() const {
        return (int16_t)m_config.axisScale.rt.offset;
    }
    void setAxisScaleRtOffset(int val) {
        if (m_config.axisScale.rt.offset != (int16_t)val) {
            m_config.axisScale.rt.offset = (int16_t)val;
            emit axisScaleRtOffsetUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleRtDeadzone() const {
        return (int16_t)m_config.axisScale.rt.deadzone;
    }
    void setAxisScaleRtDeadzone(int val) {
        if (m_config.axisScale.rt.deadzone != (int16_t)val) {
            m_config.axisScale.rt.deadzone = (int16_t)val;
            emit axisScaleRtDeadzoneUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleLXMultiplier() const {
        return (int16_t)m_config.axisScale.l_x.multiplier;
    }
    void setAxisScaleLXMultiplier(int val) {
        if (m_config.axisScale.l_x.multiplier != (int16_t)val) {
            m_config.axisScale.l_x.multiplier = (int16_t)val;
            emit axisScaleLXMultiplierUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleLXOffset() const {
        return (int16_t)m_config.axisScale.l_x.offset;
    }
    void setAxisScaleLXOffset(int val) {
        if (m_config.axisScale.l_x.offset != (int16_t)val) {
            m_config.axisScale.l_x.offset = (int16_t)val;
            emit axisScaleLXOffsetUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleLXDeadzone() const {
        return (int16_t)m_config.axisScale.l_x.deadzone;
    }
    void setAxisScaleLXDeadzone(int val) {
        if (m_config.axisScale.l_x.deadzone != (int16_t)val) {
            m_config.axisScale.l_x.deadzone = (int16_t)val;
            emit axisScaleLXDeadzoneUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleLYMultiplier() const {
        return (int16_t)m_config.axisScale.l_y.multiplier;
    }
    void setAxisScaleLYMultiplier(int val) {
        if (m_config.axisScale.l_y.multiplier != (int16_t)val) {
            m_config.axisScale.l_y.multiplier = (int16_t)val;
            emit axisScaleLYMultiplierUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleLYOffset() const {
        return (int16_t)m_config.axisScale.l_y.offset;
    }
    void setAxisScaleLYOffset(int val) {
        if (m_config.axisScale.l_y.offset != (int16_t)val) {
            m_config.axisScale.l_y.offset = (int16_t)val;
            emit axisScaleLYOffsetUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleLYDeadzone() const {
        return (int16_t)m_config.axisScale.l_y.deadzone;
    }
    void setAxisScaleLYDeadzone(int val) {
        if (m_config.axisScale.l_y.deadzone != (int16_t)val) {
            m_config.axisScale.l_y.deadzone = (int16_t)val;
            emit axisScaleLYDeadzoneUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleRXMultiplier() const {
        return (int16_t)m_config.axisScale.r_x.multiplier;
    }
    void setAxisScaleRXMultiplier(int val) {
        if (m_config.axisScale.r_x.multiplier != (int16_t)val) {
            m_config.axisScale.r_x.multiplier = (int16_t)val;
            emit axisScaleRXMultiplierUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleRXOffset() const {
        return (int16_t)m_config.axisScale.r_x.offset;
    }
    void setAxisScaleRXOffset(int val) {
        if (m_config.axisScale.r_x.offset != (int16_t)val) {
            m_config.axisScale.r_x.offset = (int16_t)val;
            emit axisScaleRXOffsetUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleRXDeadzone() const {
        return (int16_t)m_config.axisScale.r_x.deadzone;
    }
    void setAxisScaleRXDeadzone(int val) {
        if (m_config.axisScale.r_x.deadzone != (int16_t)val) {
            m_config.axisScale.r_x.deadzone = (int16_t)val;
            emit axisScaleRXDeadzoneUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleRYMultiplier() const {
        return (int16_t)m_config.axisScale.r_y.multiplier;
    }
    void setAxisScaleRYMultiplier(int val) {
        if (m_config.axisScale.r_y.multiplier != (int16_t)val) {
            m_config.axisScale.r_y.multiplier = (int16_t)val;
            emit axisScaleRYMultiplierUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleRYOffset() const {
        return (int16_t)m_config.axisScale.r_y.offset;
    }
    void setAxisScaleRYOffset(int val) {
        if (m_config.axisScale.r_y.offset != (int16_t)val) {
            m_config.axisScale.r_y.offset = (int16_t)val;
            emit axisScaleRYOffsetUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getAxisScaleRYDeadzone() const {
        return (int16_t)m_config.axisScale.r_y.deadzone;
    }
    void setAxisScaleRYDeadzone(int val) {
        if (m_config.axisScale.r_y.deadzone != (int16_t)val) {
            m_config.axisScale.r_y.deadzone = (int16_t)val;
            emit axisScaleRYDeadzoneUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getDebounceButtons() const {
        return (uint8_t)m_config.debounce.buttons;
    }
    void setDebounceButtons(int val) {
        if (m_config.debounce.buttons != (uint8_t)val) {
            m_config.debounce.buttons = (uint8_t)val;
            emit debounceButtonsUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    int getDebounceStrum() const {
        return (uint8_t)m_config.debounce.strum;
    }
    void setDebounceStrum(int val) {
        if (m_config.debounce.strum != (uint8_t)val) {
            m_config.debounce.strum = (uint8_t)val;
            emit debounceStrumUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getDebounceCombinedStrum() const {
        return m_config.debounce.combinedStrum;
    }
    void setDebounceCombinedStrum(bool val) {
        if (m_config.debounce.combinedStrum != val) {
            m_config.debounce.combinedStrum = val;
            emit debounceCombinedStrumUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getNeckWtNeck() const {
        return m_config.neck.wtNeck;
    }
    void setNeckWtNeck(bool val) {
        if (m_config.neck.wtNeck != val) {
            m_config.neck.wtNeck = val;
            emit neckWtNeckUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getNeckGh5Neck() const {
        return m_config.neck.gh5Neck;
    }
    void setNeckGh5Neck(bool val) {
        if (m_config.neck.gh5Neck != val) {
            m_config.neck.gh5Neck = val;
            emit neckGh5NeckUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getNeckGh5NeckBar() const {
        return m_config.neck.gh5NeckBar;
    }
    void setNeckGh5NeckBar(bool val) {
        if (m_config.neck.gh5NeckBar != val) {
            m_config.neck.gh5NeckBar = val;
            emit neckGh5NeckBarUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getNeckWiiNeck() const {
        return m_config.neck.wiiNeck;
    }
    void setNeckWiiNeck(bool val) {
        if (m_config.neck.wiiNeck != val) {
            m_config.neck.wiiNeck = val;
            emit neckWiiNeckUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    bool getNeckPs2Neck() const {
        return m_config.neck.ps2Neck;
    }
    void setNeckPs2Neck(bool val) {
        if (m_config.neck.ps2Neck != val) {
            m_config.neck.ps2Neck = val;
            emit neckPs2NeckUpdated();
            m_hasChanged = true;
            emit hasChangedUpdated();
        }
    }
    void setLED(QString key, int color) {
        uint32_t ucolor = color;
        auto pin = pins.indexOf(key)+1;
        for (auto& led : m_config.leds) {
            // Either update the colour of the led if it is already in the map, or set the first unused led.
            if (led.pin == pin || led.pin == 0) {
                led.pin = pin;
                led.red = ucolor >> 16 & 0xff;
                led.green = ucolor >> 8 & 0xff;
                led.blue = ucolor & 0xff;
                emit ledsUpdated();
                m_hasChanged = true;
                emit hasChangedUpdated();
                return;
            }
        }
    }
    QVariantMap getLEDColours() {
        QVariantMap l;
        for (auto led : m_config.leds) {
            if (led.pin == 0) break;
            l[pins[led.pin-1]] = led.red << 16 | led.green << 8 | led.blue;
        }
        for (auto pin: pins) {
            l[pin] = l.value(pin,0);
        }
        return l;
    }
    QVariantList getLEDs() {
        QVariantList l;
        for (auto led : m_config.leds) {
            if (led.pin == 0) break;
            l << pins[led.pin-1];
        }
        return l;
    }
    void clearLED(QString key) {
        auto pin = pins.indexOf(key)+1;
        auto a = std::remove_if(std::begin(m_config.leds), std::end(m_config.leds), [pin](Led_t x) { return x.pin == pin; });
        Led_t empty = {0,0,0};
        std::fill(a, std::end(m_config.leds), empty);
        std::copy(std::begin(m_config.leds), std::end(m_config.leds), std::begin(m_config.leds));
        emit ledsUpdated();
        m_hasChanged = true;
        emit hasChangedUpdated();
    }
    void moveLED(int from, int to) {
        if (from == to)
            return;
        auto const b = std::begin(m_config.leds);
        if (from < to)
            std::rotate(b + from, b + from + 1, b + to + 1);
        else
            std::rotate(b + to, b + from, b + from + 1);
        emit ledsUpdated();
        m_hasChanged = true;
        emit hasChangedUpdated();
    }

    QMap<QString, uint> getMappings() {
        QMap<QString, uint> map;
        PinsCombined_t* combined = reinterpret_cast<PinsCombined_t*>(&m_config.pins);
        for (uint8_t i = 0; i < pins.size(); i++) {
            if (i < XBOX_BTN_COUNT) {
                map[pins[i]] = combined->buttons[i];
            } else {
                map[pins[i]] = combined->axis[i-XBOX_BTN_COUNT].pin;
            }
        }
        return map;
    }
signals:
    void hasChangedUpdated();
    void mainInputTypeUpdated();
    void mainSubTypeUpdated();
    void mainTiltTypeUpdated();
    void mainPollRateUpdated();
    void mainFretLEDModeUpdated();
    void mainMapLeftJoystickToDPadUpdated();
    void mainMapStartSelectToHomeUpdated();
    void mainMapNunchukAccelToRightJoyUpdated();
    void mainSignatureUpdated();
    void mainVersionUpdated();
    void pinsUpUpdated();
    void pinsDownUpdated();
    void pinsLeftUpdated();
    void pinsRightUpdated();
    void pinsStartUpdated();
    void pinsBackUpdated();
    void pinsLeftStickUpdated();
    void pinsRightStickUpdated();
    void pinsLBUpdated();
    void pinsRBUpdated();
    void pinsHomeUpdated();
    void pinsCaptureUpdated();
    void pinsAUpdated();
    void pinsBUpdated();
    void pinsXUpdated();
    void pinsYUpdated();
    void pinsLtUpdated();
    void pinsLtInvertedUpdated();
    void pinsRtUpdated();
    void pinsRtInvertedUpdated();
    void pinsLXUpdated();
    void pinsLXInvertedUpdated();
    void pinsLYUpdated();
    void pinsLYInvertedUpdated();
    void pinsRXUpdated();
    void pinsRXInvertedUpdated();
    void pinsRYUpdated();
    void pinsRYInvertedUpdated();
    void axisTriggerThresholdUpdated();
    void axisJoyThresholdUpdated();
    void axisDrumThresholdUpdated();
    void axisMpu6050OrientationUpdated();
    void axisTiltSensitivityUpdated();
    void keysUpUpdated();
    void keysDownUpdated();
    void keysLeftUpdated();
    void keysRightUpdated();
    void keysStartUpdated();
    void keysBackUpdated();
    void keysLeftStickUpdated();
    void keysRightStickUpdated();
    void keysLBUpdated();
    void keysRBUpdated();
    void keysHomeUpdated();
    void keysCaptureUpdated();
    void keysAUpdated();
    void keysBUpdated();
    void keysXUpdated();
    void keysYUpdated();
    void keysLtUpdated();
    void keysRtUpdated();
    void keysLXNegUpdated();
    void keysLXPosUpdated();
    void keysLYNegUpdated();
    void keysLYPosUpdated();
    void keysRXNegUpdated();
    void keysRXPosUpdated();
    void keysRYNegUpdated();
    void keysRYPosUpdated();
    void ledsUpdated();
    void midiTypeUpdated();
    void midiNoteUpdated();
    void midiChannelUpdated();
    void rfRfInEnabledUpdated();
    void rfIdUpdated();
    void pinsSPUpdated();
    void axisScaleLtMultiplierUpdated();
    void axisScaleLtOffsetUpdated();
    void axisScaleLtDeadzoneUpdated();
    void axisScaleRtMultiplierUpdated();
    void axisScaleRtOffsetUpdated();
    void axisScaleRtDeadzoneUpdated();
    void axisScaleLXMultiplierUpdated();
    void axisScaleLXOffsetUpdated();
    void axisScaleLXDeadzoneUpdated();
    void axisScaleLYMultiplierUpdated();
    void axisScaleLYOffsetUpdated();
    void axisScaleLYDeadzoneUpdated();
    void axisScaleRXMultiplierUpdated();
    void axisScaleRXOffsetUpdated();
    void axisScaleRXDeadzoneUpdated();
    void axisScaleRYMultiplierUpdated();
    void axisScaleRYOffsetUpdated();
    void axisScaleRYDeadzoneUpdated();
    void debounceButtonsUpdated();
    void debounceStrumUpdated();
    void debounceCombinedStrumUpdated();
    void neckWtNeckUpdated();
    void neckGh5NeckUpdated();
    void neckGh5NeckBarUpdated();
    void neckWiiNeckUpdated();
    void neckPs2NeckUpdated();

private:
    Configuration_t m_config;
    const static QStringList pins;
    bool m_hasChanged;
};