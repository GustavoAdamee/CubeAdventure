#include "Personagem.h"

Personagem::Personagem(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim) :
	Entidade(pos, vel, caminhoTextura, lim)
{
}

Personagem::~Personagem()
{
}


void Personagem::setChao(bool aux)
{
}

bool Personagem::getChao()
{
	return false;
}
