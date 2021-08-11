#include "Inimigo.h"
using namespace Inimigos;

Inimigo::Inimigo(Vector2f pos, Vector2f vel, const char* caminhoTextura):
	Personagem(pos, vel, caminhoTextura)
{
}

Inimigo::~Inimigo()
{
}
