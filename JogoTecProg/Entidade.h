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

	//Vetores responsaveis pelo posi��o e velocidade da entidade
	Vector2f posicao;
	Vector2f v;
	
	//"Path" para a textura da entidade
	const char* caminho;

public:
	//Construtora e destrutora
	Entidade(Vector2f pos = { 0.0f, 0.0f }, Vector2f vel = {0.0f, 0.0f}, const char* caminhoTextura = nullptr);
	virtual ~Entidade();

	//seta o gerenciador e carrega a textura
	void setGGraf(GerenciadorGrafico& g);

	//Atualiza e desenha a entidade
	void atualizar(float t);
	void desenhar(GerenciadorGrafico& g);

	//Fun��o virtual para mover o jogador
	virtual void mover() = 0;

	//Retorna a posi��o da Entidade
	const sf::Vector2f getPos() const;
	//Seta a Posi��o da Entidade
	void setPos(const sf::Vector2f pos);

	//Seta o gerenciador de Eventos
	void setGEventos(GerenciadorEventos gE);

	//Retorna as dimens�es da entidade
	virtual Vector2f getTamEntidade() = 0;

	//Metodo virtual responsavel para verificar se a entidade em quest�o colidiu com a entidade passada por referencia
	//virtual void colidir(Entidade* entidade) = 0;
};

