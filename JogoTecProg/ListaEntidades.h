#pragma once
#include"Lista.h"
#include"Entidade.h"


class ListaEntidades
{
private:
	
	//Atributo para lista Template
	Lista<Entidade> LEs;

public:
	
	//Construtora e Destrutora
	ListaEntidades();
	~ListaEntidades();

	//Retorna a lista de entidades 
	Lista<Entidade>& getLista();

	//Sobrecarga de dois operadores
	Entidade* operator[](int i);
	bool operator>(int i);

};
