#include "Snake.h"


void Snake::Show()
{
	bool OldPos[4] = { false, false, false, false };
	playerPos = { drawnX / 2, drawnY / 2 };
	FrutPos.x = RandomNumber(1, drawnX - 1);
	FrutPos.y = RandomNumber(1, drawnY - 1);

	while (true)
	{
		Clear(hC);

		SetConsoleColor(hC, 0x5);
		bool anyKey = false;

		std::cout << "-------------------------------";
		for (size_t y = 0; y < drawnY; y++) {
			SetConsoleCurPos(hC, 0, y);
			std::wcout << "|";
			SetConsoleCurPos(hC, drawnX, y);
			std::wcout << "|";
		}
		SetConsoleCurPos(hC, 0, drawnY);
		std::cout << "-------------------------------";



		for (size_t i = 0; i < 4; i++)
		{
			if (GetAsyncKeyState(Keys[i]) != 0) 
			{
				anyKey = true;
				SnakeTail.positions[i] = true;
			}
			else
				SnakeTail.positions[i] = false;
		}

		if (!anyKey) 
		{
			for (size_t i = 0; i < 4; i++)
			{
				SnakeTail.positions[i] = GetAsyncKeyState(KeysAlt[i]);
				if (SnakeTail.positions[i])
					anyKey = true;

			}
		}

		if (anyKey)
			memcpy_s(OldPos, 4, SnakeTail.positions, 4);
		

		if (OldPos[0]) //Up
			--playerPos.y;
		if (OldPos[1]) //Down
			++playerPos.y;
		if (OldPos[2]) //Esquerda
			++playerPos.x;
		if (OldPos[3]) //Direita
			--playerPos.x;

		// Para desenhar a calda a posição atual é a da cabeça num tempo atraz
		SetConsoleCurPos(hC, playerPos.x, playerPos.y);
		SetConsoleColor(hC, 0xF);
		std::cout << "*";

		if (SnakeTail.tam)
		{
			SnakeTail.Old = SnakeTail.pos[0];
			SnakeTail.pos[0] = playerPos;

			for (int i = 1; i < SnakeTail.tam; i++)
			{
				if( i % 2 == 0)
					SetConsoleColor(hC, 0xE);
				else
					SetConsoleColor(hC, 0xA);

				SetConsoleCurPos(hC, SnakeTail.Old.x, SnakeTail.Old.y);
				std::cout << '#';

				SnakeTail.Pos = SnakeTail.pos[i];
				SnakeTail.pos[i] = SnakeTail.Old;
				SnakeTail.Old = SnakeTail.Pos;
			}
		}
		

		//Top
		if (playerPos.y <=  0)
			playerPos.y = drawnY;
		if (playerPos.x <= 0)
			playerPos.x = drawnX;

		//Bottom
		if (playerPos.y > drawnY)
			playerPos.y = 0;
		if (playerPos.x > drawnX)
			playerPos.x = 0;

		frute(playerPos);

		SetConsoleColor(hC, 0x3);
		SetConsoleCurPos(hC, 0, drawnY+1);
		std::cout << "POINTS: " << Score << std::endl
				  << "Tails: " << SnakeTail.tam << std::endl;



		Sleep(66);
		SetConsoleColor(hC, 0xF);
	}

}

void Snake::frute(POINT player)
{
	SetConsoleCurPos(hC, FrutPos.x, FrutPos.y);

	SetConsoleColor(hC, 0xC);
	std::cout << 'o';


	if (player.x == FrutPos.x and player.y == FrutPos.y)
	{
		FrutPos.x = RandomNumber(1, drawnX - 1);
		FrutPos.y = RandomNumber(1, drawnY - 1);

		Score += 5;
		SnakeTail.tam++;

		POINT Pos = { 0,0 };
		SnakeTail.pos.push_back(Pos);

	}
	std::cout.flush();
}
