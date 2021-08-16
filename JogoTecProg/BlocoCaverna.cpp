#include "BlocoCaverna.h"

BlocoCaverna::BlocoCaverna(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim, GerenciadorTiles* gTiles):
	Tiles(pos, vel, caminhoTextura, lim, gTiles)
{
}

BlocoCaverna::~BlocoCaverna()
{
}


const Vector2f BlocoCaverna::getTamEntidade() const
{
	return Vector2f();
}
