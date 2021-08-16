#include "MenuPrincipal.h"
#include <iostream>

MenuPrincipal::MenuPrincipal():
	
	Menu(4),
	tipoMenu(1)

{
	
	texto[0].setString("Jogar");
	texto[1].setString("Fases");
	texto[2].setString("Ranking");
	texto[3].setString("Sair");

}

MenuPrincipal::~MenuPrincipal()
{
	
}

const int MenuPrincipal::getTipo() const
{
	return tipoMenu;
}

int MenuPrincipal::executar()
{
	gGrafico->limpar();
	desenhar();
	gGrafico->mostrar();
	int i = -1;
	while (i == -1) {
		int evento = gEv->verificaEvento();
		switch (evento)
		{
		case 2:
			switch (getBotaoPressionado())
			{
			case 0:			//Jogar
				i = 0;
				break;
			case 1:			//Fases
				i = 1;
				break;
			case 2:	
				i = 2;		//Implementar ranking
				break;
			case 3:
				gGrafico->getJanela()->close();		//Sair
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
	return i;
}