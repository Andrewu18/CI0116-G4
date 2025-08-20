#Se importa la biblioteca random para utilizar numeros aleatorios
#Se importa la biblioteca time para cronometrar el tiempo de duracion de los metodos

import random
import time

#Este metodo se llama para crear hileras/arrays de diferentes tamanos, llenandolos de numeros al azar

def hilera_numeros_aleatorios(tamano, minimo, maximo):
    hil = [random.randint(minimo, maximo) for _ in range(tamano)]
    return hil
    
    
#Metodo para bubble sort, "burbujea" el numero mayor en cada iteracion hacia el final de la lista utilizando un movimiento swap
def bubble_sort(hilera, tamano) :
      for i in range(tamano - 1):
          for j in range(tamano - i - 1):
              if hilera[j] > hilera [j + 1]:
                  hilera[j], hilera[j + 1] = hilera[j + 1], hilera[j]
    
    
#main de prueba
def main():
    #Itera 5 veces para obtener los tiempos de 5 ejecuciones
    for z in range(5) : 
         #Hace 3 hileras de 10, 100 y 1000 elementos aleatorios con enteros del 1 al 1000
        #Imprime el estado de estas hileras antes y despues de aplicar bubble_sort
        print("Hilera de 10 numeros al azar antes y despues de aplicar bubble sort:")
        hilera10 = hilera_numeros_aleatorios(10, 1, 1000)
        print(hilera10)
        bubble_sort(hilera10, 10)
        print(hilera10)
        print("Hilera de 100 numeros al azar antes y despues de aplicar bubble sort:")
        hilera100 = hilera_numeros_aleatorios(100, 1, 1000)
        print(hilera100)
        bubble_sort(hilera100, 100)
        print(hilera100)
        print("Hilera de 1000 numeros al azar antes y despues de aplicar bubble sort:")
        hilera1k = hilera_numeros_aleatorios(1000, 1, 1000)
        print(hilera1k)
        bubble_sort(hilera1k, 1000)
        print(hilera1k)
        print("Esta fue la iteracion numero: ", z + 1)
        z + 1

    
if __name__ == "__main__":
    main()