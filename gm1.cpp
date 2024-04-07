// Game.cpp
#include "gm1.h"
using namespace std;

void Game::startGame() {
    cout << "按任意键开始...\n";
    x = getch();
    start(x);
    if(flag) {
        initialize();
        draw();
        thread inputThread(&Game::userInput, this);
        gameLoop();
        inputThread.join();
    }
}

void Game::initialize() {
    srand(time(0));
    grid = vector<vector<char>>(HEIGHT, vector<char>(WIDTH, ' '));
    playerX = 2;
    playerY = 2;
    gameOver = false;
    flag = false;

    grid[playerY][playerX] = 'P';

    for(int i = 0; i < WIDTH; ++i) grid[HEIGHT-1][i] = 'S';
    for(int i = 0; i < 35; ++i) grid[rand() % HEIGHT][rand() % WIDTH] = 'T';
}

void Game::draw() {
    system("cls");
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

void Game::movePlayer(char direction) {
    grid[playerY][playerX] = ' ';
    if(direction == 'w' && playerY > 0) playerY--;
    else if(direction == 's' && playerY < HEIGHT - 1) playerY++;
    else if(direction == 'a' && playerX > 0) playerX--;
    else if(direction == 'd' && playerX < WIDTH - 1) playerX++;

    if(grid[playerY][playerX] == 'T' || grid[playerY][playerX] == 'B') {
        gameOver = true;
        cout << "你死在了生还者营地之前...但是,前面是真的乌托邦吗..." << endl;
        system("pause");
    } else if(grid[playerY][playerX] == 'S') {
        gameOver = true;
        cout << "你成功到达了生还者营地...但在这里,是活下去还是另一种死亡?" << endl;
        system("pause");
    } else {
        grid[playerY][playerX] = 'P';
    }
}

void Game::updateBullets() {
    for (int i = HEIGHT-2; i >= 0; --i) {
        for (int j = 0; j < WIDTH; ++j) {
            if(grid[i][j] == 'B') {
                grid[i][j] = ' ';
                if(i+1 < HEIGHT) 
                {
                    if(grid[i+1][j] =='P')
                    {
                        gameOver = true;
                        cout << "你死在了生还者营地之前...但是,前面是真的乌托邦吗..." << endl;
                        system("pause");
                    }
                    grid[i+1][j] = 'B';
                }

            }
        }
    }

    
    if(rand() % 4 == 0) { 
        grid[0][rand() % WIDTH] = 'B';
    }// Implementation of updateBullets function
}

void Game::userInput() {
    char move;
    while (!gameOver) {
        move = getch();
        movePlayer(move);
    }// Implementation of userInput function
}

void Game::gameLoop() {
    while (!gameOver) {
        updateBullets();
        draw();
        this_thread::sleep_for(chrono::milliseconds(0)); 
    }// Implementation of gameLoop function
}
void Game::start(char a){
    cout<<"####          第一个关卡:逃向生还者营地          ####\n";
    cout<<"####                按wasd移动                  ####\n";
    cout<<"#### 你是人类P,如果碰到飞动的子弹B或陷阱T,游戏失败####\n";
    cout<<"####            逃至生还者营地B获得胜利          ####\n";
    cout<<"####          生存还是死亡?这是一个问题...       ####\n";
    Sleep(2000);
    system("cls");
   
}