#pragma once
#include "Menu.h"
class MenuJogadores :
    public Menu
{
private:
	
	//Atributo para o tipo do menu
	int tipoMenu;

public:
	
	//Construtora e Destrutora
	MenuJogadores(GerenciadorEventos& gE);
	~MenuJogadores();
	
	//Retorna um int para qual menu esta sendo executado no momento
	int getTipo();

	//Inicia a execu��o do menu
	int executar();
};

