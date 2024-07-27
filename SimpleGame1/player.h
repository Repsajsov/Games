#pragma once

#include "raylib.h"

class Player {
public:
  Player();
  Rectangle getRect();
  void Update();
  void Draw();

private:
  Rectangle rect;
  float speed;
};
