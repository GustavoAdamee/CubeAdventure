#include "MenuRanking.h"

MenuRanking::MenuRanking():
	Menu(7)
{
	texto[0].setString("Voltar");
	texto[1].setString("Ranking");
	

	texto[0].setPosition(Vector2f(50, 50));
	texto[1].setPosition(Vector2f(700, 50));
	texto[2].setPosition(Vector2f(600, 300));
	texto[3].setPosition(Vector2f(600, 350));
	texto[4].setPosition(Vector2f(600, 400));
	texto[5].setPosition(Vector2f(600, 450));
	texto[6].setPosition(Vector2f(600, 500));
}

MenuRanking::~MenuRanking()
{
}

const int MenuRanking::getTipo() const
{
	return 0;
}

void MenuRanking::desenhar()
{

	gGrafico->setBackground("images/fundoGrama.png");
	gGrafico->desenhaBackground();

	for (int i = 0; i < qnt_itens; i++) {
		gGrafico->getJanela()->draw(texto[i]);
	}

}

int MenuRanking::executar()
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
			i = 1;
			break;
		default:
			break;
		}
	}

	return 0;
}

void MenuRanking::cadastrar(String nome, int pontos)
{
	int i = 2;
	while (i != n) {
		i++;
	}
	
	texto[i].setString("  " + nome + "          " + to_string(pontos) + " pontos");
	
	if (n != 6) {
		n++;
	}
}
