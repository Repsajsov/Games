#pragma once
#include "../ball.h"
#include "state.h"

class GameState : public State {
public:
  GameState();
  int update(Game &game) override;
  void draw(Game &game) override;

private:
  Ball ball;
  int score;
  int lives;
};
