#pragma once
#include "Ente.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorEventos.h"

class Entidade:
	public Ente
{
protected:

	//Gerenciadores
	GerenciadorEventos gEv;
	//GerenciadorGrafico* gGraf;

	//Vetores responsaveis pelo posição e velocidade da entidade
	Vector2f posicao;
	Vector2f v;
	Vector2f limite;
	
	//"Path" para a textura da entidade
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

	//Função virtual para mover o jogador
	virtual void mover(double t) = 0;

	//Retorna a posição da Entidade
	const sf::Vector2f getPos() const;
	
	//Seta a Posição da Entidade
	void setPos(const sf::Vector2f pos);

	void setVel(Vector2f vel);
	Vector2f getVel();

	//Seta o gerenciador de Eventos
	void setGEventos(GerenciadorEventos gE);

	//Retorna as dimensões da entidade
	virtual Vector2f getTamEntidade() = 0;

	virtual void setChao(bool aux);
	virtual bool getChao();

	void setDestruir(bool aux);
	bool getDestruir();

	virtual int colidir(int lado) = 0;

	//Metodo virtual responsavel para verificar se a entidade em questão colidiu com a entidade passada por referencia
	//virtual void colidir(Entidade* entidade) = 0;
};