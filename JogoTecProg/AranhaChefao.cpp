#include "AranhaChefao.h"

AranhaChefao::AranhaChefao(Vector2f pos, Vector2f vel, const char* caminhoTextura) :
	Inimigo(pos, vel, caminhoTextura)
{
}

AranhaChefao::~AranhaChefao()
{
}

void AranhaChefao::mover(double t)
{
}


Vector2f AranhaChefao::getTamEntidade()
{
	return tam;
}
