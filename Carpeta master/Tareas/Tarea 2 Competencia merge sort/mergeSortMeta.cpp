#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>

std::vector<std::vector<int>> leerArreglosDesdeArchivo(const std::string& nombreArchivo) {
    std::vector<std::vector<int>> arreglos;
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::vector<int> arreglo;
            std::stringstream ss(linea);
            std::string elemento;
            while (std::getline(ss, elemento, ',')) {
                arreglo.push_back(std::stoi(elemento));
            }
            arreglos.push_back(arreglo);
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
    return arreglos;
}

std::vector<int> merge(const std::vector<int>& izquierda, const std::vector<int>& derecha) {
    std::vector<int> arregloOrdenado;
    int indiceIzquierda = 0;
    int indiceDerecha = 0;

    while (indiceIzquierda < izquierda.size() && indiceDerecha < derecha.size()) {
        if (izquierda[indiceIzquierda] <= derecha[indiceDerecha]) {
            arregloOrdenado.push_back(izquierda[indiceIzquierda]);
            indiceIzquierda += 1;
        } else {
            arregloOrdenado.push_back(derecha[indiceDerecha]);
            indiceDerecha += 1;
        }
    }

    while (indiceIzquierda < izquierda.size()) {
        arregloOrdenado.push_back(izquierda[indiceIzquierda]);
        indiceIzquierda += 1;
    }

    while (indiceDerecha < derecha.size()) {
        arregloOrdenado.push_back(derecha[indiceDerecha]);
        indiceDerecha += 1;
    }

    return arregloOrdenado;
}

std::vector<int> mergeSort(const std::vector<int>& arreglo) {
    if (arreglo.size() <= 1) {
        return arreglo;
    }

    int mitad = arreglo.size() / 2;
    std::vector<int> izquierda(arreglo.begin(), arreglo.begin() + mitad);
    std::vector<int> derecha(arreglo.begin() + mitad, arreglo.end());

    izquierda = mergeSort(izquierda);
    derecha = mergeSort(derecha);

    return merge(izquierda, derecha);
}

int main() {
    std::string nombreArchivo = "input.txt";
    std::vector<std::vector<int>> arreglos = leerArreglosDesdeArchivo(nombreArchivo);

    for (int i = 0; i < arreglos.size(); i++) {
        std::cout << "Arreglo " << i + 1 << ":" << std::endl;
        std::cout << "Original: ";
        for (int elemento : arreglos[i]) {
            std::cout << elemento << " ";
        }
        std::cout << std::endl;

        auto inicio = std::chrono::high_resolution_clock::now();
        std::vector<int> arregloOrdenado = mergeSort(arreglos[i]);
        auto fin = std::chrono::high_resolution_clock::now();

        std::cout << "Ordenado: ";
        for (int elemento : arregloOrdenado) {
            std::cout << elemento << " ";
        }
        std::cout << std::endl;

        auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);
        std::cout << "Tiempo de ejecución: " << duracion.count() << " microsegundos" << std::endl;
        std::cout << std::endl;
    }

    return 0;
}