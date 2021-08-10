#include "MenuPause.h"
#include <Windows.h>

MenuPause::MenuPause(GerenciadorEventos& gE, GerenciadorGrafico& g):
	Menu(gE, g, 3),
	tipoMenu(3)
{
	
	texto[0].setString("Continuar");
	texto[1].setString("Menu principal");
	texto[2].setString("Sair do jogo");

}

MenuPause::~MenuPause()
{
	
}

int MenuPause::getTipo()
{
	return tipoMenu;
}

int MenuPause::executar()
{
	
	desenhar();
	gGraf->mostrar();
	Sleep(400);
	int i = -1;
	while (i == -1) {
		int evento = gEv->verificaEvento();
		switch (evento)
		{
		case 1:
			i = 0;
			break;
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
				gGraf->getJanela()->close();
				i = 2;
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
		desenhar();
		gGraf->mostrar();
	}
	return i;
}
