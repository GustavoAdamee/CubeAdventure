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
    //v.y = 0;

    //Conjunto de ifs relacionados a leituras no teclado
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        //v.y += 300;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        v.x += 300;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        v.x += -300;
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
