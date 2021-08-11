#include "Espinho.h"

Espinho::Espinho(Vector2f pos, Vector2f vel, const char* caminhoTextura, GerenciadorTiles* gTiles):
	Tiles(pos, vel, caminhoTextura, gTiles)
{
}

Espinho::~Espinho()
{
}

Vector2f Espinho::getTamEntidade()
{
	return tam;
}
