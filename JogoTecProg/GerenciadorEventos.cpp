#include "GerenciadorEventos.h"

GerenciadorEventos::GerenciadorEventos():
	gGraf(nullptr),
	ev()
{
}

GerenciadorEventos* GerenciadorEventos::getInstancia()
{
	if (instancia == 0) {
		instancia = new GerenciadorEventos();
	}
	return instancia;
}

GerenciadorEventos::~GerenciadorEventos()
{
	gGraf = nullptr;

}

void GerenciadorEventos::setGGraf(GerenciadorGrafico* gGrafico)
{
	gGraf = gGrafico;
}

int GerenciadorEventos::verificaEvento()
{
	int i = 0;
	while (gGraf->getJanela()->pollEvent(ev)) {
		switch (ev.type)
		{
		case sf::Event::Closed:
			gGraf->getJanela()->close();
			break;
		case sf::Event::KeyReleased:
			switch (ev.key.code)
			{
			case sf::Keyboard::Escape:
				i = 1;
				break;
			case sf::Keyboard::Return:
				i = 2;
				break;
			case sf::Keyboard::Up:
				i = 3;
				break;
			case sf::Keyboard::Down:
				i = 4;
				break;
			default:
				break;
			}
		}
	}

	return i;
}

GerenciadorEventos* GerenciadorEventos::instancia = 0;