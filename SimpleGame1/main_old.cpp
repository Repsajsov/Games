#include "raylib.h"
#include <string>

class Game;
class MenuState;
class GameplayState;

class State {
public:
  virtual void Update(Game &game) = 0;
  virtual void Draw(Game &game) = 0;
  virtual ~State() = default;
};

enum class StateID { Menu, Gameplay };

class Player {
public:
  Player() : rect{100, 225, 30, 30}, speed{10.0f} {}
  Rectangle getRect() { return rect; }
  void Update() {
    if (IsKeyDown(KEY_K)) {
      rect.y -= speed;
    } else if (IsKeyDown(KEY_J)) {
      rect.y += speed;
    }
  }

  void Draw() { DrawRectangleRec(rect, BEIGE); }

private:
  Rectangle rect;
  float speed;
};

class Food {
public:
  Food() : rect{1000, 225, 20, 20}, speed{5.0f} {}
  Rectangle getRect() { return rect; }
  void Update() { rect.x -= speed; }
  void Draw() { DrawRectangleRec(rect, RED); }
  void reset() {
    rect.x = 1000;
    rect.y = GetRandomValue(50, 400);
    speed += 1;
  }

private:
  Rectangle rect;
  float speed;
};
class MenuState : public State {
public:
  void Update(Game &game) override;
  void Draw(Game &game) override;
};

class GameplayState : public State {
public:
  GameplayState()
      : player{}, food{}, score{0}, lives{3},
        scoreText{"Score: " + std::to_string(score)},
        livesText{"Lives: " + std::to_string(lives)} {}
  void Update(Game &game) override;
  void Draw(Game &game) override;

private:
  Player player;
  Food food;
  int score;
  int lives;
  std::string scoreText;
  std::string livesText;
};

class Game {
public:
  Game() : currentState(nullptr), menuState(nullptr), gameplayState(nullptr) {}

  ~Game() {
    delete menuState;
    delete gameplayState;
  }

  void changeState(StateID newStateID) {
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

  void resetState(StateID newStateID) {
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

  void run() {
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

private:
  State *currentState;
  MenuState *menuState;
  GameplayState *gameplayState;
};

void MenuState::Update(Game &game) {
  if (IsKeyPressed(KEY_E)) {
    game.changeState(StateID::Gameplay);
  }
}

void MenuState::Draw(Game &game) { DrawText("Menu State", 10, 10, 20, BLACK); }

void GameplayState::Update(Game &game) {
  if (IsKeyPressed(KEY_Q)) {
    game.changeState(StateID::Menu);
  }
  player.Update();
  food.Update();
  if (CheckCollisionRecs(player.getRect(), food.getRect())) {
    food.reset();
    score += 1;
    scoreText = "Score: " + std::to_string(score);
  } else if (food.getRect().x < 0) {
    food.reset();
    if (lives > 0) {
      lives -= 1;

    } else {
      game.changeState(StateID::Menu);
      game.resetState(StateID::Gameplay);
    }
    livesText = "Lives: " + std::to_string(lives);
  }
}

void GameplayState::Draw(Game &game) {
  DrawText("Gameplay State", 10, 10, 20, BLACK);
  DrawText(scoreText.c_str(), 700, 10, 20, BLACK);
  DrawText(livesText.c_str(), 350, 10, 20, BLACK);
  player.Draw();
  food.Draw();
}

int main() {
  Game game;
  game.changeState(StateID::Menu);
  game.run();
  return 0;
};
