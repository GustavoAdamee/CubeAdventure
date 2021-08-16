#include "Inimigo.h"
using namespace Inimigos;

Inimigo::Inimigo(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim):
	Personagem(pos, vel, caminhoTextura, lim)
{
}

Inimigo::~Inimigo()
{
}

void Inimigos::Inimigo::desenharVidas()
{
}

const float Inimigos::Inimigo::getPontos() const
{
	return 0.0f;
}
