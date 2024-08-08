#pragma once

#include "raylib.h"
#include "../config.h"

class Button
{
public:
    Button(float x, float y, float width, float height, const char *text, const int fontSize, Color buttonColor, Color textColor, Color hoverColor);
    void draw();
    bool isMouseOver();
    bool isClicked();

private:
    Rectangle rect;
    const char *text;
    const int fontSize;
    Color buttonColor;
    Color textColor;
    Color hoverColor;
};