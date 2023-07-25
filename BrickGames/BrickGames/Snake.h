#pragma once
#include "Utils.h"

struct Tails
{
	POINT Old, Pos;
	bool  positions[4] = {};
	int   tam = 1;
	std::vector<POINT> pos = { {0,0} };


};

class Snake
{
protected:
	bool pass = false;
	bool PassTailSnake = false;

	POINT FrutPos{};
	POINT playerPos;
	Tails SnakeTail;
	int Score = 0;

	int drawnX = 30;
	int drawnY = 15;


	int Keys[5]{ VK_UP, VK_DOWN, VK_RIGHT, VK_LEFT };
	int KeysAlt[5]{ 'W', 'S', 'D' , 'A'};

	HANDLE hC;

public:
	Snake(HANDLE h)
	{
		hC = h;
		Show();

	}

	void Show();
	void frute(POINT player);
	void imortal(bool v)
	{
		pass = v;
	}


};


