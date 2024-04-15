#ifndef GAME_H
#define GAME_H
#include "Snake.h"
#include "Fruit.h"


class Game {
private:
    const int width, height;
    Snake snake;
    Fruit fruit;
    int score;
    bool gameOver;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;
public:
    Game(const int width, const int height);
    void Setup();
    void Draw();
    void Input();
    void Logic();
    bool isGameOver() const;
};

#endif

