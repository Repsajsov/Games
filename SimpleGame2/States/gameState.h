#pragma once
#include "state.h"
#include "../ball.h"

class GameState : public State {
public:
  GameState();
  int update(Game &game) override;
  void draw(Game &game) override;
private:
  Ball ball;
};
