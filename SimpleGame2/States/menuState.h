#pragma once

#include "state.h"
#include "../Components/button.h"

class MenuState : public State
{
public:
  MenuState();
  int update(Game &game) override;
  void draw(Game &game) override;

private:
  Button startButton;
  Button quitButton;
  Button highscoreButton;
};
