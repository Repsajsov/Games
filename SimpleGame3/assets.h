#pragma once
#include "raylib.h"
#include <unordered_map>
#include <string>
#include <vector>

class Apple
{
public:
    Apple(float x, float y, float width, float height);
    Rectangle getRect();
    void spawn();
    void draw();

private:
    Rectangle rect;
};

class Snake
{
public:
    Snake(float x, float y, float width, float height);
    Rectangle getRect();
    Color getColor();
    void inputHandling();
    void update(double deltaTime);
    void draw();
    void add();

private:
    std::vector<Rectangle> rects;
    std::unordered_map<std::string, Vector2> directionMap;
    Vector2 direction;
    double elapsedTime;
    Color color;
};
