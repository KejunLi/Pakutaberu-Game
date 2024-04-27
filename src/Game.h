#ifndef GAME_H
#define GAME_H
#include <vector>
#include "Snake.h"
#include "Fruit.h"


class Game {
private:
    const int width, height;
    Snake snake;
    std::vector<Fruit> fruits;
    const int& numFruits;
    int score;
    bool gameOver;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;
public:
    Game(const int width, const int height, const int& numFruits);
    void Setup();
    void Draw();
    void Input();
    void Logic();
    bool isGameOver() const;
    void createFruits(int numFruits);
};

#endif

