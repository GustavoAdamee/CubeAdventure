#include "MenuPause.h"
#include <Windows.h>

MenuPause::MenuPause():
	Menu(3),
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

void MenuPause::desenhar()
{

	for (int i = 0; i < qnt_itens; i++) {
		gGrafico->getJanela()->draw(texto[i]);
	}

}

int MenuPause::executar()
{
	
	desenhar();
	gGrafico->mostrar();
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
				gGrafico->getJanela()->close();
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
		gGrafico->mostrar();
	}
	return i;
}
