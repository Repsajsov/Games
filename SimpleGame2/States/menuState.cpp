#include "menuState.h"

MenuState::MenuState() : start("Start", 20) {};

int MenuState::update(Game &game)
{
  if (IsKeyPressed(KEY_E))
  {
    return GAME;
  }
  return MENU;
}

void MenuState::draw(Game &game)
{
  DrawText("Menu", 100, 100, 20, BLACK);
  start.draw();
}
