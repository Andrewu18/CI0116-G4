#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <chrono>  // <-- importante

using namespace std;
using namespace std::chrono;

void merge(int *A, int i, int m, int f)
{
    if (A == nullptr) 
    {
        cerr << "ERROR: arreglo no valido" << endl;
        return;
    }
    int Ai = m - i + 1;
    int Ad = f - m;
    std::vector<int> I(Ai + 1), D(Ad + 1);

    for(int x = 0; x < Ai; x++) 
    {
        I[x] = A[i + x];
    }

    for(int y = 0; y < Ad; y++) 
    {
        D[y] = A[m + y + 1];
    }

    I[Ai] = INT_MAX;
    D[Ad] = INT_MAX;

    int x = 0;
    int y = 0;

    for(int k = i; k <= f; k++) 
    {
        if(I[x] <= D[y]) {
            A[k] = I[x];
            x = x + 1;
        } else {
            A[k] = D[y];
            y = y + 1;
        }
    }
}

void mergeSort(int *A, int i, int f)
{
    if (A == nullptr) 
    {
        cerr << "ERROR: arreglo no valido" << endl;
        return;
    }
    if (i >= f) 
    {
        return;
    }
    int m = (i + f) / 2;
    mergeSort(A, i, m);
    mergeSort(A, m + 1, f);
    merge(A, i, m, f);
}

int main()
{
    cout << "Desea abrir un archivo para ordenar o utilizar un arreglo con numeros aleatorios? (digite 1 o 2)" << endl;
    int opcion;
    cout << "1. Quiero que lea arreglos desde un archivo (input.txt)\n";
    cout << "2. Quiero usar un arreglo aleatorio\n";
    cin >> opcion;
    cout << "Escogio la opcion " << opcion << endl;
    
    if (opcion == 1) 
    {
        ifstream inFile("input.txt");

        if (!inFile) 
        {
            cerr << "ERROR: no se pudo abrir el archivo" << endl;
            return 1;
        }

        cout << endl;
        string linea;
        while (getline(inFile, linea))
        {
            if (linea.empty()) continue;
            stringstream ss(linea);
            vector<int> datos;
            string numero;
    
            while (getline(ss, numero, ','))
            {
                datos.push_back(stoi(numero));
            }
    
            if (datos.empty()) continue;
            int n = datos.size();
            int *A = new int[n];
            for (int i = 0; i < n; i++)
            {
                A[i] = datos[i];
            }

            auto inicio = high_resolution_clock::now();
            mergeSort(A, 0, n - 1);
            auto fin = high_resolution_clock::now();

            auto duracion = duration_cast<milliseconds>(fin - inicio).count();

            cout << "Arreglo ordenado con mergeSort: ";
            for (int i = 0; i < n; i++) {
                cout << A[i];
                if (i < n - 1) cout << ",";
            }
            cout << endl;
            cout << "Tiempo de ejecucion: " << duracion << " ms" << endl;

            delete[] A;
        }
    }

    if (opcion == 2) 
    { 
        int arregloPrueba[10] = {55, 35, 139, 10, 1, 1348, 15, 5, 193, 4};
        int n = 10;
        cout << "Arreglo original: " << endl;

        for (int i = 0; i < n; i++) 
        {
            cout << arregloPrueba[i] << " "  ;
        }

        cout << endl;

        auto inicio = high_resolution_clock::now();
        mergeSort(arregloPrueba, 0, n - 1);
        auto fin = high_resolution_clock::now();

        auto duracion = duration_cast<milliseconds>(fin - inicio).count();

        cout << "Arreglo ordenado con mergeSort: " << endl;
        for (int i = 0; i < n; i++) 
        {
            cout << arregloPrueba[i] << " "  ;
        }
        cout << endl;
        cout << "Tiempo de ejecucion: " << duracion << " ms" << endl;
    }
}
