// Game.h
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <windows.h>
#include <conio.h>
class Game {
public:
    void startGame();
    void initialize();
    void draw();
    void movePlayer(char direction);
    void updateBullets();
    void userInput();
    void gameLoop();
    void start(char a);

private:
    const int WIDTH = 30;
    const int HEIGHT = 30;
    std::vector<std::vector<char>> grid;
    int playerX;
    int playerY;
    bool flag;
    bool gameOver;
    char x;
};

#endif
