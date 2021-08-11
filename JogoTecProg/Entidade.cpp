#include "Entidade.h"

Entidade::Entidade(Vector2f pos, Vector2f vel, const char* caminhoTextura):
	
	Ente(),
	posicao(pos), 
	v(vel), 
	caminho(caminhoTextura),
	gEv()

{
	gGrafico->carregarTextura(caminho);
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

void Entidade::desenhar()
{
	gGrafico->desenhar(caminho, posicao);
}

const sf::Vector2f Entidade::getPos() const
{
	return posicao;
}

void Entidade::setPos(const sf::Vector2f pos)
{
	posicao = pos;
}
Vector2f Entidade::getVel()
{
	return v;
}
void Entidade::setVel(Vector2f vel)
{
	v.y = vel.y;
}
void Entidade::setGEventos(GerenciadorEventos gE)
{
	gEv = gE;
	
}

void Entidade::setChao(bool aux)
{
}

bool Entidade::getChao()
{
	return false;
}

void Entidade::setDestruir(bool aux)
{
	destruir = aux;
}

bool Entidade::getDestruir()
{
	return destruir;
}

const float Entidade::g = 1200;


