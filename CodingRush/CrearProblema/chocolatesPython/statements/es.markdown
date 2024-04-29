# Description
Christian recientemente fue contratado por el Centro de Investigación en Inteligencia Computacional (CIIC). Esta compañía paga a sus empleados diariamente con una cantidad de chocolates que varía de acuerdo al estado de las finanzas de la empresa. Christian se ha comprometido con su médico de cabecera a mantener una dieta de chocolates diaria constante, es decir, va a comer la misma cantidad de chocolates durante todos los días que trabaje en CIIC.

Cuando él recibe la paga, él puede comer algunos de esos chocolates (siempre guardando su dieta de chocolates por día) y guardar alguna cantidad que prefiera para comerlos en otra ocasión y así poder cumplir con su dieta de chocolates. El logró predecir las finanzas de la empresa de los próximos $N$ días, así que sabe cuántos chocolates recibirá cada día.

Christian quieren encontrar un mejor amigo para que le diga cuánto es el máximo número de chocolates que podrá comer diariamente dadas las condiciones mencionadas anteriormente. ¡Usted podría ser ese mejor amigo!

# Task
Dados la cantidad de días que Christian trabajará en la CIIC y el número de chocolates que recibirá cada día, calcule el máximo número de chocolates que puede comer por día preservando la dieta. Es decir, garantizando que pueda consumir la misma cantidad todos los días.

# Input
Línea 1: Un entero $N$ la cantidad de días que Christian trabajará en la CIIC.
Luego, por cada una de las siguientes $N$ ($1 \leq N \leq  10000 $) líneas, $c_i$ ($1 \leq c_i \leq 100000$), la cantidad de chocolates que recibirá en el día i-ésimo.


# Output
Un entero $M$ el máximo número de chocolates que puede comer por día preservando la dieta.

# Example
||input
5
6
4
1
3
5
||output
3
||end

