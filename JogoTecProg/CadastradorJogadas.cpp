#include "CadastradorJogadas.h"

CadastradorJogadas::CadastradorJogadas():
	
	Ente(),
	fonte(),
	texto()

{


	if (!fonte.loadFromFile("Happy chicken.ttf")) {
	}

	for (int i = 0; i < 5; i++) {
		
		texto[i].setFont(fonte);
		texto[i].setScale(1, 1);
		texto[i].setFillColor(sf::Color::White);
		
	}

	texto[0].setPosition(sf::Vector2f(600, 50));
	texto[1].setPosition(sf::Vector2f(400, 400));
	texto[2].setPosition(sf::Vector2f(450, 400));
	texto[3].setPosition(sf::Vector2f(500, 400));
	texto[4].setPosition(sf::Vector2f(1000, 400));
	
	texto[0].setFillColor(sf::Color::Yellow);
	texto[1].setFillColor(sf::Color::Yellow);


	texto[0].setString("Salvar Pontuação");
	texto[1].setString("A");
	texto[2].setString("A");
	texto[3].setString("A");
	texto[4].setString("2000 pontos");

}

CadastradorJogadas::~CadastradorJogadas()
{
}

void CadastradorJogadas::executar()
{

	gGrafico->limpar();
	desenhar();
	gGrafico->mostrar();
	/*int i = -1;
	while (i == -1) {
		int evento = gEv->verificaEvento();
		switch (evento)
		{
		case 2:
			switch (getBotaoPressionado())
			{
			case 0:
				i = 0;
				break;
			case 1:
				i = 1;
				break;
			case 2:
				i = 2;
				break;
			case 3:
				i = 3;
				break;
			}
			break;
		case 3:
			moveCima();
			break;
		case 4:
			moveBaixo();
			break;
		default:
			break;
		}
		gGrafico->limpar();
		desenhar();
		gGrafico->mostrar();
	}
	return i;*/

}

void CadastradorJogadas::desenhar()
{
	while (1)
	{
		gGrafico->limpar();


		for (int i = 0; i < 5; i++) {
			gGrafico->getJanela()->draw(texto[i]);
		}

		gGrafico->mostrar();
	}
}
