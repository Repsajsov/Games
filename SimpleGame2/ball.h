#pragma once
#include "raylib.h"
#include "config.h"
#include "Utilities/random_generator.h"
#include <iostream>

class Ball
{
public:
  Ball();
  void update();
  void draw();
  void changeDirection();

private:
  Rectangle rect;
  float speed;
  float dx;
  float dy;
};
