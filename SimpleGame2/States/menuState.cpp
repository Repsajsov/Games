#include "menuState.h"

MenuState::MenuState() : startButton((SCREEN_WIDTH - 200) / 2, (SCREEN_HEIGHT - 100) / 2, 200, 100, "START", 20, BLUE, BLACK, DARKBLUE),
                         quitButton(50, 50, 75, 50, "QUIT", 16, BLUE, BLACK, DARKBLUE),
                         highscoreButton((SCREEN_WIDTH - (50 + 75)), 50, 75, 50, "HIGHSCORES", 16, BLUE, BLACK, DARKBLUE) {};

int MenuState::update(Game &game)
{
  if (startButton.isClicked())
  {
    return GAME;
  }
  if (quitButton.isClicked())
  {
    return;
  }

  if (IsKeyPressed(KEY_E))
  {
    return GAME;
  }
  return MENU;
}

void MenuState::draw(Game &game)
{
  startButton.draw();
  quitButton.draw();
  highscoreButton.draw();
}
