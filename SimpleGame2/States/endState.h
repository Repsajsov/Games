#include "state.h"

class EndState : public State {
public:
  int update(Game &game) override;
  void draw(Game &game) override;
};
