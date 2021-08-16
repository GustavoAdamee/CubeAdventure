#pragma once
#include "Elemento.h"
#include "Entidade.h"

template<class TL>
class Lista
{
private:


	int tam;

public:

	//Construtora e Destrutora
	Lista();
	~Lista();

	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;

	//Retorna o tamaho da lista
	const int getTam() const;

	//Retorna um determinado item da lista
	TL* getItem(int posicao);

	//Inseri um item na lista
	void push(TL* pItem);

	//Retira um item da lista
	void pop(TL* pItem);

};



//Implementando as funções
template<class TL>
inline Lista<TL>::Lista()
{
	pPrimeiro = nullptr;
	pUltimo = nullptr;

	int tam = -1;
}

template<class TL>
inline Lista<TL>::~Lista()
{
	pPrimeiro = nullptr;
	pUltimo = nullptr;

	int tam = -1;
}

template<class TL>
inline const int Lista<TL>::getTam() const
{
	return tam;
}

template<class TL>
inline TL* Lista<TL>::getItem(int posicao)
{
	Elemento<TL>* pAux = pPrimeiro;

	if (posicao == 0)
	{
		return pAux->getItem();
	}
	for (int i = 0; i < posicao; i++)
	{
		pAux = pAux->getProx();
	}

	return pAux->getItem();
}

template<class TL>
inline void Lista<TL>::push(TL* pItem)
{

	if (pPrimeiro == nullptr)
	{
		pPrimeiro = new Elemento<TL>;
		pPrimeiro->setItem(pItem);
		pUltimo = pPrimeiro;
	}
	else
	{
		Elemento<TL>* pAux = new Elemento<TL>;
		pAux->setItem(pItem);
		pAux->setAnte(pUltimo);
		pUltimo->setProx(pAux);
		pUltimo = pAux;
	}
	tam++;
}

template<class TL>
inline void Lista<TL>::pop(TL* pItem)
{
	Elemento<TL>* pAux = pPrimeiro;
	Elemento<TL>* pAuxAnt = nullptr;

	while (pAux->getItem() != pItem)
	{
		pAuxAnt = pAux;;
		pAux = pAux->getProx();
	}
	if (pAux == pPrimeiro)
	{
		pPrimeiro = pAux->getProx();
		pPrimeiro->setAnte(nullptr);
	}
	else if (pAux == pUltimo)
	{
		pAuxAnt->setProx(nullptr);
		pUltimo = pAuxAnt;
	}
	else
	{
		pAuxAnt->setProx(pAux->getProx());
		pAux->getProx()->setAnte(pAuxAnt);
	}
	delete pAux;
	tam--;

}

//template<class LE>
//template<class TE>
//class Lista<LE>::Elemento<TE>* Lista<LE>::Elemento<TE>::getAnte()
//{
//	return pAnte;
//}
//
////TypeName