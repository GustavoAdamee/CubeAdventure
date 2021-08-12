#include "FaseCavernaChefao.h"

FaseCavernaChefao::FaseCavernaChefao(CuboCowboy* pJ1, CuboExplorador* pJ2, GerenciadorTiles& gTiles, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground):
	Fase(pJ1, pJ2, gTiles, caminhoTile, caminhoMapaTile, caminhoBackground)
{
	pJogador1->setPos(sf::Vector2f(60, 780));
	
	if (pJogador2) {
		pJogador2->setPos(sf::Vector2f(120, 780));
	}

	criarObstaculos();
	criarObstaculosDanosos();
	criarInimigos();
}

FaseCavernaChefao::~FaseCavernaChefao()
{
}

void FaseCavernaChefao::criarInimigos()
{
	Inseto* insetoAux = nullptr;

	//Spawn de Insetos
	insetoAux = new Inseto(Vector2f(350, 800), Vector2f(0, 0), "images/inseto.png");
	listaEntidades->getLista().push(insetoAux);

	insetoAux = new Inseto(Vector2f(1150, 800), Vector2f(0, 0), "images/inseto.png");
	listaEntidades->getLista().push(insetoAux);

	insetoAux = new Inseto(Vector2f(900, 550), Vector2f(0, 0), "images/inseto.png");
	listaEntidades->getLista().push(insetoAux);

	//Inimigos aleatorios (66% de chance de spawn)
	//if (rand() % 3 != 1) {
		insetoAux = new Inseto(Vector2f(300, 550), Vector2f(0, 0), "images/inseto.png");
		listaEntidades->getLista().push(insetoAux);
	//}


	Aranha* aranhaAux = nullptr;

	//Spawn de Aranhas
	aranhaAux = new Aranha(Vector2f(700, 805), Vector2f(0, 0), "images/aranha.png");
	listaEntidades->getLista().push(aranhaAux);

	aranhaAux = new Aranha(Vector2f(1300, 555), Vector2f(0, 0), "images/aranha.png");
	listaEntidades->getLista().push(aranhaAux);

	aranhaAux = new Aranha(Vector2f(900, 755), Vector2f(0, 0), "images/aranha.png");
	listaEntidades->getLista().push(aranhaAux);

	//Inimigos aleatorios (66% de chance de spawn)
	//if (rand() % 3 != 1) {
		aranhaAux = new Aranha(Vector2f(550, 555), Vector2f(0, 0), "images/aranha.png");
		listaEntidades->getLista().push(aranhaAux);
	//}

	
	AranhaChefao* chefaoAux = nullptr;

	//Spawn do Chefao
	chefaoAux = new AranhaChefao(Vector2f(1100, 235), Vector2f(100, 0), "images/aranhaChefao.png", Vector2f(1000, 1110));
	listaEntidades->getLista().push(chefaoAux);
}

void FaseCavernaChefao::criarObstaculosDanosos()
{

	Espinho* espinhoAux = nullptr;

	//Spawn de Espinhos
	espinhoAux = new Espinho(Vector2f(650, 600), Vector2f(0, 0), "images/espinho.png");
	listaEntidades->getLista().push(espinhoAux);

	espinhoAux = new Espinho(Vector2f(700, 600), Vector2f(0, 0), "images/espinho.png");
	listaEntidades->getLista().push(espinhoAux);

	espinhoAux = new Espinho(Vector2f(1150, 600), Vector2f(0, 0), "images/espinho.png");
	listaEntidades->getLista().push(espinhoAux);
	espinhoAux = new Espinho(Vector2f(1200, 600), Vector2f(0, 0), "images/espinho.png");
	listaEntidades->getLista().push(espinhoAux);


	//Obstaculo aleatorio(50 % de chance de spawn)
	if (rand() % 2 == 0) {
		espinhoAux = new Espinho(Vector2f(1000, 800), Vector2f(0, 0), "images/espinho.png");
		listaEntidades->getLista().push(espinhoAux);
	}


	BlocoVoador* blocoVoadorAux = nullptr;

	//Spawn de BlocosVoadores
	blocoVoadorAux = new BlocoVoador(Vector2f(550, 650), Vector2f(0, 0), "images/blocoVoador.png");
	listaEntidades->getLista().push(blocoVoadorAux);

	blocoVoadorAux = new BlocoVoador(Vector2f(250, 50), Vector2f(0, 0), "images/blocoVoador.png");
	listaEntidades->getLista().push(blocoVoadorAux);

	blocoVoadorAux = new BlocoVoador(Vector2f(550, 50), Vector2f(0, 0), "images/blocoVoador.png");
	listaEntidades->getLista().push(blocoVoadorAux);

	//Obstaculo aleatorio(50 % de chance de spawn)
	if (rand() % 2 == 0) {
		blocoVoadorAux = new BlocoVoador(Vector2f(800, 400), Vector2f(0, 0), "images/blocoVoador.png");
		listaEntidades->getLista().push(blocoVoadorAux);
	}
	//Obstaculo aleatorio(66 % de chance de spawn)
	if (rand() % 3 != 0) {
		blocoVoadorAux = new BlocoVoador(Vector2f(400, 50), Vector2f(0, 0), "images/blocoVoador.png");
		listaEntidades->getLista().push(blocoVoadorAux);
	}

}

void FaseCavernaChefao::criarObstaculos()
{
	Tiles* pTile = new BlocoCaverna({ 0,0 }, { 0,0 }, caminhoTile, { 0,0 }, gTiles);
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

