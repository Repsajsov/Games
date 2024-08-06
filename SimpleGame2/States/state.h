#pragma once
#include "raylib.h"
#include <memory>
#include "../config.h"

enum StateType
{
  MENU,
  GAME,
  END
};

class Game;

class State
{
public:
  virtual ~State() = default;
  virtual int update(Game &game) = 0;
  virtual void draw(Game &game) = 0;
};
