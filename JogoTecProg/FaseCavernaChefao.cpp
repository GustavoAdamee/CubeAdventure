#include "FaseCavernaChefao.h"

FaseCavernaChefao::FaseCavernaChefao(CuboCowboy* pJ1, CuboExplorador* pJ2, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground):
	Fase(pJ1, pJ2, caminhoTile, caminhoMapaTile, caminhoBackground)
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
	insetoAux = new Inseto(Vector2f(350, 800), Vector2f(-25, -300), "images/inseto.png", Vector2f(250, 430));
	listaEntidades->getLista().push(insetoAux);

	insetoAux = new Inseto(Vector2f(1150, 800), Vector2f(-30, -300), "images/inseto.png", Vector2f(1100, 1250));
	listaEntidades->getLista().push(insetoAux);

	insetoAux = new Inseto(Vector2f(900, 550), Vector2f(25, -300), "images/inseto.png", Vector2f(850, 980));
	listaEntidades->getLista().push(insetoAux);

	//Inimigos aleatorios (66% de chance de spawn)
	if (rand() % 3 != 1) {
		insetoAux = new Inseto(Vector2f(300, 550), Vector2f(-20, -300), "images/inseto.png", Vector2f(255, 340));
		listaEntidades->getLista().push(insetoAux);
	}


	Aranha* aranhaAux = nullptr;

	//Spawn de Aranhas
	aranhaAux = new Aranha(Vector2f(700, 805), Vector2f(-25, 0), "images/aranha.png", Vector2f(610,790));
	listaEntidades->getLista().push(aranhaAux);

	aranhaAux = new Aranha(Vector2f(1300, 555), Vector2f(20, 0), "images/aranha.png", Vector2f(1263, 1348));
	listaEntidades->getLista().push(aranhaAux);

	aranhaAux = new Aranha(Vector2f(900, 755), Vector2f(18, 0), "images/aranha.png", Vector2f(900,947));
	listaEntidades->getLista().push(aranhaAux);

	//Inimigos aleatorios (66% de chance de spawn)
	if (rand() % 3 != 1) {
		aranhaAux = new Aranha(Vector2f(550, 555), Vector2f(-25, 0), "images/aranha.png", Vector2f(503, 596));
		listaEntidades->getLista().push(aranhaAux);
	}

	//Spawn do Chefao
	alienAux = new Alien(Vector2f(1100, 235), Vector2f(50, 0), "images/alien.png", Vector2f(1000, 1110));
	listaEntidades->getLista().push(alienAux);
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
	blocoVoadorAux = new BlocoVoador(Vector2f(550, 652), Vector2f(0, 20), "images/blocoVoador.png", Vector2f(652, 760));
	listaEntidades->getLista().push(blocoVoadorAux);

	blocoVoadorAux = new BlocoVoador(Vector2f(250, 53), Vector2f(0, 45), "images/blocoVoador.png", Vector2f(53, 270));
	listaEntidades->getLista().push(blocoVoadorAux);

	blocoVoadorAux = new BlocoVoador(Vector2f(550, 53), Vector2f(0, 45), "images/blocoVoador.png", Vector2f(53, 270));
	listaEntidades->getLista().push(blocoVoadorAux);

	//Obstaculo aleatorio(50 % de chance de spawn)
	if (rand() % 2 == 0) {
		blocoVoadorAux = new BlocoVoador(Vector2f(800, 403), Vector2f(0, 20), "images/blocoVoador.png", Vector2f(403,560));
		listaEntidades->getLista().push(blocoVoadorAux);
	}
	
	//Obstaculo aleatorio(66 % de chance de spawn)
	if (rand() % 3 != 0) {
		blocoVoadorAux = new BlocoVoador(Vector2f(400, 53), Vector2f(0, 35), "images/blocoVoador.png", Vector2f(53, 270));
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

void FaseCavernaChefao::criarProjeteis()
{
	if (alienAux) {
		Projetil* pAux = nullptr;

		pAux = alienAux->atirar();

		if (pAux) {

			listaEntidades->getLista().push(pAux);

		}
	}	
	if (alienAux->getDestruir()) {
		passaFase = true;
	}
	
}

const int FaseCavernaChefao::getFaseAtual() const
{
	return 3;
}

