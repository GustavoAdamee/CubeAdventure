#include "BlocoVoador.h"

BlocoVoador::BlocoVoador(Vector2f pos , Vector2f vel , const char* caminhoTextura , GerenciadorTiles* gTiles):
	Tiles(pos, vel, caminhoTextura, gTiles)
{
}

BlocoVoador::~BlocoVoador()
{
}

void BlocoVoador::mover()
{
}

Vector2f BlocoVoador::getTamEntidade()
{
	return tam;
}
