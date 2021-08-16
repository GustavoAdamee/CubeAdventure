#include "FaseGrama.h"
using namespace Jogadores;
using namespace Fases;
using namespace Inimigos;

FaseGrama::FaseGrama(CuboCowboy* pJ1, CuboExplorador* pJ2, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground) :
	Fase(pJ1, pJ2, caminhoTile, caminhoMapaTile, caminhoBackground)
{
	pJogador1->setPos(sf::Vector2f(130, 780));
	
	if (pJogador2 != nullptr) {
		pJogador2->setPos(sf::Vector2f(70, 780));
	}
	

	criarObstaculos();
	criarObstaculosDanosos();
	criarInimigos();
}

FaseGrama::~FaseGrama()
{

}

void FaseGrama::criarInimigos()
{
	Inseto* insetoAux = nullptr;

	//Spawn de Insetos
	insetoAux = new Inseto(Vector2f(900, 700), Vector2f(-60, 0), "images/inseto.png", Vector2f(800, 1000)); //lim em x
	listaEntidades->getLista().push(insetoAux);

	insetoAux = new Inseto(Vector2f(800, 500), Vector2f(-50, 0), "images/inseto.png", Vector2f(750, 1000));
	listaEntidades->getLista().push(insetoAux);

	insetoAux = new Inseto(Vector2f(400, 400), Vector2f(-50, 0), "images/inseto.png", Vector2f(250, 450));
	listaEntidades->getLista().push(insetoAux);

	//Inimigos aleatorios (66% de chance de spawn)
	if (rand() % 3 != 1) {
		insetoAux = new Inseto(Vector2f(1300, 250), Vector2f(-50, 0), "images/inseto.png", Vector2f(1150, 1500));
		listaEntidades->getLista().push(insetoAux);
	}
	


	Aranha* aranhaAux = nullptr;

	//Spawn de Aranhas

	aranhaAux = new Aranha(Vector2f(1170,705), Vector2f(-50, 0), "images/aranha.png", Vector2f(1130, 1200));
	listaEntidades->getLista().push(aranhaAux);

	aranhaAux = new Aranha(Vector2f(1000, 205), Vector2f(-50, 0), "images/aranha.png", Vector2f(950, 1030));
	listaEntidades->getLista().push(aranhaAux);


	aranhaAux = new Aranha(Vector2f(750, 205), Vector2f(-50, 0), "images/aranha.png", Vector2f(700, 800));
	listaEntidades->getLista().push(aranhaAux);
	
	//Inimigos aleatorios (50% de chance de spawn)
	if (rand() % 2 != 1) {
		aranhaAux = new Aranha(Vector2f(1320, 505), Vector2f(-50, 0), "images/aranha.png", Vector2f(1300, 1400));
		listaEntidades->getLista().push(aranhaAux);
	}

	

	insetoAux = nullptr;
	aranhaAux = nullptr;

}

void FaseGrama::criarObstaculosDanosos()
{
	Espinho* espinhoAux = nullptr;
	
	//Spawn de Espinhos
	espinhoAux = new Espinho(Vector2f(650, 800), Vector2f(0, 0), "images/espinho.png");
	listaEntidades->getLista().push(espinhoAux);
	
	espinhoAux = new Espinho(Vector2f(700, 800), Vector2f(0, 0), "images/espinho.png");
	listaEntidades->getLista().push(espinhoAux);
	
	espinhoAux = new Espinho(Vector2f(850, 250), Vector2f(0, 0), "images/espinho.png");
	listaEntidades->getLista().push(espinhoAux);

	espinhoAux = new Espinho(Vector2f(900, 250), Vector2f(0, 0), "images/espinho.png");
	listaEntidades->getLista().push(espinhoAux);

	//Obstaculo aleatorio(50 % de chance de spawn)
	if (rand() % 2 == 0) {
		espinhoAux = new Espinho(Vector2f(650, 500), Vector2f(0, 0), "images/espinho.png");
		listaEntidades->getLista().push(espinhoAux);
	}
	

	BlocoVoador* blocoVoadorAux = nullptr;
	
	//Spawn de BlocosVoadores
	blocoVoadorAux = new BlocoVoador(Vector2f(400, 600), Vector2f(0, 50), "images/blocoVoador.png", Vector2f(600, 700)); //lim em y
	listaEntidades->getLista().push(blocoVoadorAux);

	blocoVoadorAux = new BlocoVoador(Vector2f(300, 50), Vector2f(0, 50), "images/blocoVoador.png", Vector2f(50, 150));
	listaEntidades->getLista().push(blocoVoadorAux);

	blocoVoadorAux = new BlocoVoador(Vector2f(600, 50), Vector2f(0, 50), "images/blocoVoador.png", Vector2f(50, 150));
	listaEntidades->getLista().push(blocoVoadorAux);

	if (rand() % 3 != 0) {
		blocoVoadorAux = new BlocoVoador(Vector2f(450, 50), Vector2f(0, 60), "images/blocoVoador.png", Vector2f(50, 180));
		listaEntidades->getLista().push(blocoVoadorAux);
	}
	
	espinhoAux = nullptr;
	blocoVoadorAux = nullptr;

}

void FaseGrama::criarObstaculos()
{
	Tiles* pTile = new BlocoGrama({ 0,0 }, { 0,0 }, caminhoTile, { 0,0 }, gTiles);
	for (int i = 0; i < 32; i++) {
		for (int j = 0; j < 18; j++) {
			if (gTiles->getInfo(i, j) != -1) {
				pTile->initTile(i, j);
			}
		}
	}

	pTile = nullptr;

}

const int FaseGrama::getFaseAtual() const
{
	return 1;
}

