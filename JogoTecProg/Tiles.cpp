#include "Tiles.h"

Tiles::Tiles(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim, GerenciadorTiles* gTiles) :
	Entidade(pos, vel, caminhoTextura, lim),
	gTiles(gTiles)
{
}

Tiles::~Tiles()
{
	gTiles = nullptr;
}

void Tiles::mover(double t)
{
}

void Tiles::initTile(int i, int j)
{
	gTiles->initMapaTiles(i, j);
}

int Tiles::colidir(int lado)
{
	return 0;
}




