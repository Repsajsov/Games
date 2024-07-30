#include "States/endState.h"
#include "States/gameState.h"
#include "States/menuState.h"
#include "States/state.h"
#include <raylib.h>

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 450;
int FPS = 60;
char GAME_NAME[] = "SimpleGame2";
const int STATE_COUNT = 3;

class Game {
public:
  Game() : currentStateIndex(MENU) {
    states[MENU] = new MenuState();
    states[GAME] = new GameState();
    states[END] = new EndState();
  };

  ~Game() {
    for (int i = 0; i < STATE_COUNT; i++) {
      delete states[i];
    }
  }
  void run() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    SetTargetFPS(FPS);

    int newStateIndex;
    while (!WindowShouldClose()) {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      newStateIndex = states[currentStateIndex]->update(*this);
      states[currentStateIndex]->draw(*this);

      if (newStateIndex != currentStateIndex) {
        currentStateIndex = newStateIndex;
      }
      EndDrawing();
    }
    CloseWindow();
  }
  void changeState(int newStateIndex) {
    if (newStateIndex >= 0 && newStateIndex < STATE_COUNT) {
      currentStateIndex = newStateIndex;
    }
  }

private:
  State *states[STATE_COUNT];
  int currentStateIndex;
};

int main() {
  Game game;
  game.run();
  return 0;
}
