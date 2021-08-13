#include "GerenciadorGrafico.h"
#include <iostream>

GerenciadorGrafico::GerenciadorGrafico():
	
	janela{ new RenderWindow(VideoMode(1600, 900), "Cube Adventure") },
	texturas(),
	background(),
	backgroundText()

{

}

GerenciadorGrafico::~GerenciadorGrafico()
{
	delete janela;

	for (auto i : texturas) {
		delete i.second;
	}
}

void GerenciadorGrafico::mostrar() const
{
	janela->display();
}

void GerenciadorGrafico::limpar(int r, int g, int b)
{
	janela->clear(Color(r, g, b));
}

void GerenciadorGrafico::desenhar(const string& caminho, const Vector2f posicao)
{
	if (texturas.count(caminho) == 0) {
		cout << texturas.size() << endl;
		cout << "Atencao! Imagem em " << caminho << " nao carregada!" << endl;
		exit(111);
	}

	Texture* text = texturas[caminho];
	Sprite sprite;

	sprite.setTexture(*text);
	sprite.setPosition(posicao.x, posicao.y);
	

	janela->draw(sprite);
}

bool GerenciadorGrafico::carregarTextura(const string& caminho)
{

	if (texturas.count(caminho) == 1) return true;
	else {

		try
		{
			Texture* text = new Texture();

			if (text->loadFromFile(caminho)) {
				texturas.emplace(caminho, text);
				return true;
			}
			else {
				throw 999;
			}
		}
		catch (int aux)
		{
			if (aux == 999) {
				cout << "Atencao! imagem em " << caminho << "nao encontrada!" << endl;
				exit(999);
			}
		}
	}
}

RenderWindow* GerenciadorGrafico::getJanela() const
{
	return janela;
}

bool GerenciadorGrafico::janelaAberta()
{
	if (janela->isOpen()) {
		return true;
	}
	return false;
}

void GerenciadorGrafico::setBackground(const char* caminho)
{
	backgroundText.loadFromFile(caminho);
	background.setTexture(backgroundText);
}

void GerenciadorGrafico::desenhaBackground()
{
	janela->draw(background);
}


void GerenciadorGrafico::desenhaPontos(float pontuacao)
{

	if (!fonte.loadFromFile("Happy chicken.ttf")) {
	}

	for (int i = 0; i < 2; i++) {
		texto[i].setFont(fonte);
		texto[i].setScale(1, 1);
		texto[i].setFillColor(sf::Color::Yellow);
	}

	texto[0].setPosition(sf::Vector2f((janela->getSize().x -200) / 2, 50));
	texto[1].setPosition(sf::Vector2f((janela->getSize().x + 100) / 2, 50));


	texto[0].setString("Pontos: ");
	texto[1].setString(to_string(static_cast<int>(pontuacao)));
	janela->draw(texto[0]);
	janela->draw(texto[1]);


}
