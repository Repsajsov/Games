#include "game.h"
#include "gameplayState.h"
#include "menuState.h"
#include "raylib.h"
#include "state.h"
#include "stateID.h"

Game::Game()
    : currentState(nullptr), menuState(nullptr), gameplayState(nullptr) {}

Game::~Game() {
  delete menuState;
  delete gameplayState;
}

void Game::changeState(StateID newStateID) {
  switch (newStateID) {
  case StateID::Menu:
    if (!menuState) {
      menuState = new MenuState();
    }
    currentState = menuState;
    break;
  case StateID::Gameplay:
    if (!gameplayState) {
      gameplayState = new GameplayState();
    }
    currentState = gameplayState;
    break;
  }
}

void Game::resetState(StateID newStateID) {
  switch (newStateID) {
  case StateID::Menu:
    delete menuState;
    menuState = new MenuState();
    break;
  case StateID::Gameplay:
    delete gameplayState;
    gameplayState = new GameplayState();
    break;
  }
}

void Game::run() {
  InitWindow(800, 450, "States");
  SetTargetFPS(60);
  while (!WindowShouldClose()) {
    if (currentState) {
      currentState->Update(*this);
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if (currentState) {
      currentState->Draw(*this);
    }
    EndDrawing();
  }
  CloseWindow();
}
