#pragma once
#include <iostream>
using namespace std;

template <class TE>
class Elemento
{
private:

	Elemento<TE>* pProx;
	Elemento<TE>* pAnte;

	TE* pItem;

public:

	Elemento();
	~Elemento();

	void setProx(Elemento<TE>* pProx);
	Elemento<TE>* getProx();

	void setAnte(Elemento<TE>* pAnte);
	Elemento<TE>* getAnte();

	void setItem(TE* pI);
	TE* getItem();

	//void operator ++(int);
};


//Funções implementadas
template<class TE>
inline Elemento<TE>::Elemento()
{
	pAnte = nullptr;
	pProx = nullptr;
	pItem = nullptr;
}

template<class TE>
inline Elemento<TE>::~Elemento()
{
	pAnte = nullptr;
	pProx = nullptr;
	pItem = nullptr;
}

template<class TE>
inline void Elemento<TE>::setProx(Elemento<TE>* pProx)
{
	this->pProx = pProx;
}

template<class TE>
inline void Elemento<TE>::setAnte(Elemento<TE>* pAnte)
{
	this->pAnte = pAnte;
}

template<class TE>
inline Elemento<TE>* Elemento<TE>::getAnte()
{
	return pAnte;
}

template<class TE>
inline Elemento<TE>* Elemento<TE>::getProx()
{
	return pProx;
}

template<class TE>
inline void Elemento<TE>::setItem(TE* pI)
{
	this->pItem = pI;
}

template<class TE>
inline TE* Elemento<TE>::getItem()
{
	return pItem;
}

//template<class TE>
//inline void Elemento<TE>::operator++(int)
//{
//
//	
//
//}

