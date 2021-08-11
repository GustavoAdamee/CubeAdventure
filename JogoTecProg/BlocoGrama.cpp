#include "BlocoGrama.h"

BlocoGrama::BlocoGrama(Vector2f pos, Vector2f vel, const char* caminhoTextura, GerenciadorTiles* gTiles):
	Tiles(pos, vel, caminhoTextura, gTiles)
{

}

BlocoGrama::~BlocoGrama()
{
}

Vector2f BlocoGrama::getTamEntidade()
{
	return Vector2f();
}
