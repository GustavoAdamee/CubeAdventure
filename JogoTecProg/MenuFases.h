#pragma once
#include"Menu.h"

class MenuFases:
	public Menu
{
private:
	
	//Atributo para o tipo do menu
	int TipoMenu;

public:
	
	//Construtora e Destrutora
	MenuFases();
	~MenuFases();

	//Retorna um int para qual menu esta sendo executado no momento
	const int getTipo() const;

	//Inicia a execução do menu
	int executar();
};

