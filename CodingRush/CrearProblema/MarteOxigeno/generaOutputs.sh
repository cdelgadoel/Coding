#!/bin/bash

# Este script ejecuta solution.py con archivos de entrada y salida, dependiendo de si el parámetro 1 es "-1" o no.

# Verifica que se haya proporcionado exactamente tres argumentos
if [ "$#" -ne 3 ]; then
    echo "Uso: $0 <grupo> <caso inicial> <caso final>"
    exit 1
fi

# Asigna los argumentos a variables para mejor claridad
grupo=$1
caso_inicial=$2
caso_final=$3

# Bucle desde caso_inicial hasta caso_final
for (( i = caso_inicial; i <= caso_final; i++ )); do
    # Decide el nombre del archivo en base al valor de grupo
    if [ "$grupo" == "-1" ]; then
        # Si el grupo es -1, no incluirlo en el nombre del archivo
        python solution.py < "./cases/$i.in" > "./cases/$i.out"
    else
        # Si el grupo no es -1, incluirlo en el nombre del archivo
        python solution.py < "./cases/$grupo.$i.in" > "./cases/$grupo.$i.out"
    fi
done
