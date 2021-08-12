#pragma once
#include "Entidade.h"
class Projetil :
    public Entidade
{

private:

    Vector2f tam = Vector2f(24, 24);

public:
    
    //Construtora e destrutora
    Projetil(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vector2f lim = { 0.0f, 0.0f });
    ~Projetil();

    void mover(double t);

    Vector2f getTamEntidade();

    int colidir(int lado);

};

