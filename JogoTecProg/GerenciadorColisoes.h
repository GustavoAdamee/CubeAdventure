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
	class InfoTiles
	{
	public:
		Vector2f posicao;
		Vector2f tamanho;
	};

private:
	vector<InfoTiles> vetorTiles;

public:

	//Construtora e Destrutora
	GerenciadorColisoes();
	~GerenciadorColisoes();

	//Percorre laços verificando colisões com a entidade passado por parametro
	void VerificaColisoes(Entidade* aux);

	int checarColisao(Entidade* aux1, Entidade* aux2);

	//Faz os sets para os atributos
	void setListaEntidades(ListaEntidades* listaEnt);
	void setGerenciadorTiles(GerenciadorTiles* gTiles);

	void adicionarTile(InfoTiles aux);
	void limparTiles();
};

