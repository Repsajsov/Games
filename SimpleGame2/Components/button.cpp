#include "button.h"

Button::Button(float x, float y, float width, float height, const char *text, const int fontSize, Color buttonColor, Color textColor, Color hoverColor)
    : rect{x, y, width, height}, text{text}, fontSize{fontSize}, buttonColor{buttonColor}, textColor{textColor}, hoverColor{hoverColor} {}

void Button::draw()
{
    Color currentColor = isMouseOver() ? hoverColor : buttonColor;
    DrawRectangleRec(rect, currentColor);

    Vector2 textSize = MeasureTextEx(GetFontDefault(), text, fontSize, 1);
    Vector2 textPosition = {
        rect.x + (rect.width - textSize.x) / 2,
        rect.y + (rect.height - textSize.y) / 2};
    DrawTextEx(GetFontDefault(), text, textPosition, fontSize, 1, textColor);
}

bool Button::isMouseOver()
{
    return CheckCollisionPointRec(GetMousePosition(), rect);
}

bool Button::isClicked()
{
    return isMouseOver() && IsMouseButtonDown(MOUSE_BUTTON_LEFT);
}