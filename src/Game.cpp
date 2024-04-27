#include "Game.h"
#include <ncurses.h>
//#include <unistd.h> //It provides functions related to process control, I/O handling, file manipulation, and other system-level operations

Game::Game(const int w, const int h, const int& nf)
    : width(w), height(h), snake(width / 2, height / 2), numFruits(nf), score(0), gameOver(false) {
        for (int i = 0; i < numFruits; i++) {
            Fruit newFruit(width, height);
            newFruit.respawn();
            fruits.push_back(newFruit);
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

void Game::createFruits(int numFruits) {
    //fruits.clear();
    for (int i = 0; i < numFruits; i++) {
        Fruit newFruit(width, height);
        do {
            newFruit.respawn();
        } while (newFruit.getX() == snake.getX() && newFruit.getY() == snake.getY());
        fruits.push_back(newFruit);
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

            if (i == snake.getY() && j == snake.getX()) 
                snake.draw();
            else {
                bool fruitDrawn = false;
                for (const Fruit& fruit : fruits) {
                    if (i == fruit.getY() && j == fruit.getX()) {
                        fruit.draw();
                        fruitDrawn = true;
                        break;
                    }
                }
                if (!fruitDrawn) {
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
            snake.moveLeft();
            break;
        case RIGHT:
            snake.moveRight();
            break;
        case UP:
            snake.moveUp();
            break;
        case DOWN:
            snake.moveDown();
            break;
        default:
            break;
    }

    if (snake.getX() >= width || snake.getX() < 0 || snake.getY() >= height || snake.getY() < 0)
        gameOver = true;

    // Check if the snake has eaten any fruits
    for (auto it = fruits.begin(); it != fruits.end();) {
        if (snake.getX() == it->getX() && snake.getY() == it->getY()) {
            score += 10;
            it = fruits.erase(it);
            // Optionally, add a new fruit here
            createFruits(1);
        } else {
            ++it;
        }
    }
}

bool Game::isGameOver() const { return gameOver; }

