#include "BlocoGrama.h"

BlocoGrama::BlocoGrama(Vector2f pos, Vector2f vel, const char* caminhoTextura, GerenciadorGrafico* g, GerenciadorTiles* gTiles):
	Tiles(pos, vel, caminhoTextura, g, gTiles)
{

}

BlocoGrama::~BlocoGrama()
{
}

Vector2f BlocoGrama::getTamEntidade()
{
	return Vector2f();
}
