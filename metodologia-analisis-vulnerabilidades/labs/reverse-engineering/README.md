# Laboratorio: reversing básico

Utilizar el binario propio generado en `labs/buffer-overflow/`.

```bash
file ./demo
readelf -h ./demo
readelf -s ./demo
objdump -d ./demo
strings -n 5 ./demo
```

Importar el binario en Ghidra, ejecutar el análisis y localizar `main`. Comparar el pseudocódigo con el fuente y documentar arquitectura, símbolos, funciones y limitaciones.
