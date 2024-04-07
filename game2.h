

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

void SetColor(UINT uFore,UINT uBack);

void SetTitle(LPCWSTR lpTitle) ;
void HideConsoleCursor() ;

void printStr(string& text, int startX, int startY);


void printText(string text, int sleep);

void game2();

