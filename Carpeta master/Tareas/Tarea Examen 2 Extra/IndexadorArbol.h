#ifndef INDEXADORARBOL_H
#define INDEXADORARBOL_H

#include "IIndexador.h"
#include <map>

// Clase para idnexar el arbol, hereda la clase base 
class IndexadorArbol : public IIndexador
{
private:
    std::map<std::string, int> indice;

public:
    void agregarPalabra(const std::string& palabra) override
    {
        indice[palabra]++;
    }

    std::vector<std::pair<std::string, int>> obtenerConteoOrdenado() override
    {
        std::vector<std::pair<std::string, int>> ordenado(indice.begin(), indice.end());
        return ordenado;
    }
};

#endif
