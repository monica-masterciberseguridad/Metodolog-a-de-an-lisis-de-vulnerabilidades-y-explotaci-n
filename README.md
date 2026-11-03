# Metodología de análisis de vulnerabilidades y explotación

Proyecto académico para el Módulo 6 del Máster en Ciberseguridad. Presenta una metodología reproducible para analizar software, estudiar vulnerabilidades conocidas y practicar técnicas de análisis de binarios en un laboratorio aislado.

> **Estado de las evidencias:** este repositorio contiene metodología, guías y laboratorios propuestos. Los resultados, capturas, versiones de herramientas y tiempos de ejecución deben añadirse después de ejecutar cada práctica. No se presentan como realizados experimentos que todavía no se han ejecutado.

## Objetivos

- Definir un proceso técnico repetible de análisis de vulnerabilidades.
- Relacionar fallos de implementación con debilidades CWE y casos CVE.
- Practicar análisis estático, dinámico, fuzzing y reversing sobre programas de laboratorio.
- Describir un flujo responsable de investigación ante una posible vulnerabilidad desconocida.
- Documentar hallazgos de forma que otro analista pueda reproducirlos.

## Estructura

```text
docs/       Memoria técnica del proyecto
labs/       Laboratorios reproducibles
evidence/   Capturas y resultados generados al ejecutar las prácticas
references/ Bibliografía y fuentes técnicas
```

## Requisitos recomendados

- Máquina virtual Linux desechable y actualizada.
- Usuario sin privilegios administrativos para ejecutar las pruebas.
- Compilador GCC o Clang, GDB y sanitizadores.
- AFL++ para fuzzing.
- Ghidra para análisis estático de binarios.
- Git para control de versiones.

## Orden de trabajo

1. Leer `docs/01-introduccion.md` y `docs/02-metodologia.md`.
2. Ejecutar el laboratorio de `labs/buffer-overflow/`.
3. Ejecutar el laboratorio de `labs/fuzzing/`.
4. Documentar el análisis de caso de `docs/03-analisis-vulnerabilidades.md`.
5. Completar el plan de investigación 0-day de `docs/05-investigacion-0days.md`.
6. Añadir evidencias reales a `evidence/` y actualizar las conclusiones.

## Alcance y autorización

Todas las pruebas prácticas se limitan a código propio, binarios de laboratorio o sistemas para los que exista autorización expresa. No se deben ejecutar pruebas contra sistemas de terceros ni utilizar las técnicas descritas para obtener acceso no autorizado.

## Criterio de calidad

Cada hallazgo debe incluir como mínimo: identificador, entorno, versión, precondiciones, pasos de reproducción, resultado observado, impacto, limitaciones, evidencia y mitigación.
