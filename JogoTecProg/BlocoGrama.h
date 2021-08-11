#pragma once
#include "Tiles.h"


class BlocoGrama :
	public Tiles
{
private:

public:
	BlocoGrama(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr, GerenciadorTiles* gTiles = nullptr);
	~BlocoGrama();

	
	Vector2f getTamEntidade();

};

