#pragma once
#include "stateID.h"
#include <memory>

class State;
class MenuState;
class GameplayState;

class Game {
public:
  Game();
  ~Game();
  void changeState(StateID newStateID);
  void resetState(StateID newStateID);
  void run();

private:
  State *currentState;
  MenuState *menuState;
  GameplayState *gameplayState;
};
