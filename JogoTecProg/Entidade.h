#pragma once
#include "Ente.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"

class Entidade:
	public Ente
{
protected:

	//Gerenciadores
	GerenciadorEventos* gEv;

	//Vetores responsaveis pelo posi��o e velocidade da entidade
	Vector2f posicao;
	Vector2f v;
	Vector2f limite;
	
	//Caminho para a textura da entidade
	const char* caminho;

	static const float g;

	bool destruir = false;

public:
	//Construtora e destrutora
	Entidade(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = {0.0f, 0.0f}, const char* caminhoTextura = nullptr, Vector2f lim = { 0.0f, 0.0f });
	virtual ~Entidade();

	//Atualiza e desenha a entidade
	void atualizar(float t);
	void desenhar()final;

	//Fun��o virtual para mover o jogador
	virtual void mover(double t) = 0;

	//Retorna a posi��o da Entidade
	const sf::Vector2f getPos() const;
	
	//Seta a Posi��o da Entidade
	void setPos(const sf::Vector2f pos);

	void setVel(const Vector2f vel);
	const Vector2f getVel() const;

	//Seta o gerenciador de Eventos
	void setGEventos(GerenciadorEventos* gE);

	//Retorna as dimens�es da entidade
	const virtual Vector2f getTamEntidade() const = 0;

	virtual void setChao(const bool aux);
	const virtual bool getChao() const;

	void setDestruir(const bool aux);
	const bool getDestruir() const;

	virtual int colidir(int lado) = 0;

	virtual void desenharVidas();

	const virtual float getPontos() const;
};