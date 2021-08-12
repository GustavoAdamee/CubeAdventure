#include "BlocoGrama.h"

BlocoGrama::BlocoGrama(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim , GerenciadorTiles* gTiles):
	Tiles(pos, vel, caminhoTextura, lim, gTiles)
{

}

BlocoGrama::~BlocoGrama()
{
}

Vector2f BlocoGrama::getTamEntidade()
{
	return Vector2f();
}
