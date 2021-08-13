#pragma once

#include "GerenciadorEventos.h"
#include "Ente.h"

class CadastradorJogadas:
	public Ente
{
private:

	Font fonte;
	Text texto[5];

public:
	
	//Construtora e Destrutora
	CadastradorJogadas();
	~CadastradorJogadas();

	//Executa o cadastro da pontuação do(a) "nome da pessoa"
	void executar();

	//Desenha na tela os textos
	void desenhar();


};

