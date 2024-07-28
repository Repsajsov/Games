#include "States/menuState.h"
#include "States/state.h"
#include <raylib.h>

int SCREENWIDTH = 800;
int SCREENHEIGHT = 450;
int FPS = 60;
char GAMENAME[] = "SimpleGame2";

class Game {
public:
  Game() : currentState(std::make_unique<MenuState>()) {}
  void run() {
    InitWindow(SCREENWIDTH, SCREENHEIGHT, GAMENAME);
    SetTargetFPS(FPS);

    while (!WindowShouldClose()) {
      std::unique_ptr<State> newState = currentState->update(*this);
    }
  }

private:
  std::unique_ptr<State> currentState;
};
