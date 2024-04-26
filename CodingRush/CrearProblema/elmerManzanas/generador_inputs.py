import random
import os
from math import *

def genera_input_string():
    n = random.randint(1, 100000)
    string_caso = f"{n}\n" # \n es el salto de linea
    for i in range(n):
        string_caso += f"{random.randint(1, 100000)}\n"
    return string_caso

if __name__ == '__main__':
    cantidad_casos_manuales = 2
    cantidad_casos_automaticos = 18
    nombre_grupo = ''
    for caso in range(cantidad_casos_manuales, cantidad_casos_manuales + cantidad_casos_automaticos):
        if nombre_grupo:
            nombre_caso = f'{nombre_grupo}.{caso}'
        else:
            nombre_caso = f'{caso}'
        
        input_string = genera_input_string()

        # lo unico que hace la funcion es pegar los strings con una diagonal /
        path_archivo = os.path.join('cases', f'{nombre_caso}.in')
        with open(path_archivo, 'w') as f:
            f.write(input_string.strip('\t\n\r'))