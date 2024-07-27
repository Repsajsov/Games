#pragma once

class Game;

class State {
public:
  virtual void Update(Game &game) = 0;
  virtual void Draw(Game &game) = 0;
  virtual ~State() = default;
};
