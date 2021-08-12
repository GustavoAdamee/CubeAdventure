#include "AranhaChefao.h"

AranhaChefao::AranhaChefao(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim) :
	Inimigo(pos, vel, caminhoTextura, lim)
{
}

AranhaChefao::~AranhaChefao()
{
}

void AranhaChefao::mover(double t)
{
	if (posicao.x <= limite.x || posicao.x >= limite.y) {
		v.x = -v.x;
	}
}


Vector2f AranhaChefao::getTamEntidade()
{
	return tam;
}

int AranhaChefao::colidir(int lado)
{
	if (lado == 2) {
		vida--;
		if (vida == 0) {
			destruir = true;
		}
		return 0;
	}
	else if (lado == 0) {
		return 0;
	}
	return 1;
}
