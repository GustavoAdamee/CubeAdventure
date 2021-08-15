#pragma once

#include"GerenciadorTiles.h"
#include"ListaEntidades.h"
#include"Entidade.h"



class GerenciadorColisoes
{
private:
	
	//Gerenciadores
	GerenciadorTiles* gTiles;
	
	//Listas
	ListaEntidades* listaEnt;
	
	//Armazena todas as tiles da uma fase
	vector < GerenciadorTiles::InfoTiles > vetorTiles;

	//Singleton
	static GerenciadorColisoes* instancia;

	//Construtora privada
	GerenciadorColisoes();

public:

	static GerenciadorColisoes* getInstancia();

	//Destrutora
	~GerenciadorColisoes();

	//Percorre laços verificando colisões com a entidade passado por parametro
	void VerificaColisoes(Entidade* aux);

	int checarColisao(Entidade* aux1, Entidade* aux2);

	//Faz os sets para os atributos
	void setListaEntidades(ListaEntidades* listaEnt);
	void setGerenciadorTiles(GerenciadorTiles* gTiles);

	void adicionarTile(GerenciadorTiles::InfoTiles aux);
	void limparTiles();
};

