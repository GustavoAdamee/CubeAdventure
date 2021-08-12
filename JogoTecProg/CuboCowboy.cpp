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
}

Vector2f CuboCowboy::getTamEntidade()
{
    return tam;
}

int CuboCowboy::colidir(int lado)
{
    if (lado == 1) {
        vida--;
        if (vida == 0) {
            destruir = true;
            vida = 3;
        }
    }
    return 0;
}
