#include "FaseGrama.h"
using namespace Jogadores;
using namespace Fases;
using namespace Inimigos;

FaseGrama::FaseGrama(CuboCowboy* pJ1, CuboExplorador* pJ2, GerenciadorGrafico& g, GerenciadorTiles& gTiles, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground) :
	Fase(pJ1, pJ2, g, gTiles, caminhoTile, caminhoMapaTile, caminhoBackground)
{
	pJogador1->setPos(sf::Vector2f(130, 780));
	
	if (pJogador2 != nullptr) {
		pJogador2->setPos(sf::Vector2f(70, 780));
	}
	

	criarPlataformas();
	criarObstaculos();
	criarInimigos();
}

FaseGrama::~FaseGrama()
{

}

void FaseGrama::criarInimigos()
{
	Inseto* insetoAux = nullptr;
	Aranha* aranhaAux = nullptr;

	for (int i = 1; i <= (rand() % 2 + 3); i++) {
		//Randomizar posicao do inimigo aqui
		insetoAux = new Inseto(Vector2f(i*300, 250), Vector2f(0, 0), "images/inseto.png");
		insetoAux->setGGraf(*gGraf);
		listaEntidades->getLista().push(insetoAux);
	}

	for (int i = 1; i <= (rand() % 2 + 3); i++) {
		aranhaAux = new Aranha(Vector2f(i*200+200, 805), Vector2f(0, 0), "images/aranha.png");
		aranhaAux->setGGraf(*gGraf);
		listaEntidades->getLista().push(aranhaAux);
	}
}

void FaseGrama::criarObstaculos()
{
}

void FaseGrama::criarPlataformas()
{
	Tiles* pTile = new BlocoGrama({ 0,0 }, { 0,0 }, caminhoTile, gGraf, gTiles);
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 18; j++) {
			if (gTiles->getInfo(i, j) != -1) {
				pTile->initTile(i, j);
			}
		}
	}
}

int FaseGrama::getFaseAtual()
{
	return 1;
}


