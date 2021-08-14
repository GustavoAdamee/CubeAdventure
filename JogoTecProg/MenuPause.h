#pragma once
#include"Menu.h"

class MenuPause: public Menu
{
private:
	
	//Atributo para o tipo do menu
	int tipoMenu;

public:
	
	//Construtora e Destrutora
	MenuPause();
	~MenuPause();
	
	//Retorna um int para qual menu esta sendo executado no momento
	int getTipo();

	//Desenha o menu sem background
	void desenhar();

	//Inicia a execução do menu₢
	int executar();

};

