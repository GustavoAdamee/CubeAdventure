#pragma once

#include "Entidade.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorTiles.h"


class Tiles :
    public Entidade
{
protected:
    
    GerenciadorGrafico* gGraf;
    GerenciadorTiles* gTiles;

public:
    
    Tiles(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, GerenciadorGrafico* g = nullptr, GerenciadorTiles* gTiles = nullptr);
    ~Tiles();

    //Deixar virtual e depois mandar para tile que for mover 
    void mover();

    void initTile(int i, int j);

    virtual Vector2f getTamEntidade() = 0;
};

