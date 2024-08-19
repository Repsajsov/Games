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

Snake::Snake(float x, float y, float width, float height) : rects{{x, y, width, height}}, elapsedTime{0}, color{RED}, isAdded{false}
{
    directionMap["LEFT"] = {-1, 0};
    directionMap["RIGHT"] = {1, 0};
    directionMap["UP"] = {0, -1};
    directionMap["DOWN"] = {0, 1};
}

std::deque<Rectangle> Snake::getRect() { return rects; }

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
    isAdded = true;
}
void Snake::update(double deltaTime)
{
    inputHandling();
    elapsedTime += deltaTime;
    if (elapsedTime >= 0.25)
    {
        Rectangle newHead = {rects.front().x + (direction.x * 50), rects.front().y + (direction.y * 50), 50, 50};
        rects.push_front(newHead);
        if (!isAdded)
        {
            rects.pop_back();
        }
        isAdded = false;
        elapsedTime = 0;
    }
}

void Snake::draw()
{
    for (size_t i = 0; i < rects.size(); ++i)
    {
        DrawRectangleRec(rects[i], color);
    }
}
