# 3. Casos reales y análisis técnico

## 3.1. Caso principal: CVE-2021-3156 (Baron Samedit)

### Resumen

CVE-2021-3156 afectó a Sudo y se describió como un desbordamiento de búfer en el heap relacionado con el manejo de argumentos en el modo `sudoedit`. CERT-EU publicó un aviso técnico en febrero de 2021. La vulnerabilidad podía permitir a un usuario local sin privilegios elevar privilegios en sistemas afectados, bajo las condiciones descritas por los avisos del fabricante y las distribuciones.

### Debilidad y causa

El caso se relaciona con manejo incorrecto de límites y terminación de cadenas en memoria. El análisis debe distinguir:
- La condición de entrada que activa la ruta vulnerable.
- La operación de copia o procesamiento que excede el espacio previsto.
- El objeto de memoria afectado.
- Las versiones vulnerables y las versiones corregidas.
- Las condiciones de explotación específicas de cada plataforma.

No se incluyen instrucciones para explotar sistemas reales. La reproducción debe realizarse únicamente en un laboratorio aislado y utilizando material de investigación autorizado.

### Proceso de análisis propuesto

1. Consultar el aviso del proveedor y los registros de distribución.
2. Identificar versiones afectadas y parcheadas.
3. Revisar el diff de la corrección para localizar la validación añadida o el flujo corregido.
4. Reconstruir el flujo de argumentos a través del código.
5. Explicar por qué el error produce corrupción en heap.
6. Contrastar el impacto descrito por fuentes independientes.
7. Documentar mitigación: actualizar a una versión corregida y verificar el paquete instalado.

### Lecciones

- Los errores de parsing de argumentos pueden tener consecuencias graves.
- Un bug de memoria requiere analizar el contexto de ejecución y los privilegios.
- El parche y la prueba de regresión son parte esencial del análisis.
- Los detalles de explotabilidad dependen de versión, compilación y entorno.

## 3.2. Debilidad CWE-787: Out-of-bounds Write

CWE-787 describe una escritura fuera de los límites previstos de un buffer. Puede causar corrupción de memoria, caída del proceso o, en determinadas condiciones, comprometer integridad o flujo de ejecución.

### Preguntas de investigación

- ¿Qué tamaño tiene el destino?
- ¿Cómo se calcula el tamaño de la entrada?
- ¿Se comprueban desbordamientos en la aritmética?
- ¿Puede el atacante controlar los datos o la longitud?
- ¿Qué memoria puede quedar afectada?
- ¿Qué defensas de compilación y ejecución están activas?

MITRE señala que pruebas dinámicas como fuzzing pueden ayudar a detectar esta clase de debilidad. La presencia de CWE-787 no determina por sí sola una severidad o explotabilidad concreta.

## 3.3. Caso práctico de laboratorio: buffer overflow controlado

El laboratorio de `labs/buffer-overflow/` crea un programa didáctico con un buffer de tamaño fijo y una copia sin validación adecuada. Se compila con AddressSanitizer para detectar la escritura fuera de límites.

Objetivo de aprendizaje:
- Entender la diferencia entre tamaño de entrada y capacidad del destino.
- Observar un diagnóstico del sanitizador.
- Corregir la validación y comprobar que la prueba deja de fallar.

Este ejercicio no pretende obtener ejecución de código ni construir una cadena de explotación. Se centra en identificar, reproducir y corregir la causa raíz en un programa propio.

## 3.4. Ficha de análisis para futuros casos

| Campo | Información que debe registrarse |
|---|---|
| Identificador | CVE, CWE o ID interno |
| Producto | Nombre, versión y plataforma |
| Fuente | Aviso del proveedor y fuentes independientes |
| Precondiciones | Acceso, privilegios e interacción |
| Causa raíz | Error técnico concreto |
| Reproducción | Pasos mínimos en entorno autorizado |
| Impacto | Confidencialidad, integridad y disponibilidad |
| Evidencia | Logs, crash, traza, hash y capturas |
| Mitigación | Parche, configuración o cambio de código |
| Validación | Prueba posterior a la corrección |

## 3.5. Limitaciones

Los casos reales se describen a partir de avisos y referencias públicas. No se afirma haber auditado el código de Sudo ni reproducido CVE-2021-3156. Para convertir esta sección en evidencia práctica, se debe adjuntar el análisis del parche, las versiones consultadas y las conclusiones propias.
