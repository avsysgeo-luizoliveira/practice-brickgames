#include "Utils.h"

void Clear(HANDLE hConsole)
{
	// Fazer a limpeza do cout
	std::cout.flush();


	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD topLeft = { 0, 0 };

	// Pega as infos do console atual
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
		abort();

	// Multiplica o tamaho geral para o buffer de todo o espaço consumido
	DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

	DWORD written;

	FillConsoleOutputCharacterW(hConsole, L' ', length, topLeft, &written); // preencher o console com o tamanho começando do topleft (0 ,0) sendo as cordenadas
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, length, topLeft, &written); // Colocar o parametro de escrita
	SetConsoleCursorPosition(hConsole, topLeft); // E por fim devolver o cursor para o topo
}

void SetConsoleCurPos(HANDLE hConsole, short x, short y)
{
	std::cout.flush(); // Limpar o cout *opcional*
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hConsole, coord); // Seta a cordenada de maneira mais facil :)
}

void SetConsoleColor(HANDLE hConsole, short colour)
{
	std::cout.flush();
	SetConsoleTextAttribute(hConsole, colour); // Seta a coloração de maneira mais facil :)
}


