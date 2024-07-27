#include "menuState.h"
#include "game.h"
#include "raylib.h"

void MenuState::Update(Game &game) {
  if (IsKeyPressed(KEY_E)) {
    game.changeState(StateID::Gameplay);
  }
}

void MenuState::Draw(Game &game) {
  DrawText("Press E to play!",
           800 / 2 - MeasureText("Press E to play!", 40) / 2, 450 / 2 + 100, 40,
           BLACK);
}
