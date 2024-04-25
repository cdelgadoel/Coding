@echo off
REM Este script ejecuta solution.py con archivos de entrada y salida, los compara y limpia.
REM Se espera que reciba tres parámetros: grupo, caso inicial y caso final.

REM Verifica que se hayan proporcionado exactamente tres argumentos
if "%~3"=="" (
    echo Uso: %0 [grupo] [caso inicial] [caso final]
    exit /b
)

REM Asigna los argumentos a variables
set "grupo=%1"
set /a "caso_inicial=%2"
set /a "caso_final=%3"
set "all_coherent=1"

REM Bucle desde caso_inicial hasta caso_final
for /L %%i in (%caso_inicial%,1,%caso_final%) do (
    REM Decide el nombre del archivo basado en si el grupo es '-1'
    if "%grupo%"=="-1" (
        set "entrada=.\cases\%%i.in"
        set "salida_prueba=.\cases\%%i.prueba"
        set "salida_esperada=.\cases\%%i.out"
    ) else (
        set "entrada=.\cases\%grupo%.%%i.in"
        set "salida_prueba=.\cases\%grupo%.%%i.prueba"
        set "salida_esperada=.\cases\%grupo%.%%i.out"
    )

    REM Ejecuta Python con los archivos de entrada y guarda la salida en un directorio diferente
    python solution.py < "%entrada%" > "%salida_prueba%"

    REM Compara los archivos de salida
    fc "%salida_prueba%" "%salida_esperada%" > nul
    if not errorlevel 1 (
        echo El caso %%i no es coherente con la solucion en solution.py
        set "all_coherent=0"
    )

    REM Borra el archivo en el directorio pruebas
    del "%salida_prueba%"
)

REM Imprime un mensaje si todos los casos son coherentes
if "%all_coherent%"=="1" (
    echo Todos los casos son coherentes con la solucion.
)
