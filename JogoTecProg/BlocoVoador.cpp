#include "BlocoVoador.h"

BlocoVoador::BlocoVoador(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim, GerenciadorTiles* gTiles):
	Tiles(pos, vel, caminhoTextura, lim, gTiles)
{
}

BlocoVoador::~BlocoVoador()
{
}

void BlocoVoador::mover(double t)
{
	if (posicao.y <= limite.x || posicao.y >= limite.y) {
		v.y = -v.y;
	}
}

Vector2f BlocoVoador::getTamEntidade()
{
	return tam;
}

int BlocoVoador::colidir(int lado)
{
	if (lado == 0) {
		return 0;
	}
	else {
		return 1;
	}
}
