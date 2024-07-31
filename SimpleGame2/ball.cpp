#include "ball.h"
#include <raylib.h>
#include "Utilities/random_generator.h"
#include <iostream>
#include "config.h"

Ball::Ball() : rect{100, 100, 50, 50}, 
  speed{10}, 
  dx{RandomGenerator::randomFloat(-1, 1)}, 
  dy{(float)sqrt(1 - pow(dx, 2))}  {};
     
void Ball::update() {
 rect.x += dx * speed;
 rect.y += dy * speed;
 std::cout << dx << " " << dy << std::endl;

 if(rect.x >= SCREEN_WIDTH || rect.x <= 0) {
   dx *= -1;
 };
 
 if(rect.y >= SCREEN_HEIGHT || rect.y <= 0) {
   dy *= -1;
 };

};



void Ball::draw() {
  DrawCircle(rect.x, rect.y, 20, BLACK);
}
