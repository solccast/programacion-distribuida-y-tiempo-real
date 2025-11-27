# gRPC 
gRPC es un framework para comunicación cliente-servidor basado en HTTP/2 y Protocol Buffers (protobuf).
El archivo `.proto` es la base de todo.

## Cardinalidades
### `repeated` 
- Es lista o arreglo de elementos.
- Puede tener 0 a N elementos.
- El orden de los valores se mantiene. 

### `optional`
- Permite marcar si un campo fue seteado o no.
- Sólo sirve para tipos escalares (int, bool, string...).
- El campo se mantiene presente.