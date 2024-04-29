# Description
La delegación croata, consistente en $M$ personas, está viajando a la el Coding Rush versiAustralia. Actualmente están esperando en una fila para el check-in en el aeropuerto. Hay $N$ mostradores de check-in abiertos. Algunos oficiales trabajan de manera más eficiente que otros, por lo que los mostradores operan a diferentes velocidades. En el $k$-ésimo mostrador, se requieren $T_k$ segundos para completar el check-in de un solo pasajero, y los miembros de nuestra delegación conocen exactamente estos números.

Al principio, todos los mostradores están listos para aceptar al siguiente pasajero, y los miembros de la delegación son las únicas personas en la fila. Una persona solo puede ocupar (empezar el check-in en) un mostrador disponible cuando todas las personas frente a ella en la fila han dejado la fila (han empezado, no necesariamente terminado, el check-in) ya. En ese momento, la persona puede ocupar inmediatamente un mostrador disponible (si hay uno), pero también puede optar por esperar otro mostrador (más rápido) que se libere. Los miembros de nuestra delegación, siendo geeks de la informática, toman esta decisión de tal manera que el momento en que todos ellos hayan terminado el check-in sea lo más pronto posible. Tu tarea es encontrar ese momento en el tiempo.

Describamos el escenario del primer ejemplo a continuación. Hay dos mostradores, con tiempos de procesamiento de 7 y 10 segundos, respectivamente. De las seis personas en la delegación, las primeras dos ocupan inmediatamente los dos mostradores. A tiempo 7, el primer mostrador se libera, y la tercera persona lo ocupa. A tiempo 10, la cuarta persona ocupa el segundo mostrador. A tiempo 14, la quinta persona ocupa el primer mostrador. A tiempo 20, el segundo mostrador se libera nuevamente, pero la sexta persona decide esperar un segundo más (tiempo 21) para que el primer mostrador se vuelva disponible, y luego lo ocupa. De esta manera, el check-in se completa a tiempo 28. Si la sexta persona no hubiera esperado por el mostrador más rápido, el check-in habría tomado un total de 30 segundos.
# Input

La primera línea de entrada contiene dos enteros positivos, $N$, el número de mostradores, y $M$ (1$\leq M \leq 1000$), el número de personas en la delegación.

Cada una de las siguientes $N$ (1$\leq N \leq 1000$) líneas contiene un número del enunciado del problema (1$\leq T_k \leq 100$).

# Output

La primera y única línea de salida debe contener el tiempo mínimo requerido en segundos.

# Example
||input
2 6
7
10
||output
28
||input
7 10
3
8
3
6
9
2
4
||output
8
||end
