#include "endState.h"

int EndState::update(Game &game) {
  if (IsKeyPressed(KEY_E)) {
    return MENU;
  }
  return END;
}

void EndState::draw(Game &game) { DrawText("End", 100, 100, 20, BLACK); }
