# Programación Distribuida y Tiempo Real - Práctica 1

> Explicación: [Presentación Sockets](https://docs.google.com/presentation/d/1_xWZFXiBqr4c0OSkn-6PywYsiKOY5Nhr_f3SaV_b3FY/edit?slide=id.g144820ab889_0_139#slide=id.g144820ab889_0_139)

## 1) Teniendo en cuenta la comunicación con sockets (puede usar tanto los ejemplos provistos como también otras fuentes de información, que se sugiere referenciar de manera explícita):
### a- Identifique similitudes y diferencias entre los sockets en C y en Java.
**Similitudes**:
    - Ambos usan Sockets TCP/IP para la comunicación de red. 
    - Ambos son compatibles con TCP/UDP y aplican los mismos principios de conexión

**Diferencias**: 
    - Abstracción: C posee un enfoque **bajo nivel** en el que se usan llamadas explícitas para el manejo de los sockets, buffers y errores, en cambio Java ofrece una API más amigable mediante clases Socket, ServerSocket, InputStream y OutputStream 
    - Tipos de datos: Java abstrae el orden de bytes e inicialización pero requiere convertir los datos manualmente (usando DataInputStream por ejemplo) pero en C se pueden transmitir directamente las estructuras. 

![alt text](image.png)

### b- ¿Por qué puede decirse que los ejemplos no son representativos del modelo c/s? Nota: corroborar con la clase donde se explica el modelo C/S.

### c- ¿Qué cambio/s deberían hacerse para que “cliente” provisto funcione como “servidor” y el “servidor” provisto funcione como “cliente”? Nota: corroborar con la clase donde se explica el modelo C/S.
