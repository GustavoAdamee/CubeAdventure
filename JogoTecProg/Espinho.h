#pragma once
#include "Tiles.h"
class Espinho :
    public Tiles
{
private:

    Vector2f tam = Vector2f(50, 50);

public:
    Espinho(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vector2f lim = { 0.0f, 0.0f }, GerenciadorTiles* gTiles = nullptr);
    ~Espinho();

    Vector2f getTamEntidade();

    int colidir(int lado);
};

