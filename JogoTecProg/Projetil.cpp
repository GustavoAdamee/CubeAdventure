#include "Projetil.h"
#include <iostream>

Projetil::Projetil(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim):
	Entidade(pos, vel, caminhoTextura, lim)
{
}

Projetil::~Projetil()
{
}

void Projetil::mover(double t)
{
	if (posicao.x < limite.x) {
		destruir = true;
	}

	else if (posicao.y < limite.y) {
		destruir = true;
	}

	//cout << "posicao" << posicao.x << endl;
}

Vector2f Projetil::getTamEntidade()
{
	return tam;
}

int Projetil::colidir(int lado)
{
	if (lado == 0) {
		
		return 0;

	}

	else{
		
		destruir = true;
		
		return 1;
	}
}
