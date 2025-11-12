#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


//Se crea el mapa que se usara para el grafo
using Grafo = unordered_map<int, vector<pair<int, int>>>;

//Metodo para la ruta breadth first
vector<int> ruta_bfs(const Grafo &grafo, int origen, int destino)
{
    set<int> visitados;
    queue<vector<int>> cola;
    cola.push({origen});

    while (!cola.empty())
    {
        vector<int> ruta = cola.front();
        cola.pop();
        int nodo = ruta.back();

        if (nodo == destino)
            return ruta;

        if (!visitados.count(nodo))
        {
            visitados.insert(nodo);
            for (auto &[vecino, peso] : grafo.at(nodo))
            {
                vector<int> nueva_ruta = ruta;
                nueva_ruta.push_back(vecino);
                cola.push(nueva_ruta);
            }
        }
    }
    return {};
}

//Metodo para la ruta depth first
vector<int> ruta_dfs(const Grafo &grafo, int origen, int destino)
{
    set<int> visitados;
    stack<vector<int>> pila;
    pila.push({origen});

    while (!pila.empty())
    {
        vector<int> ruta = pila.top();
        pila.pop();
        int nodo = ruta.back();

        if (nodo == destino)
            return ruta;

        if (!visitados.count(nodo))
        {
            visitados.insert(nodo);
            for (auto &[vecino, peso] : grafo.at(nodo))
            {
                vector<int> nueva_ruta = ruta;
                nueva_ruta.push_back(vecino);
                pila.push(nueva_ruta);
            }
        }
    }
    return {};
}

//Meotod para calcular el costo, como dice el enunciado toma la lista y suma los pesos
int calcular_costo(const Grafo &grafo, const vector<int> &ruta)
{
    if (ruta.size() < 2)
        return 0;

    int costo_total = 0;
    for (size_t i = 0; i < ruta.size() - 1; ++i)
    {
        int origen = ruta[i];
        int destino = ruta[i + 1];

        for (auto &[vecino, peso] : grafo.at(origen))
        {
            if (vecino == destino)
            {
                costo_total += peso;
                break;
            }
        }
    }
    return costo_total;
}



//Main para la ejecucion de los metodos
int main()
{
    Grafo grafo = 
    {
        {0, {{42, 25}, {5, 5}, {8, 7}}},
        {5, {{0, 5}, {12, 4}, {15, 6}}},
        {8, {{0, 7}, {15, 2}, {12, 5}, {20, 2}}},
        {12, {{5, 4}, {8, 5}, {30, 6}, {20, 7}}},
        {15, {{5, 6}, {8, 2}, {20, 9}, {1, 1}}},
        {20, {{15, 9}, {12, 7}, {8, 2}, {22, 3}, {42, 10}}},
        {30, {{12, 6}, {42, 3}}},
        {42, {{0, 25}, {30, 3}, {20, 10}}},
        {1, {{15, 1}}},
        {22, {{20, 3}, {25, 4}}},
        {25, {{22, 4}}},
        {10, {}},
        {18, {}},
        {35, {}}};

    int origen = 0;
    int destino = 42;

    vector<int> rutaBFS = ruta_bfs(grafo, origen, destino);
    vector<int> rutaDFS = ruta_dfs(grafo, origen, destino);

    //Impresiones
    cout << "La ruta BFS es: ";
    for (int nodo : rutaBFS)
    {
        cout << nodo << " ";
    }
        cout << "\n Costo BFS: " << calcular_costo(grafo, rutaBFS) << " minutos\n\n";


    cout << "La ruta DFS es: ";
    for (int nodo : rutaDFS)
    {

        cout << nodo << " ";
    }  
        cout << "\n Costo DFS: " << calcular_costo(grafo, rutaDFS) << " minutos\n";
   
    return 0;
    
}