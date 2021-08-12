#include "Inseto.h"

Inseto::Inseto(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim) :
	Inimigo(pos, vel, caminhoTextura, lim)
{

}

Inseto::~Inseto()
{
}

void Inseto::mover(double t)
{
	if (posicao.x <= limite.x || posicao.x >= limite.y) {
		v.x = -v.x;
	}
}

Vector2f Inseto::getTamEntidade()
{
	return tam;
}

int Inseto::colidir(int lado)
{
	if (lado == 2) {
		destruir = true;
		return 0;
	}
	else if (lado == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

