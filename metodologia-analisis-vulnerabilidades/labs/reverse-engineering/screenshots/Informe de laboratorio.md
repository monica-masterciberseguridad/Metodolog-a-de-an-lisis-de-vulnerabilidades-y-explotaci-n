# Laboratorio 3 – Reverse Engineering

## 1. Introducción

En este laboratorio se ha realizado un ejercicio práctico de ingeniería inversa utilizando herramientas de análisis de binarios en un entorno Ubuntu.

El objetivo ha sido estudiar el funcionamiento de un programa desarrollado en lenguaje C a partir de su archivo ejecutable, identificando su estructura, sus funciones y las instrucciones generadas durante la compilación.

Para ello, se han utilizado herramientas como GCC, Readelf, Objdump, Strings y Ghidra, con el propósito de analizar las características del ejecutable y reconstruir su lógica mediante el análisis estático.

## 2. Entorno de trabajo

El laboratorio se ha desarrollado utilizando las siguientes herramientas:

- Sistema operativo: Ubuntu.
- Lenguaje de programación: C.
- Compilador: GCC 13.3.0.
- GNU Readelf: 2.42.
- GNU Objdump: 2.42.
- GNU Strings: 2.42.
- Herramienta de ingeniería inversa: Ghidra 12.2.

El programa desarrollado se ha denominado `programa` y su código fuente se encuentra en el archivo `programa.c`.

El ejecutable generado presenta las siguientes características:

- Formato: ELF (Executable and Linkable Format).
- Arquitectura: x86-64.
- Clase: 64 bits.
- Endianness: Little Endian.
- Compilador: GCC.
- 
- ## 3. Creación del programa

Para realizar el laboratorio se desarrolló un programa en lenguaje C con dos funciones principales:

- `main()`: contiene la función principal del programa, declara una variable de tipo cadena y muestra los resultados por pantalla.
- `calcular()`: recibe dos números enteros y devuelve su suma.

El programa utiliza una cadena de texto con el nombre «Reverse Engineering» y realiza una operación matemática con los valores 10 y 20.

El código fuente se guardó en el archivo `programa.c`.

## 4. Compilación del binario

Una vez desarrollado el código fuente, se utilizó el compilador GCC para generar el archivo ejecutable.

Se empleó el siguiente comando:

```bash
gcc -g -O0 programa.c -o programa
```

Las opciones utilizadas fueron:

- `-g`: incorpora información de depuración.
- `-O0`: evita las optimizaciones del compilador.
- `-o programa`: establece el nombre del ejecutable generado.

Posteriormente, se utilizaron los comandos `ls -lh` y `file` para comprobar la existencia del archivo y consultar sus características.

El resultado confirmó que se había generado correctamente un ejecutable ELF de 64 bits para arquitectura x86-64.

## 5. Análisis del formato ELF

Una vez generado el ejecutable, se utilizó la herramienta GNU Readelf para examinar su estructura interna.

Se ejecutó el siguiente comando:

```bash
readelf -h programa
```

El análisis de la cabecera permitió identificar las siguientes características:

- Formato ELF de 64 bits.
- Arquitectura x86-64.
- Codificación Little Endian.
- Sistema operativo ABI: UNIX System V.
- Tipo de archivo: DYN (Position-Independent Executable).

Estos datos permiten conocer la estructura y las características principales del archivo ejecutable generado por GCC.

## 6. Análisis de la tabla de símbolos

A continuación, se utilizó el comando:

```bash
readelf -s programa
```

Este comando permitió consultar la tabla de símbolos del ejecutable.

Posteriormente, se filtraron los símbolos relacionados con las funciones principales mediante:

```bash
readelf -s programa | grep -E 'main|calcular|printf'
```

Se identificaron los siguientes elementos:

- `main`: función principal del programa.
- `calcular`: función encargada de realizar la suma.
- `printf`: función externa utilizada para mostrar información por pantalla.

La presencia de estos símbolos facilita la identificación de las funciones y dependencias del programa durante el análisis estático.

## 7. Análisis de cadenas del ejecutable

Para identificar las cadenas de texto almacenadas en el binario se utilizó la herramienta Strings.

Se ejecutó el siguiente comando:

```bash
strings -n 5 programa
```

Entre las cadenas identificadas destacan:

- `Reverse Engineering`
- `Nombre: %s`
- `Resultado: %d`
- `calcular`
- `nombre`
- `resultado`

También se identificaron referencias a bibliotecas del sistema y a información del compilador GCC.

Este análisis permitió localizar información relevante del programa sin necesidad de ejecutar el binario.

## 8. Ejecución del programa

Finalmente, se ejecutó el archivo generado mediante:

```bash
./programa
```

La salida obtenida fue:

```text
Nombre: Reverse Engineering
Resultado: 30
```

El resultado confirma que el programa muestra correctamente la cadena de texto y realiza la suma de los valores 10 y 20 mediante la función `calcular()`.

La ejecución permitió comprobar que el comportamiento del programa coincide con la lógica implementada en el código fuente.

## 9. Análisis estático con Ghidra

Para realizar un análisis más detallado del ejecutable se utilizó Ghidra, una herramienta de ingeniería inversa que permite examinar binarios, visualizar instrucciones ensamblador y generar pseudocódigo.

Se creó un proyecto denominado `Laboratorio-Reverse-Engineering` y se importó el ejecutable `programa`.

Ghidra reconoció correctamente el formato ELF y la arquitectura x86-64.

A continuación, se ejecutó el análisis automático del binario mediante las opciones predeterminadas.

## 10. Análisis de la función main()

Dentro de Ghidra se localizó la función `main()` mediante el árbol de símbolos.

El análisis permitió identificar:

- La declaración de una cadena de caracteres.
- La asignación del texto «Reverse Engineering».
- La llamada a la función `calcular()` con los argumentos 10 y 20.
- Las llamadas a `printf()` para mostrar los resultados.
- La presencia de un mecanismo de protección de pila.

Ghidra generó una representación en pseudocódigo que permitió comprender la lógica general de la función sin consultar directamente el código fuente.

11. Análisis de la función calcular()

También se localizó la función calcular() en el árbol de funciones de Ghidra.

El pseudocódigo reconstruido permitió identificar que recibe dos parámetros enteros, realiza una suma y devuelve el resultado.

La operación reconstruida es equivalente a:

int calcular(int a, int b) {
    return a + b;
}

Este resultado coincide con el comportamiento observado durante la ejecución del programa.

## 12. Conclusiones

En este laboratorio se realizó un análisis estático básico de un programa compilado en C mediante herramientas de línea de comandos y Ghidra.

Se identificó el formato ELF del ejecutable y se examinaron su cabecera, tabla de símbolos y cadenas de texto. También se utilizó `objdump` para consultar el desensamblado y se ejecutó el programa para comprobar su comportamiento.

Finalmente, mediante Ghidra se localizaron las funciones `main()` y `calcular()`, y se examinó su pseudocódigo. El análisis permitió comprobar que el programa almacena una cadena de texto, realiza una suma de dos valores y muestra ambos resultados por pantalla.

El laboratorio permitió practicar técnicas básicas de ingeniería inversa y conocer cómo obtener información de un binario sin depender exclusivamente de su código fuente.

## 13. Evidencias

Las capturas de pantalla realizadas durante el laboratorio se encuentran en la carpeta `screenshots` de este directorio.

Incluyen evidencias de las herramientas instaladas, el código fuente, la compilación, el análisis del formato ELF, la tabla de símbolos, las cadenas de texto, el desensamblado, la ejecución del programa y el análisis realizado con Ghidra.
