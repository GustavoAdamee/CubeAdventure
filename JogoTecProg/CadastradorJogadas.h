#pragma once

#include "GerenciadorEventos.h"
#include "Menu.h"

class CadastradorJogadas:
	public Menu
{
private:

	//Atributos respons�veis por gerenciar as letras "interag�veis" ao salvar uma jogada
	int letra = 65;
	int n_letra = 1;

public:
	
	//Construtora e Destrutora
	CadastradorJogadas();
	~CadastradorJogadas();

	//Executa o cadastro da pontua��o do(a) "nome da pessoa"
	String executar(int pontos);

	//Desenha na tela os textos
	void desenhar();

};

