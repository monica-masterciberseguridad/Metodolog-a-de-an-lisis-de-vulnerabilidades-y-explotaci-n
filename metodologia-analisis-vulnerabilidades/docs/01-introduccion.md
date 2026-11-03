# 1. Introducción y alcance

## 1.1. Contexto

El análisis de vulnerabilidades no consiste únicamente en localizar un fallo o ejecutar un exploit publicado. Requiere comprender el comportamiento del software, identificar las condiciones que originan una debilidad, demostrar su impacto de manera controlada y comunicar el resultado con suficiente precisión para que pueda verificarse y corregirse.

Este proyecto propone una metodología aplicable principalmente a programas nativos y binarios, sin excluir aplicaciones y servicios. Se combinan análisis estático, análisis dinámico, fuzzing, ingeniería inversa y revisión de la superficie de ataque.

## 1.2. Objetivos

- Comprender el flujo de datos desde la entrada hasta las operaciones sensibles.
- Identificar validaciones ausentes o incorrectas y errores de gestión de memoria.
- Construir casos mínimos de reproducción.
- Diferenciar un fallo observable de una vulnerabilidad con impacto de seguridad.
- Evaluar severidad, alcance y condiciones de explotación.
- Recomendar correcciones y pruebas de regresión.

## 1.3. Alcance y limitaciones

El trabajo se centra en vulnerabilidades de software y ejercicios de laboratorio. No pretende demostrar que se ha descubierto un 0-day real ni que se ha desarrollado un exploit contra un producto de producción. Los ejercicios se ejecutarán sobre código deliberadamente vulnerable creado para el proyecto y en entornos aislados.

El documento del módulo solicita metodología, casos reales o ejemplos, binarios practicados y un flujo práctico ante vulnerabilidades desconocidas. Las evidencias de ejecución deben añadirse por el autor una vez realizadas las prácticas.

## 1.4. Principios de trabajo

1. **Autorización:** definir por escrito el alcance y los activos permitidos.
2. **Reproducibilidad:** registrar versiones, configuración, comandos y entradas.
3. **Mínimo impacto:** utilizar snapshots, contenedores o máquinas virtuales desechables.
4. **Evidencia:** conservar entradas, trazas, logs y hashes relevantes.
5. **Divulgación responsable:** coordinar la comunicación con el mantenedor o proveedor.
6. **Mitigación:** el análisis debe terminar con medidas correctivas verificables.
