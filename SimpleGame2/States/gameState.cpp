#include "gameState.h"

int GameState::update(Game &game) {
  if (IsKeyPressed(KEY_Q)) {
    return MENU;
  } else if (IsKeyPressed(KEY_E)) {
    return END;
  }
  return GAME;
}

void GameState::draw(Game &game) { DrawText("Game", 100, 100, 20, BLACK); }
