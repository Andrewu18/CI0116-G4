#ifndef INDEXADORHASH_H
#define INDEXADORHASH_H

#include "IIndexador.h"
#include <map>



//to do hash, vacia para compilar por meintras con el makefile

class IndexadorHash : public IIndexador
{
public:
    void agregarPalabra(const std::string& palabra) override
    {
    }

    std::vector<std::pair<std::string, int>> obtenerConteoOrdenado() override
    {
        return {};
    }
};





#endif