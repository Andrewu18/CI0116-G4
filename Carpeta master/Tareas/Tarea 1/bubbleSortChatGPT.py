import random
import time

# Algoritmo Bubble Sort basado en el pseudocódigo dado
def bubble_sort(A):
    n = len(A)
    for i in range(n):  # for i = 0 to n-1
        for j in range(n - i - 1):  # for j = 0 to n - i - 1
            if A[j] > A[j + 1]:  # if A[j] > A[j+1]
                A[j], A[j + 1] = A[j + 1], A[j]  # exchange

# Función para ejecutar las pruebas
def run_tests():
    sizes = [10, 100, 1000]  # tamaños de arreglos
    num_runs = 5  # número de ejecuciones por cada tamaño
    
    for size in sizes:
        print(f"\nTamaño del arreglo: {size}")
        tiempos = []
        
        for run in range(1, num_runs + 1):
            # Crear arreglo aleatorio
            arr = [random.randint(1, 1000) for _ in range(size)]
            
            # Medir tiempo
            start = time.perf_counter()
            bubble_sort(arr)  # ordenar con Bubble Sort
            end = time.perf_counter()
            
            tiempo = end - start
            tiempos.append(tiempo)
            
            print(f"Ejecución {run}: {tiempo:.6f} segundos")
        
        promedio = sum(tiempos) / num_runs
        print(f"Promedio: {promedio:.6f} segundos")

if __name__ == "__main__":
    run_tests()
