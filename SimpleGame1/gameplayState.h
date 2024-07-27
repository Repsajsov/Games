#pragma once

#include "food.h"
#include "player.h"
#include "state.h"
#include "stateID.h"
#include <string>

class Game;

class GameplayState : public State {
public:
  GameplayState();
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
