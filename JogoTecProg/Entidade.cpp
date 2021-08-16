#include "Entidade.h"

Entidade::Entidade(Vector2f pos, Vector2f vel, const char* caminhoTextura, Vector2f lim):
	
	Ente(),
	posicao(pos), 
	v(vel), 
	caminho(caminhoTextura),
	gEv(),
	limite(lim)

{
	gGrafico->carregarTextura(caminho);
}

Entidade::~Entidade()
{

}


void Entidade::atualizar(float t)
{
	posicao += v * t;
	//posicao.x += v.x * t;
	//posicao.y += v.y * t;
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
const Vector2f Entidade::getVel() const
{
	return v;
}
void Entidade::setVel(const Vector2f vel)
{
	v.x = vel.x;
	v.y = vel.y;
}
void Entidade::setGEventos(GerenciadorEventos* gE)
{
	gEv = gE;
	
}

void Entidade::setChao(bool aux)
{
}

const bool Entidade::getChao() const
{
	return false;
}

void Entidade::setDestruir(const bool aux)
{
	destruir = aux;
}

const bool Entidade::getDestruir() const
{
	return destruir;
}

void Entidade::desenharVidas()
{
}

const float Entidade::getPontos() const
{
	return 0.0f;
}

const float Entidade::g = 1200;


