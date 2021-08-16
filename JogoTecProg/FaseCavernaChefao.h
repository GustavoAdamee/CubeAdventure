#pragma once
#include "Fase.h"
#include "Alien.h"
using namespace Fases;
using namespace Jogadores;
using namespace Inimigos;

class FaseCavernaChefao : public Fase
{
private:

	Alien* alienAux = NULL;

public:
	FaseCavernaChefao(CuboCowboy* pJ1, CuboExplorador* pJ2, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground);
	~FaseCavernaChefao();

	void criarInimigos();

	void criarObstaculosDanosos();

	void criarObstaculos();

	void criarProjeteis();

	const int getFaseAtual() const;
};

