#pragma once
#include "raylib.h"

class Ball {
  public:
    Ball();
    void update(); 
    void draw();
  private:
    Rectangle rect;
    float speed;
    float dx;
    float dy;
};
