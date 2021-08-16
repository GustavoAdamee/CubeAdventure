#pragma once

#include "Ente.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"

#define MAX_ITENS 8

class Menu:
	public Ente
{
protected:
	
	//indica a quantidade de "opções" de cada menu
	//Indica o indice de cada "opção"	
	int qnt_itens;
	int indiceItem;
	
	//Parte "grafica" de cada menu
	sf::Font fonte;
	sf::Text texto[MAX_ITENS];

	//Todos os menus possuem o mesmo gerenciador
	static GerenciadorEventos* gEv;
	
public:
	//Construtora e Destrutora
	Menu(int n_itens);
	virtual ~Menu();

	//Desenha os textos na tela
	virtual void desenhar();
	
	//Interações de cada menu seta cima e baixo
	void moveCima();
	void moveBaixo();

	//Retorna o indice de cada "opção"
	const int getBotaoPressionado() const;

	//Virtuais para retorna qual menu esta sendo executado e para executá-lo
	const virtual int getTipo() const;
	virtual int executar();

	static void setGEventos(GerenciadorEventos* gEventos);

	virtual void cadastrar(String nome, int pontos);
};

