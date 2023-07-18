#include "Crash.h"

void WaitEnter()
{
	do{
		auto WaitInput = _getch();
		if (WaitInput == VK_RETURN) return;
		
	} while (true);
}


void Crash::show()
{
	newBet();

	while (true)
	{
		Clear(hC);


		if(!crash)
			IndiceCrash += 0.1f;

		if (!stop)
			MyIndiceCrash = IndiceCrash;

		if (IndiceCrash >= randoMax) crash = true;

		if (!stop && crash && points <= 0.0f) {
			std::cout << "Now you don't have points: " << points << std::endl;
			std::cout << "You lost" << std::endl;
			return;
		}


		float maxDraw = IndiceCrash;
		SetConsoleCurPos(hC, 0, 0);
		std::cout << ":----------: x" << multiplayer + 1;

		for (int i = 1; i < h; i++) {

			SetConsoleCurPos(hC, 0, i);
			std::cout << "|" << std::setw(w + 1) << "|";

			if (i == 5)
				std::cout << " x" << std::fixed << std::setprecision(1) << multiplayer + 0.5f;

		}

		if (IndiceCrash / 10 >= multiplayer + 1)
			multiplayer += 1;


		if (multiplayer > 0)
			maxDraw = IndiceCrash - (10 * multiplayer);


		for (float x = 0.0; x < maxDraw; x++)
		{
			SetConsoleCurPos(hC, x, h - x);
			std::cout << "/";
		}

		SetConsoleCurPos(hC, 0, h);
		std::cout << ":----------: x" << multiplayer << std::endl;
		std::cout << "BET: " << bet;

		if (crash)
		{
			SetConsoleCurPos(hC, 0, h / 2);
			std::cout << "|----------------|\n|  CRASH x" << std::fixed << std::setprecision(2) << randoMax / 9 << "   |\n|----------------|";

			if (stop)
			{
				float won = bet * (MyIndiceCrash / 9);
				std::cout << "\nYou won: " << won << std::endl;
				points += won;

			}
			else
			{
				std::cout << "\nYou lose your bet\n";
				points -= bet;
			}

			WaitEnter();
			Clear(hC);
		}



		if (!crash)
		{
			if (!stop)
			{
				std::cout << "  PRESS SPACE FOR RETIRE ";

				if (GetAsyncKeyState(VK_SPACE))
				{
					stop = true;
				}
			}
			else
			{
				std::cout << "\nYou Stoped in " << MyIndiceCrash;
			}

		}




		if (crash)
		{
			std::cout << " You have : " << points << "\nPress enter to Bet again\n";
			WaitEnter();
			newBet();
			Sleep(100);
		}

		std::this_thread::sleep_for(std::chrono::microseconds(100));

	}

}

void Crash::newBet()
{
	Clear(hC);
	multiplayer = 0;
	IndiceCrash = 0;
	MyIndiceCrash = 0;
	crash = false;
	stop = false;
	randoMax = GenRandom();
	std::cout << "Let the betting! you have: " << points << " points to bet, how much do you want to bet ?\n";
	std::cin >> bet;
	if (bet > points) {
		std::cout << "OOoooh Aooh ambitious but you don't have it all" << std::endl;
		Sleep(1000);
		newBet();
	}

}

float Crash::GenRandom()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	float min = Min;
	float max = randomMax;

	float media = 10.0; 
	float desvioPadrao = 5.0;

	std::normal_distribution<float> dis(media, desvioPadrao);

	// Gera o número aleatório
	float numeroAleatorio = dis(gen);


	while (numeroAleatorio < min || numeroAleatorio > max) {
		numeroAleatorio = dis(gen);
	}

	return numeroAleatorio;
}
