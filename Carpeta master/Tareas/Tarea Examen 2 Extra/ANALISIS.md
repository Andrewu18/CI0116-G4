1) Comparar los tiempos de inserción de ambas implementaciones: 
¿Cuál fue más rápida? 
¿Por qué? 
Relacionar la respuesta con la complejidad de inserción promedio de una tabla hash y la de un árbol balanceado.

Nota: Respuestas sin tilde o ñ para evitar problemas de formatos.

R/ 

Resultados obtenidos en una ejecucion (en segundos):

| Implementación             | Insercion     | Ordenado      | Total    | Palabras procesadas | Palabras unicas |
| -------------------------- | ------------- | ------------ | --------- | ------------------- | --------------- |
| **Hash**                   | 0.0389        | 0.0040       | 0.0430    | 381,208             | 22,363          |
| **Árbol**                  | 0.0640        | 0.0020       | 0.0660    | 381,208             | 22,363          |

Hash es el mash rapido para inserciones.
Porque hash, por la forma que funciona, asigna y no debe buscar mucho en comparacion a un arbol para insercion.
Hash utiliza inserta en O(1) promedio mientras que un arbol usa O(log n), por lo cual se comprueba.

2) Compara los tiempos de recuperación ordenada: 
¿Cuál fue más rápida? 
Explicar la diferencia de rendimiento observada, refiriéndose a la complejidad de std::sort que IndexadorHash tuvo que ejecutar, versus el recorrido que IndexadorArbol pudo realizar.

R/
El mas rapido fue el arbol.
Esto es por las diferentes formas que cada indexador ordeno los datos, arbol al utilizar map ya tiene los datos ordenados por lo que no necesita sortearlo, solo recorrerlo, mientras que hash debe ordenarlos mediante std::sort.
std::sort tiene complejidad O(n log n) mientras que el recorrido de un arbol ya ordenado (por utilizar map) es O(n), claramente se denota esto en los tiempos obtenidos.


3) Si la aplicación solo necesitara saber si una palabra existe (como un corrector ortográfico) y no necesitara una lista ordenada, 
¿qué estructura sería estratégicamente superior y por qué? 
Si la aplicación necesitara constantemente mostrar la lista de palabras en orden alfabético (como un diccionario o un índice de libro), ¿qué estructura elegirían y por qué?

R/
Hash seria la mejor opcion, porque cuando el orden no importa es mas rapido, lo cual es el caso cuando se busca una palabra.

Si se necesita la lista ordenada, arbol es claramente la mejor opcion ya que como se demostro anteriormente, arbol ordena las palabras mas rapidamente al usar map y una lista de palabras en orden alfabetico necesita este ordenamiento.