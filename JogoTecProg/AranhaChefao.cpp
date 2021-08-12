#include "AranhaChefao.h"


AranhaChefao::AranhaChefao(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim) :
	Inimigo(pos, vel, caminhoTextura, lim),
	Atirador()
{
}

AranhaChefao::~AranhaChefao()
{
}

void AranhaChefao::mover(double t)
{
	if (posicao.x <= limite.x ) {
		v.x = fabs(v.x);
	}
	
	else if (posicao.x >= limite.y) {
		v.x = -fabs(v.x);
	}

	delayAtirar += t;

}


Vector2f AranhaChefao::getTamEntidade()
{
	return tam;
}

int AranhaChefao::colidir(int lado)
{
	if (lado == 2) {
		vida--;
		if (vida == 0) {
			destruir = true;
		}
		return 0;
	}
	else if (lado == 0) {
		return 0;
	}
	return 1;
}

Projetil* AranhaChefao::atirar()
{

	int projetil;
	
	Projetil* projetilAux = nullptr;

	if (delayAtirar > 2) {
		
		printf("atirar aranhaChefao");

		projetilAux = new Projetil(Vector2f(1000,1000), Vector2f(-50, 0), "images/orbFogo.png", Vector2f(posicao.x - 300, 50));

		delayAtirar = 0;
	}

	return projetilAux;
}
