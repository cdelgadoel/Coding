@echo off
REM Este script ejecuta solution.py con archivos de entrada y salida en un bucle.

REM Verifica que se haya proporcionado exactamente un argumento
IF "%~1"=="" (
    echo Uso: %0 [numero maximo]
    exit /b 1
)

REM El argumento es el número máximo (inclusive) para el bucle
set max_number=%1

REM Bucle desde 0 hasta max_number
FOR /L %%i IN (0,1,%max_number%) DO (
    REM Ejecuta Python con los archivos de entrada y salida correspondientes
    python solution.py < ".\cases\%%i.in" > ".\cases\%%i.out"
)

echo Proceso completado.
