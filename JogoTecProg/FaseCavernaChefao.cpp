#include "FaseCavernaChefao.h"

FaseCavernaChefao::FaseCavernaChefao(CuboCowboy* pJ1, CuboExplorador* pJ2, GerenciadorGrafico& g, GerenciadorTiles& gTiles, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground):
	Fase(pJ1, pJ2, g, gTiles, caminhoTile, caminhoMapaTile, caminhoBackground)
{
	pJogador1->setPos(sf::Vector2f(60, 780));
	
	if (pJogador2) {
		pJogador2->setPos(sf::Vector2f(120, 780));
	}

	criarPlataformas();
	criarObstaculos();
	criarInimigos();
}

FaseCavernaChefao::~FaseCavernaChefao()
{
}

void FaseCavernaChefao::criarInimigos()
{
	Inseto* insetoAux = nullptr;
	Aranha* aranhaAux = nullptr;
	AranhaChefao* chefaoAux = nullptr;

	for (int i = 1; i <= (rand() % 2 + 3); i++) {
		//Randomizar posicao do inimigo aqui
		insetoAux = new Inseto(Vector2f(i * 100 + 150, 800), Vector2f(0, 0), "images/inseto.png");
		insetoAux->setGGraf(*gGraf);
		listaEntidades->getLista().push(insetoAux);
	}

	for (int i = 1; i <= (rand() % 2 + 3); i++) {
		//Randomizar posicao do inimigo aqui
		aranhaAux = new Aranha(Vector2f(i * 100 + 650, 550), Vector2f(0, 0), "images/aranha.png");
		aranhaAux->setGGraf(*gGraf);
		listaEntidades->getLista().push(aranhaAux);
	}

	chefaoAux = new AranhaChefao(Vector2f(1100, 235), Vector2f(0, 0), "images/aranhaChefao.png");
	chefaoAux->setGGraf(*gGraf);
	listaEntidades->getLista().push(chefaoAux);
}

void FaseCavernaChefao::criarObstaculos()
{
}

void FaseCavernaChefao::criarPlataformas()
{
	Tiles* pTile = new BlocoCaverna({ 0,0 }, { 0,0 }, caminhoTile, gGraf, gTiles);
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 18; j++) {
			if (gTiles->getInfo(i, j) != -1) {
				pTile->initTile(i, j);
			}
		}
	}
}

int FaseCavernaChefao::getFaseAtual()
{
	return 3;
}

void FaseCavernaChefao::desenhar()
{
}
