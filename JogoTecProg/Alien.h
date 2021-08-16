#pragma once
#include "Inimigo.h"
#include "Atirador.h"
using namespace Inimigos;

class Alien :
    public Inimigo, public Atirador
{
private:
	
	Vector2f tam = Vector2f(200, 130);
	
	int vida = 3;

	double delayVida = 0;

	int projetil = 0;

public:
	
	Alien(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vector2f lim = { 0.0f, 0.0f });
	~Alien();

	void mover(double t);

	const Vector2f getTamEntidade() const;

	int colidir(int lado);

	Projetil* atirar();

	void desenharVidas();

	const float getPontos() const;

};




