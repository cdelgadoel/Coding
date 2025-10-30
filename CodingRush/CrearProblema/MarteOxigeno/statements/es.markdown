# Descripción
María está en una misión en Marte y se encuentra en una vasta red de túneles marcianos, que están mapeados en una matriz donde cada celda contiene un nivel de oxígeno representado por un número entero. María necesita encontrar un camino desde la entrada, ubicada en la esquina superior izquierda de la matriz, hasta la salida, en la esquina inferior derecha, de tal manera que el menor nivel de oxígeno en su camino sea el más alto posible entre todos los caminos posibles. María sólo puede moverse hacia la derecha o hacia abajo en cada paso.

# Objetivo
Determinar el máximo valor mínimo de oxígeno que María puede garantizar en su camino desde la entrada hasta la salida.

# Entrada
La primera línea contiene dos enteros, $N$ y $M$, que representan las dimensiones de la matriz. Las siguientes $N$ líneas contienen cada una $M$ números enteros que representan una fila de los túneles. ($1 \leq N, M \leq 100$). Los valores están entre $1$ y $10000$.

Cada entero es un número positivo que representa el nivel de oxígeno en esa celda del túnel.

# Output
Imprimir el máximo valor mínimo del nivel de oxígeno que María puede mantener a lo largo de cualquier camino posible desde la entrada hasta la salida.

# Example
||input
3 3
5 3 4
6 9 1
3 3 8
||output
3
||description
María puede pasar por los siguientes niveles de oxígeno: 5, 6, 9, 3 y 8. El mínimo en este camino es 3. No hay ningún camino que evada al 3 o al 1, así que 3 es el máximo nivel que puede mantener en todo su trayecto.
||input
1 5
1 2 3 4 5
||output
1
||description
Solo hay un camino posible, y el valor mínimo de este camino es 1. 
||end
