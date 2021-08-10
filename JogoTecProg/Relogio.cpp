#include "Relogio.h"

#include <iostream>


Relogio::Relogio() : ultimo{ clock() }, atual{ 0 }, dt{ 0 }, pausado{ false } {
}

Relogio::~Relogio() {
}

double Relogio::getTempo() {
    if (pausado) {
        reiniciar();
        return 0.0;
    }

    atual = clock();
    

    dt = (double)(atual - ultimo) / CLOCKS_PER_SEC;

    ultimo = atual;
    
    return dt;
}

void Relogio::reiniciar() {
    pausado = false;
    ultimo = clock();
}

void Relogio::pausar() {
    pausado = true;
}