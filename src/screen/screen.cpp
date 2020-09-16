#include "screen.h"

Screen::Screen(generalSetStruct* _genSettings)
{
    numPad = new NumPad(&tft);
    preditScreen = new Screen_Predit(_genSettings, &screenMode, &tft, numPad);
    mseditScreen = new Screen_MSedit(_genSettings, &screenMode, &tft, numPad);
    teditScreen = new Screen_Tedit(&screenMode, &tft, numPad);
    homeScreen = new Screen_Home(_genSettings, &screenMode, &tft, preditScreen, mseditScreen, teditScreen);
}

void Screen::begin()
{
    pinMode(SCREEN_LIGHT_PIN, OUTPUT);
    digitalWrite(SCREEN_LIGHT_PIN, HIGH);
    tft.begin();
    tft.setRotation(3);
    tft.setTextWrap(false);
    (*homeScreen).begin();
    screenMode = 0;
}

void Screen::run()
{
    mouseData = readScreen();
    if (screenMode == menuScreenConstants.SCREEN_MODE_HOME) {
        (*homeScreen).run(mouseData);
        if (screenMode == menuScreenConstants.SCREEN_MODE_PREDIT) {
            (*preditScreen).begin();
        }
        if (screenMode == menuScreenConstants.SCREEN_MODE_MSEDIT) {
            (*mseditScreen).begin();
        }
        if (screenMode == menuScreenConstants.SCREEN_MODE_TEDIT) {
            (*teditScreen).begin();
        }
    }
    if (screenMode == menuScreenConstants.SCREEN_MODE_PREDIT) {
        (*preditScreen).run(mouseData);
        if (screenMode == menuScreenConstants.SCREEN_MODE_HOME) {
            (*homeScreen).begin();
        }
    }
    if (screenMode == menuScreenConstants.SCREEN_MODE_MSEDIT) {
        (*mseditScreen).run(mouseData);
        if (screenMode == menuScreenConstants.SCREEN_MODE_HOME) {
            (*homeScreen).begin();
        }
    }
    if (screenMode == menuScreenConstants.SCREEN_MODE_TEDIT) {
        (*teditScreen).run(mouseData);
        if (screenMode == menuScreenConstants.SCREEN_MODE_HOME) {
            (*homeScreen).begin();
        }
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
    if (mouseData.mouseRawPressed == true && mouseData.millisSinceRawMouseDown > menuScreenConstants.SCREEN_DEBOUNCE_TIME) {
        mouseData.mousePressed = true;
    }
    if (mouseData.mouseRawPressed == false && mouseData.millisSinceRawMouseUp > menuScreenConstants.SCREEN_DEBOUNCE_TIME) {
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
    return analogRead(SCREEN_TOUCH_X_M_PIN) < menuScreenConstants.SCREEN_PRESSED_THRESHOLD;
}

float Screen::readMouseY()
{
    unsigned long sum = 0;
    for (int i = 0; i < menuScreenConstants.mouseAvgArrNum; i++) {
        pinMode(SCREEN_TOUCH_Y_M_PIN, INPUT);
        pinMode(SCREEN_TOUCH_Y_P_PIN, INPUT);
        pinMode(SCREEN_TOUCH_X_M_PIN, OUTPUT);
        digitalWrite(SCREEN_TOUCH_X_M_PIN, HIGH);
        pinMode(SCREEN_TOUCH_X_P_PIN, OUTPUT);
        digitalWrite(SCREEN_TOUCH_X_P_PIN, LOW);
        sum += analogRead(SCREEN_TOUCH_Y_P_PIN) + analogRead(SCREEN_TOUCH_Y_M_PIN);
    }
    sum /= menuScreenConstants.mouseAvgArrNum;
    return map(sum, menuScreenConstants.SCREEN_MIN_Y, menuScreenConstants.SCREEN_MAX_Y, 0, menuScreenConstants.SCREEN_HEIGHT);
}
float Screen::readMouseX()
{
    unsigned long sum = 0;
    for (int i = 0; i < menuScreenConstants.mouseAvgArrNum; i++) {
        pinMode(SCREEN_TOUCH_X_M_PIN, INPUT);
        pinMode(SCREEN_TOUCH_X_P_PIN, INPUT);
        pinMode(SCREEN_TOUCH_Y_M_PIN, OUTPUT);
        digitalWrite(SCREEN_TOUCH_Y_M_PIN, HIGH);
        pinMode(SCREEN_TOUCH_Y_P_PIN, OUTPUT);
        digitalWrite(SCREEN_TOUCH_Y_P_PIN, LOW);
        sum += analogRead(SCREEN_TOUCH_X_M_PIN) + analogRead(SCREEN_TOUCH_X_P_PIN);
    }
    sum /= menuScreenConstants.mouseAvgArrNum;
    return map(sum, menuScreenConstants.SCREEN_MIN_X, menuScreenConstants.SCREEN_MAX_X, 0, menuScreenConstants.SCREEN_WIDTH);
}
