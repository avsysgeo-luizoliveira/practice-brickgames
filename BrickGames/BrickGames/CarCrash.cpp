#include "CarCrash.h"



void CarCrash::show()
{



	while (true) 
	{
		Clear(hC);

		// Criar cenario
		
		for (int i = 0; i < 11; i++) {

			if (SceneRunning)
				std::cout << "|\t\t|" << std::endl;
			else
				std::cout << "\t\t\t" << std::endl;

			SceneRunning = !SceneRunning;
		}

		// Cabe 4 carros
		//std::cout << "  XXXYYYZZZAAA  "; // considerando

		// Movimentação do player
		Player.Show(hC, PlayerPosition.X , PlayerPosition.Y);

		// API DO WINDOWS MAS SE ENCONTRAR UMA MELHOR PARA INPUT MELHOR AINDA.
		if (GetAsyncKeyState(Controller[0]) != 0)
			PlayerPosition.X--;
		if (GetAsyncKeyState(Controller[1]) != 0)
			PlayerPosition.X++;


		Sleep(66); // 15 fps
	}
}
