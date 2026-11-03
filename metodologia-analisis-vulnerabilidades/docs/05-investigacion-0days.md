# 5. Flujo de investigación ante una posible vulnerabilidad desconocida

## 5.1. Preparación del entorno

La investigación comienza con un entorno reproducible:
- Máquina virtual o contenedor aislado, con snapshot.
- Sin credenciales ni datos reales.
- Red deshabilitada o restringida cuando no sea necesaria.
- Límites de CPU, memoria, disco y tiempo.
- Versiones y hashes de binarios registrados.
- Copias de seguridad y procedimiento de restauración.

## 5.2. Selección del objetivo

Se priorizan componentes con alta exposición de entradas y complejidad: parsers, decodificadores, protocolos, deserializadores, controladores y bibliotecas compartidas. La selección se justifica por superficie de ataque, impacto potencial, disponibilidad de símbolos o código fuente y viabilidad de instrumentación.

## 5.3. Revisión de cambios (diffing)

Cuando hay dos versiones comparables:
1. Obtener versiones legítimas y verificar su procedencia.
2. Comparar cambios de código, símbolos, funciones y bloques.
3. Priorizar cambios en validación de entradas, memoria y autenticación.
4. Formular hipótesis sobre el motivo del cambio.
5. Diseñar pruebas de regresión para verificar el comportamiento.

Un diff llamativo no demuestra una vulnerabilidad. Puede reflejar refactorización o corrección de un bug no relacionado con seguridad.

## 5.4. Ingeniería inversa

Si no hay código fuente:
- Identificar arquitectura, formato y dependencias.
- Revisar imports, strings y símbolos disponibles.
- Reconstruir funciones y flujo de control con Ghidra.
- Localizar límites de confianza y rutas de entrada.
- Observar validaciones, asignaciones y operaciones sensibles.
- Mantener nombres y comentarios como hipótesis, no como hechos.

## 5.5. Fuzzing guiado por cobertura

El flujo propuesto:
1. Definir harness o interfaz de entrada.
2. Crear corpus semilla válido.
3. Instrumentar el objetivo cuando sea posible.
4. Aplicar mutaciones y diccionarios adecuados al formato.
5. Monitorizar cobertura, crashes y recursos.
6. Deduplicar y minimizar casos.
7. Reproducir cada fallo fuera del fuzzer.
8. Investigar la causa raíz con debugger y sanitizadores.

En binarios sin código fuente se pueden evaluar modos de instrumentación binaria compatibles, considerando que la cobertura, velocidad y estabilidad pueden variar.

## 5.6. Triage y confirmación

Cada crash se clasifica:
- Error de entrada o configuración.
- Aserción o terminación esperada.
- Denegación de servicio.
- Lectura o escritura fuera de límites.
- Uso después de liberar memoria.
- Corrupción de memoria de causa aún desconocida.

Se determina si la entrada es determinista, si el fallo es alcanzable desde una interfaz controlable y qué impacto real puede tener. No se afirma ejecución de código arbitrario sin evidencia suficiente.

## 5.7. Divulgación responsable

Si el hallazgo afecta a un producto real:
1. Revisar el proceso de reporte de vulnerabilidades del proveedor.
2. Preparar un informe privado con versión, impacto y reproducción mínima.
3. Evitar publicar datos que faciliten explotación antes de coordinar la corrección.
4. Acordar plazos y canales de comunicación.
5. Validar el parche y documentar la atribución cuando proceda.

## 5.8. Criterios de cierre

La investigación se cierra cuando:
- Existe una explicación técnica reproducible o se documenta por qué no pudo confirmarse.
- El impacto y las limitaciones están descritos.
- Se ha comunicado el hallazgo de forma responsable si afecta a terceros.
- Hay una mitigación o recomendación accionable.
- Se conserva una prueba de regresión.
