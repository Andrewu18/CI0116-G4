#ifndef IINDEXADOR_H
#define IINDEXADOR_H

#include <string>
#include <vector>
#include <utility>


//Clase base abstrancta, para heredarse por el indexadorArbol e indexadorHash
class IIndexador
{
public:
    virtual ~IIndexador() {}
    virtual void agregarPalabra(const std::string& palabra) = 0;
    virtual std::vector<std::pair<std::string, int>> obtenerConteoOrdenado() = 0;
};

#endif