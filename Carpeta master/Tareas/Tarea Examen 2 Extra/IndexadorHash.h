#ifndef INDEXADORHASH_H
#define INDEXADORHASH_H

//Classe para hash

#include "IIndexador.h"
#include <map>
#include <unordered_map>
#include <algorithm>

class IndexadorHash : public IIndexador
{
private:
    std::unordered_map<std::string, int> indice;

public:
    void agregarPalabra(const std::string& palabra) override
    {
        indice[palabra]++;
    }

    std::vector<std::pair<std::string, int>> obtenerConteoOrdenado() override
    {
        std::vector<std::pair<std::string, int>> ordenado(indice.begin(), indice.end());
        std::sort(ordenado.begin(), ordenado.end(),
                  [](const auto& a, const auto& b)
                  {
                      return a.first < b.first;
                  });
        return ordenado;
    }
};

#endif