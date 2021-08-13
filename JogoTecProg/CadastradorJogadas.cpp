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
	//texto[4].setString("2000 pontos");

}

CadastradorJogadas::~CadastradorJogadas()
{
}

String CadastradorJogadas::executar(int pontos)
{
	texto[1].setString("A");
	texto[2].setString("A");
	texto[3].setString("A");
	texto[4].setString(to_string(pontos) + " pontos");

	gGrafico->limpar();
	desenhar();
	gGrafico->mostrar();
	int i = -1;
	while (i == -1) {
		int evento = gEv->verificaEvento();
		switch (evento)
		{
		case 2: //Enter pressionado
			switch (n_letra)
			{
			case 1: //Primeira letra
				texto[n_letra++].setFillColor(sf::Color::White);
				texto[n_letra].setFillColor(sf::Color::Yellow);
				letra = 65;
				break;
			case 2: //Segunda letra
				texto[n_letra++].setFillColor(sf::Color::White);
				texto[n_letra].setFillColor(sf::Color::Yellow);
				letra = 65;
				break;
			case 3: //Terceira letra
				i = 1;
				texto[n_letra].setFillColor(sf::Color::White);
				texto[1].setFillColor(sf::Color::Yellow);
				n_letra = 1;
				break;
			}
			break;
		case 3: //Seta cima (letra anterior)
			if (letra == 65) { //A para Z
				letra = 90;
			}
			else {
				letra--;
			}
			texto[n_letra].setString(char(letra));
			break;
		case 4: //Seta baixo (proxima letra)
			if (letra == 90) { //Z para A
				letra = 65;
			}
			else {
				letra++;
			}
			texto[n_letra].setString(char(letra));
			break;
		default:
			break;
		}
		gGrafico->limpar();
		desenhar();
		gGrafico->mostrar();
	}
	return (String(texto[1].getString() + texto[2].getString() + texto[3].getString()));
}

void CadastradorJogadas::desenhar()
{
	for (int i = 0; i < 5; i++) {
		gGrafico->getJanela()->draw(texto[i]);
	}
}

void CadastradorJogadas::setGEv(GerenciadorEventos* gEventos)
{
	gEv = gEventos;
}
