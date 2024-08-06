#pragma once

#include "state.h"
#include "../Components/start.h"
class MenuState : public State
{
public:
  MenuState();
  int update(Game &game) override;
  void draw(Game &game) override;

private:
  Start start;
};
