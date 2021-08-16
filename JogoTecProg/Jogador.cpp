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

void Jogadores::Jogador::setChao(const bool aux)
{
    chao = aux;
}

const bool Jogadores::Jogador::getChao() const
{
    return chao;
}

int Jogadores::Jogador::colidir(int lado)
{
    if (lado == 1 && delay >= 1.3) { //Colisao danosa com inimigos

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

const int Jogadores::Jogador::getVida() const
{
    return vida;
}

void Jogadores::Jogador::desenharVidas()
{
}

const float Jogadores::Jogador::getPontos() const
{
    if (destruir) { //Perde pontos ao perder todas as vidas
        return -450.0f;
    }
    
    
    return 0.0f;
}



