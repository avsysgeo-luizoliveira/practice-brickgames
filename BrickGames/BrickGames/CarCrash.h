#pragma once
#include "Utils.h"

struct Cars
{
	int w = 3;
	int h = 3;
	int x = 0;
	int y = 0;
	char DesingChar = 'X';

	
	void Show(HANDLE hconsole, short x, short y) 
	{
		SetConsoleCurPos(hconsole, x + 1, y - w);
		std::cout << DesingChar;
		SetConsoleCurPos(hconsole, x, 1 + y - w );
		std::cout << DesingChar << DesingChar << DesingChar;
		SetConsoleCurPos(hconsole, x, 2 + y - w);
		std::cout << DesingChar << " " << DesingChar;
	}

};



class CarCrash
{
protected:
	HANDLE hC;
	Cars Player;

public:

	CarCrash(HANDLE hConsole) {
		hC = hConsole;
		show();
	}

	void show();

private:
	std::vector<char> Controller = { 'A', 'D' };
	bool SceneRunning = true;
	COORD PlayerPosition{ 7, 10 };
	char PlayerInput = 0x0;

};

