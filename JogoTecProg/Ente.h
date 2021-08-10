#pragma once
class Ente
{

protected:

public:

	//Contrutora e Destrutora
	Ente();
	~Ente();

	//Virtual para chamar as funções de desenhar em cada classe que herda Ente
	virtual void desenhar() = 0;
	
};

