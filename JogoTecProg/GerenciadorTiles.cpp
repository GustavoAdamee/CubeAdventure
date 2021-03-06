#include "GerenciadorTiles.h"

#include "GerenciadorColisoes.h"

GerenciadorTiles::GerenciadorTiles():
	
	gGraf(nullptr),
	gColisoes(nullptr),
	tile(),
	texturaTile(),
	caminhoMapaTile(),
	caminhoTile(),
	file(),
	vetorTiles(),
	mapa()

{

}

GerenciadorTiles* GerenciadorTiles::getInstancia()
{
	if (instancia == 0) {
		instancia = new GerenciadorTiles();
	}
	return instancia;
}

GerenciadorTiles::~GerenciadorTiles()
{
	gGraf = nullptr;
	
	mapa[0][0];
	
	limpaTiles();
}

void GerenciadorTiles::initTiles()
{
	ifstream file(caminhoMapaTile);
	cout << caminhoMapaTile << endl;
	if (file.is_open()) {
		string tileLocation;
		file >> tileLocation;

		texturaTile.loadFromFile(caminhoTile);
		tile.setTexture(texturaTile);

		while (file.eof() == false) {
			string aux;
			file >> aux;

			char x = aux[0];

			//Faz a dividas alterações na 'matriz' de tiles
			if (isdigit(x) == false) {
				mapa[contador.x][contador.y] = -1;
				//cout << "mapa" << map[loadCounter.x][loadCounter.y] << endl;
			}
			else {
				mapa[contador.x][contador.y] = (x - '0');
				//cout << "map" << map[loadCounter.x][loadCounter.y] << endl;
			}
			//Percorre a 'matriz' de tiles
			if (file.peek() == '\n') {
				contador.x = 0;
				contador.y++;
			}
			else {
				contador.x++;
			}
		}
		contador.x = 0;
		contador.y = 0;
	}
	else {
		cout << caminhoMapaTile << "nao foi aberto corretamente" << std::endl;
	}

	
}

void GerenciadorTiles::initMapaTiles(int i, int j)
{
	//Tamanho de cada tile em pixels
	tile.setPosition((float)i * 50, (float)j * 50);		
	
	tile.setTextureRect(IntRect(mapa[i][j] * 50, 0, 50, 50));

	InfoTiles  aux;
	aux.posicao = Vector2f((float)i * 50, (float)j * 50);
	aux.tamanho = Vector2f(50.0, 50.0);

	gColisoes->adicionarTile(aux);

	vetorTiles.push_back(tile);
	
}

int GerenciadorTiles::getInfo(int i, int j)
{
	return mapa[i][j];
}

void GerenciadorTiles::desenhaListaTiles()
{
	vector<Sprite>::const_iterator aux;
	for (aux = vetorTiles.begin(); aux != vetorTiles.end(); aux++) {
		
		gGraf->getJanela()->draw(*aux);
	}
}

vector<Sprite>* GerenciadorTiles::getVetorTiles()
{
	return &vetorTiles;
}

void GerenciadorTiles::setGColisoes(GerenciadorColisoes* gCol)
{
	gColisoes = gCol;
	gColisoes->setGerenciadorTiles(this);
}

void GerenciadorTiles::setGGraf(GerenciadorGrafico* gG)
{
	gGraf = gG;
}

void GerenciadorTiles::setCaminhos(const char* caminhoTile, const char* caminhoMapaTile)
{
	this->caminhoTile = caminhoTile;
	this->caminhoMapaTile = caminhoMapaTile;
}

void GerenciadorTiles::limpaTiles()
{
	vetorTiles.clear();
}

GerenciadorTiles* GerenciadorTiles::instancia = 0;



