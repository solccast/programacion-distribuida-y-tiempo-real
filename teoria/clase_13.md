# Programación Distribuida y Tiempo Real - Teoría - Clase 13: Movilidad de código

## Movilidad de código 
Se refiere a la capacidad de transferir código ejecutable o procesos en ejecución entre computadoras. En principio, en un sistema distribuido, siempre se transfiere algún tipo de información o datos pero la movidad de código lleva esto al nivel de la lógica de aplicación. 

> Los términos movilidad de código y migración de código/procesos se utilizan a menudo como sinónimos, aunque no necesariamente lo son. La migración tiene una interpretación histórica asociada a los procesos en ejecución.

### Razones
La migración de código se soporta principalmente por dos motivos: 
- **eficiencia**: si mantenemos el código en un único lugar ese será el único lugar del sistema distribuido dónde se computará entonces, si tenemos la capacidad de mover código de un lado a otro en realidad tenemos la posibilidad de repartir la carga computacional -> **balanceo de carga computacional** 
- **Minimizar la comunicación** o **disminuir la carga de la red de comunicaciones**: si en vez de mover todos los datos al sistema para ser procesados se migra el código a donde se encuentran ubicados los datos reduce la comunicación si la transferencia del código es menor que la transferencias de grandes volúmenes de datos a través de la red. 
- **carga dinámica del código**: a priori, a medida que es necesario, a partir de una solicitud, el servidor proporciona código el cual el cliente descarga de manera dinámica la implementación **DEBO AHONDAR MÁS SOBRE ESTO PORQ NO LO TERMINO DE ENTENDER**
- **Mejora de la respuesta/velocidad para un usuario**: trasladar partes del sistema al usuario para que realice procesamiento local. 

## Migración de código
La interpretación que siempre se la ha dado 
min 10:40