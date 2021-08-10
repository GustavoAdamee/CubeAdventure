#pragma once
#include "Entidade.h"

class Personagem : public Entidade
{
protected:

public:
	Personagem(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr);

	~Personagem();

	virtual void mover() = 0;

	virtual Vector2f getTamEntidade() = 0;
};
