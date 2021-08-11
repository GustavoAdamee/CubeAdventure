#include "Tiles.h"

Tiles::Tiles(Vector2f pos, Vector2f vel, const char* caminhoTextura, GerenciadorTiles* gTiles) :
	Entidade(pos, vel, caminhoTextura),
	gTiles(gTiles)
{
}

Tiles::~Tiles()
{
	gTiles = nullptr;
}

void Tiles::mover()
{
}

void Tiles::initTile(int i, int j)
{
	gTiles->initMapaTiles(i, j);
}




