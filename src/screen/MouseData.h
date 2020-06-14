#ifndef MOUSE_DATA_STRUCT_H
#define MOUSE_DATA_STRUCT_H

#include <Arduino.h>

struct MouseData
{
  float mouseX;
  float mouseY;
  float lastMouseX;
  float lastMouseY;
  float mouseXDown;
  float mouseYDown;
  float mouseXUp;
  float mouseYUp;
  elapsedMillis millisSinceMouseDown;
  boolean mousePressed;
  boolean lastMousePressed;
  boolean mouseDown;
  boolean mouseUp;
  elapsedMillis millisSinceMouseUp;
  elapsedMillis millisSinceRawMouseDown;
  boolean lastMouseRawPressed;
  boolean mouseRawPressed;
  elapsedMillis millisSinceRawMouseUp;
};
#endif
