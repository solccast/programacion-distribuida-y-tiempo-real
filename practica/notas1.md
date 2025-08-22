# Sockets 
## qué es?
es la comunicación de dos procesos 
se abre un puerto que escucha y otro puerto se comunica con él. 
protocolos tcp y udp 
concepto de cliente servidor

> entender como mecanismo de comunicación entre dos procesos 

puede ser concurrente, de 1 vía o de dos 

## sockets en C 
### cliente en C
llamar al metodo Sicket() 
el connect() permite generar el espacio de direccion y cuerpo 
las operaciones read  y write para la comunicación 

### servidor en C
listen() q espera las conexiones 
acept() para aceptar una conexión 
la misma operacion read y write
todas las variables en C son udp 
aca es un buffer para ir y venir



## socket en Java
metodos mas abstractos, mas alto nivel 
en cambio aca hay que pensar qué dato es el que recibe ya que se usa datastream 

realmente es cliente y servidor
es por cuestion del servidor, porq deberia manejar concurrencia y aceptar mas clientes 

los ejemplos estan dados en tcp 


[!NOTE] Tener encuenta las disferencias entre sockets de Java y C 

---



