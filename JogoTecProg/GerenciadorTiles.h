#pragma once
#include "GerenciadorGrafico.h"

#include "cctype"
#include "fstream"
#include "iostream"
#include <vector>

using namespace std;

class GerenciadorColisoes;

class GerenciadorTiles
{
private:
   //Gerenciadores
    GerenciadorGrafico* gGraf;
    GerenciadorColisoes* gColisoes;

    //Sprites e texturas para as tiles
    Sprite tile;
    Texture texturaTile;

    //Mapa q ira armazenar as informações para desenhar as fases
    int mapa[32][18];
    Vector2i contador = Vector2i(0, 0);

    //"Paths" para as tiles e o mapa com seus valores
    const char* caminhoMapaTile;
    const char* caminhoTile;

    //Arquivo que ira abrir os txt e os png
    ifstream file;

    //Armazena as sprites das tiles para desenhá-las
    vector<Sprite> vetorTiles;

public:
    //Construtora e Destrutora
    GerenciadorTiles();
    ~GerenciadorTiles();

    //Abre o arquivo .txt e inicializa os valores 
    void initTiles();
    
    //Armazena a posição e a textura de cada tile e manda ela para um vector
    void initMapaTiles(int i, int j);   
    
    //Retona a informação da tile na posição da matriz [i][j]
    int getInfo(int i, int j);
    
    //Percorre o vetor de sprites desenhando as tiles
    void desenhaListaTiles();

    vector<Sprite>* getVetorTiles();

    void setGColisoes(GerenciadorColisoes* gCol);
    void setGGraf(GerenciadorGrafico* gG);

    void setCaminhos(const char* caminhoTile, const char* caminhoMapaTile);
    void limpaTiles();
};

