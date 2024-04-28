#ifndef GAME_H
#define GAME_H
#include <vector>
#include "abstractDraw.h"
#include "Pakuman.h"
#include "Bean.h"
#include "Monster.h"


class Game {
private:
    const int width, height;
    Pakuman pakuman;
    const int& numBeans;
    const int& numMonsters;
    std::vector<abstractDraw*> drawables;
    int score;
    bool gameOver;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;

    // Define constants for directions
    const char LEFT_KEY = 'a';
    const char RIGHT_KEY = 'd';
    const char UP_KEY = 'w';
    const char DOWN_KEY = 's';
    const char EXIT_KEY = 'x';
    const char PAUSE_KEY = 'p';

public:
    Game(const int width, const int height, const int& numBeans, const int& numMonsters);
    void Setup();
    void Draw();
    void Input();
    void Logic();
    int getScore();
    bool isGameOver() const;
    void createBeans(int numBeans);
    ~Game();
};

#endif

