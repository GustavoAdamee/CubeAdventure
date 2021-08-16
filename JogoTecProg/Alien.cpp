#include "Alien.h"


Alien::Alien(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim) :
	Inimigo(pos, vel, caminhoTextura, lim),
	Atirador()
{
}

Alien::~Alien()
{
}


void Alien::mover(double t)
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


const Vector2f Alien::getTamEntidade() const
{
	return tam;
}

int Alien::colidir(int lado)
{
	if (lado == 2 && delayVida > 1.5) { //Colisao por cima apos o delay
		vida--;
		delayVida = 0;
		if (vida == 0) {
			destruir = true;
		}
		return 0;
	}
	else if (lado == 0 || lado == 2) { //Sem colisao ou colisao por cima durante delay
		return 0;
	}
	return 1;
}

Projetil* Alien::atirar()
{
	
	Projetil* projetilAux = nullptr;

	if (delayAtirar > 1.5) {
		
		if (projetil == 0) { //Projetil frente
			projetilAux = new Projetil(Vector2f(posicao.x + 50, posicao.y + 70), Vector2f(-150, 0), "images/orbFogo.png", Vector2f(50, 50));
			projetil = 1;
		}
		else if(projetil == 1){ //Projetil diagonal frente
			projetilAux = new Projetil(Vector2f(posicao.x + 50, posicao.y + 70), Vector2f(-150, -100), "images/orbFogo.png", Vector2f(50, 50));
			projetil = 2;
		}
		else {
			if (rand() % 3) { // Projetil cima
				projetilAux = new Projetil(Vector2f(posicao.x + 50, posicao.y + 70), Vector2f(0, -150), "images/orbFogo.png", Vector2f(50, 50));
			}
			else { //Projetil diagonal atrás
				projetilAux = new Projetil(Vector2f(posicao.x + 50, posicao.y + 70), Vector2f(50, -150), "images/orbFogo.png", Vector2f(50, 50));
			}
			projetil = 0;
		}
		delayAtirar = 0;
	}

	return projetilAux;
}

void Alien::desenharVidas()
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


const float Alien::getPontos() const
{
	if (destruir) { //Chefao neutralizado
		return 500.0f;
	}
	
	return 0.0f;
}
