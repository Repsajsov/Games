#include "player.h"
#include "raymath.h"
#include <raylib.h>

Player::Player() : rect{100, 225, 30, 30}, speed{10.0f} {}

void Player::Update() {
  Vector2 mousePosition = GetMousePosition();
  rect.y = mousePosition.y - rect.height / 2;
  rect.y = Clamp(rect.y, 0, 450 - rect.height);
}

void Player::Draw() { DrawRectangleRec(rect, BEIGE); }

Rectangle Player::getRect() { return rect; }
