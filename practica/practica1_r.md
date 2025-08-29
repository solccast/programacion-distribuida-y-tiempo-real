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

No son representativos porque el servidor no realiza trabajo extra sobre la petición, sino que es un simple echo. Es una conexión simple entre dos sockets.


### c- ¿Qué cambio/s deberían hacerse para que “cliente” provisto funcione como “servidor” y el “servidor” provisto funcione como “cliente”? Nota: corroborar con la clase donde se explica el modelo C/S.

Sería necesario cambiar que el cliente se quede esperando un requerimiento y no sea el que inicie la comunicación. Para el caso del servidor, es necesario quitar el estado `listen` y que sea éste el que inicie la comunicación. Tiene que tener la capacidad de que sea concurrente. 


## 2) Desarrolle experimentos para quede claro que:
a - Aunque un proceso “servidor” programado en C haya obtenido un socket y hecho un `bind()` no va a haber ningún otro proceso que pueda hacer una conexión con ́el a menos que se haya hecho el `listen()`¿Por que este mismo experimento no podría hacerse programando en Java?

Porque el `listen()` se usa para esperar una determinada cantidad de conexiones entrantes en un socket. Al momento de crear un socket éste no posee identidad es decir, no posee dirección IP ni número de puerto, la instrucción `bind()` permite que el kernel sepa qué dirección asignar al socket para que los clientes sepan donde conectarse. `listen()` sin `bind()` funciona en el sentido de que el socket queda en modo pasivo, pero va a escuchar en un puerto aleatorio. En el caso de no realizar el `listen()` no se crea la cola de requerimientos y por lo tanto ningún cliente podrá completar la conexión TCP a ese puerto. 
Si se levanta `server2_a` se puede ver que el servidor queda escuchando pero el cliente no puede conectarse, nos salta `connection refused` pues desconoce el puerto. 
En Java no es posible realizar lo mismo porque una vez que se crea el `ServerSocket()` se crea el socket en conjunto con el puerto ya en escucha. Es decir no hay una etapa bind sin listen. El `accept()` del socket sólo se encarga de sacar un requerimiento de la cola de escucha que se generó cuando se creó el socket. 

![alt text](image-2.png)
En la imagen podemos ver que aleatoriamente se asigna un puerto y el cliente no puede conectarse. 


b - Un proceso “cliente” puede tener una conexión con el proceso “servidor” aunque el “servidor” no haya ejecutado la operación `accept()`.

Lo que probé fue dormir el proceso por 30 segundos y que se cierre el socket para ver el proceso cliente y qué es lo que ocurría: el requerimiento se encola y nunca es tomado por el servidor, mientras tanto el cliente se queda esperando; una vez que el socket se cierra el cliente lanza el error `ERROR reading from socket: Connection reset by peer`.

3) Modifique el código (programa C o Java o ambos) para que la cantidad de datos que se comunican sea de 101, 102, 103, 104, 105 y 106 y contengan bytes asignados directamente en el programa (sin leer de teclado ni mostrar en pantalla los datos del buffer). Tenga en cuenta que el valor de retorno de la llamada a read(...) tanto en C como en Java retornan la cantidad de bytes efectivamente le´ıda y puede ser menor a la que se le indica/pedida como par´ametro. Explique c´omo verifica el correcto funcionamiento de lo desarrollado. El env´ıo debe realizarse en una ´unica llamada a la funci´on correspondiente a menos que el valor de retorno indique que hay datos pendientes de env´ıo.

---

# Anotaciones 

## C: El ciclo socket → bind → listen → accept

En el servidor TCP en C ( `server.c`):

- `socket()`
Crea un descriptor de archivo para un socket, pero todavía no está asociado a nada.

- `bind()`
Asocia ese socket a una dirección IP y un número de puerto. 
→ Esto garantiza que si alguien intenta conectarse a IP:puerto, el sistema operativo sabe a qué socket referirse.

- `listen()`
Marca el socket como pasivo (aceptando conexiones). Además, crea una cola de backlog donde el kernel acumula las conexiones entrantes hasta que la aplicación las atienda.
→ Si no hacés `listen()`, aunque hayas hecho `bind()`, el kernel rechaza los intentos de conexión porque ese puerto no está “escuchando”.

- `accept()`
Se bloquea esperando un cliente. Cuando llega uno, el kernel lo saca de la cola de backlog y devuelve un nuevo descriptor de socket (newsockfd).
→ Ese descriptor es el que usarás para leer y escribir con ese cliente en particular.
→ El socket original (sockfd) sigue escuchando y puede aceptar otros clientes.

![alt text](image-1.png)