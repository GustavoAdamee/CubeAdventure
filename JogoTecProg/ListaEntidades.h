#pragma once
#include"Lista.h"
#include"Entidade.h"


class ListaEntidades
{
private:
	Lista<Entidade> LEs;

public:
	ListaEntidades();

	~ListaEntidades();

	Lista<Entidade>& getLista();

	Entidade* operator[](int i);
	bool operator>(int i);

};
