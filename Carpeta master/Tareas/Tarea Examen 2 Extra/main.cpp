#include <iostream>
#include <fstream>
#include <cctype>
#include <chrono>
#include "IndexadorArbol.h"
#include "IndexadorHash.h"



//Funcion auxiliar
std::string limpiarPalabra(const std::string& s)
{
    std::string limpia;
    for (char c : s)
    {
        if (std::isalpha(static_cast<unsigned char>(c)))
        {
            limpia += std::tolower(static_cast<unsigned char>(c));
        }
    }
    return limpia;
}


//Main principal 
int main()
{
    //Booleano para decidir el uso de hash o arbol
    bool usarHash = true;
    //Instancia de indexador
    IIndexador* indexador;

    //Pide al usuario si quiere usr hash o arbol, usando el boleano, y dependieno de la respuesta usa la instancia pasada de Indexador y crea el indexador hash o arbol
    std::cout << "Desea usar hash o arbol para indexar? (1 = hash, 0 = arbol): ";
    std::cin >> usarHash;

    if (usarHash)
        indexador = new IndexadorHash();
    else
        indexador = new IndexadorArbol();


    //ifstream basico para abrir el archivo
    std::ifstream archivo("quijote.txt");
    if (!archivo.is_open())
    {
        std::cerr << "ERROR: No se pudo abrir el archivo" << std::endl;
        return 1;
    }

    //Use chrono para captar los tiempos
    std::string palabra;
    auto inicioLectura = std::chrono::high_resolution_clock::now();

    int totalPalabras = 0;
    while (archivo >> palabra)
    {
        std::string limpia = limpiarPalabra(palabra);
        if (!limpia.empty())
        {
            indexador->agregarPalabra(limpia);
            totalPalabras++;
        }
    }


    //Capturas para el tiempo de lectura e indexacon
    auto finLectura = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempoLectura = finLectura - inicioLectura;
    std::cout << "Tiempo de lectura e indexado: " << tiempoLectura.count() << " segundos" << std::endl;

    archivo.close();
    //Capturas para el tiempo de conteo y palabras
    auto inicioOrden = std::chrono::high_resolution_clock::now();
    auto conteoOrdenado = indexador->obtenerConteoOrdenado();
    auto finOrden = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tiempoOrden = finOrden - inicioOrden;
    std::cout << "Tiempo de obtener conteo ordenado: " << tiempoOrden.count() << " segundos" << std::endl;

    std::cout << "Total de palabras procesadas: " << totalPalabras << std::endl;
    std::cout << "Palabras unicas: " << conteoOrdenado.size() << std::endl;

    int maximo = 0;
    std::cout << "Cuantas palabras unicas desea mostrar? ";
    std::cin >> maximo;

    for (int i = 0; i < maximo && i < (int)conteoOrdenado.size(); ++i)
    {
        std::cout << conteoOrdenado[i].first << " -> " << conteoOrdenado[i].second << std::endl;
    }

    //Libera el espacio agarrado por la creacion de indexador
    delete indexador;
    return 0;
}
