#pragma once
#include "Personagem.h"
#include <ctime>

namespace Inimigos {
    class Inimigo : public Personagem
    {
    protected:

    public:

        //Construtora e destrutora
        Inimigo(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr);
        ~Inimigo();

        virtual void mover() = 0;

        virtual Vector2f getTamEntidade() = 0;

    };

}