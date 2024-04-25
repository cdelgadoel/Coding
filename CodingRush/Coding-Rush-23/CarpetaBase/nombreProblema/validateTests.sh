#!/bin/bash

# Este script ejecuta solution.py con archivos de entrada y salida, los compara y limpia.

# Verifica que se haya proporcionado exactamente un argumento
if [ "$#" -ne 1 ]; then
    echo "Uso: $0 <número máximo>"
    exit 1
fi

# El argumento es el número máximo (inclusive) para el bucle
max_number=$1
all_coherent=true

# Bucle desde 0 hasta max_number
for (( i = 0; i <= max_number; i++ )); do
    # Ejecuta Python con los archivos de entrada y guarda la salida en un directorio diferente
    python solution.py < "./cases/$i.in" > "./cases/$i.prueba"

    # Compara los archivos de salida
    if ! cmp -s "./cases/$i.prueba" "./cases/$i.out"; then
        echo "El caso $i no es coherente con la solución en solution.py"
        all_coherent=false
    fi

    # Borra el archivo en el directorio pruebas
    rm "./cases/$i.prueba"
done

if $all_coherent ; then
    echo "Todos los casos son coherentes con la solución."
fi
