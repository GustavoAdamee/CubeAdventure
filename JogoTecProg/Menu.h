#pragma once

#include "Ente.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"

#define MAX_ITENS 4

class Menu:
	public Ente
{
protected:
	
	//Gerenciadores
	GerenciadorEventos* gEv;

	//indica a quantidade de "op��es" de cada menu
	//Indica o indice de cada "op��o"	
	int qnt_itens;
	int indiceItem;
	
	//Parte "grafica" de cada menu
	sf::Font fonte;
	sf::Text texto[MAX_ITENS];
	
public:
	//Construtora e Destrutora
	Menu(GerenciadorEventos& gE, int n_itens);
	virtual ~Menu();

	//Desenha os textos na tela
	void desenhar();
	
	//Intera��es de cada menu seta cima e baixo
	void moveCima();
	void moveBaixo();

	//Retorna o indice de cada "op��o"
	int getBotaoPressionado();

	//Virtuais para retorna qual menu esta sendo executado e para execut�-lo
	virtual int getTipo() = 0;
	virtual int executar() = 0;

};

