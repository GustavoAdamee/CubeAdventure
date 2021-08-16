#pragma once
#include "Inimigo.h"
using namespace Inimigos;

class Inseto : public Inimigo
{
private:
	
	Vector2f tam = Vector2f(50, 50);
	float chao = 0;

public:
	Inseto(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vector2f lim = { 0.0f, 0.0f });
	~Inseto();

	void mover(double t);

	const Vector2f getTamEntidade() const;

	int colidir(int lado);

	const float getPontos() const;

};

