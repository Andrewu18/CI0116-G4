import random
import time
import copy

def bubble_sort_optimizado(lista):
    n = len(lista)
    hubo_intercambio = True
    
    while hubo_intercambio:
        hubo_intercambio = False
        for j in range(n - 1):
            if lista[j] > lista[j + 1]:
                lista[j], lista[j + 1] = lista[j + 1], lista[j]
                hubo_intercambio = True
        n -= 1
        
    return lista

def calcular_promedio_tiempo(nombre_arreglo, arreglo_original, num_repeticiones=5):
    tiempos = []
    
    print(f"\n--- Probando {nombre_arreglo} (Tamaño: {len(arreglo_original)}) ---")
    
    for i in range(num_repeticiones):
        # Usamos una copia del arreglo para cada repetición
        # para que el arreglo original no se modifique y la prueba sea justa.
        arreglo_copia = copy.deepcopy(arreglo_original)
        
        inicio_tiempo = time.perf_counter()
        bubble_sort_optimizado(arreglo_copia)
        fin_tiempo = time.perf_counter()
        
        tiempo_ejecucion = fin_tiempo - inicio_tiempo
        tiempos.append(tiempo_ejecucion)
        
        print(f"  Intento {i + 1}: {tiempo_ejecucion:.6f} segundos")
        
    promedio = sum(tiempos) / len(tiempos)
    print(f"\n  Tiempo promedio de {nombre_arreglo} en {num_repeticiones} intentos: {promedio:.6f} segundos")
    return promedio

# Creación de los arreglos aleatorios
arreglo1 = [random.randint(1, 1000) for _ in range(10)]
arreglo2 = [random.randint(1, 1000) for _ in range(100)]
arreglo3 = [random.randint(1, 1000) for _ in range(1000)]

# Medición y cálculo de tiempos
promedio_arreglo1 = calcular_promedio_tiempo("Arreglo 1", arreglo1)
promedio_arreglo2 = calcular_promedio_tiempo("Arreglo 2", arreglo2)
promedio_arreglo3 = calcular_promedio_tiempo("Arreglo 3", arreglo3)