#include "MenuPrincipal.h"
#include <iostream>

MenuPrincipal::MenuPrincipal(GerenciadorEventos& gE, GerenciadorGrafico& g):
	
	Menu(gE, g, 4),
	tipoMenu(1)

{
	
	texto[0].setString("Jogar");
	texto[1].setString("Fases");
	texto[2].setString("Ranking");
	texto[3].setString("Sair");

}

MenuPrincipal::~MenuPrincipal()
{
	gGraf = nullptr;
	gEv = nullptr;
}

int MenuPrincipal::getTipo()
{
	return tipoMenu;
}

int MenuPrincipal::executar()
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
			case 2: //Implementar ranking
				break;
			case 3:
				gGraf->getJanela()->close();
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
		gGraf->limpar();
		desenhar();
		gGraf->mostrar();
	}
	return i;
}