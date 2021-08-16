#pragma once
#include "Menu.h"
class MenuRanking :
    public Menu
{
private:

    int n = 2;

public:
    MenuRanking();
    ~MenuRanking();

    int getTipo();

    void desenhar();

    int executar();

    void cadastrar(String nome, int pontos);
};

