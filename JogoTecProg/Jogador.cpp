#include "Jogador.h"
using namespace Jogadores;

Jogador::Jogador(Vector2f pos, Vector2f vel, const char* caminhoTextura) :
    Personagem(pos, vel, caminhoTextura)
{
}

Jogador::~Jogador()
{
}

void Jogadores::Jogador::mover(double t)
{
}

void Jogadores::Jogador::setChao(bool aux)
{
    chao = aux;
}

bool Jogadores::Jogador::getChao()
{
    return chao;
}

int Jogadores::Jogador::colidir(int lado)
{
    return 0;
}

