#include "Game.h"
#include <ncurses.h>
//#include <unistd.h> //It provides functions related to process control, I/O handling, file manipulation, and other system-level operations

Game::Game(const int w, const int h, const int& nf, const int& nm)
    : width(w), height(h), pakuman(width / 2, height / 2), numBeans(nf), numMonsters(nm), score(0), gameOver(false) {
        for (int i = 0; i < numBeans; i++) {
            Bean* newBean = new Bean(width, height);
            newBean->respawn();
            drawables.push_back(newBean);
        }
        for (int i = 0; i < numMonsters; i++) {
            Monster* newMonster = new Monster(width, height);
            newMonster->showoff();
            drawables.push_back(newMonster);
        }
}

void Game::Setup() {
    initscr(); // Initialize ncurses
    clear(); // Clear the screen
    noecho(); // Disable automatic echoing of typed characters
    cbreak(); // Line buffering disabled. Input characters are available to the program without waiting for Enter to be pressed.
    curs_set(0); // Hide cursor

    dir = STOP;
}

void Game::createBeans(int numBeans) {
    //beans.clear();
    for (int i = 0; i < numBeans; i++) {
        Bean* newBean = new Bean(width, height);
        do {
            newBean->respawn();
        } while (newBean->getX() == pakuman.getX() && newBean->getY() == pakuman.getY());
        drawables.push_back(newBean);
    }
}

void Game::Draw() {
    clear(); // Clear the screen

    // Draw the top boundary
    for (int i = 0; i < width + 2; i++)
        printw("#");
    printw("\n");

    // Draw the side boundary and pakutaberu and dots
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Draw the left boundary
            if (j == 0)
                printw("#");

            if (i == pakuman.getY() && j == pakuman.getX()) 
                pakuman.draw();
            else {
                bool Drawn = false;
                for (abstractDraw* drawable : drawables) {
                    if (i == drawable->getY() && j == drawable->getX()) {
                        drawable->draw();
                        Drawn = true;
                        break;
                    }
                }
                if (!Drawn) {
                    printw(" ");
                }
            }

            // Draw the right boundary
            if (j == width - 1)
                printw("#");
        }
        printw("\n");
    }

    // Draw the bottom boundary
    for (int i = 0; i < width + 2; i++)
        printw("#");
    printw("\n");

    // Show score
    printw("Score: %d\n", score);
    refresh(); // Refresh the screen
}

void Game::Input() {
    timeout(100); // Set a timeout for getch to prevent blocking
    int ch = getch();
    switch (ch) {
        case 'a': 
            dir = LEFT;
            break;
        case 'd': 
            dir = RIGHT;
            break;
        case 'w': 
            dir = UP;
            break;
        case 's': 
            dir = DOWN;
            break;
        case 'x': 
            gameOver = true;
            break;
        case 'p':
            dir = STOP;
            break;
    }
}

void Game::Logic() {
    switch (dir) {
        case LEFT:
            pakuman.moveLeft();
            break;
        case RIGHT:
            pakuman.moveRight();
            break;
        case UP:
            pakuman.moveUp();
            break;
        case DOWN:
            pakuman.moveDown();
            break;
        default:
            break;
    }

    if (pakuman.getX() >= width || pakuman.getX() < 0 || pakuman.getY() >= height || pakuman.getY() < 0) {
        printw("Run into a brick wall.\n");
        gameOver = true;
    }
    

    // Check if the pakuman has eaten any beans
    for (std::vector<abstractDraw*>::iterator it = drawables.begin(); it != drawables.end(); it++) {
        // check if the drawable object is of type Bean or Monster by using dynamic_cast
        Bean* bean = dynamic_cast<Bean*>(*it);
        Monster* monster = dynamic_cast<Monster*>(*it);
        if (bean != nullptr) {
            if (pakuman.getX() == bean->getX() && pakuman.getY() == bean->getY()) {
                score += 10;
                it = drawables.erase(it);
                // Create a new bean here after one is eaten
                createBeans(1);
            } 
        }
        // monster movement, and gameover if pakuman touches any monster
        else if (monster != nullptr) {
            monster->move();
            if (pakuman.getX() == monster->getX() && pakuman.getY() == monster->getY()) {
                printw("You have been slain by a monster.\n");
                gameOver = true;
            } 
        }
    }
}

bool Game::isGameOver() const { return gameOver; }

int Game::getScore() { return score; }


Game::~Game() {
    for (abstractDraw* drawable : drawables) {
        delete drawable; // Delete each Drawable object
    }
    drawables.clear(); // Clear the vector to remove all pointers
}