#pragma once
#include "Tiles.h"
class BlocoVoador :
    public Tiles
{
private:

    Vector2f tam = Vector2f(50, 50);

public:
    BlocoVoador(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, GerenciadorTiles* gTiles = nullptr);
    ~BlocoVoador();

    void mover();

    Vector2f getTamEntidade();
};

