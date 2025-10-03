gRPC considerarlo como protocolo (RPC) desarrollado por Google.
Que sea un lenguaje neutral (no le importa cómo están definidos tanto el servidor como el cliente).

Son llamadas a procesos (puertos), no a servicios. 
El archivo .proto tiene definido las aestructuras de información que se van a enviar entre cliente y servidor. 
Un .proto es un archivo de texto donde se definen:

Los mensajes (datos) → qué estructuras de información se van a enviar entre cliente y servidor.

Los servicios (interfaces) → qué métodos RPC existen, qué reciben y qué devuelven.

Estos archivos usan la sintaxis de Protocol Buffers (protobuf), el lenguaje de definición de interfaces (IDL) de gRPC.

> El fuerte: streaming bidireccional -> comunicación fluída. 

---
https://grpc.io/docs/what-is-grpc/core-concepts/