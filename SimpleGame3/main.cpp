#include "raylib.h"
#include <unordered_map>
#include <string>
#include "assets.h"
#include "config.h"

class State
{
public:
    virtual ~State() = default;
    virtual int update(double deltaTime) = 0;
    virtual void draw() = 0;
};

class EndState : public State
{
public:
    int update(double deltaTime) override { return END; }
    void draw() override {}
};
class GameState : public State
{
public:
    GameState() : snake{250, 250, 50, 50}, apple{(float)GetRandomValue(0, 10) * 50, (float)GetRandomValue(0, 10) * 50, 50, 50}
    {
    }
    ~GameState() override {};
    int update(double deltaTime) override
    {
        snake.update(deltaTime);
        if (CheckCollisionRecs(snake.getRect()[0], apple.getRect()))
        {
            apple.spawn();
            snake.add();
            score++;
        }
        else if ((snake.getRect()[0].x >= 550 || snake.getRect()[0].y >= 550) || (snake.getRect()[0].x < 0 || snake.getRect()[0].y < 0))
        {
            return END;
        }
        else
        {
            for (size_t i = 1; i < snake.getRect().size(); ++i)
            {
                if (snake.getRect()[0].x == snake.getRect()[i].x && snake.getRect()[0].y == snake.getRect()[i].y)
                {
                    return END;
                }
            }
        }
        return GAME;
    }

    void draw() override
    {
        snake.draw();
        apple.draw();
    }

private:
    Snake snake;
    Apple apple;
    int score;
};

class Game
{
public:
    Game() : currentStateIndex(GAME)
    {
        InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "SimpleGame3");
        SetConfigFlags(FLAG_VSYNC_HINT);
        states[GAME] = std::make_unique<GameState>();
        states[END] = std::make_unique<EndState>();
    }

    void run()
    {
        while (!WindowShouldClose())
        {
            double deltaTime = GetFrameTime();
            int newStateIndex = states[currentStateIndex]->update(deltaTime);

            BeginDrawing();
            ClearBackground(RAYWHITE);
            states[currentStateIndex]->draw();
            EndDrawing();

            if (newStateIndex != currentStateIndex)
            {
                currentStateIndex = newStateIndex;
            }
        }
        CloseWindow();
    }

private:
    std::unique_ptr<State> states[MAX_STATES];
    int currentStateIndex;
};

int main()
{
    Game game{};
    game.run();

    return 0;
}
