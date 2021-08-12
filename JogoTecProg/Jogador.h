#pragma once
#include "Personagem.h"

namespace Jogadores {

	class Jogador : public Personagem
	{
	protected:
		bool chao = true;
		int vida = 3;

	public:

		//Construtora e destrutora
		Jogador(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr);
		~Jogador();

		//Move o jogador conforme seu movimento proprio
		virtual void mover(double t) = 0;

		virtual Vector2f getTamEntidade() = 0;

		void setChao(bool aux);
		bool getChao();

		int colidir(int lado);

	};

}
