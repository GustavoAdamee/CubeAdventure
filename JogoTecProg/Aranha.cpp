#include "Aranha.h"

Aranha::Aranha(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim) :
	Inimigo(pos, vel, caminhoTextura, lim)
{
}

Aranha::~Aranha()
{
}

void Aranha::mover(double t) //em X
{
	if (posicao.x <= limite.x) {
		v.x = fabsf(v.x);
	}
	else if (posicao.x >= limite.y) {
		v.x = -fabs(v.x);
	}
}

Vector2f Aranha::getTamEntidade()
{
	return tam;
}

int Aranha::colidir(int lado)
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


