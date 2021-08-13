#pragma once

#include <map>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class GerenciadorGrafico
{
private:
	//Atributo que a classe ira manipular
	RenderWindow* janela;
	
	//Mapa com as texturas e seus respectivos "paths"
	map<const string, Texture*> texturas;

	//background para os mapas das fases
	Sprite background;
	Texture backgroundText;

	//Atributos para desenhar um score na tela em tempo de execução
	sf::Font fonte;
	sf::Text texto[2];

public:
	//Construtora e Destrutora
	GerenciadorGrafico();
	~GerenciadorGrafico();
	
	//Printa na tela as texturas
	void mostrar() const;
	
	//Limpa a tela em RBG
	void limpar(int r = 0, int g = 0, int b = 0);
	
	//Desenha na tela as texturas
	void desenhar(const string& caminho, const Vector2f posicao);
	
	//Carrega os "paths" das texturas
	bool carregarTextura(const string& caminho);
	
	//retorna a janela do programa
	RenderWindow* getJanela() const;
	
	//Informa true caso a janela estiver aberta
	bool janelaAberta();

	//Seta e desenha um background
	void setBackground(const char* caminho);
	void desenhaBackground();

	//Desenha a pontuação do jogador na tela
	void desenhaPontos(float pontuacao);

};

