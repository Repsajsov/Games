#pragma once
#include "state.h"

class GameState : public State {
public:
  int update(Game &game) override;
  void draw(Game &game) override;
};
