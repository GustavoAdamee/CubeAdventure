#pragma once
#include "Fase.h"
#include "AranhaChefao.h"
using namespace Fases;
using namespace Jogadores;
using namespace Inimigos;

class FaseCavernaChefao : public Fase
{
private:

public:
	FaseCavernaChefao(CuboCowboy* pJ1, CuboExplorador* pJ2, GerenciadorGrafico& g, GerenciadorTiles& gTiles, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground);
	~FaseCavernaChefao();

	void criarInimigos();

	void criarObstaculos();

	void criarPlataformas();

	int getFaseAtual();
	
	void desenhar();
};

