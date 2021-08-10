#include "Personagem.h"

Personagem::Personagem(Vector2f pos, Vector2f vel, const char* caminhoTextura) :
	Entidade(pos, vel, caminhoTextura)
{
}

Personagem::~Personagem()
{
}

void Personagem::desenhar()
{
}
