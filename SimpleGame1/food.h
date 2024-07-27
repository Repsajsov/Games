#pragma once

#include "raylib.h"

class Food {
public:
  Food();
  void Update();
  void Draw();
  Rectangle getRect();
  void reset();

private:
  Rectangle rect;
  float speed;
};
