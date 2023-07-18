#include "Teterianos.h"

void Teterianos::show()
{


	Clear(hC);

	int index = 0;
	listTetrominos.push_back(Generation());
	int drawNing = 0;
	int PX;
	int PY;

	while (true)
	{



		for (size_t y = 0; y < 20; y++)
		{
			PX = listTetrominos[index].x;
			PY = listTetrominos[index].y;
			for (size_t x = 0; x < 30; x++)
			{
				SetConsoleCurPos(hC, x, y);
				listTetrominos[index].Draw(x,y);
			
				std::cout << " ";

			

			}


			drawNing++;
		}

		//listTetrominos[index].y++;


		Sleep(100);
	}

}

Tretros Teterianos::Generation()
{

	int index = RandomNumber(0, 6);
	std::cout << index;
	Tretros NewOne;
	NewOne.screen = true;
	for (size_t i = 0; i < 16; i++)
	{
		NewOne.tetrominions[i] = tetrominos[index][i];
	}
	NewOne.x = 8;

	return NewOne;
}
