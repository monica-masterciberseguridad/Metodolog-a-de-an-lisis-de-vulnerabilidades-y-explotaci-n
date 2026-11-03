# 2. Metodología de análisis de vulnerabilidades

## 2.1. Fase 0: autorización y definición del alcance

Antes de realizar pruebas se documentan:

- Propietario del software y autorización.
- Versiones, plataformas y componentes incluidos.
- Interfaces de entrada y dependencias.
- Técnicas permitidas y excluidas.
- Ventana de pruebas, límites de recursos y contactos de emergencia.
- Reglas de tratamiento de datos y conservación de evidencias.

El resultado es un documento de alcance. Una prueba técnicamente correcta puede ser improcedente si se realiza fuera de la autorización concedida.

## 2.2. Fase 1: reconocimiento y modelado

Se identifica qué hace el programa, cómo se ejecuta y qué datos procesa.

Actividades:
- Identificar formato, arquitectura, sistema operativo y dependencias.
- Enumerar argumentos, archivos, sockets, protocolos y APIs de entrada.
- Revisar permisos, privilegios, límites de confianza y componentes externos.
- Dibujar un flujo de datos desde la entrada hasta las operaciones sensibles.
- Priorizar parsers, deserializadores, formatos complejos y código nativo.

Herramientas orientativas: `file`, `strings`, `readelf`, `objdump`, `ldd` (con cautela), documentación del fabricante y SBOM cuando exista.

## 2.3. Fase 2: análisis estático

Se estudia el código fuente o el binario sin depender de una ejecución concreta.

En código fuente:
- Revisar límites de buffers, conversiones de tipos y aritmética de tamaños.
- Buscar uso inseguro de memoria, liberaciones dobles y referencias colgantes.
- Comprobar validación de entradas y manejo de errores.
- Revisar llamadas a funciones sensibles y rutas alternativas.

En binarios:
- Identificar arquitectura, símbolos, secciones e imports.
- Reconstruir funciones y flujo de control.
- Localizar comparaciones, operaciones de copia, asignaciones y validaciones.
- Relacionar referencias cruzadas con entradas controlables.

Herramientas: Ghidra, IDA Free, Binary Ninja (según licencia), `objdump`, `readelf` y analizadores estáticos.

El análisis estático genera hipótesis; no demuestra por sí solo que una ruta sea alcanzable ni que el fallo sea explotable.

## 2.4. Fase 3: análisis dinámico

Se ejecuta el programa con entradas controladas y se observa su comportamiento.

Técnicas:
- Depuración paso a paso.
- Inspección de argumentos, registros, memoria y pila.
- Trazado de llamadas y errores.
- Instrumentación con AddressSanitizer y UndefinedBehaviorSanitizer.
- Comparación entre entradas válidas, límites y entradas malformadas.

Herramientas: GDB, LLDB, Valgrind, sanitizadores de Clang/GCC y trazas del sistema.

Se registra el comportamiento normal antes de introducir entradas anómalas. Esto ayuda a distinguir un fallo nuevo de un comportamiento esperado.

## 2.5. Fase 4: fuzzing

El fuzzing genera o muta entradas para explorar rutas de ejecución y detectar comportamientos anómalos.

Flujo recomendado:
1. Elegir un objetivo pequeño y una interfaz de entrada estable.
2. Preparar un corpus inicial de muestras válidas.
3. Instrumentar el programa si la herramienta y el código lo permiten.
4. Configurar límites de tiempo, memoria y espacio.
5. Ejecutar la campaña y monitorizar cobertura y recursos.
6. Agrupar fallos, minimizar casos y reproducirlos fuera del fuzzer.
7. Clasificar el fallo y conservar el caso mínimo.

AFL++ recomienda instrumentar el objetivo, preparar el corpus y ejecutar la campaña; también advierte de los recursos que puede consumir el fuzzing. Véase la bibliografía.

Un crash no equivale automáticamente a una vulnerabilidad explotable. Debe investigarse la causa raíz, la alcanzabilidad, el impacto y las condiciones necesarias.

## 2.6. Fase 5: validación e impacto

Para cada hipótesis se intenta obtener una reproducción mínima, consistente y no destructiva.

Se documenta:
- Entrada que activa el fallo.
- Versión y configuración exactas.
- Resultado esperado y observado.
- Tipo de fallo: crash, corrupción, lectura/escritura fuera de límites, bypass, etc.
- Privilegios requeridos e interacción necesaria.
- Impacto en confidencialidad, integridad y disponibilidad.
- Mitigaciones existentes y factores que reducen o aumentan el riesgo.

La severidad debe justificarse con el contexto del producto y, cuando proceda, una métrica como CVSS. No se asigna una puntuación sin explicar sus supuestos.

## 2.7. Fase 6: análisis de causa raíz y mitigación

La recomendación debe corregir la causa, no limitarse a ocultar el síntoma.

Ejemplos:
- Validar longitud y estructura antes de copiar o procesar datos.
- Comprobar desbordamientos aritméticos al calcular tamaños.
- Preferir APIs que reciben el tamaño del destino.
- Gestionar correctamente propiedad y vida útil de memoria.
- Aplicar límites de recursos y defensas de compilación.
- Añadir pruebas unitarias, regresión y fuzzing continuo.

## 2.8. Fase 7: informe y seguimiento

El informe incluye resumen ejecutivo, descripción técnica, impacto, reproducción, evidencias, mitigación y referencias. Tras la corrección, se repite el caso de prueba y se comprueba que no se ha introducido una regresión.

## 2.9. Mentalidad del analista

La investigación debe ser escéptica y sistemática: formular hipótesis, intentar refutarlas, separar hechos de inferencias, conservar resultados negativos y evitar afirmar explotabilidad sin pruebas. La calidad del informe es parte del trabajo técnico.
