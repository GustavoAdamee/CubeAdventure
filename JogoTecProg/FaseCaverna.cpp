#include "FaseCaverna.h"

FaseCaverna::FaseCaverna(CuboCowboy* pJ1, CuboExplorador* pJ2, GerenciadorTiles& gTiles, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground) :
	Fase(pJ1, pJ2, gTiles, caminhoTile, caminhoMapaTile, caminhoBackground)
{
	pJogador1->setPos(sf::Vector2f(50, 50));
	
	if (pJogador2) {
		pJogador2->setPos(sf::Vector2f(100, 100));
	}

	criarObstaculosDanosos();
	criarObstaculos();
	criarInimigos();	
}

FaseCaverna::~FaseCaverna()
{
}

void FaseCaverna::criarInimigos()
{
	Inseto* insetoAux = nullptr;

	//Spawn de Insetos
	insetoAux = new Inseto(Vector2f(400, 250), Vector2f(0, 0), "images/inseto.png");
	listaEntidades->getLista().push(insetoAux);

	insetoAux = new Inseto(Vector2f(1100, 250), Vector2f(0, 0), "images/inseto.png");
	listaEntidades->getLista().push(insetoAux);

	insetoAux = new Inseto(Vector2f(1450, 800), Vector2f(0, 0), "images/inseto.png");
	listaEntidades->getLista().push(insetoAux);
	
	//Inimigos aleatorios (66% de chance de spawn)
	//if (rand() % 3 != 1) {
		insetoAux = new Inseto(Vector2f(100, 800), Vector2f(0, 0), "images/inseto.png");
		listaEntidades->getLista().push(insetoAux);
	//}

	
	Aranha* aranhaAux = nullptr;
	
	//Spawn de Aranhas
	aranhaAux = new Aranha(Vector2f(700, 155), Vector2f(0, 0), "images/aranha.png");
	listaEntidades->getLista().push(aranhaAux);

	aranhaAux = new Aranha(Vector2f(1050, 455), Vector2f(0, 0), "images/aranha.png");
	listaEntidades->getLista().push(aranhaAux);
	
	aranhaAux = new Aranha(Vector2f(1000, 655), Vector2f(0, 0), "images/aranha.png");
	listaEntidades->getLista().push(aranhaAux);

	//Inimigos aleatorios (66% de chance de spawn)
	//if (rand() % 3 != 1) {
		aranhaAux = new Aranha(Vector2f(150, 605), Vector2f(0, 0), "images/aranha.png");
		listaEntidades->getLista().push(aranhaAux);
	//}

	//if (rand() % 3 != 1) {
		aranhaAux = new Aranha(Vector2f(1450, 305), Vector2f(0, 0), "images/aranha.png");
		listaEntidades->getLista().push(aranhaAux);
	//}

}

void FaseCaverna::criarObstaculosDanosos()
{
	Espinho* espinhoAux = nullptr;

	//Spawn de Espinhos
	espinhoAux = new Espinho(Vector2f(700, 450), Vector2f(0, 0), "images/espinho.png");
	listaEntidades->getLista().push(espinhoAux);

	espinhoAux = new Espinho(Vector2f(750, 450), Vector2f(0, 0), "images/espinho.png");
	listaEntidades->getLista().push(espinhoAux);

	espinhoAux = new Espinho(Vector2f(150, 400), Vector2f(0, 0), "images/espinho.png");
	listaEntidades->getLista().push(espinhoAux);


	//Obstaculo aleatorio(50 % de chance de spawn)
	if (rand() % 2 == 0) {
		espinhoAux = new Espinho(Vector2f(1300, 200), Vector2f(0, 0), "images/espinho.png");
		listaEntidades->getLista().push(espinhoAux);
	}


	BlocoVoador* blocoVoadorAux = nullptr;

	//Spawn de BlocosVoadores
	blocoVoadorAux = new BlocoVoador(Vector2f(900, 50), Vector2f(0, 0), "images/blocoVoador.png");
	listaEntidades->getLista().push(blocoVoadorAux);

	blocoVoadorAux = new BlocoVoador(Vector2f(600, 550), Vector2f(0, 0), "images/blocoVoador.png");
	listaEntidades->getLista().push(blocoVoadorAux);

	blocoVoadorAux = new BlocoVoador(Vector2f(1350, 550), Vector2f(0, 0), "images/blocoVoador.png");
	listaEntidades->getLista().push(blocoVoadorAux);

	//Obstaculo aleatorio(50 % de chance de spawn)
	if (rand() % 2 == 0) {
		blocoVoadorAux = new BlocoVoador(Vector2f(800, 500), Vector2f(0, 0), "images/blocoVoador.png");
		listaEntidades->getLista().push(blocoVoadorAux);
	}
	//Obstaculo aleatorio(66 % de chance de spawn)
	if (rand() % 3 != 0) {
		blocoVoadorAux = new BlocoVoador(Vector2f(1200, 550), Vector2f(0, 0), "images/blocoVoador.png");
		listaEntidades->getLista().push(blocoVoadorAux);
	}


}

void FaseCaverna::criarObstaculos()
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