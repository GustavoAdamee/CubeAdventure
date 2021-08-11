#include "GerenciadorColisoes.h"

GerenciadorColisoes::GerenciadorColisoes():
	gTiles(nullptr),
	listaEnt(nullptr)
{
}

GerenciadorColisoes::~GerenciadorColisoes()
{
	gTiles = nullptr;

	listaEnt = nullptr;

	limparTiles();
}

void GerenciadorColisoes::VerificaColisoes(Entidade* entidade)
{
	entidade->setChao(false);
	for (auto it = vetorTiles.begin(); it != vetorTiles.end(); it++) {
		
		Vector2f pos1 = entidade->getPos();
		Vector2f tam1 = entidade->getTamEntidade();
		Vector2f pos2 = (*it).posicao;
		Vector2f tam2 = (*it).tamanho;



		//por baixo do tile
		if (pos1.x + tam1.x > pos2.x && pos1.x < pos2.x + tam2.x &&
			pos1.y < pos2.y + tam2.y && pos1.y > pos2.y + tam2.y - 2) {

			entidade->setPos(Vector2f(pos1.x, pos2.y + tam2.y));
			if (entidade->getVel().y < 0) {
				entidade->setVel(Vector2f(entidade->getVel().x, 0));
			}
		}
		//pela esquerda do tile
		else if (pos1.x + tam1.x > pos2.x && pos1.x + tam1.x < pos2.x + tam2.x / 2 &&
			pos1.y + tam1.y > pos2.y + 2 && pos1.y < pos2.y + tam2.y) {

			entidade->setPos(Vector2f(pos2.x - tam1.x, pos1.y));
		}

		//pela direita do tile
		else if (pos1.x > pos2.x + tam2.x / 2 && pos1.x < pos2.x + tam2.x &&
			pos1.y + tam1.y > pos2.y + 2 && pos1.y < pos2.y + tam2.y) {

			entidade->setPos(Vector2f(pos2.x + tam2.x, pos1.y));
		}

		//por cima do tile
		else if (pos1.x + tam1.x > pos2.x && pos1.x < pos2.x + tam2.x &&
			pos1.y + tam1.y > pos2.y && pos1.y < pos2.y + 2) {

			entidade->setPos(Vector2f(pos1.x, pos2.y - tam1.y));
			entidade->setChao(true);
		}


	}


	//Verifica colisão das entidades
	for (int i = 0; i < listaEnt->getLista().getTam(); i++) {
		Entidade* pAux;
		pAux = listaEnt->getLista().getItem(i);
		checarColisao(entidade, pAux);
		//pAux->colidir(checarColisao(entidade, pAux));
	}
}

int GerenciadorColisoes::checarColisao(Entidade* aux1, Entidade* aux2)
{
	
	Vector2f pos1 = aux1->getPos();
	Vector2f tam1 = aux1->getTamEntidade();
	Vector2f pos2 = aux2->getPos();
	Vector2f tam2 = aux2->getTamEntidade();

	int i = 0;
	/*
	1 = colisao pela esquerda do aux2
	2 = colisao por cima do aux2
	3 = colisao pela direita do aux2
	4 = colisao por baixo do aux2
	*/

	if (tam1.y != tam2.y) {
		//pela esquerda do aux2
		if (pos1.x + tam1.x > pos2.x && pos1.x + tam1.x < pos2.x + tam2.x / 2 &&
		pos1.y + tam1.y > pos2.y + 2 && pos1.y < pos2.y + tam2.y) {

			aux1->setPos(Vector2f(pos2.x - tam1.x, pos1.y));
			return 1;
		}

		//pela direita do aux2
		else if (pos1.x > pos2.x + tam2.x / 2 && pos1.x < pos2.x + tam2.x &&
		pos1.y + tam1.y > pos2.y + 2 && pos1.y < pos2.y + tam2.y) {

			aux1->setPos(Vector2f(pos2.x + tam2.x, pos1.y));
			return 3;
		}

		//por cima do aux2
		else if (pos1.x + tam1.x > pos2.x && pos1.x < pos2.x + tam2.x &&
		pos1.y + tam1.y > pos2.y && pos1.y < pos2.y + 2) {

			aux1->setPos(Vector2f(pos1.x, pos2.y - tam1.y));

			aux1->setVel(Vector2f(aux1->getVel().x, 0));
			aux1->setChao(true);
			//listaEnt->getLista().pop(aux2);
			return 2;
		}


		//por baixo do aux2
		else if (pos1.x + tam1.x > pos2.x && pos1.x < pos2.x + tam2.x &&
		pos1.y < pos2.y + tam2.y && pos1.y > pos2.y + tam2.y - 2) {

			aux1->setPos(Vector2f(pos1.x, pos2.y + tam2.y));
			return 4;
		}
	
	}

	return 0;

}

void GerenciadorColisoes::setListaEntidades(ListaEntidades* listaEnt)
{
	this->listaEnt = listaEnt;
}

void GerenciadorColisoes::setGerenciadorTiles(GerenciadorTiles* gTiles)
{
	this->gTiles = gTiles;
}

void GerenciadorColisoes::adicionarTile(InfoTiles aux)
{
	vetorTiles.push_back(aux);
}

void GerenciadorColisoes::limparTiles()
{
	vetorTiles.clear();
}

