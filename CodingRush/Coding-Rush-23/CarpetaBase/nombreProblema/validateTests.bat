@echo off
REM Este script ejecuta solution.py con archivos de entrada y salida, los compara y limpia.

REM Verifica que se haya proporcionado exactamente un argumento
IF "%~1"=="" (
    echo Uso: %0 [numero maximo]
    exit /b 1
)

REM El argumento es el número máximo (inclusive) para el bucle
set max_number=%1
set all_coherent=1

REM Bucle desde 0 hasta max_number
FOR /L %%i IN (0,1,%max_number%) DO (
    REM Ejecuta Python con los archivos de entrada y guarda la salida en un directorio diferente
    python solution.py < ".\cases\%%i.in" > ".\cases\%%i.prueba"
    
    REM Compara los archivos de salida
    fc ".\cases\%%i.prueba" ".\cases\%%i.out" > nul
    IF NOT errorlevel 1 (
        echo El caso %%i no es coherente con la solucion en solution.py
        set all_coherent=0
    )
    
    REM Borra el archivo en el directorio pruebas
    del ".\cases\%%i.prueba"
)

IF "%all_coherent%"=="1" (
    echo Todos los casos son coherentes con la solucion.
)