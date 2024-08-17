#include "raylib.h"
#include <unordered_map>
#include <string>
#include "assets.h"

constexpr int SCREEN_WIDTH = 550;
constexpr int SCREEN_HEIGHT = 550;

class State
{
public:
    virtual ~State() = default;
    virtual void update(double deltaTime) = 0;
    virtual void draw() = 0;
};

class GameState : public State
{
public:
    GameState() : snake{250, 250, 50, 50}, apple{(float)GetRandomValue(0, 10) * 50, (float)GetRandomValue(0, 10) * 50, 50, 50}
    {
    }
    ~GameState() override {};
    void update(double deltaTime) override
    {
        snake.update(deltaTime);
        if (CheckCollisionRecs(snake.getRect(), apple.getRect()))
        {
            apple.spawn();
            snake.add();
        }
        if ((snake.getRect().x >= SCREEN_WIDTH || snake.getRect().y >= SCREEN_HEIGHT) || (snake.getRect().x < 0 || snake.getRect().y < 0))
        {
            DrawText("GAMEOVER", 250, 250, 20, RED);
        }
    }
    void draw() override
    {
        snake.draw();
        apple.draw();
    }

private:
    Snake snake;
    Apple apple;
};

class Game
{
public:
    Game() : state{new GameState}
    {
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SimpleGame3");
        SetConfigFlags(FLAG_VSYNC_HINT);
    }

    void run()
    {
        while (!WindowShouldClose())
        {
            double deltaTime = GetFrameTime();
            state->update(deltaTime);
            BeginDrawing();
            ClearBackground(RAYWHITE);
            state->draw();
            EndDrawing();
        }
        delete state;
        CloseWindow();
    }

private:
    State *state;
};

int main()
{
    Game game{};
    game.run();

    return 0;
}
