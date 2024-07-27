#pragma once

#include "state.h"
#include "stateID.h"

class Game;
class MenuState : public State {
public:
  void Update(Game &game) override;
  void Draw(Game &game) override;
};
