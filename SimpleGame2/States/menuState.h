#pragma once
#include "state.h"

class MenuState : public State {
public:
  int update(Game &game) override;
  void draw(Game &game) override;
};
