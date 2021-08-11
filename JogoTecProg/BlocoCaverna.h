#pragma once
#include "Tiles.h"

class BlocoCaverna:
	public Tiles
{
private:

public:
	BlocoCaverna(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, GerenciadorTiles* gTiles = nullptr);
	~BlocoCaverna();

	Vector2f getTamEntidade();
};


