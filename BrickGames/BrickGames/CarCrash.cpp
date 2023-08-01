#include "CarCrash.h"



void CarCrash::show()
{
	GameStating = true;
	while (GameStating)
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
		if (GetAsyncKeyState(Controller[0]) != 0) {
			PlayerPosition.X--;
			if (PlayerPosition.X == 1) { GameStating = false; CarCrash::GameHover(); }
		}
		if (GetAsyncKeyState(Controller[1]) != 0) {
			PlayerPosition.X++;
			if (PlayerPosition.X == 13) { GameStating = false; CarCrash::GameHover(); }
		}
		Sleep(33); // 15 fps
	}
}

void CarCrash::GameHover() {
	while (true) {
		Clear(hC);
		std::cout << "GAMER HOVER \nTOTAL DE PONTOS: " << PlayerPoints ;
		Sleep(33); // 15 fps
	}
}
