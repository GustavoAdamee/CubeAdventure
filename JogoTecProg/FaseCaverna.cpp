#include "FaseCaverna.h"

FaseCaverna::FaseCaverna(CuboCowboy* pJ1, CuboExplorador* pJ2, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground) :
	Fase(pJ1, pJ2, caminhoTile, caminhoMapaTile, caminhoBackground)
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
	insetoAux = new Inseto(Vector2f(400, 250), Vector2f(-50, 0), "images/inseto.png", Vector2f(300,430));
	listaEntidades->getLista().push(insetoAux);

	insetoAux = new Inseto(Vector2f(1100, 250), Vector2f(-50, 0), "images/inseto.png", Vector2f(970, 1170));
	listaEntidades->getLista().push(insetoAux);

	insetoAux = new Inseto(Vector2f(1450, 800), Vector2f(-20, 0), "images/inseto.png", Vector2f(1400, 1460));
	listaEntidades->getLista().push(insetoAux);
	
	//Inimigos aleatorios (66% de chance de spawn)
	if (rand() % 3 != 1) {
		insetoAux = new Inseto(Vector2f(100, 800), Vector2f(-50, 0), "images/inseto.png", Vector2f(50, 300));
		listaEntidades->getLista().push(insetoAux);
	}

	
	Aranha* aranhaAux = nullptr;
	
	//Spawn de Aranhas
	aranhaAux = new Aranha(Vector2f(700, 155), Vector2f(-60, 0), "images/aranha.png", Vector2f(570, 780));
	listaEntidades->getLista().push(aranhaAux);

	aranhaAux = new Aranha(Vector2f(1050, 455), Vector2f(-40, 0), "images/aranha.png", Vector2f(950, 1145));
	listaEntidades->getLista().push(aranhaAux);
	
	aranhaAux = new Aranha(Vector2f(1000, 655), Vector2f(-30, 0), "images/aranha.png", Vector2f(945, 1055));
	listaEntidades->getLista().push(aranhaAux);

	//Inimigos aleatorios (66% de chance de spawn)
	//if (rand() % 3 != 1) {
		aranhaAux = new Aranha(Vector2f(150, 605), Vector2f(-30, 0), "images/aranha.png", Vector2f(50, 180));
		listaEntidades->getLista().push(aranhaAux);
	//}

	//if (rand() % 3 != 1) {
		aranhaAux = new Aranha(Vector2f(1450, 305), Vector2f(-20, 0), "images/aranha.png", Vector2f(1405, 1495));
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
	blocoVoadorAux = new BlocoVoador(Vector2f(920, 53), Vector2f(0, 20), "images/blocoVoador.png", Vector2f(50, 180));
	listaEntidades->getLista().push(blocoVoadorAux);

	blocoVoadorAux = new BlocoVoador(Vector2f(600, 553), Vector2f(0, 45), "images/blocoVoador.png", Vector2f(550, 790));
	listaEntidades->getLista().push(blocoVoadorAux);

	blocoVoadorAux = new BlocoVoador(Vector2f(1350, 553), Vector2f(0, 35), "images/blocoVoador.png", Vector2f(550, 760));
	listaEntidades->getLista().push(blocoVoadorAux);

	//Obstaculo aleatorio(50 % de chance de spawn)
	if (rand() % 2 == 0) {
		blocoVoadorAux = new BlocoVoador(Vector2f(800, 503), Vector2f(0, 20), "images/blocoVoador.png", Vector2f(500, 690));
		listaEntidades->getLista().push(blocoVoadorAux);
	}
	//Obstaculo aleatorio(66 % de chance de spawn)
	if (rand() % 3 != 0) {
		blocoVoadorAux = new BlocoVoador(Vector2f(1200, 553), Vector2f(0, 20), "images/blocoVoador.png", Vector2f(550, 600));
		listaEntidades->getLista().push(blocoVoadorAux);
	}


}

void FaseCaverna::criarObstaculos()
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

int FaseCaverna::getFaseAtual()
{
	return 2;
}