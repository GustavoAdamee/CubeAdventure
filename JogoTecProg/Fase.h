#pragma once

#include"CuboCowboy.h"
#include"CuboExplorador.h"
#include"Inseto.h"
#include"Aranha.h"
#include"ListaEntidades.h"
#include"Tiles.h"
#include"BlocoGrama.h"
#include"BlocoCaverna.h"
#include"GerenciadorGrafico.h"
#include"GerenciadorTiles.h"
using namespace Jogadores;

namespace Fases {

	class Fase
	{
	protected:
		//Entidades - Jogadores
		CuboCowboy* pJogador1;
		CuboExplorador* pJogador2;

		//Lista com entidades da fase
		ListaEntidades* listaEntidades;

		//Gerenciadores
		GerenciadorGrafico* gGraf;
		GerenciadorTiles* gTiles;

		//"Paths" dos arquivos para desenhar o mapa da fase
		const char* caminhoTile;
		const char* caminhoMapaTile;

		//Indicadora para caso a fase tenha sido concluida
		bool passaFase;

		//Privada pois nao precisa ser acessada de fora da classe
		void inicializaElementos();
	
	public:
		//Construtora e Destrutora
		Fase(CuboCowboy* pJ1, CuboExplorador* pJ2, GerenciadorGrafico& g, GerenciadorTiles& gTiles, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground);
		virtual ~Fase();

		//Inicializadoras Virtuais
		virtual void criarInimigos() = 0;
		virtual void criarObstaculos() = 0;
		virtual void criarPlataformas() = 0;
		
		//Retorna a fase atual
		virtual int getFaseAtual() = 0;

		//Retorna a lista de entidades
		ListaEntidades* getListaEntidades();

		//Funções para caso a fase tenha sido concluida
		void setPassouFase(bool aux);
		bool passouFase();
		void verificaFase();

		//Seta o mapa na tela
		void desenhaMapa();

	};
}