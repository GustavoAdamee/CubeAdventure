#pragma once
#include "Fase.h"
#include "AranhaChefao.h"
using namespace Fases;
using namespace Jogadores;
using namespace Inimigos;

class FaseCavernaChefao : public Fase
{
private:

	AranhaChefao* aranhaChefao = NULL;

public:
	FaseCavernaChefao(CuboCowboy* pJ1, CuboExplorador* pJ2, GerenciadorTiles& gTiles, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground);
	~FaseCavernaChefao();

	void criarInimigos();

	void criarObstaculosDanosos();

	void criarObstaculos();

	void criarProjeteis();

	int getFaseAtual();
};

