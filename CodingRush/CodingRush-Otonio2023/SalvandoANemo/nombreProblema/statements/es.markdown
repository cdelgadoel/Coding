# Descripción
Jorge es un gran entusiasta por ayudar a la vida marina. Una noticia ha captado su atención, en la que se habla de anillos de plástico que hay en el Océano Pacífico. Un fenómeno interesante es que puede haber anillos dentro de otro anillos. 

Como Jorge tiene muchas ganas de ayudar, decidió juntar esfuerzos para ir a recoger el plástico de un anillo, y de paso, todo el plástico dentro de ese anillo. Ayuda a Jorge a saber la máxima cantidad de plástico que puede recoger del océano. 

Para simplificar este problema, consideraremos que los anillos y el océano tienen forma rectangular. Se te dará una matriz, donde cada celda representa una unidad de agua o una unidad de plástico. Además se garantiza que los anillos no se van a traslapar entre sí. 

Por ejemplo, en la siguiente imagen se muestran cuatro anillos. Hay un anillo que tiene otros dos dentro y todos los demás no tienen ninguno dentro. 
![oceano](https://user-images.githubusercontent.com/47729566/284033746-bc3b60e6-c336-487e-b1be-fe7533b16332.jpg)

# Entrada
En la primera línea un número entero positivo $r$, el número de renglones que abarcará el océano.

En la segunda línea, un número entero positivo $c$ el número de columnas que abarcará cada renglón del océano.

En cada una de las siguientes $r$ líneas, habrá un string de $c$ caractéres. Cada caractér será una letra **'o'** o una letra **'x'**. Si la celda tiene una letra **'o'**, quiere decir que en esa celda hay agua. Si la celda tiene una letra **'x'**, quiere decir que en esa celda hay plástico. 

# Salida
Un solo entero, la máxima cantidad de plástico que Jorge puede recoger.

# Ejemplo
||input
11
13
xxxxxxxxxoooo
xoooooooxoxxx
xoxxxxxoxoxox
xoxoooxoxoxox
xoxxxxxoxoxox
xoooooooxoxxx
xoxxxxxoxoooo
xoxoooxoxoooo
xoxxxxxoxoooo
xoooooooxoooo
xxxxxxxxxoooo
||output
60
||description
La mejor opción es ir por el anillo que contiene otros dos anillos. Esto representa 60 unidades de plástico levantado.
||input
5
5
ooooo
oxxxo
oxoxo
oxxxo
ooooo
||output
8
||description
En este caso, solo hay un anillo, y Jorge recoge todo el plástico de ese anillo. 
||end

# Límites 
* 1 $\leq$ $r$, $c$ $\leq$ 1000