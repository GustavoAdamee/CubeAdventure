#include "BlocoCaverna.h"

BlocoCaverna::BlocoCaverna(Vector2f pos, Vector2f vel, const char* caminhoTextura, GerenciadorGrafico* g, GerenciadorTiles* gTiles):
	Tiles(pos, vel, caminhoTextura, g, gTiles)
{
}

BlocoCaverna::~BlocoCaverna()
{
}

Vector2f BlocoCaverna::getTamEntidade()
{
	return Vector2f();
}
