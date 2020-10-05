#include "volumeSlider.h"
volumeSlider::volumeSlider(Adafruit_ILI9341* _tft, MouseData* _mouseData, int _xPos, int _yPos, int _width, int _height, uint16_t _standardColor, uint16_t _activeColor, int _rangeMax, int _boxWidth, int _val)
{
    val = _val;
    lastVal = _val;
    tft = _tft;
    mouseData = _mouseData;
    xPos = _xPos;
    yPos = _yPos;
    width = _width;
    height = _height;
    rangeMax = _rangeMax;
    boxWidth = _boxWidth;
    standardColor = _standardColor;
    activeColor = _activeColor;
    state = false;
    undrawn = true;
    newVal = false;
}

void volumeSlider::run()
{
    if (undrawn) {
        undrawn = false;
        draw();
    }
    if ((*mouseData).mouseX > xPos and (*mouseData).mouseX < xPos + width and (*mouseData).mouseY > yPos and (*mouseData).mouseY < yPos + height) {
        if ((*mouseData).mouseDown) {
            state = true;
            draw();
        }
    } else if (state == true) {
        state = false;
        draw();
        newVal = true;
    }
    if ((*mouseData).mouseUp && state == true) {
        state = false;
        draw();
        newVal = true;
    }
    if (state) {
        lastVal = val;
        val = constrain(map((*mouseData).mouseX, xPos + boxWidth / 2, xPos + width - boxWidth / 2, 0, rangeMax), 0, rangeMax);
        if (val != lastVal) {
            draw();
        }
    }
}
void volumeSlider::draw()
{
    (*tft).fillRect(xPos, yPos, width, height, standardColor);
    (*tft).setTextSize(1);
    (*tft).fillRect(map(val, 0, rangeMax, xPos, xPos + width - boxWidth), yPos, boxWidth, height, activeColor);
    (*tft).setTextColor(0);
    (*tft).setCursor(map(val, 0, rangeMax, xPos, xPos + width - boxWidth) + menuScreenConstants.SCREEN_FONT_WIDTH, yPos + height / 2);
    (*tft).print(map(val, 0, rangeMax, 0, 100));
}
int volumeSlider::getVal()
{
    return val;
}
void volumeSlider::setVal(int _val)
{
    val = _val;
}
void volumeSlider::setUndrawn()
{
    undrawn = true;
}
boolean volumeSlider::newValue()
{
    if (newVal) {
        newVal = false;
        return true;
    }
    return false;
}