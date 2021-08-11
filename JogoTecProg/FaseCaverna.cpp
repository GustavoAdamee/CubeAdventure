#include "FaseCaverna.h"

FaseCaverna::FaseCaverna(CuboCowboy* pJ1, CuboExplorador* pJ2, GerenciadorTiles& gTiles, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground) :
	Fase(pJ1, pJ2, gTiles, caminhoTile, caminhoMapaTile, caminhoBackground)
{
	pJogador1->setPos(sf::Vector2f(50, 50));
	
	if (pJogador2) {
		pJogador2->setPos(sf::Vector2f(100, 100));
	}

	criarPlataformas();
	criarObstaculos();
	criarInimigos();	
}

FaseCaverna::~FaseCaverna()
{
}

void FaseCaverna::criarInimigos()
{
	Inseto* insetoAux = nullptr;
	Aranha* aranhaAux = nullptr;

	for (int i = 1; i <= (rand() % 2 + 3); i++) {
		insetoAux = new Inseto(Vector2f(i * 70, 800), Vector2f(0, 0), "images/inseto.png");
		listaEntidades->getLista().push(insetoAux);
	}
	
	for (int i = 1; i <= (rand() % 2 + 3); i++) {
		aranhaAux = new Aranha(Vector2f(i * 100 + 500, 150), Vector2f(0, 0), "images/aranha.png");
		listaEntidades->getLista().push(aranhaAux);
	}
}

void FaseCaverna::criarObstaculos()
{

}

void FaseCaverna::criarPlataformas()
{
	Tiles* pTile = new BlocoCaverna({ 0,0 }, { 0,0 }, caminhoTile, gTiles);
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 18; j++) {
			if (gTiles->getInfo(i, j) != -1) {
				pTile->initTile(i, j);
			}
		}
	}
}

int FaseCaverna::getFaseAtual()
{
	return 2;
}