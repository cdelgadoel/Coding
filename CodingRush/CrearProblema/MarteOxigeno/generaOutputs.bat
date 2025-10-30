@echo off
REM Este script ejecuta solution.py con archivos de entrada y salida, dependiendo de si el parametro 1 es "-1" o no.

REM Verifica que se hayan proporcionado exactamente tres argumentos
if "%~3"=="" (
    echo Uso: %0 [grupo] [caso inicial] [caso final]
    exit /b
)

REM Asigna los argumentos a variables para mayor claridad
set "grupo=%1"
set /a "caso_inicial=%2"
set /a "caso_final=%3"

REM Bucle desde caso_inicial hasta caso_final
for /L %%i in (%caso_inicial%,1,%caso_final%) do (
    REM Decide el nombre del archivo en base al valor de grupo
    if "%grupo%"=="-1" (
        REM Si el grupo es -1, no incluirlo en el nombre del archivo
        python solution.py < ".\cases\%%i.in" > ".\cases\%%i.out"
    ) else (
        REM Si el grupo no es -1, incluirlo en el nombre del archivo
        python solution.py < ".\cases\%grupo%.%%i.in" > ".\cases\%grupo%.%%i.out"
    )
)

echo Proceso completado.
exit /b
