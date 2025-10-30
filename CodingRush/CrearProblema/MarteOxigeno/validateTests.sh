#!/bin/bash

# Este script ejecuta solution.py con archivos de entrada y salida, los compara y limpia.
# Se espera que reciba tres parámetros: grupo, caso inicial y caso final.

# Verifica que se hayan proporcionado exactamente tres argumentos
if [ "$#" -ne 3 ]; then
    echo "Uso: $0 <grupo> <caso inicial> <caso final>"
    exit 1
fi

# Asigna los argumentos a variables
grupo=$1
caso_inicial=$2
caso_final=$3
all_coherent=true

# Bucle desde caso_inicial hasta caso_final
for (( i = caso_inicial; i <= caso_final; i++ )); do
    # Decide el nombre del archivo basado en si el grupo es '-1'
    if [ "$grupo" == "-1" ]; then
        entrada="./cases/$i.in"
        salida_prueba="./cases/$i.prueba"
        salida_esperada="./cases/$i.out"
    else
        entrada="./cases/$grupo.$i.in"
        salida_prueba="./cases/$grupo.$i.prueba"
        salida_esperada="./cases/$grupo.$i.out"
    fi

    # Ejecuta Python con los archivos de entrada y guarda la salida en un directorio diferente
    python solution.py < "$entrada" > "$salida_prueba"

    # Compara los archivos de salida
    if ! cmp -s "$salida_prueba" "$salida_esperada"; then
        echo "El caso $i no es coherente con la solución en solution.py"
        all_coherent=false
    fi

    # Borra el archivo en el directorio pruebas
    rm "$salida_prueba"
done

# Imprime un mensaje si todos los casos son coherentes
if $all_coherent ; then
    echo "Todos los casos son coherentes con la solución."
fi
