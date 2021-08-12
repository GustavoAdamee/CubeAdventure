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
    if (lado == 1 && delay >= 1.3) {

        vida--;

        delay = 0;

        if (vida == 0) {

            destruir = true;

            vida = 3;
        }
    }

    return 0;
}

void Jogadores::Jogador::resetaVida()
{
    vida = 3;
}

int Jogadores::Jogador::getVida()
{
    return vida;
}



