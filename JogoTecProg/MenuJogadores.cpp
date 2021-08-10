#include "MenuJogadores.h"

MenuJogadores::MenuJogadores(GerenciadorEventos& gE, GerenciadorGrafico& g):
	Menu(gE, g, 3),
	tipoMenu(2)
{
	texto[0].setString("1 jogador");
	texto[1].setString("2 jogadores");
	texto[2].setString("Voltar");
}

MenuJogadores::~MenuJogadores()
{
	gGraf = nullptr;
	gEv = nullptr;
}

int MenuJogadores::getTipo()
{
	return tipoMenu;
}

int MenuJogadores::executar()
{
	gGraf->limpar();
	desenhar();
	gGraf->mostrar();
	int i = -1;
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
			default:
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
		gGraf->limpar();
		desenhar();
		gGraf->mostrar();
	}
	return i;
}
