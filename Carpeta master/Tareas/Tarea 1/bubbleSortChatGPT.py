import random
import time

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break

def medir_tiempo(size, repeticiones=5):
    tiempos = []
    for _ in range(repeticiones):
        arr = [random.randint(0, 10000) for _ in range(size)]
        inicio = time.perf_counter()
        bubble_sort(arr)
        fin = time.perf_counter()
        tiempos.append(fin - inicio)
    return tiempos, sum(tiempos) / repeticiones

def main():
    tamaños = [10, 100, 1000]
    for t in tamaños:
        tiempos, promedio = medir_tiempo(t)
        print(f"\nTamaño {t}:")
        for i, tiempo in enumerate(tiempos, 1):
            print(f"  Ejecución {i}: {tiempo:.6f} segundos")
        print(f"  Promedio: {promedio:.6f} segundos")

if __name__ == "__main__":
    main()
