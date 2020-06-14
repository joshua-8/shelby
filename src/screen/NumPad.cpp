#include "NumPad.h"

NumPad::NumPad(Adafruit_ILI9341 *_tft)
{
    tft = _tft;
    button0 = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH * 0 / 3, NUMPAD_POS_Y + NUMPAD_HEIGHT * 3 / 5, NUMPAD_WIDTH / 3, NUMPAD_HEIGHT / 5, NUMPAD_BACKGROUND_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_ACTIVE_COLOR, "0", true);
    button1 = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH * 0 / 3, NUMPAD_POS_Y + NUMPAD_HEIGHT * 2 / 5, NUMPAD_WIDTH / 3, NUMPAD_HEIGHT / 5, NUMPAD_BACKGROUND_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_ACTIVE_COLOR, "1", true);
    button2 = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH * 1 / 3, NUMPAD_POS_Y + NUMPAD_HEIGHT * 2 / 5, NUMPAD_WIDTH / 3, NUMPAD_HEIGHT / 5, NUMPAD_BACKGROUND_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_ACTIVE_COLOR, "2", true);
    button3 = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH * 2 / 3, NUMPAD_POS_Y + NUMPAD_HEIGHT * 2 / 5, NUMPAD_WIDTH / 3, NUMPAD_HEIGHT / 5, NUMPAD_BACKGROUND_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_ACTIVE_COLOR, "3", true);
    button4 = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH * 0 / 3, NUMPAD_POS_Y + NUMPAD_HEIGHT * 1 / 5, NUMPAD_WIDTH / 3, NUMPAD_HEIGHT / 5, NUMPAD_BACKGROUND_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_ACTIVE_COLOR, "4", true);
    button5 = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH * 1 / 3, NUMPAD_POS_Y + NUMPAD_HEIGHT * 1 / 5, NUMPAD_WIDTH / 3, NUMPAD_HEIGHT / 5, NUMPAD_BACKGROUND_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_ACTIVE_COLOR, "5", true);
    button6 = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH * 2 / 3, NUMPAD_POS_Y + NUMPAD_HEIGHT * 1 / 5, NUMPAD_WIDTH / 3, NUMPAD_HEIGHT / 5, NUMPAD_BACKGROUND_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_ACTIVE_COLOR, "6", true);
    button7 = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH * 0 / 3, NUMPAD_POS_Y + NUMPAD_HEIGHT * 0 / 5, NUMPAD_WIDTH / 3, NUMPAD_HEIGHT / 5, NUMPAD_BACKGROUND_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_ACTIVE_COLOR, "7", true);
    button8 = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH * 1 / 3, NUMPAD_POS_Y + NUMPAD_HEIGHT * 0 / 5, NUMPAD_WIDTH / 3, NUMPAD_HEIGHT / 5, NUMPAD_BACKGROUND_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_ACTIVE_COLOR, "8", true);
    button9 = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH * 2 / 3, NUMPAD_POS_Y + NUMPAD_HEIGHT * 0 / 5, NUMPAD_WIDTH / 3, NUMPAD_HEIGHT / 5, NUMPAD_BACKGROUND_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_ACTIVE_COLOR, "9", true);

    buttonDec = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH * 1 / 3, NUMPAD_POS_Y + NUMPAD_HEIGHT * 3 / 5, NUMPAD_WIDTH / 3, NUMPAD_HEIGHT / 5, NUMPAD_BACKGROUND_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_ACTIVE_COLOR, ".", true);
    buttonNeg = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH * 2 / 3, NUMPAD_POS_Y + NUMPAD_HEIGHT * 3 / 5, NUMPAD_WIDTH / 3, NUMPAD_HEIGHT / 5, NUMPAD_BACKGROUND_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_ACTIVE_COLOR, "-", true);
    buttonY = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH * 0 / 3, NUMPAD_POS_Y + NUMPAD_HEIGHT * 4 / 5, NUMPAD_WIDTH / 3, NUMPAD_HEIGHT / 5, NUMPAD_YES_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_ACTIVE_COLOR, "Y", true);
    buttonN = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH * 1 / 3, NUMPAD_POS_Y + NUMPAD_HEIGHT * 4 / 5, NUMPAD_WIDTH / 3, NUMPAD_HEIGHT / 5, NUMPAD_NO_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_ACTIVE_COLOR, "N", true);
    buttonDel = new sButton(tft, NUMPAD_POS_X + NUMPAD_WIDTH * 2 / 3, NUMPAD_POS_Y + NUMPAD_HEIGHT * 4 / 5, NUMPAD_WIDTH / 3, NUMPAD_HEIGHT / 5, NUMPAD_DEL_COLOR, NUMPAD_ACTIVE_COLOR, NUMPAD_TEXT_COLOR, NUMPAD_ACTIVE_COLOR, "<", true);
    str.reserve(NUMPAD_STRING_LENGTH + 1);
}

