#include "ball.h"

Ball::Ball()
    : rect{100, 100, 40, 40}, speed{5}, dx{RandomGenerator::randomFloat(-1, 1)},
      dy{(float)sqrt(1 - pow(dx, 2))} {};

void Ball::update()
{
  rect.x += dx * speed;
  rect.y += dy * speed;
  std::cout << dx << " " << dy << std::endl;

  if (rect.x >= SCREEN_WIDTH - (2 * BALL_RADIUS) || rect.x <= 0)
  {
    dx *= -1;
  };

  if (rect.y >= SCREEN_HEIGHT - (2 * BALL_RADIUS) || rect.y <= 0)
  {
    dy *= -1;
  };

  Vector2 mousePosition = GetMousePosition();
  Vector2 centerCircle = {rect.x + BALL_RADIUS, rect.y + BALL_RADIUS};
  if (CheckCollisionPointCircle(mousePosition, centerCircle, BALL_RADIUS) &&
      IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  {
    changeDirection();
  }
  else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
  {
  }
};

void Ball::changeDirection()
{
  dx = RandomGenerator::randomFloat(-1, 1);
  dy = (float)sqrt(1 - pow(dx, 2));
}

void Ball::draw()
{
  DrawCircle(rect.x + BALL_RADIUS, rect.y + BALL_RADIUS, 20, BLACK);
  DrawRectangleLines(rect.x, rect.y, 40, 40, RED);
}
