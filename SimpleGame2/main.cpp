#include "States/state.h"
#include "States/menuState.h"
#include "States/gameState.h"
#include "States/endState.h"
#include "raylib.h"
#include "config.h"

class Game
{
public:
  Game() : currentStateIndex(MENU)
  {
    states[MENU] = new MenuState();
    states[GAME] = new GameState();
    states[END] = new EndState();
  };
  ~Game()
  {
    for (int i = 0; i < STATE_COUNT; i++)
    {
      delete states[i];
    }
  }
  void run()
  {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
    SetTargetFPS(FPS);

    int newStateIndex;
    while (!WindowShouldClose())
    {
      BeginDrawing();
      ClearBackground(RAYWHITE);
      newStateIndex = states[currentStateIndex]->update(*this);
      states[currentStateIndex]->draw(*this);

      if (newStateIndex != currentStateIndex)
      {
        currentStateIndex = newStateIndex;
      }
      EndDrawing();
    }
    CloseWindow();
  }
  void changeState(int newStateIndex)
  {
    if (newStateIndex >= 0 && newStateIndex < STATE_COUNT)
    {
      currentStateIndex = newStateIndex;
    }
  }

private:
  State *states[STATE_COUNT];
  int currentStateIndex;
};

int main()
{
  Game game;
  game.run();
  return 0;
}
