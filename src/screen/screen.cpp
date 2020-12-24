#include "screen.h"
Screen::Screen(MsgScreen* _msgScreen)
{
    tft = new Adafruit_ILI9341(SCREEN_CS_PIN, SCREEN_DC_PIN, SCREEN_MOSI_PIN, SCREEN_CLK_PIN, 255, SCREEN_MISO_PIN);
    mouseData = { -1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0, false, false, false, false };
    menuScreen = new MenuScreen(&mouseData, tft);
    msgScreen = _msgScreen;
    (*msgScreen).setTFT(tft);
}

void Screen::begin()
{
    pinMode(SCREEN_LIGHT_PIN, OUTPUT);
    digitalWrite(SCREEN_LIGHT_PIN, HIGH);
    (*tft).begin();
    (*tft).setRotation(3);
    (*tft).setTextWrap(false);
    (*menuScreen).begin();
}

void Screen::run()
{
    mouseData = readScreen();
    if (!(*msgScreen).display()) {
        if ((*msgScreen).wasShowing()) {
            (*menuScreen).begin();
        }
        (*menuScreen).run();
    }
}
MouseData Screen::readScreen()
{
    mouseData.lastMousePressed = mouseData.mousePressed;
    mouseData.lastMouseRawPressed = mouseData.mouseRawPressed;
    mouseData.mouseRawPressed = readMousePressed();
    if (mouseData.mouseRawPressed == true && mouseData.lastMouseRawPressed == false) {
        mouseData.millisSinceRawMouseDown = 0;
    }
    if (mouseData.mouseRawPressed == false && mouseData.lastMouseRawPressed == true) {
        mouseData.millisSinceRawMouseUp = 0;
        mouseData.mouseXUp = mouseData.lastMouseX;
        mouseData.mouseYUp = mouseData.lastMouseY;
    }
    if (mouseData.mouseRawPressed == true && mouseData.millisSinceRawMouseDown > screenConstants.SCREEN_DEBOUNCE_TIME) {
        mouseData.mousePressed = true;
    }
    if (mouseData.mouseRawPressed == false && mouseData.millisSinceRawMouseUp > screenConstants.SCREEN_DEBOUNCE_TIME) {
        mouseData.mousePressed = false;
    }
    if (mouseData.mouseRawPressed) {
        mouseData.mouseX = readMouseX();
        mouseData.mouseY = readMouseY();
    }
    if (mouseData.mousePressed) {
        mouseData.lastMouseX = mouseData.mouseX;
        mouseData.lastMouseY = mouseData.mouseY;
    }
    if (mouseData.lastMousePressed == false and mouseData.mousePressed == true) {
        mouseData.lastMouseX = mouseData.mouseX;
        mouseData.lastMouseY = mouseData.mouseY;
        mouseData.mouseXDown = mouseData.mouseX;
        mouseData.mouseYDown = mouseData.mouseY;
        mouseData.mouseDown = true;
        mouseData.millisSinceMouseDown = 0;
    } else {
        mouseData.mouseDown = false;
    }
    if (mouseData.lastMousePressed == true and mouseData.mousePressed == false) {
        mouseData.mouseUp = true;
        mouseData.millisSinceMouseUp = 0;
    } else {
        mouseData.mouseUp = false;
    }
    return mouseData;
}
boolean Screen::readMousePressed()
{
    pinMode(SCREEN_TOUCH_X_P_PIN, INPUT_PULLUP);
    pinMode(SCREEN_TOUCH_X_M_PIN, INPUT_PULLUP);
    pinMode(SCREEN_TOUCH_Y_M_PIN, OUTPUT);
    digitalWrite(SCREEN_TOUCH_Y_M_PIN, LOW);
    pinMode(SCREEN_TOUCH_Y_P_PIN, OUTPUT);
    digitalWrite(SCREEN_TOUCH_Y_P_PIN, LOW);
    return analogRead(SCREEN_TOUCH_X_M_PIN) < screenConstants.SCREEN_PRESSED_THRESHOLD;
}

float Screen::readMouseY()
{
    unsigned long sum = 0;
    for (int i = 0; i < screenConstants.mouseAvgArrNum; i++) {
        pinMode(SCREEN_TOUCH_Y_M_PIN, INPUT);
        pinMode(SCREEN_TOUCH_Y_P_PIN, INPUT);
        pinMode(SCREEN_TOUCH_X_M_PIN, OUTPUT);
        digitalWrite(SCREEN_TOUCH_X_M_PIN, HIGH);
        pinMode(SCREEN_TOUCH_X_P_PIN, OUTPUT);
        digitalWrite(SCREEN_TOUCH_X_P_PIN, LOW);
        sum += analogRead(SCREEN_TOUCH_Y_P_PIN) + analogRead(SCREEN_TOUCH_Y_M_PIN);
    }
    sum /= screenConstants.mouseAvgArrNum;
    return map(sum, screenConstants.SCREEN_MIN_Y, screenConstants.SCREEN_MAX_Y, 0, screenConstants.SCREEN_HEIGHT);
}
float Screen::readMouseX()
{
    unsigned long sum = 0;
    for (int i = 0; i < screenConstants.mouseAvgArrNum; i++) {
        pinMode(SCREEN_TOUCH_X_M_PIN, INPUT);
        pinMode(SCREEN_TOUCH_X_P_PIN, INPUT);
        pinMode(SCREEN_TOUCH_Y_M_PIN, OUTPUT);
        digitalWrite(SCREEN_TOUCH_Y_M_PIN, HIGH);
        pinMode(SCREEN_TOUCH_Y_P_PIN, OUTPUT);
        digitalWrite(SCREEN_TOUCH_Y_P_PIN, LOW);
        sum += analogRead(SCREEN_TOUCH_X_M_PIN) + analogRead(SCREEN_TOUCH_X_P_PIN);
    }
    sum /= screenConstants.mouseAvgArrNum;
    return map(sum, screenConstants.SCREEN_MIN_X, screenConstants.SCREEN_MAX_X, 0, screenConstants.SCREEN_WIDTH);
}
