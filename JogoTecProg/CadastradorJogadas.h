#pragma once

#include "GerenciadorEventos.h"
#include "Menu.h"

class CadastradorJogadas:
	public Menu
{
private:

	//Atributos responsáveis por gerenciar as letras "interagíveis" ao salvar uma jogada
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

};

