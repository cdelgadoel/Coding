#!/bin/bash

# Este script ejecuta solution.py con archivos de entrada y salida en un bucle.

# Verifica que se haya proporcionado exactamente un argumento
if [ "$#" -ne 1 ]; then
    echo "Uso: $0 <número máximo>"
    exit 1
fi

# El argumento es el número máximo (inclusive) para el bucle
max_number=$1

# Bucle desde 0 hasta max_number
for (( i = 0; i <= max_number; i++ )); do
    # Ejecuta Python con los archivos de entrada y salida correspondientes
    python solution.py < "./cases/$i.in" > "./cases/$i.out"
done
