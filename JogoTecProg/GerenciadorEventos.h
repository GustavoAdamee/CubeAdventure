#pragma once
#include <SFML/Graphics.hpp>
#include "GerenciadorGrafico.h"

class Jogador1;
class Jogador2;

class GerenciadorEventos
{
private:

	//Atributo que a classe é responasavel por manipular
	Event ev;
	
	//Gerenciadores
	GerenciadorGrafico* gGraf;

	//Singleton
	static GerenciadorEventos* instancia;
	//Construtora privada
	GerenciadorEventos();

public:

	//Retorna gerenciador ja criado, se nao houver cria um novo
	static GerenciadorEventos* getInstancia();

	//Destrutora
	~GerenciadorEventos();

	//Seta o gerenciador grafico
	void setGGraf(GerenciadorGrafico* gGrafico);

	//Verifica qual tecla foi "pressionada" e retona por meio de um int 
	int verificaEvento();
	

};

