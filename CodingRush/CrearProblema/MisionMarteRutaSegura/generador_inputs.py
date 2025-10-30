import random
import os
from math import *

def genera_input_string(num):
    n = random.randint(2, 100)
    m = random.randint(2, 100)
    caso = f"{n} {m}\n"
    ma = []
    for i in range(n):
        ma.append([])
        for j in range(m):
            if num%2 == 0:
                ma[i].append(".X"[random.randint(0, 1)])
            else:
                ma[i].append(".")
    m1, m2 = random.randint(0, n-1), random.randint(0, m-1)
    ma[m1][m2] = 'M'
    d1, d2 = random.randint(0, n-1), random.randint(0, m-1)
    while d1 == m1 and d2 == m2:
        d1, d2 = random.randint(0, n-1), random.randint(0, m-1)
    ma[d1][d2] = 'D'
    for i in range(n):
        for j in range(m):
            caso += f"{ma[i][j]}"
        caso += "\n"
    return caso
        
if __name__ == '__main__':
    cantidad_casos_manuales = 2
    cantidad_casos_automaticos = 13
    nombre_grupo = 'g1'
    for caso in range(cantidad_casos_manuales, cantidad_casos_manuales + cantidad_casos_automaticos):
        if nombre_grupo:
            nombre_caso = f'{nombre_grupo}.{caso}'
        else:
            nombre_caso = f'{caso}'
        
        input_string = genera_input_string(caso)

        # lo unico que hace la funcion es pegar los strings con una diagonal /
        path_archivo = os.path.join('cases', f'{nombre_caso}.in')
        with open(path_archivo, 'w') as f:
            f.write(input_string.strip('\t\n\r'))