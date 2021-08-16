#pragma once

#include"CuboCowboy.h"
#include"CuboExplorador.h"
#include"ListaEntidades.h"
#include"FaseGrama.h"
#include"FaseCaverna.h"
#include"FaseCavernaChefao.h"
#include"MenuPrincipal.h"
#include"MenuJogadores.h"
#include"MenuPause.h"
#include"MenuFases.h"
#include"MenuRanking.h"
#include"CadastradorJogadas.h"
#include<Windows.h>
#include"GerenciadorGrafico.h"
#include"GerenciadorEventos.h"
#include"GerenciadorTiles.h"
#include"GerenciadorColisoes.h"
#include"Relogio.h"

using namespace Jogadores;
using namespace Fases;

class Jogo
{
private:

	//Entidades
	CuboCowboy* pJogador1;
	CuboExplorador* pJogador2;

	//Lista com entidades do jogo
	ListaEntidades* LEs;

	//Ponteiro para gerar fases
	Fase* fase;

	//Atributos para menu
	Menu* menu;
	int indiceMenu;
	MenuRanking* ranking;

	//Gerenciadores
	GerenciadorGrafico* gerenciadorGrafico;
	GerenciadorEventos* gerenciadorEventos;
	GerenciadorColisoes* gerenciadorColisoes;
	GerenciadorTiles* gerenciadorTiles;

	//Passagem de tempo
	Relogio relogio;

	//Pontuação de cada Jogada 
	float pontuacao = 0;

	//Cadastrador de pontuação
	CadastradorJogadas cadastrarJogadas;


public:

	//Construtora e destrutora
	Jogo();
	~Jogo();

	//Função/Metodo responsavel por iniciar as funções q dao inicio ao programa
	void executarJogo();

	//Gerencia qual janela de menu sera executada
	void trocarMenu(bool Fases = false, int indicaFase = 0);

	//Gerencia as ações que cada menu pode realizar
	void gerenciarMenuPrincipal();
	void gerenciarMenuJogadores(int numFase = 0);
	void gerenciarMenuPause();
	void gerenciarMenuFases();

	//Verifica se o pause foi acionado
	void verificaPause();
	//Verifica se o Jogador passou de fase
	void verificaFase();
	//Verifica se houve e atualiza as entidades
	void verificaAtualizacoes();

	//Gera uma fase
	void gerarFase();

	//Gerencia as colisoes dentro de uma fase
	void gerenciaColisoes();

	//Percorre a lista de entidades desenhando-as
	void desenhaEntidades();

	//Reseta a fase executada 
	void reiniciaFase();
};

