#pragma once

#include "Projetil.h"

class Atirador
{
protected:

    double delayAtirar = 0;

public:
    
    //Construtora e destrutora
    Atirador();
    ~Atirador();

    //Retorna o projetil atirado quando poss�vel
    virtual Projetil* atirar() = 0;

};

