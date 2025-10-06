1.
a. Introduzca cambios mínimos, como la inclusión de `exit()`, para provocar situaciones donde no se reciban comunicaciones o no haya un receptor disponible. Agregar screenshots de los errores encontrados.

En este caso el exit lo puse antes luego de iniciar el server en `App.java`, del lado del cliente se observa lo siguiente:  
![alt text](image.png)

b. Este uso lo saqué de:  https://github.com/grpc/grpc-java/tree/master/examples/src/main/java/io/grpc/examples/deadline
Conceptos: https://grpc.io/docs/guides/deadlines/

**Modificación del lado del cliente**
![alt text](image-2.png)

**Modificación del lado del server en la función**
![alt text](image-3.png)

**OUTPUT CLIENTE**
![alt text](image-1.png)

### Ventajas:
- Los deadlines permiten a los clientes establecer un límite de tiempo para esperar una respuesta del servidor. Esto evita que las solicitudes queden bloqueadas indefinidamente en caso de problemas como:
    - Retrasos en el servidor.
    - Problemas de red.
    - Sobrecarga del sistema.

- Mejora de la experiencia del usuario: Al usar deadlines, los clientes pueden manejar errores de manera más predecible y proporcionar retroalimentación al usuario (como mensajes de error o reintentos), en lugar de dejarlo esperando sin respuesta.

- Optimización de recursos: Cuando se excede un deadline, gRPC cancela automáticamente la solicitud en el cliente y el servidor. Esto libera recursos en ambos extremos, evitando que se procesen solicitudes que ya no son relevantes.