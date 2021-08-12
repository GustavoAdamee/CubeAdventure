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
	delayVida += t;

}


Vector2f AranhaChefao::getTamEntidade()
{
	return tam;
}

int AranhaChefao::colidir(int lado)
{
	if (lado == 2 && delayVida > 1.5) {
		vida--;
		delayVida = 0;
		if (vida == 0) {
			destruir = true;
		}
		return 0;
	}
	else if (lado == 0 || lado == 2) {
		return 0;
	}
	return 1;
}

Projetil* AranhaChefao::atirar()
{
	
	Projetil* projetilAux = nullptr;

	if (delayAtirar > 1.5) {
		
		if (projetil == 0) {
			projetilAux = new Projetil(Vector2f(posicao.x + 50, posicao.y + 70), Vector2f(-150, 0), "images/orbFogo.png", Vector2f(50, 50));
			projetil = 1;
		}
		else if(projetil == 1){
			projetilAux = new Projetil(Vector2f(posicao.x + 50, posicao.y + 70), Vector2f(-150, -100), "images/orbFogo.png", Vector2f(50, 50));
			projetil = 2;
		}
		else {
			if (rand() % 3) {
				projetilAux = new Projetil(Vector2f(posicao.x + 50, posicao.y + 70), Vector2f(0, -150), "images/orbFogo.png", Vector2f(50, 50));
			}
			else {
				projetilAux = new Projetil(Vector2f(posicao.x + 50, posicao.y + 70), Vector2f(50, -150), "images/orbFogo.png", Vector2f(50, 50));
			}
			projetil = 0;
		}
		delayAtirar = 0;
	}

	return projetilAux;
}

void AranhaChefao::desenharVidas()
{
	gGrafico->carregarTextura("images/vidaChefao.png");

	if (vida >= 1) {

		gGrafico->desenhar("images/vidaChefao.png", Vector2f(posicao.x+30, 60));

	}

	if (vida >= 2) {

		gGrafico->desenhar("images/vidaChefao.png", Vector2f(posicao.x + 70, 60));

	}

	if (vida >= 3) {

		gGrafico->desenhar("images/vidaChefao.png", Vector2f(posicao.x + 110, 60));

	}
}
