#include "Menu.h"

Menu::Menu(int n_itens) :

	Ente(),
	qnt_itens(n_itens),
	indiceItem(0),
	fonte(),
	texto()

{
	if (qnt_itens) {
		float width = gGrafico->getJanela()->getSize().x;
		float height = gGrafico->getJanela()->getSize().y;

		if (!fonte.loadFromFile("Happy chicken.ttf")) {
		}

		for (int i = 0; i < qnt_itens; i++) {
			texto[i].setFont(fonte);
			texto[i].setScale(1, 1);
			texto[i].setFillColor(sf::Color::White);
			texto[i].setPosition(sf::Vector2f(50, height / (qnt_itens + 1) * (i + 1)));
		}

		texto[0].setFillColor(sf::Color::Yellow);
	}
	

}

Menu::~Menu()
{

}

void Menu::desenhar()
{
	
	gGrafico->setBackground("images/backGround.png");
	gGrafico->desenhaBackground();
	
	for (int i = 0; i < qnt_itens; i++) {
		gGrafico->getJanela()->draw(texto[i]);
	}
}

void Menu::moveCima()
{
	if (indiceItem - 1 >= 0) {
		texto[indiceItem].setFillColor(sf::Color::White);
		indiceItem--;
		texto[indiceItem].setFillColor(sf::Color::Yellow);
	}
}

void Menu::moveBaixo()
{
	if (indiceItem + 1 < qnt_itens) {
		texto[indiceItem].setFillColor(sf::Color::White);
		indiceItem++;
		texto[indiceItem].setFillColor(sf::Color::Yellow);
	}
}

const int Menu::getBotaoPressionado() const
{
	return indiceItem;
}

const int Menu::getTipo() const
{
	return 0;
}

int Menu::executar()
{
	return 0;
}

void Menu::setGEventos(GerenciadorEventos* gEventos)
{
	gEv = gEventos;
}

void Menu::cadastrar(String nome, int pontos)
{
}

GerenciadorEventos* Menu::gEv = 0;