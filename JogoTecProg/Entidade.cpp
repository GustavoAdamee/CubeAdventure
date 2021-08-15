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
Vector2f Entidade::getVel()
{
	return v;
}
void Entidade::setVel(Vector2f vel)
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

void Entidade::desenharVidas()
{
}

float Entidade::getPontos()
{
	return 0.0f;
}

const float Entidade::g = 1200;


