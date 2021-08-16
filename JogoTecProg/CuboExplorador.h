#pragma once
#include "Jogador.h"
using namespace Jogadores;

class CuboExplorador : public Jogador
{
private:

	Vector2f tam = Vector2f(50, 70);

public:
	CuboExplorador(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr);
	~CuboExplorador();

	void mover(double t);

	const Vector2f getTamEntidade() const;

	void desenharVidas();

};


