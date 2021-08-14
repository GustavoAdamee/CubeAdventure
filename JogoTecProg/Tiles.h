#pragma once

#include "Entidade.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorTiles.h"


class Tiles :
    public Entidade
{
protected:
    
    GerenciadorTiles* gTiles;

public:
    
    Tiles(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vector2f lim = { 0.0f, 0.0f }, GerenciadorTiles* gTiles = nullptr);
    virtual ~Tiles();

    //Deixar virtual e depois mandar para tile que for mover 
    virtual void mover(double t);

    void initTile(int i, int j);

    virtual Vector2f getTamEntidade() = 0;

    virtual int colidir(int lado);
};

