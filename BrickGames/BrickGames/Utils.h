#pragma once
#include "head.h"

void Clear(HANDLE hConsole);
void SetConsoleCurPos(HANDLE hConsole, short x, short y);
void SetConsoleColor(HANDLE hConsole, short colour);
int RandomNumber(int min, int max);