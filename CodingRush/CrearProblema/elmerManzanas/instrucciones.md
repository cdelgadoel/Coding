# ¿Cómo subir un problema en OmegaUp?

Primero copia la carpeta base y cambia su nombre por el del problema a subir.

Hay varios archivos y carpetas, pero lo más importante es la carpeta de `cases`, de `statements` y el archivo `solution.py`. Los otros archivos son para ayudarte a hacer algunas cosas más fácil. 

Ya que hayas modificado cada cosa, mándanos la carpeta en un .zip a **itamcodingrush@gmail.com**.

Ahora así, veamos cómo modificar cada cosa. 


## statements
Hay una archivo que se llama `es.markdown`. Ahí pega la redacción del problema. Checa que se vea bien la redacción en esta [página](https://omegaup.com/redaccion.php).

Es también en esta carpeta donde se pone la plantilla, en caso de que quieras incluir una. Nombra al archivo `plantilla.py`, e inclúyela en la redacción del problema poniendo este bloque de código al final del archivo:
```
<details><summary>Checa la `plantilla.py`</summary>

{{plantilla.py}}
```

## cases
Aquí es donde pondrás los casos que deberá pasar el algoritmo para considerarse correcto. Puedes crear tantos casos como quieras. 

La recomendación es que crees manualmente casos extremos, y que crees algunos mediante el archivo generador_inputs.py que se encuentra dentro de la carpeta base inicial. Esto te ayudará a crear casos donde el input sea muy grande, que claramente no queremos generar a mano. 

También puedes generar los casos completamente a mano, solo asegúrate de que las pruebas sean adecuadas y no insuficientes para que algoritmos incorrectos sean calificados como correctos. 

Cada caso tendrá un archivo de entrada y un archivo con la salida esperada. La terminación del archivo de entrada es `.in` y la de la salida esperada es `.out`. Dentro del archivo de entrada literalmente va el caso a evaluar, y en el archivo de salida va la respuesta. 

Así, supongamos que hay tres casos. Entonces, habría seis archivos en esta carpeta: $0.in$, $0.out$, $1.in$, $1.out$, $2.in$, y $2.out$.

### Agrupar casos
Hay una cosa importante para los problemas en los que la salida es `SI` o `NO`, o en los que son pocas las opciones de salida. En el caso de "SI"/"NO", alguien podría mandar una solución que sea `print("SI")` y obtener la mitad de los puntos del problema. Es por esto que se pueden agrupar casos. Para esto, ponle a los casos que quieras agrupar el prefijo que indique el nombre del grupo.

Siguiendo con el ejemplo de tener tres casos, y suponiendo que queremos agrupar los primeros dos casos, entonces el contenido de la carpeta sería:  $grupo1.0.in$, $grupo1.0.out$, $grupo1.1.in$, $grupo1.1.out$, $2.in$, y $2.out$.

## solutions(Opcional)
En la carpeta **solutions**, hay un archivo que se llama `es.markdown`. Hay redacta la solución a tu problema, es decir, las ideas u observaciones que llevan a crear el algoritmo que resuelve el problema. 

## solution.py
Pega aquí la solución del problema.

## genera_inputs.py
Como se mencionó, este archivo ayuda a generar casos *automáticamente*. Solo genera la entrada de los casos, es decir, los archivos `.in`. Para generar los `.out` se usará el archivo `genera_outputs.py`.

Lo que hace el archivo es usar un for. En cada iteración del for creará un caso nuevo. Para que esto pase, necesitamos crear un string que contenga el caso y luego guardarlo dentro de un archivo `.in` dentro de la carpeta de cases. La variable `nombre_caso` guardará el nombre del archivo donde se va a guardar el caso.

Así, lo que hay que modificar es lo siguiente:
1. la variable `cantidad_casos_manuales`: un entero que contenga el número de casos manuales que quieres generar en total. 
2. la variable `cantidad_casos_automaticos`: un entero que contenga el número de casos que quieres generar automáticamente. 
3. la variable `nombre_grupo`: solo es necesario modificarla si los casos a generar van dentro de un grupo. 
4. la función `genera_input_string`: debe devolver un string que contenga el caso que se va a guardar dentro del archivo de entrada.
    
    Te puedes ayudar de la librería random de python para generar números diferentes en cada caso. 

    También usa el caractér `\n` para representar los saltos de línea en el archivo. 

    Habrá veces en que quieras pegarle valores numéricos o valor de variables al caso. Para esto puedes usar *f-strings* de python. Búscalos en línea si no los conoces.  

    Por ejemplo, supongamos que nuestro input tiene primero una línea con un entero $n$ que está entre 1 y 100, luego hay $n$ líneas, cada una con un entero entre 30 y 1000. 

    Entonces la función se escribiría de la siguiente forma:
    ```python
    def genera_input_string():
        n = random.randint(1, 100)
        input_string = f'{n}\n'
        for _ in range(n):
            num = random.randint(30, 1000)
            input_string += f'{num}\n'
        return input_string
    ```
    
No olvides agregar los casos manuales si vas a incluirlos.

Ya que dejaste tu programa `generador_inputs.py` como querías, tienes que correrlo. Esto es corriéndolo como cualquier otro archivo de python. Por ejemplo, si estás en una terminal colocado en la misma carpeta donde está el archivo, solo corre `python generador_inputs.py`.

## Generar la respuesta a los casos de prueba (archivos .out)
Para esto, escribe se usará la solución al problema que está en el archivo `solution.py`. Lo siguiente depende de tu sistema operativo. 

### Si estás en Linux o MacOS
Necesitarás correr el script `generaOutputs.sh` y darle como argumentos:
-  el grupo al que pertenecen los casos para los que generarás el output o -1 si no tienen grupo.
-  el caso inicial del grupo
-  el caso final del grupo (inclusivo)

Por ejemplo, si tienes del caso 2 al 19 sin grupo, correrás `bash generaOutputs.sh -1 2 19`.

Por otro lado, si tienes del caso 0 al 100 en el grupo g0, correrás `bash generaOutputs.sh g0 0 100`.


### Si estás en Windows
Necesitarás correr el script `generaOutputs.bat` y darle como argumentos:
-  el grupo al que pertenecen los casos para los que generarás el output o -1 si no tienen grupo.
-  el caso inicial del grupo
-  el caso final del grupo (inclusivo)

Por ejemplo, si tienes del caso 2 al 19 sin grupo, correrás `generaOutputs.bat -1 2 19`.

Por otro lado, si tienes del caso 0 al 100 en el grupo g0, correrás `generaOutputs.bat g0 0 100`.

## Validar tus casos
Esto es especialmente importante para los casos generados manualmente. Validar estos casos con tu solución ayudará a mantener la coherencia de los casos. 

También puede ayudarte a probar otras soluciones al problema y ver que todas producen los mismos resultados. Para ello tendrán que poner la solución nueva que quieras probar en el archivo `solution.py`.

Lo siguiente depende de tu sistema operativo. 

### Si estás en Linux o MacOS
Necesitarás correr el script `validateTests.sh` y darle como argumentos:
-  el grupo al que pertenecen los casos para los que generarás el output o -1 si no tienen grupo.
-  el caso inicial del grupo
-  el caso final del grupo (inclusivo)

Por ejemplo, si tienes del caso 2 al 19 sin grupo, correrás `bash validateTests.sh -1 2 19`.

### Si estás en Windows
Necesitarás correr el script `validateTests.bat` y darle como argumentos:
-  el grupo al que pertenecen los casos para los que generarás el output o -1 si no tienen grupo.
-  el caso inicial del grupo
-  el caso final del grupo (inclusivo)

Por ejemplo, si tienes del caso 2 al 19 sin grupo, correrás `validateTests.bat -1 2 19`.

