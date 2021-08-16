#pragma once
#include "Personagem.h"

namespace Jogadores {

	class Jogador : public Personagem
	{
	protected:
	
		bool chao = true;
		
		int vida = 3;

		double delay = 0;

	public:

		//Construtora e destrutora
		Jogador(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = { 0.0f, 0.0f }, const char* caminhoTextura = nullptr);
		virtual ~Jogador();

		//Move o jogador conforme seu movimento proprio
		virtual void mover(double t) = 0;

		const virtual Vector2f getTamEntidade() const = 0;

		void setChao(const bool aux);
		const bool getChao() const;

		int colidir(int lado);

		void resetaVida();

		const int getVida() const;

		virtual void desenharVidas();

		const float getPontos() const;

	};

}
