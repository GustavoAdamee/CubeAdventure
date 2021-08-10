#pragma once
#include "Fase.h"
using namespace Fases;
using namespace Jogadores;
using namespace Inimigos;

class FaseGrama : public Fase
{
private:

public:
	FaseGrama(CuboCowboy* pJ1, CuboExplorador* pJ2, GerenciadorGrafico& g, GerenciadorTiles& gTiles, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground);
	~FaseGrama();

	void criarInimigos();

	void criarObstaculos();

	void criarPlataformas();

	int getFaseAtual();

};


