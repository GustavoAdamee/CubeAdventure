#include "CuboCowboy.h"
#include <iostream>

CuboCowboy::CuboCowboy(Vector2f pos, Vector2f vel, const char* caminhoTextura) :
    Jogador(pos, vel, caminhoTextura)
{
}

CuboCowboy::~CuboCowboy()
{
}

void CuboCowboy::mover(double t)
{

    v.x = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        v.x += 250;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        v.x += -250;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        //std::cout << chao << endl;
        if (chao) {
            v.y = -500;
            chao = false;
        }  
    }
    if (chao) {
        v.y = 0;
    }
    else {
        v.y += g * t;
    }

    delay += t;

}

Vector2f CuboCowboy::getTamEntidade()
{
    return tam;
}


void CuboCowboy::desenharVidas()
{

    gGrafico->carregarTextura("images/vida.png");

    if (vida >= 1) {

        gGrafico->desenhar("images/vida.png", Vector2f(60, 60));

    }

    if (vida >= 2) {

        gGrafico->desenhar("images/vida.png", Vector2f(100, 60));

    }

    if (vida >= 3) {

        gGrafico->desenhar("images/vida.png", Vector2f(140, 60));

    }


}
