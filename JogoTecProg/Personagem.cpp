#include "Personagem.h"

Personagem::Personagem(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim) :
	Entidade(pos, vel, caminhoTextura, lim)
{
}

Personagem::~Personagem()
{
}


void Personagem::setChao(const bool aux)
{
}

const bool Personagem::getChao() const
{
	return false;
}

void Personagem::desenharVidas()
{
}

const float Personagem::getPontos() const
{
	return 0.0f;
}
