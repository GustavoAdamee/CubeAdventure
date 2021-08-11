#include "CuboExplorador.h"

CuboExplorador::CuboExplorador(Vector2f pos, Vector2f vel, const char* caminhoTextura) :
    Jogador(pos, vel, caminhoTextura)
{
}

CuboExplorador::~CuboExplorador()
{
}

void CuboExplorador::mover(double t)
{

    v.x = 0;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        v.x += 250;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        v.x += -250;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
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

Vector2f CuboExplorador::getTamEntidade()
{
    return tam;
}
