#include "Tiles.h"

Tiles::Tiles(Vector2f pos, Vector2f vel, const char* caminhoTextura, GerenciadorGrafico* g, GerenciadorTiles* gTiles) :
	Entidade(pos, vel, caminhoTextura),
	gGraf(g),
	gTiles(gTiles)
{
}

Tiles::~Tiles()
{
	gGraf = nullptr;
	
	gTiles = nullptr;
}

void Tiles::mover()
{
}

void Tiles::initTile(int i, int j)
{
	gTiles->initMapaTiles(i, j);
}

void Tiles::desenhar()
{
}



