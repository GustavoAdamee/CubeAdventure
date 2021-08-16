#pragma once
#include "Entidade.h"

class Personagem : public Entidade
{
protected:

public:
	Personagem(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, Vector2f lim = { 0.0f, 0.0f });

	virtual ~Personagem();

	virtual void mover(double t) = 0;

	const virtual Vector2f getTamEntidade() const = 0;

	virtual void setChao(const bool aux);
	const virtual bool getChao() const;

	virtual int colidir(int lado) = 0;

	virtual void desenharVidas();

	const virtual float getPontos() const;
};
