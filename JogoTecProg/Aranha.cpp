#include "Aranha.h"

Aranha::Aranha(Vector2f pos, Vector2f vel, const char* caminhoTextura) :
	Inimigo(pos, vel, caminhoTextura)
{
}

Aranha::~Aranha()
{
}

void Aranha::mover()
{
}

void Aranha::desenhar()
{
}

Vector2f Aranha::getTamEntidade()
{
	return tam;
}

//bool Aranha::checaColisao(Entidade* entidade)
//{
//
//}
