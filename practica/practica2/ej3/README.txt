# Uso 
Uso de comandos Linux: 
- Para levantar el servidor es necesario correr el script `./run_server_pinpong.sh` que se encargará de hacer la compilación de los archivos necesarios. En esta misma computadora con el comando `hostname -I | awk '{print $2}'` obtendremos la IP que será necesaria para el cliente. 
- Para levantar el cliente es necesario correr el script `/run_client_pingpong.sh <IP_SERVIDOR>` el cual es necesario obtener la IP de la otra computadora física. Este script se encarga tanto de compilar el código .c como de llevar a cabo las pruebas. 
Los resultados se verán reflejados en el archivo `resultados.txt` en el mismo directorio donde se encuentre. 