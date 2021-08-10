#include "Entidade.h"

Entidade::Entidade(Vector2f pos, Vector2f vel, const char* caminhoTextura):
	
	Ente(),
	posicao(pos), 
	v(vel), 
	caminho(caminhoTextura),
	gEv()

{

}

Entidade::~Entidade()
{

}

void Entidade::setGGraf(GerenciadorGrafico& g)
{
	g.carregarTextura(caminho);
}

void Entidade::atualizar(float t)
{
	posicao += v * t;
}

void Entidade::desenhar(GerenciadorGrafico& g)
{
	g.desenhar(caminho, posicao);
}

const sf::Vector2f Entidade::getPos() const
{
	return posicao;
}

void Entidade::setPos(const sf::Vector2f pos)
{
	posicao = pos;
}
void Entidade::setGEventos(GerenciadorEventos gE)
{
	gEv = gE;
	
}




