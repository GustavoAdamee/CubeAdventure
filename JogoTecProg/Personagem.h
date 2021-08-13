#pragma once
#include "Entidade.h"

class Personagem : public Entidade
{
protected:

public:
	Personagem(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vector2f lim = { 0.0f, 0.0f });

	~Personagem();

	virtual void mover(double t) = 0;

	virtual Vector2f getTamEntidade() = 0;

	virtual void setChao(bool aux);
	virtual bool getChao();

	virtual int colidir(int lado) = 0;

	virtual void desenharVidas();

	virtual float getPontos();
};
