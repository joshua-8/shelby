#ifndef DRIVEBASE_H_
#define DRIVEBASE_H_
#include "JMotor.h"
#include "constants/drivetrainConstants.h"
#include "constants/pinout.h"
#include "constants/wheelConstants.h"
#include <Arduino.h>

class Drivebase {
public:
    JMotorDriverAvrPWMDir leftMotorDriver = JMotorDriverAvrPWMDir(LEFT_WHEEL_SPEED_PIN, LEFT_WHEEL_DIR_PIN);
    JMotorDriverAvrPWMDir rightMotorDriver = JMotorDriverAvrPWMDir(LEFT_WHEEL_SPEED_PIN, LEFT_WHEEL_DIR_PIN);
    JEncoderQuadratureAttachInterrupt leftWheelEncoder = JEncoderQuadratureAttachInterrupt(LEFT_WHEEL_ENCODER_CHA_PIN, LEFT_WHEEL_ENCODER_CHB_PIN, 1.0 / wheelConstants.ticksPerMeter);
    JEncoderQuadratureAttachInterrupt rightWheelEncoder = JEncoderQuadratureAttachInterrupt(RIGHT_WHEEL_ENCODER_CHA_PIN, RIGHT_WHEEL_ENCODER_CHB_PIN, 1.0 / wheelConstants.ticksPerMeter);
    JVoltageCompMeasure<8> mbatMonitor = JVoltageCompMeasure<8>(BAT_MONITOR_PIN, drivetrainConstants.batMon);
    JMotorCompBasic leftMotorCompensator = JMotorCompBasic(mbatMonitor, 12, .05);
    JMotorCompBasic rightMotorCompensator = JMotorCompBasic(mbatMonitor, 12, .05);
    JControlLoopBasic leftMotorControlLoop = JControlLoopBasic(1, 1000);
    JControlLoopBasic rightMotorControlLoop = JControlLoopBasic(1, 1000);
    JMotorControllerClosed leftMotorController = JMotorControllerClosed(leftMotorDriver, leftMotorCompensator, leftWheelEncoder, leftMotorControlLoop);
    JMotorControllerClosed rightMotorController = JMotorControllerClosed(rightMotorDriver, rightMotorCompensator, rightWheelEncoder, rightMotorControlLoop);
    JDrivetrainTwoSide drvtrain = JDrivetrainTwoSide(leftMotorController, rightMotorController, drivetrainConstants.wheelbase);
    JDrivetrainControllerBasic drivetrain = JDrivetrainControllerBasic(drvtrain, { 1, 1, 1 }, { 1, 1, 1 }, { .1, .1, .1 });
    void begin();
    void run();
};
#endif