void NumPad::setInteger(boolean _integer)
{
    constrainInteger = _integer;
}
void NumPad::setVal(float _val)
{
    finalVal = _val;
    val = finalVal;
    str = "#";
}
float NumPad::getFinalVal()
{
    return finalVal;
}

void NumPad::begin()
{
    setUndrawn();
    val = 0;
    finalVal = 0;
    str = "#";
}

boolean NumPad::run(MouseData mouseData)
{
    boolean change = false;
    if (str == "#")
    {
        change = true;
        str = getValString();
    }
    (*button0).run(mouseData);
    (*button1).run(mouseData);
    (*button2).run(mouseData);
    (*button3).run(mouseData);
    (*button4).run(mouseData);
    (*button5).run(mouseData);
    (*button6).run(mouseData);
    (*button7).run(mouseData);
    (*button8).run(mouseData);
    (*button9).run(mouseData);
    (*buttonDec).run(mouseData);
    (*buttonNeg).run(mouseData);
    (*buttonY).run(mouseData);
    (*buttonN).run(mouseData);
    (*buttonDel).run(mouseData);

    if (str.length() < NUMPAD_STRING_LENGTH + (str.charAt(0) == '-' ? 1 : 0) + (str.indexOf('.') != -1 ? 1 : 0))
    {
        if ((*button0).getJustReleased())
        {
            str.append(0);
            change = true;
        }
        if ((*button1).getJustReleased())
        {
            str.append("1");
            change = true;
        }
        if ((*button2).getJustReleased())
        {
            str.append("2");
            change = true;
        }
        if ((*button3).getJustReleased())
        {
            str.append("3");
            change = true;
        }
        if ((*button4).getJustReleased())
        {
            str.append("4");
            change = true;
        }
        if ((*button5).getJustReleased())
        {
            str.append("5");
            change = true;
        }
        if ((*button6).getJustReleased())
        {
            str.append("6");
            change = true;
        }
        if ((*button7).getJustReleased())
        {
            str.append("7");
            change = true;
        }
        if ((*button8).getJustReleased())
        {
            str.append("8");
            change = true;
        }
        if ((*button9).getJustReleased())
        {
            str.append("9");
            change = true;
        }
    }
    if ((*buttonDec).getJustReleased() && !constrainInteger && str.length() < NUMPAD_STRING_LENGTH + (str.charAt(0) == '-' ? 1 : 0))
    {
        if (str == ""||str=="-")
        {
            str = "0";
        }
        str.append(".");
        change = true;
    }

    if ((*buttonDel).getJustReleased())
    {
        change = true;

        if (str.length() == 1)
        {
            str = "";
        }
        else
        {
            str = str.substring(0, str.length() - 1);
        }
    }
    val = str.toFloat();
    if (str == "")
    {
        val = 0;
    }

    if ((*buttonNeg).getJustReleased())
    {
        if (val < 0||str.charAt(0)=='-')
            str = str.substring(1, str.length());
        else
            str = "-" + str;

        change = true;
        val = -val; //negative key
    }
    if ((*buttonY).getJustReleased())
    {
        change = true;
        if (constrainInteger)
        {
            finalVal = int(val);
        }
        else
        {
            finalVal = val;
        }
    }
    if ((*buttonN).getJustReleased())
    {
        if (val == finalVal) //quick clear
        {
            str = String("");
            val = str.toFloat();
            if (str == "")
            {
                val = 0;
            }
            change = true;
        }
        else
        {
            change = true;
            val = finalVal;
            str = getValString();
        }
    }
    return change;
}

void NumPad::setUndrawn()
{
    (*button0).setUndrawn();
    (*button1).setUndrawn();
    (*button2).setUndrawn();
    (*button3).setUndrawn();
    (*button4).setUndrawn();
    (*button5).setUndrawn();
    (*button6).setUndrawn();
    (*button7).setUndrawn();
    (*button8).setUndrawn();
    (*button9).setUndrawn();
    (*buttonDec).setUndrawn();
    (*buttonNeg).setUndrawn();
    (*buttonY).setUndrawn();
    (*buttonN).setUndrawn();
    (*buttonDel).setUndrawn();
}
String NumPad::getValString()
{
    return String(val, NUMPAD_STRING_LENGTH - 1 - max(int(log10(abs(val))), 0));
}
String NumPad::getFinalValString()
{
    return String(finalVal, NUMPAD_STRING_LENGTH - 1 - max(int(log10(abs(finalVal))), 0));
}
String NumPad::getString()
{
    return str;
}