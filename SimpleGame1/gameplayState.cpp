#include "gameplayState.h"
#include "game.h"

Game game;

GameplayState::GameplayState()
    : player{}, food{}, score{0}, lives{3},
      scoreText{"Score: " + std::to_string(score)},
      livesText{"Lives: " + std::to_string(lives)} {}

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
