#include "BlocoCaverna.h"

BlocoCaverna::BlocoCaverna(Vector2f pos, Vector2f vel, const char* caminhoTextura, GerenciadorTiles* gTiles):
	Tiles(pos, vel, caminhoTextura, gTiles)
{
}

BlocoCaverna::~BlocoCaverna()
{
}


Vector2f BlocoCaverna::getTamEntidade()
{
	return Vector2f();
}
