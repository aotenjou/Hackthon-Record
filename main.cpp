#include <Windows.h>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <windows.h>
#include <conio.h>
#include"mainPlot1.cpp"
#include"mainPlot2.cpp"
#include"mainPlot3.cpp"
#include"mainPlot4.cpp"
#include"mainPlot5.cpp"
#include"gm1.h"
#include"gm1.cpp"
#include"game2.h"
#include"game2.cpp"
#include"game3.cpp"
#include"game4.cpp"
using namespace std;
int main()
{
PlaySound(TEXT("song.wav"), NULL, SND_FILENAME | SND_ASYNC);


    system("color 0A");

    Plot1();
    Game game;
    game.startGame();
    system("cls");
    
    Plot2();
    system("cls");
    game2();
PlaySound(TEXT("song1.wav"), NULL, SND_FILENAME | SND_ASYNC);
    Plot3();
    system("cls");
    bool t = false;
    while(!t)
    {
        system("cls");
        point21 a;
	    t = a.game_start();
    }
PlaySound(TEXT("song2.wav"), NULL, SND_FILENAME | SND_ASYNC);
    Plot4();
    game_power gm4;
    gm4.start();
    system("cls");
    Plot5();
    
}