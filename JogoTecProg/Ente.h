#pragma once
#include "GerenciadorGrafico.h"
class Ente
{

protected:
	static GerenciadorGrafico* gGrafico;

public:
	//static GerenciadorGrafico* gGrafico;
	//Contrutora e Destrutora
	Ente();
	~Ente();

	//Virtual para chamar as funções de desenhar em cada classe que herda Ente
	virtual void desenhar() = 0;

	static void setGGrafico(GerenciadorGrafico* gGraf);
	
};

