#Se importa la biblioteca random para utilizar numeros aleatorios

import random

#Este metodo se llama para crear hileras/arrays de diferentes tamanos, llenandolos de numeros al azar

def hilera_numeros_aleatorios(tamano, minimo, maximo):
    hil = [random.randint(minimo, maximo) for _ in range(tamano)]
    return hil
    
#main de prueba
def main():
    hilera1 = hilera_numeros_aleatorios(10, 1, 1000)
    print("impresion de prueba de main, imprimiendo array al azar de 10 numeros")
    print(hilera1)
    
if __name__ == "__main__":
    main()
    