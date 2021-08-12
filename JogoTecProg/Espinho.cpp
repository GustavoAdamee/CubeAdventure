#include "Espinho.h"

Espinho::Espinho(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim, GerenciadorTiles* gTiles):
	Tiles(pos, vel, caminhoTextura, lim, gTiles)
{
}

Espinho::~Espinho()
{
}

Vector2f Espinho::getTamEntidade()
{
	return tam;
}

int Espinho::colidir(int lado)
{
	if (lado == 0) {
		return 0;
	}
	else {
		return 1;
	}
}
