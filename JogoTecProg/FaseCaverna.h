#pragma once
#include "Fase.h"
using namespace Fases;
using namespace Jogadores;
using namespace Inimigos;

class FaseCaverna : public Fase
{
private:

public:
	FaseCaverna(CuboCowboy* pJ1, CuboExplorador* pJ2, GerenciadorGrafico& g, GerenciadorTiles& gTiles, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground);
	~FaseCaverna();

	void criarInimigos();

	void criarObstaculos();

	void criarPlataformas();

	int getFaseAtual();

	void desenhar();

};

