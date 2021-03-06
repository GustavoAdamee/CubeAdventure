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

    //Mapa q ira armazenar as informa??es para desenhar as fases
    int mapa[32][18];
    Vector2i contador = Vector2i(0, 0);

    //"Paths" para as tiles e o mapa com seus valores
    const char* caminhoMapaTile;
    const char* caminhoTile;

    //Arquivo que ira abrir os txt e os png
    ifstream file;

    //Armazena as sprites das tiles para desenh?-las
    vector<Sprite> vetorTiles;

    //Singleton
    static GerenciadorTiles* instancia;

    //Construtora privada
    GerenciadorTiles();

public:
    
    class InfoTiles
    {
    
    public:
        
        Vector2f posicao;
        Vector2f tamanho;

    };
    
    GerenciadorTiles* getInstancia();

    //Destrutora
    ~GerenciadorTiles();

    //Abre o arquivo .txt e inicializa os valores 
    void initTiles();
    
    //Armazena a posi??o e a textura de cada tile e manda ela para um vector
    void initMapaTiles(int i, int j);   
    
    //Retona a informa??o da tile na posi??o da matriz [i][j]
    int getInfo(int i, int j);
    
    //Percorre o vetor de sprites desenhando as tiles
    void desenhaListaTiles();

    //Retorna um vector com as sprites das tiles
    vector<Sprite>* getVetorTiles();

    //Seta gerenciadores
    void setGColisoes(GerenciadorColisoes* gCol);
    void setGGraf(GerenciadorGrafico* gG);

   //Seta as "paths"
    void setCaminhos(const char* caminhoTile, const char* caminhoMapaTile);
    
    //Clear no vector da stl
    void limpaTiles();
};

