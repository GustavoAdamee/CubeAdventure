#include "Inseto.h"

Inseto::Inseto(Vector2f pos, Vector2f vel, const char* caminhoTextura) :
	Inimigo(pos, vel, caminhoTextura)
{

}

Inseto::~Inseto()
{
}

void Inseto::mover(double t)
{
}

Vector2f Inseto::getTamEntidade()
{
	return tam;
}

