#include "start.h"

Start::Start(const char *text, int fontSize) : text(text), fontSize(fontSize), position(getPosition()) {};

void Start::draw()
{
    DrawRectangle(position.x, position.y, 100, 100, BLUE);
    DrawText(text, position.x, position.y, fontSize, BLACK);
};

Vector2 Start::getPosition()
{
    int size = MeasureText(text, fontSize);
    Vector2 position = {
        (float)(SCREEN_WIDTH - size) / 2,
        (float)(SCREEN_HEIGHT - size) / 2};
    return position;
};