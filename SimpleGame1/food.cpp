#include "food.h"
#include "raylib.h"

Food::Food() : rect{1000, 225, 20, 20}, speed{5.0f} {}

void Food::Update() { rect.x -= speed; }

void Food::Draw() { DrawRectangleRec(rect, RED); }

void Food::reset() {
  rect.x = 1000;
  rect.y = GetRandomValue(50, 400);
  speed += 1;
}

Rectangle Food::getRect() { return rect; }
