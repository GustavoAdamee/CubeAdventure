#pragma once
#include "Inimigo.h"
#include "Atirador.h"
using namespace Inimigos;

class AranhaChefao :
    public Inimigo, public Atirador
{
private:
	Vector2f tam = Vector2f(200, 130);
public:
	AranhaChefao(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr);
	~AranhaChefao();

	void mover();

	void desenhar();

	Vector2f getTamEntidade();

};

