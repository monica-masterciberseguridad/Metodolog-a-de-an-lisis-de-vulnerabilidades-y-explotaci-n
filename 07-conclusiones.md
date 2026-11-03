# 7. Conclusiones

El análisis de vulnerabilidades es un proceso iterativo que combina comprensión del software, formulación de hipótesis, experimentación controlada y comunicación técnica. La detección de un crash es solo el inicio: es necesario reproducirlo, identificar su causa, evaluar su impacto y proponer una corrección verificable.

Los casos de corrupción de memoria muestran la importancia de controlar tamaños, límites y vida útil de los objetos. El estudio de CVE-2021-3156 permite relacionar un error de procesamiento de argumentos con consecuencias de seguridad relevantes. El fuzzing amplía la exploración de entradas, mientras que el reversing permite investigar binarios cuando el código fuente no está disponible.

La aproximación a posibles 0-days debe ser disciplinada: entorno aislado, diffing, análisis estático y dinámico, fuzzing, triage y divulgación responsable. La investigación no debe confundir indicios con confirmaciones ni presentar como explotable un fallo cuyo impacto no se ha demostrado.

## Trabajo futuro

- Ejecutar y documentar los tres laboratorios.
- Añadir capturas y logs sin datos sensibles.
- Ampliar el análisis de un segundo CVE con su parche.
- Incorporar pruebas de regresión automatizadas.
- Revisar periódicamente las versiones de herramientas y referencias.

## Declaración de alcance de las evidencias

Las prácticas descritas son un plan reproducible. Las evidencias empíricas deben incorporarse después de su ejecución por el autor. No se atribuyen al autor resultados de laboratorio que no se hayan obtenido.
