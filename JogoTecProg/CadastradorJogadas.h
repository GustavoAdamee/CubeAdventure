#pragma once

#include "GerenciadorEventos.h"
#include "Ente.h"

class CadastradorJogadas:
	public Ente
{
private:

	Font fonte;
	Text texto[5];

	GerenciadorEventos* gEv;

	int letra = 65;
	int n_letra = 1;

public:
	
	//Construtora e Destrutora
	CadastradorJogadas();
	~CadastradorJogadas();

	//Executa o cadastro da pontuação do(a) "nome da pessoa"
	String executar(int pontos);

	//Desenha na tela os textos
	void desenhar();

	void setGEv(GerenciadorEventos* gEventos);
};

