# 7. Conclusiones

El análisis de vulnerabilidades es un proceso iterativo que combina comprensión del software, formulación de hipótesis, experimentación controlada y comunicación técnica. La detección de un crash es solo el inicio: es necesario reproducirlo, identificar su causa, evaluar su impacto y proponer una corrección verificable.

Los casos de corrupción de memoria muestran la importancia de controlar tamaños, límites y vida útil de los objetos. El estudio de CVE-2021-3156 permite relacionar un error de procesamiento de argumentos con consecuencias de seguridad relevantes. El fuzzing amplía la exploración de entradas, mientras que el reversing permite investigar binarios cuando el código fuente no está disponible.

La aproximación a posibles 0-days debe ser disciplinada: entorno aislado, diffing, análisis estático y dinámico, fuzzing, triage y divulgación responsable. La investigación no debe confundir indicios con confirmaciones ni presentar como explotable un fallo cuyo impacto no se ha demostrado.

## Trabajo futuro

Aunque se han completado los tres laboratorios prácticos previstos, existen varias líneas de mejora que permitirían ampliar el alcance del proyecto:

- Ampliar el análisis de vulnerabilidades reales mediante el estudio de nuevos CVE.
- Incorporar nuevos objetivos de fuzzing y ampliar los corpus de pruebas.
- Profundizar en el análisis de binarios mediante ingeniería inversa.
- Automatizar pruebas de regresión para verificar las correcciones.
- Ampliar las evidencias técnicas con nuevos casos prácticos y resultados reproducibles.
- Mantener actualizadas las herramientas y referencias utilizadas.


## Declaración de alcance de las evidencias

Las evidencias incluidas en este proyecto corresponden a las prácticas realizadas en entornos de laboratorio controlados.

Se han documentado tres ejercicios prácticos:

- Buffer Overflow: identificación de un error de escritura fuera de límites mediante AddressSanitizer y comprobación de su corrección.
- Fuzzing: utilización de AFL++ para explorar entradas de un programa y analizar los resultados obtenidos.
- Ingeniería inversa: inspección de un binario ELF mediante herramientas de análisis estático y Ghidra.

Los informes y las capturas de pantalla asociados a estos ejercicios se encuentran organizados en sus respectivos directorios dentro de `labs`.

Los resultados descritos se limitan a las pruebas efectivamente realizadas y no implican el descubrimiento de vulnerabilidades 0-day en software de producción.
