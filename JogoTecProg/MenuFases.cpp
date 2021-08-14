#include "MenuFases.h"

MenuFases::MenuFases():
	
	Menu(4),
	TipoMenu(4)

{
	
	texto[0].setString("Fase Grama");
	texto[1].setString("Fase Caverna");
	texto[2].setString("Fase Caverna Chefao");
	texto[3].setString("Voltar");

}

MenuFases::~MenuFases()
{
	
}

int MenuFases::getTipo()
{
	return TipoMenu;
}

int MenuFases::executar()
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
	return i;
}
