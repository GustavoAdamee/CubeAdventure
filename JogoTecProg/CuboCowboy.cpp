#include "CuboCowboy.h"

CuboCowboy::CuboCowboy(Vector2f pos, Vector2f vel, const char* caminhoTextura) :
    Jogador(pos, vel, caminhoTextura)
{
}

CuboCowboy::~CuboCowboy()
{
}

void CuboCowboy::mover()
{

    v.x = 0;
    v.y = 0;

    //Conjunto de ifs relacionados a leituras no teclado
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        v.y += 300;
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
        v.y += -300;
    }
}

void CuboCowboy::desenhar()
{
}

Vector2f CuboCowboy::getTamEntidade()
{
    return tam;
}
