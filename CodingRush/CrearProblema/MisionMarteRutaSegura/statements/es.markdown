# Descripción del Problema
María ha aterrizado en Marte y necesita llegar a un punto específico para instalar una señal de comunicación. El terreno en Marte está dividido entre áreas habitables e inhabitables. María solo puede moverse por áreas habitables y necesita tu ayuda para determinar si puede llegar a su destino.

El mapa de Marte se representa como una matriz de caracteres, donde cada celda puede ser:

- "." : Territorio habitable.
- "X" : Territorio inhabitable.
- "M" : El punto inicial de María.
- "D" : Destino de María. 

María puede moverse horizontal o verticalmente entre las celdas habitables, pero no puede moverse diagonalmente ni entrar en zonas inhabitables.

# Objetivo
Determinar si María puede llegar al destino desde su punto de inicio, moviéndose solo por territorio habitable. 

# Entrada
La primera línea contiene dos enteros, 
$N$ y $M$ ($2 \leq N, M \leq 100$), que indican las dimensiones de la matriz. Las siguientes $N$ líneas contienen cada una un string de $M$ caracteres que representa una fila del mapa de Marte.

# Salida
Imprimir "EUREKA" si María puede llegar al destino usando solo áreas habitables, de lo contrario imprimir "SEND HELP".

# Ejemplo
||input
4 4
M...
..X.
XXX.
...D
||output
EUREKA
||description
María puede moverse hacia la derecha desde su posición inicial hasta llegar a la esquina, y luego desplazarse a la esquina de abajo, llegando a su destino utilizando solo territorio habitable.
||input
4 5
M.X.X
..XDX
XXX.X
....X
||output
SEND HELP
||description
No hay forma de moverse por territorio habitable de forma que María llegue a su destino.
||end
