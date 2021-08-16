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
    if (chao) { //Zera velocidade em y ao encostar no chao
        v.y = 0;
    }
    else {
        v.y += g * (float)t; //Gravidade
    }

    delay += t;
}

const Vector2f CuboExplorador::getTamEntidade() const
{
    return tam;
}

void CuboExplorador::desenharVidas()
{

    gGrafico->carregarTextura("images/vida.png");

    if (vida >= 1) {

        gGrafico->desenhar("images/vida.png", Vector2f(1438, 60));

    }

    if (vida >= 2) {

        gGrafico->desenhar("images/vida.png", Vector2f(1478, 60));

    }

    if (vida >= 3) {

        gGrafico->desenhar("images/vida.png", Vector2f(1518, 60));

    }


}
