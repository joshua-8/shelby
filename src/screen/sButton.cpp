#include "sButton.h"

sButton::sButton(Adafruit_ILI9341* _tft, MouseData* _mouseData, int _xPos, int _yPos, int _width, int _height, uint16_t _standardColor, uint16_t _activeColor, uint16_t _textColor, uint16_t _edgeColor, String _label, boolean _momentary)
{
    tft = _tft;
    mouseData = _mouseData;
    xPos = _xPos;
    yPos = _yPos;
    width = max(_width, 0);
    height = max(_height, menuScreenConstants.SCREEN_FONT_HEIGHT + 1);
    standardColor = _standardColor;
    activeColor = _activeColor;
    textColor = _textColor;
    edgeColor = _edgeColor;
    state = false;
    lastState = false;
    undrawn = true;
    secondLabel = "";
    if (_label.length() * menuScreenConstants.SCREEN_FONT_WIDTH + 4 >= width) {
        label = "";
    } else {
        label = _label;
    }
    momentary = _momentary;
}

void sButton::run()
{
    lastState = state;
    if (undrawn) {
        draw();
        undrawn = false;
    }
    if (momentary) {
        if ((*mouseData).mouseX > xPos and (*mouseData).mouseX < xPos + width and (*mouseData).mouseY > yPos and (*mouseData).mouseY < yPos + height) {
            if ((*mouseData).mouseDown) {
                state = true;
                draw();
            }
        }
        if ((*mouseData).mouseUp) {
            state = false;
            draw();
        }
    } else { //if latching
        if ((*mouseData).mouseUp and (*mouseData).mouseXUp > xPos and (*mouseData).mouseXUp < xPos + width and (*mouseData).mouseYUp > yPos and (*mouseData).mouseYUp < yPos + height) {
            state = !state;
            draw();
        }
    }
}
void sButton::draw()
{
    (*tft).fillRect(xPos, yPos, width, height, state ? activeColor : standardColor);
    (*tft).drawRect(xPos, yPos, width, height, edgeColor);
    (*tft).setCursor(xPos + 2, yPos + 2);
    (*tft).setTextColor(textColor);
    (*tft).setTextSize(1);
    (*tft).print(label);
    (*tft).setCursor(xPos + 2, yPos + height / 2);
    (*tft).print(secondLabel);
}
boolean sButton::getState()
{
    return state;
}
boolean sButton::getJustPushed()
{
    return (state == true and lastState == false);
}
boolean sButton::getJustReleased()
{
    return (state == false and lastState == true);
}
void sButton::setState(boolean _state)
{
    lastState = state;
    state = _state;
    draw();
}
boolean sButton::setText(String _label)
{
    if (_label.length() * menuScreenConstants.SCREEN_FONT_WIDTH + 4 >= width) {
        return true;
    }
    label = _label;
    draw();
    return false;
}

boolean sButton::setSubText(String _label)
{
    if (_label.length() * menuScreenConstants.SCREEN_FONT_WIDTH + 4 >= width) {
        return true;
    }
    secondLabel = _label;
    draw();
    return false;
}
void sButton::setUndrawn()
{
    undrawn = true;
}
