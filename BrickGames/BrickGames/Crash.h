#pragma once
#include "Utils.h"

class Crash
{
protected:
	int randomMax = 99;
	int Min = 0;
	float scale = 0.0;
	float multiplayer = 0;
	float IndiceCrash = 0;
	float MyIndiceCrash = 0;
	bool crash = false;
	bool stop = false;
	float points = 200;
	float bet;

	HANDLE hC;
public:
	void show();
	Crash(HANDLE HandleConsole)
	{
		hC = HandleConsole;
		show();
	};

	void newBet();

private:
	int w = 10, h = 10;
	float randoMax = 0;
	
	float GenRandom();


};

