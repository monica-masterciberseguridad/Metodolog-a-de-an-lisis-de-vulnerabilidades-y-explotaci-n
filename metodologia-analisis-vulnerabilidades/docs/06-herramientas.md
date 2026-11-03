# 6. Herramientas y selección

| Herramienta | Uso principal | Consideraciones |
|---|---|---|
| Ghidra | Ingeniería inversa y análisis estático | La interpretación del analista sigue siendo necesaria |
| GDB / LLDB | Depuración dinámica | Trabajar con binarios de laboratorio |
| AFL++ | Fuzzing guiado por cobertura | Requiere preparar objetivo y corpus; consume recursos |
| AddressSanitizer | Detección de errores de memoria | Requiere recompilar con instrumentación compatible |
| UndefinedBehaviorSanitizer | Detección de ciertos comportamientos indefinidos | No detecta todas las clases de fallos |
| Valgrind | Análisis dinámico de memoria | Puede ralentizar considerablemente la ejecución |
| readelf / objdump | Inspección de ELF y desensamblado | La salida depende de arquitectura y símbolos |
| Git | Trazabilidad de cambios | No almacenar secretos, dumps sensibles ni binarios propietarios |

## Criterios de selección

La herramienta se elige en función de la pregunta técnica. Para localizar rutas de entrada puede ser útil el análisis estático; para confirmar un acceso inválido, un sanitizador; para explorar combinaciones de entradas, fuzzing; y para entender el estado del proceso, un depurador.

Ninguna herramienta sustituye la revisión de causa raíz ni la validación manual de falsos positivos.
