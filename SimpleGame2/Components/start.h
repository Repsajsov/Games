#pragma once

#include "raylib.h"
#include "../config.h"

class Start
{
public:
    Start(const char *text, int fontSize);
    void draw();
    Vector2 getPosition();

private:
    const char *text;
    const int fontSize;
    Vector2 position;
};