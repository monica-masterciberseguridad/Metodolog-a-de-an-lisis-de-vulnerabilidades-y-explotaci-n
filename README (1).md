# Laboratorio: fuzzing con AFL++

Preparar un parser de laboratorio propio que acepte un archivo de entrada y tenga un comportamiento determinista. Compilarlo con la instrumentación recomendada por la documentación de AFL++ para el compilador disponible.

Crear un corpus `seeds/` con entradas válidas y ejecutar, si el objetivo acepta un archivo por argumento:

```bash
afl-fuzz -i seeds -o findings -- ./parser @@
```

`parser` es un marcador: debe sustituirse por el binario real del laboratorio. Registrar configuración, duración, cobertura, fallos y recursos. Reproducir cada caso interesante fuera del fuzzer y minimizarlo antes de analizarlo.
