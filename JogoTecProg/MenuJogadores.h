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
	MenuJogadores();
	~MenuJogadores();
	
	//Retorna um int para qual menu esta sendo executado no momento
	int getTipo();

	//Inicia a execução do menu
	int executar();
};

