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
    JMotorDriverAvrPWMDir rightMotorDriver = JMotorDriverAvrPWMDir(RIGHT_WHEEL_SPEED_PIN, RIGHT_WHEEL_DIR_PIN);
    JEncoderQuadratureAttachInterrupt leftWheelEncoder = JEncoderQuadratureAttachInterrupt(LEFT_WHEEL_ENCODER_CHA_PIN, LEFT_WHEEL_ENCODER_CHB_PIN, .25 / wheelConstants.ticksPerMeter);
    JEncoderQuadratureAttachInterrupt rightWheelEncoder = JEncoderQuadratureAttachInterrupt(RIGHT_WHEEL_ENCODER_CHA_PIN, RIGHT_WHEEL_ENCODER_CHB_PIN, .25 / wheelConstants.ticksPerMeter, true);
    JVoltageCompMeasure<8> mbatMonitor = JVoltageCompMeasure<8>(BAT_MONITOR_PIN, drivetrainConstants.batMon);
    JMotorCompBasic leftMotorCompensator = JMotorCompBasic(mbatMonitor, 3.65, .05);
    JMotorCompBasic rightMotorCompensator = JMotorCompBasic(mbatMonitor, 3.65, .05);
    JControlLoopBasic leftMotorControlLoop = JControlLoopBasic(35, 1000);
    JControlLoopBasic rightMotorControlLoop = JControlLoopBasic(35, 1000);
    JMotorControllerClosed leftMotorController = JMotorControllerClosed(leftMotorDriver, leftMotorCompensator, leftWheelEncoder, leftMotorControlLoop, INFINITY, INFINITY, .05, false, 2.0);
    JMotorControllerClosed rightMotorController = JMotorControllerClosed(rightMotorDriver, rightMotorCompensator, rightWheelEncoder, rightMotorControlLoop, INFINITY, INFINITY, .05, false, 2.0);
    JDrivetrainTwoSide drvtrain = JDrivetrainTwoSide(leftMotorController, rightMotorController, drivetrainConstants.wheelbase);
    JDrivetrainControllerBasic drivetrain = JDrivetrainControllerBasic(drvtrain, { 10, 200, 0 }, { .8, 80, 0 }, { .1, 20, 0 });
    void begin();
    void run();
};
#endif
