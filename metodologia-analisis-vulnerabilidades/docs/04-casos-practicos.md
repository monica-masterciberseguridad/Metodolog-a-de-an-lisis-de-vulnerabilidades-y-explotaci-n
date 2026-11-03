# 4. Plan de prácticas con binarios

## 4.1. Laboratorio A: detección de escritura fuera de límites

**Objetivo:** compilar y ejecutar un programa propio que contiene un error de límites y observar el diagnóstico de AddressSanitizer.

Requisitos: Linux, GCC o Clang.

Código de ejemplo (`labs/buffer-overflow/demo.c`):

```c
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    char buffer[16];

    if (argc != 2) {
        fprintf(stderr, "Uso: %s <texto>\\n", argv[0]);
        return 1;
    }

    /* Intencionadamente inseguro: solo para este laboratorio local. */
    strcpy(buffer, argv[1]);

    printf("Entrada: %s\\n", buffer);
    return 0;
}
```

Compilación con sanitizador:

```bash
clang -g -O1 -fsanitize=address -fno-omit-frame-pointer \
  -o demo demo.c
```

Prueba de control (entrada corta):

```bash
./demo hola
```

Prueba de detección (entrada más larga que el buffer):

```bash
./demo 12345678901234567890
```

El sanitizador debería informar de una escritura fuera de límites. El texto exacto depende de la versión del compilador y del entorno.

**Corrección propuesta:** sustituir la copia no acotada por validación explícita de longitud y una operación segura acorde al diseño. La solución debe contemplar el byte nulo final y rechazar entradas que superen la capacidad.

**Evidencias a guardar:**
- `clang --version`
- comando de compilación
- ejecución de control
- diagnóstico del sanitizador
- versión corregida y prueba de regresión

## 4.2. Laboratorio B: fuzzing de un parser pequeño

**Objetivo:** conocer el ciclo de fuzzing con AFL++ sobre un objetivo de laboratorio.

Preparar un parser propio que acepte un archivo de entrada y valide una estructura sencilla. No utilizar servicios de terceros ni corpus con datos sensibles.

Flujo general:
1. Compilar el parser con el wrapper de instrumentación de AFL++.
2. Crear `seeds/` con varias entradas válidas pequeñas.
3. Crear un directorio de salida separado.
4. Ejecutar la campaña con límites de recursos adecuados.
5. Revisar los casos que producen fallos.
6. Minimizar cada caso y reproducirlo con el binario instrumentado y con sanitizadores.

Ejemplo de invocación una vez preparado un objetivo compatible:

```bash
afl-fuzz -i seeds -o findings -- ./parser @@
```

El comando es una plantilla: `parser` debe existir y aceptar un nombre de archivo mediante `@@`. La compilación y la instrumentación dependen del lenguaje y del modo de AFL++ elegido.

Registrar duración, cobertura reportada, número de casos, fallos, consumo aproximado y limitaciones. No presentar el número de ejecuciones como medida suficiente de calidad.

## 4.3. Laboratorio C: reversing básico

**Objetivo:** inspeccionar un binario de laboratorio sin modificarlo.

Comandos iniciales:

```bash
file ./demo
readelf -h ./demo
readelf -s ./demo
objdump -d ./demo
strings -n 5 ./demo
```

En Ghidra:
1. Crear un proyecto local.
2. Importar el binario propio.
3. Seleccionar el lenguaje/arquitectura detectado.
4. Ejecutar el análisis automático.
5. Localizar `main` y seguir referencias a funciones relevantes.
6. Comparar el pseudocódigo con el fuente.
7. Documentar qué información puede recuperarse y qué incertidumbres introduce la ausencia de símbolos.

## 4.4. Plantilla de registro de práctica

- Fecha:
- Autor:
- Sistema operativo y versión:
- CPU/arquitectura:
- Compilador/herramienta y versión:
- Hash SHA-256 del binario:
- Objetivo:
- Procedimiento:
- Resultado esperado:
- Resultado observado:
- Evidencias:
- Limitaciones:
- Conclusión:
