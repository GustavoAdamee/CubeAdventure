#pragma once
#include "Jogador.h"
using namespace Jogadores;

class CuboCowboy : public Jogador
{
private:
	
	Vector2f tam = Vector2f(50, 70);

public:
	CuboCowboy(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr);
	~CuboCowboy();

	void mover();

	void desenhar();

	Vector2f getTamEntidade();

};
