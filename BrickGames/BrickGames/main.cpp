#include "head.h"
#include "CarCrash.h"

int main()
{
	// para os jogos é importante passar o hConsole pois vamos fazer telas dinamicas baseado em posição do console
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 

	// O console screen buffer é toda informação do console atual, isso é posição cordenadas e afins, são uteis para saber oque tá aonde e aonde o "cursor" se encontra
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	GetConsoleScreenBufferInfo(hConsole, &screenBufferInfo);


	// Mecanismo de CENA BASICAS, isso é informar ao render se precisa limpar a tela e quando desenha um quadro novo
	static bool ClearMenuFrame = false, RenderNextFrame = true;

	std::vector<std::string> Games = { "Car Crash", "Options Or Nothing :)", "Exit" }; // Lista de opções
	int IndexMenuSelected = 0; // Index de seleção do usuario

	char InputUser; // Entrada do úsuario

	while (true)
	{
		
		// RENDER 
		if (RenderNextFrame)
		{
			std::cout << "-----------------------------------------\n|\t\tMENU\t\t\t|\n-----------------------------------------\n";

			// 3 mas pode mudar
			for (size_t i = 0; i < Games.size(); i++)
			{
				std::cout << "\t" << (IndexMenuSelected == i ? " > " : "  ")
					<< Games[i] << std::endl;
			}
		}
		RenderNextFrame = false;


		// INPUT WAIT
		InputUser = _getch();


		if (toupper(InputUser) == 'W')
		{
			IndexMenuSelected--;

			if (IndexMenuSelected < 0)
				IndexMenuSelected = Games.size() - 1;


			ClearMenuFrame = true;
		}

		if (toupper(InputUser) == 'S')
		{
			IndexMenuSelected++;

			if (IndexMenuSelected >= Games.size())
				IndexMenuSelected = 0;

			ClearMenuFrame = true;
		}


		if (InputUser == VK_RETURN) // tecla enter ou Char 13
		{
			CarCrash Cars(hConsole);

			// Precisamos fazer algo aqui :D

		}



		// O jogos vão funciona abaixo dos 60 fps então não se preocupa tanto com a limpeza de telas, vamos utilizar os buffers ao nosso favor

		// Mas antes de entender os buffers vamos entender como funciona ACT \ NEXT renderização que os jogos mostra para nós
		// Nos jogos modernos, não sabemos oque vai acontecer na proxima cena, mas podemos limpar a cena atual quando a proxima cena já estiver feita
		// E para isso permanecer de forma suave fazendo as imagens se mover é necessario ser rapido
		// Então não se discarta a cena atual para fazer a proxima, se prepara a proxima cena e por fim apaga a tela atual
		// A Gpu é o hardware dedicado para isso, então alocamos as texturas e os modelos na memoria
		// Para no fim montar a proxima cena quando for chamada
		// Quando a proxima cena for chamada, jogamos a cena anterior para atrás e começamos a desenha a nova cena
		// E nesse momento é feito os calculos de luz, e fisica dos objetos
		// Então as cenas não são feitas em tempo real, mas os calculos sim
		// O que ocaciona Tearing

		// Então Porque os jogos 2D antigos não tinha esse problema de Tearing?
		// A resposta é simples meu caro ProHat, já era tudo pre-renderizado, basicamente eram imagem em BitMap jogado na memoria, do cartucho ou Console.
		// Um problema que poderia acontecer é caso a copia da imagem antiga seja detelada antes de por a nova na memoria, numa troca de spriter por exemplo,
		// se fosse lento o suficiente é capaz de ver a imagem sumindo e ficando um quadrado na posição do personagem com uma imagem distorcida e depois aparecendo
		// o novo spriter.

		// Jogos em console tem tearing?
		// Não e sim! é uma resposta abistrata para a pergunta
		// Pois a "imagem" é feita diante dos nossos olhos, e depende do processador, trocar tudo antes que possam ser visto
		// Então digamos que cada linha do console em 600x400, isso é 600 caracteres por linhas em 400 linhas, leva alguns MS para ser totalmente apagadas e
		// redesenhadas.
		// Oque a depender do processador pode ser visto a cena ser feita diante dos seus olhos em camera lenta
		// Irei fazer um exemplo mais tarde.

		// EM resumo, Os jogos atuais utilizam um metodo não novo para mostrar os graficos, tendo uma cena de fundo e mostrando a nova cena sendo montada
		// jogos 2D antigos, eram imagem pre-renderizadas alocada na memoria, oque não fazia acontecer o Tearing, mas baixos quadro poderia fazer as cenas não serem feitas
		// de forma planejada, sendo lenta \ imagem sumindo e aparecendo em seguida como de um inimigo, ou mesmo do personagem.
		// Então vamos enfretar basicamente os 2 problemas fazendo um jogo em console
		// Pois como podemos notar a imagem é feita a cada linha e similar ao tearing em jogos 3d pode se notar as telas sendo feita se muito lento
		// Mas isso só vai acontecer em poucos momentos como apos uma limpa da tela, ou se precisamos escrever algo muito grande na tela;
		// Nesse caso vamos ter o efeito tearing caso contrario, se lento demais podemos notar o efeito do console 2D, sendo um pixel sendo refeito

		// A e é claro tamos trabalhando com uma forma diferente de pixeis
		// como você pode notar os modelos de caracteres não corresponde a um quadrado perfeito e sim um retangolo
		// Por isso a altura é maior que a largura
		// O que pode deixa as coisas despropocionais então tomamos cuidados com linha \ colunas antes de desenhar algo

		if (ClearMenuFrame)
		{
			ClearMenuFrame = false;
			RenderNextFrame = true;
			system("cls");
		}

		InputUser = '\0'; // devolver o valor de caracter NULO
		
		Sleep(16); // 60 fps
	}


	return 0;
}