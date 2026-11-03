# Laboratorio: escritura fuera de límites

Ejecutar únicamente en una máquina virtual local. Este ejemplo contiene intencionadamente un error de memoria.

```bash
clang -g -O1 -fsanitize=address -fno-omit-frame-pointer -o demo demo.c
./demo hola
./demo 12345678901234567890
```

Guardar el diagnóstico generado por AddressSanitizer y comparar con una versión corregida que valide `strlen(argv[1])` antes de copiar. Registrar las versiones y no afirmar resultados hasta ejecutar los comandos.
