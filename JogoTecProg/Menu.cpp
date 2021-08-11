#include "Menu.h"

Menu::Menu(GerenciadorEventos& gE, int n_itens) :
	
	Ente(),
	gEv(&gE),
	qnt_itens(n_itens),
	indiceItem(0),
	fonte(),
	texto()
	
{
	
	float width = gGrafico->getJanela()->getSize().x;
	float height = gGrafico->getJanela()->getSize().y;
	
	if (!fonte.loadFromFile("Happy chicken.ttf")) {
	}
	
	for (int i = 0; i < qnt_itens; i++) {
		texto[i].setFont(fonte);
		texto[i].setScale(1, 1);
		texto[i].setFillColor(sf::Color::White);
		texto[i].setPosition(sf::Vector2f(50, height / (qnt_itens + 1) * (i+1)));
	}
	
	texto[0].setFillColor(sf::Color::Yellow);
}

Menu::~Menu()
{

}

void Menu::desenhar()
{
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

int Menu::getBotaoPressionado()
{
	return indiceItem;
}