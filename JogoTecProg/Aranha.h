#pragma once
#include "Inimigo.h"
using namespace Inimigos;

class Aranha :
	public Inimigo
{
private:
	Vector2f tam = Vector2f (50, 45);
public:
	Aranha(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vector2f lim = { 0.0f, 0.0f });
	~Aranha();

	void mover(double t);

	Vector2f getTamEntidade();
	
	int colidir(int lado);
	

};

