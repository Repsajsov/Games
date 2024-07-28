#pragma once
#include "state.h"

class MenuState : public State {
public:
  std::unique_ptr<State> update(Game &game) override;
  std::unique_ptr<State> draw(Game &game) override;
};
