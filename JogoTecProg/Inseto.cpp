#include "Inseto.h"

Inseto::Inseto(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim) :
	Inimigo(pos, vel, caminhoTextura, lim),
	chao(pos.y)
{

}

Inseto::~Inseto()
{
}

void Inseto::mover(double t)
{
	if (posicao.y > chao) {
		posicao.y = chao;
		v.y = 0;
	}
	else if (posicao.y < chao) {
		v.y += g * t;
	}
	if ((chao == posicao.y) && (rand() % 1000 == 0)) {
		v.y = -350;
	}
	if (posicao.x <= limite.x) {
		v.x = fabsf(v.x);
	}
	else if (posicao.x >= limite.y) {
		v.x = -fabsf(v.x);
	}

}

Vector2f Inseto::getTamEntidade()
{
	return tam;
}

int Inseto::colidir(int lado)
{
	if (lado == 2) {
		destruir = true;
		return 0;
	}
	else if (lado == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

