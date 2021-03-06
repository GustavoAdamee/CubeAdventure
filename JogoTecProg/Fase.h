#pragma once

#include"Ente.h"
#include"CuboCowboy.h"
#include"CuboExplorador.h"
#include"Inseto.h"
#include"Aranha.h"
#include"ListaEntidades.h"
#include"Tiles.h"
#include"BlocoGrama.h"
#include"BlocoCaverna.h"
#include"Espinho.h"
#include"BlocoVoador.h"
#include"GerenciadorGrafico.h"
#include"GerenciadorTiles.h"

using namespace Jogadores;

namespace Fases {

	class Fase:
		public Ente
	{
	protected:
		//Entidades - Jogadores
		CuboCowboy* pJogador1;
		CuboExplorador* pJogador2;

		//Lista com entidades da fase
		ListaEntidades* listaEntidades;

		//Gerenciadores
		static GerenciadorTiles* gTiles;

		//Caminho dos arquivos para desenhar o mapa da fase
		const char* caminhoTile;
		const char* caminhoMapaTile;

		//Indicadora para caso a fase tenha sido concluida
		bool passaFase;

		//Privada pois nao precisa ser acessada de fora da classe
		void inicializaElementos();
	
	public:
		//Construtora e Destrutora
		Fase(CuboCowboy* pJ1, CuboExplorador* pJ2, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground);
		virtual ~Fase();

		//Inicializadoras Virtuais
		virtual void criarInimigos();
		virtual void criarObstaculosDanosos();
		virtual void criarObsataculos();
		virtual void criarProjeteis();
		
		//Retorna a fase atual
		const virtual int getFaseAtual() const = 0;

		//Retorna a lista de entidades
		ListaEntidades* getListaEntidades();

		//Fun??es para caso a fase tenha sido concluida
		void setPassouFase(const bool aux);
		bool passouFase();
		void verificaFase();

		//Seta o mapa na tela
		void desenhar()final;

		//Seta um gerenciador de tiles para todas as fases
		static void setGTiles(GerenciadorTiles* gT);

	};
}