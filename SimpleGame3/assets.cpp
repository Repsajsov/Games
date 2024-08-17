#include "assets.h"

Apple::Apple(float x, float y, float width, float height) : rect{x, y, width, height} {}

Rectangle Apple::getRect() { return rect; }

void Apple::spawn()
{
    rect.x = GetRandomValue(0, 10) * 50;
    rect.y = GetRandomValue(0, 10) * 50;
}
void Apple::draw()
{
    DrawRectangleRec(rect, GREEN);
}

Snake::Snake(float x, float y, float width, float height) : rects{{x, y, width, height}}, color{RED}, elapsedTime{0}
{
    directionMap["LEFT"] = {-1, 0};
    directionMap["RIGHT"] = {1, 0};
    directionMap["UP"] = {0, -1};
    directionMap["DOWN"] = {0, 1};
}

Rectangle Snake::getRect() { return rects[0]; }

Color Snake::getColor() { return color; }

void Snake::inputHandling()
{
    if (IsKeyPressed(KEY_H) && (direction.x != 1))
    {
        direction = directionMap["LEFT"];
    }
    else if (IsKeyPressed(KEY_L) && (direction.x != -1))
    {
        direction = directionMap["RIGHT"];
    }
    else if (IsKeyPressed(KEY_K) && (direction.y != 1))
    {
        direction = directionMap["UP"];
    }
    else if (IsKeyPressed(KEY_J) && (direction.y != -1))
    {
        direction = directionMap["DOWN"];
    }
}

void Snake::add()
{
    // Rectangle temp = rects[rects.size()];
    // rects.push_back(temp);
}

void Snake::update(double deltaTime)
{
    inputHandling();
    elapsedTime += deltaTime;
    if (elapsedTime >= 0.25)
    {
        Rectangle temp;
        for (size_t i = rects.size() - 1; i > 0; --i)
        {
            temp = rects[i];
            rects[i + 1] = temp;
        }
        rects[0].x += direction.x * 50;
        rects[0].y += direction.y * 50;
        elapsedTime = 0;
    }
}

void Snake::draw()
{
    for (auto it = rects.begin(); it != rects.end(); ++it)
    {
        DrawRectangleRec(*it, color);
    }
}