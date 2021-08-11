#include "Fase.h"
using namespace Fases;

Fase::Fase(CuboCowboy* pJ1, CuboExplorador* pJ2, GerenciadorTiles& gTiles, const char* caminhoTile, const char* caminhoMapaTile, const char* caminhoBackground) :
	
	Ente(),
	gTiles(&gTiles),
	pJogador1(pJ1),
	pJogador2(nullptr),
	listaEntidades(nullptr),
	caminhoTile(caminhoTile),
	caminhoMapaTile(caminhoMapaTile),
	passaFase(false)

{
	gTiles.setCaminhos(caminhoTile, caminhoMapaTile);
	gGrafico->setBackground(caminhoBackground);
	
	gTiles.initTiles();
	
	if(pJ2 != nullptr){
		this->pJogador2 = pJ2;
	}
	
	listaEntidades = new ListaEntidades();

	passaFase = false;

	inicializaElementos();
}

Fase::~Fase()
{
	pJogador1 = nullptr;
	pJogador2 = nullptr;

	Entidade* pAux = NULL;
	for (int i = 0; i < listaEntidades->getLista().getTam(); i++)
	{
		pAux = listaEntidades->getLista().getItem(i);
		listaEntidades->getLista().pop(pAux);
	}
	pAux = nullptr;
	
	delete listaEntidades;
	listaEntidades = nullptr;	
}

int Fase::getFaseAtual()
{
	return 0;
}

ListaEntidades* Fase::getListaEntidades()
{
	return listaEntidades;
}

void Fase::setPassouFase(bool aux)
{
	passaFase = aux;
}

bool Fase::passouFase()
{
	return passaFase;
}


//Função/Metodo privado
void Fase::inicializaElementos()
{
	
	if(pJogador2!=nullptr){
		listaEntidades->getLista().push(static_cast<Entidade*>(pJogador1));
		listaEntidades->getLista().push(static_cast<Entidade*>(pJogador2));
	}
	else
	{
		listaEntidades->getLista().push(static_cast<Entidade*>(pJogador1));
	}
	
}
void Fase::verificaFase()	
{
	gGrafico->getJanela();
	if(pJogador2!=nullptr){
		if (pJogador1->getPos().x > gGrafico->getJanela()->getSize().x || pJogador2->getPos().x > gGrafico->getJanela()->getSize().x) {
			setPassouFase(true);
		}
	}
	else
	{
		if (pJogador1->getPos().x > gGrafico->getJanela()->getSize().x) {
			setPassouFase(true);
		}
	}
	
}

void Fase::desenhar()
{
	gGrafico->desenhaBackground();
	gTiles->desenhaListaTiles();
}
