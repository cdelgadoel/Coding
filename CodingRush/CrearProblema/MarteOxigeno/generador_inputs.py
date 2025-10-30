import random
import os
from math import *

def genera_extremo():
    n = 100
    caso = f"{n} {n}\n"
    mat = []
    for i in range(n):
        mat.append([0]*n)
    
    mat[n-1][0] = 10000//2
    for i in range(1, n):
        mat[n-1 - i][i] = i
    
    for i in range(0, n-1):
        mat[i][0] = 10000 - i
    for i in range(1, n):
        mat[n-1][i] = 10000 - 100 + 1 - i

    for i in range(n):
        for j in range(n):
            if mat[i][j] == 0:
                mat[i][j] = 10000 - i*n - j
    
    for i in range(n):
        for j in range(n):
            caso += f"{mat[i][j]}" + " \n"[j==n-1]
    return caso

def genera_input_string():
    n = random.randint(1, 100)
    m = random.randint(1, 100)
    caso = f"{n} {m}\n"
    for i in range(n):
        for j in range(m):
            caso += f"{random.randint(1, 10000)}" + " \n"[j==m-1]
    return caso
if __name__ == '__main__':
    cantidad_casos_manuales = 3
    cantidad_casos_automaticos = 17
    nombre_grupo = 'g0'
    for caso in range(cantidad_casos_manuales, cantidad_casos_manuales + cantidad_casos_automaticos):
        if nombre_grupo:
            nombre_caso = f'{nombre_grupo}.{caso}'
        else:
            nombre_caso = f'{caso}'
        
        if caso != cantidad_casos_manuales:
            input_string = genera_input_string()
        else:
            input_string = genera_extremo()

        # lo unico que hace la funcion es pegar los strings con una diagonal /
        path_archivo = os.path.join('cases', f'{nombre_caso}.in')
        with open(path_archivo, 'w') as f:
            f.write(input_string.strip('\t\n\r'))