#include "Jogador.h"
using namespace Jogadores;

Jogador::Jogador(Vector2f pos, Vector2f vel, const char* caminhoTextura) :
    Personagem(pos, vel, caminhoTextura)
{
}

Jogador::~Jogador()
{
}

