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

	//vector<GerenciadorColisoes::DadosTiles> vetorTiles;

public:
	typedef struct infoTiles
	{
		Vector2f posicao;
		Vector2f tamanho;
	}InfoTiles;

	vector<infoTiles> vetorTiles;

	//Construtora e Destrutora
	GerenciadorColisoes();
	~GerenciadorColisoes();

	//Percorre laços verificando colisões com a entidade passado por parametro
	void VerificaColisoes(Entidade* aux);

	int checarColisao(Entidade* aux1, Entidade* aux2);

	//Faz os sets para os atributos
	void setListaEntidades(ListaEntidades* listaEnt);
	void setGerenciadorTiles(GerenciadorTiles* gTiles);

	void adicionarTile(infoTiles aux);
	void limparTiles();
};

