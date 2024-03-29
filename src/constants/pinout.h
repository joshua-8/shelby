#ifndef PINOUT_H
#define PINOUT_H
#include <Arduino.h>
const byte PIXY_MOSI_PIN = 0;
const byte PIXY_MISO_PIN = 1;
const byte BNO055_SCL_PIN = 3;
const byte BNO055_SDA_PIN = 4;
const byte SCREEN_DC_PIN = 5;
const byte SCREEN_LIGHT_PIN = 6;
#define RIGHT_TOF_SERIAL_PORT Serial2
#define LEFT_TOF_SERIAL_PORT Serial3
const byte SCREEN_MOSI_PIN = 11;
const byte SCREEN_MISO_PIN = 12;
const byte SCREEN_CLK_PIN = 13;
const byte SCREEN_CS_PIN = 15;
const byte SCREEN_TOUCH_Y_P_PIN = 17;
const byte SCREEN_TOUCH_X_P_PIN = 18;
const byte SCREEN_TOUCH_Y_M_PIN = 19;
const byte SCREEN_TOUCH_X_M_PIN = 20;
const byte GO_BUTTON_BLUE_PIN = 21;
const byte GO_BUTTON_GREEN_PIN = 22;
const byte GO_BUTTON_RED_PIN = 23;
const byte TAIL_SERVO_PIN = 24;
const byte HEAD_PAN_SERVO_PIN = 25;
const byte HEAD_TILT_SERVO_PIN = 26;
const byte LEFT_WHEEL_DIR_PIN = 27;
const byte RIGHT_WHEEL_DIR_PIN = 28;
const byte LEFT_WHEEL_SPEED_PIN = 29;
const byte RIGHT_WHEEL_SPEED_PIN = 30;
const byte PIXY_CS_PIN = 31;
const byte PIXY_SCK_PIN = 32;
const byte AUDIO_FX_RX_PIN = 33;
const byte AUDIO_FX_TX_PIN = 34;
const byte AUDIO_FX_AUX_PIN = 35;
const byte BAT_MONITOR_PIN = 39;
const byte IR_RECEIVER_PIN = 40;
const byte LEFT_WHEEL_MAG_SENSOR_PIN = 41;
const byte RIGHT_WHEEL_MAG_SENSOR_PIN = 42;
const byte LEFT_WHEEL_ENCODER_CHB_PIN = 43;
const byte LEFT_WHEEL_ENCODER_CHA_PIN = 44;
const byte RIGHT_WHEEL_ENCODER_CHB_PIN = 45;
const byte RIGHT_WHEEL_ENCODER_CHA_PIN = 46;
const byte RIGHT_TOF_SERVO_CONTROL_PIN = 47;
const byte LEFT_TOF_SERVO_CONTROL_PIN = 48;
const byte RIGHT_TOF_SERVO_POSITION_PIN = 49;
const byte LEFT_TOF_SERVO_POSITION_PIN = 50;
const byte EYE_LIGHTS_CLOCK_PIN = 51;
const byte EYE_LIGHTS_DATA_PIN = 52;
const byte GO_STOP_BUTTON_PIN = 53;
const byte RIGHT_WHEEL_LIGHTS_CLOCK_PIN = 55;
const byte RIGHT_WHEEL_LIGHTS_DATA_PIN = 54;
const byte LEFT_WHEEL_LIGHTS_CLOCK_PIN = 57;
const byte LEFT_WHEEL_LIGHTS_DATA_PIN = 56;
const byte BACK_DIST_PIN = A10; //a10
const byte FRONT_DIST_PIN = A11; //a11
const byte RIGHT_DIST_PIN = A21; //dac0
const byte LEFT_DIST_PIN = A22; //dac1
#endif
