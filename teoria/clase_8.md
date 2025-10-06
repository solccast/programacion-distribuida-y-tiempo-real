# Programación Distribuida y Tiempo Real - Teoría - Clase 8: Tiempo Real

## Aspectos Comerciales de TR
Desde una perspectiva comercial, una aplicación de tiempo real (real-time app) está diseñada para funcionar dentro de un marco de tiempo que es efectivamente inmediato para el usuario. El tiempo de respuesta del procesamiento ocurre tan rápido que cualquier interacción parece estar sucediendo en tiempo real.

Algunas características comunes de estas aplicaciones incluyen:
• Baja latencia (Low Latency).
• Interacción Síncrona (Synchronous Interaction).
• Mecanismo de "Empuje" (Push Mechanism) -> forma de llamar al callback en la web y vuelva para seguir (caso de las promesas en JS). 

> Se descarta entonces lo _inmediato_ y _swiftly_. 

## Técnicas 
En el contexto técnico de la programación, los sistemas de tiempo real se distinguen porque son requerimientos no funcionales. Se habla de plazos y determinismo. 
Un sistema de tiempo real es un sistema de cómputo que debe reaccionar con restricciones de tiempo precisas a eventos en el ambiente. Por consiguiente, la corrección del comportamiento de estos sistemas depende no solo del resultado de la computación, sino también del instante de tiempo en el cual se produce el resultado. La palabra "tiempo" aquí significa que la exactitud del sistema depende tanto del resultado lógico como del momento en que se produce ese resultado.

## Clasificación
Los sistemas de TR se clasifican según la severidad de las consecuencias de no cumplir con los plazos (deadlines):

| Tipo de TR | Consecuencia del incumplimiento                     | Características Clave                                                                 |
|------------|-----------------------------------------------------|--------------------------------------------------------------------------------------|
| **Duro (Hard)**| Destrucción o inconsistencia.                       | El fallo en el plazo puede ser relativamente sencillo de identificar (destrucción y/o inconsistencia), pero no necesariamente sencillo de resolver porque hay que asegurar deterministicamente el sistema tiene que responder. Usualmente el enfoque está en TR Duro. Si no se responde en determinado tiempo el sistema se rompe o queda inconsistente. |
| **Blando (Soft)**| Afecta la calidad en función del tiempo ($f(t)$). | La respuesta posterior al límite no implica necesariamente la destrucción o inconsistencia del sistema, sino que degrada la _calidad_ (ejemplo: control de temperatura). La respuesta siempre se espera, pero afecta a la calidad del sistema (un sistema malo)|
| **Firme (Firm)**| Descarte de algunas respuestas.                    | La eventual ausencia/pérdida de respuesta dentro del límite de tiempo/plazo no genera destrucción, pero tampoco tiene valor, por lo que se descarta. Ejemplo: streaming, perder un frame o un bloque. |

## Conceptos asociados
En TR, se habla de tareas para referirse a **actividades que tienen un límite de tiempo de respuesta definido**. Un sistema de TR puede incluir múltiples tareas, incluyendo tareas críticas (usualmente asociadas a TR Duro) y tareas con límites blandos o firmes.

### Clases de Tareas/Eventos según Activación
Las tareas se clasifican según cómo o cuándo aparecen:
- Periódicas (y periodicidad) - Sincrónicas: Ocurren a intervalos regulares.
- "Aperiódicas":
    - Esporádicas: Tienen un tiempo mínimo ($T$) entre activaciones.
    - Irregulares: (basadas en probabilidad).
    - Ráfagas: Ocurren en grupos.


### Ejecución de una Tarea de TR: Ejes Temporales
La ejecución de una tarea de TR involucra varios puntos en el tiempo:
- $t_0$: Momento de la **Activación/Evento**. (Depende del problema).
- $t_1$: Momento del **Inicio de Ejecución**. (Depende de qué factores: de cuando es reconocido para el sistema, de cuán disponibles están los recursos).
- $t_2$: Momento del Fin de Ejecución.
- $t_3$: Momento del Plazo de Ejecución (**Deadline**) o Tiempo Máximo de Respuesta. (Dependerá del problema)
Métricas Temporales
• Tiempo de Respuesta: $t_2 - t_0$.
• Plazo de Ejecución (Deadline): $t_3 - t_0$.
• $t_1 - t_0$ (Retraso de activación/inicio que puede variar), $t_2 - t_1$ (Tiempo de ejecución: puede variar también, depende del hardware y del scheduling), y por lo tanto $t_3 - t_2$ (Tiempo que "sobra": más cerca de $t_3$ es el límite máximo pero si el slice es más pequeño entonces se optimizan más los recursos ya que se libera rápido -trade off-), dependen no solo del sistema de cómputo sino de la cantidad de tareas.

## Implicaciones para el diseño de sistemas
• Planificación (Scheduling): Se enfoca en el cumplimiento de las restricciones de tiempo en lugar de priorizar el rendimiento. Generalmente se trata de planificación a corto plazo (CPU).
• Concurrencia: Es casi natural debido a la necesidad de identificar y gestionar tareas.
• Complejidad: Menor cantidad y heterogeneidad de tareas implica menores problemas para asegurar TR (mayoritariamente "duro").
• Prioridades: Uso intensivo de prioridades (de TR).
• Preemption (Preemptividad): No "respetar" el slice de tiempo asignado a una tarea por una de mayor prioridad.
• Minimización de tareas: Reducir las tareas sin restricciones de TR para evitar interferencias/competencia por recursos.

