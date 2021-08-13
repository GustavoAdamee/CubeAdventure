#include "ListaEntidades.h"

ListaEntidades::ListaEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
}


Lista<Entidade>& ListaEntidades::getLista()
{
    return LEs;
}

Entidade* ListaEntidades::operator[](int i)
{
    return getLista().getItem(i);
}

bool ListaEntidades::operator>(int i)
{
    if (LEs.getTam() > i) {
        return true;
    }
    return false;
}



