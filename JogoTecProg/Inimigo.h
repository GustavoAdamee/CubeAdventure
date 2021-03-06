#pragma once
#include "Personagem.h"
#include <ctime>

namespace Inimigos {
    class Inimigo : public Personagem
    {
    protected:


    public:

        //Construtora e destrutora
        Inimigo(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vector2f lim = { 0.0f, 0.0f });
        virtual ~Inimigo();

        virtual void mover(double t) = 0 ;

        const virtual Vector2f getTamEntidade() const = 0;

        virtual int colidir(int lado) = 0;

        virtual void desenharVidas();

        const virtual float getPontos() const;
    };

}