#include "Ente.h"

Ente::Ente()
{
}


Ente::~Ente()
{
}

void Ente::setGGrafico(GerenciadorGrafico* gGraf)
{
	gGrafico = gGraf;
}

GerenciadorGrafico* Ente::gGrafico = nullptr;
