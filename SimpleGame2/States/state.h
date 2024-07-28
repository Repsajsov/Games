#pragma once
#include "raylib.h"
#include <memory>

class Game;

class State {
public:
  virtual ~State() = default;
  virtual std::unique_ptr<State> update(Game &game) = 0;
  virtual std::unique_ptr<State> draw(Game &game) = 0;
};
