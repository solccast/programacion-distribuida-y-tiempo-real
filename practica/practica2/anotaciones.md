# Práctica 2

## Punto 1
Versión 22.04 mantenida oficialmente por Ubuntu 
Se configura el vagrantfile de la siguiente forma:
```
  # Box oficial de Ubuntu 22.04 LTS (Jammy Jellyfish)
  config.vm.box = "ubuntu/jammy64"
```

Una vez levantado con Vagrant el servicio de Ubuntu mediante el uso del comando `lsb_release -a` podemos acceder a los detalles de la distribución de Linux que estamos usando:  
```bash
vagrant@ubuntu-prueba:~$ lsb_release -a
No LSB modules are available.
Distributor ID: Ubuntu
Description:    Ubuntu 22.04.5 LTS
Release:        22.04
Codename:       jammy
```
El código proporcionado por la cátedra contiene la siguiente versión de Ubuntu: 
```bash
No LSB modules are available.
Distributor ID: Ubuntu
Description:    Ubuntu 18.04.3 LTS
Release:        18.04
Codename:       bionic
```

---
# Considerar
Para ejecutar client_prueba en una máquina y que envíe datos a server_prueba en otra máquina de la misma red, sigue estos pasos:

1. En la máquina servidor (donde ejecutas server_prueba):
Obtén la dirección IP local de la máquina (puedes usar ipconfig en Windows o ifconfig/ip a en Linux).
Ejecuta el servidor con el puerto y tamaño deseado:
(Asegúrate de que el firewall permita conexiones entrantes al puerto usado, por ejemplo, 12345).
2. En la máquina cliente (donde ejecutas client_prueba):
Usa la IP de la máquina servidor como parámetro HOST:
(Reemplaza 192.168.1.100 por la IP real del servidor).
3. Consideraciones adicionales
- Ambos ejecutables deben estar compilados y accesibles en sus respectivas máquinas.
- El puerto debe ser el mismo en ambos comandos.
- La red debe permitir la comunicación entre ambas máquinas (sin restricciones de firewall o NAT).
Si usas el script bash, reemplaza HOST="localhost" por la IP del servidor.
Ejemplo de cambio en el script `HOST="192.168.1.100"  # IP del servidor`

Comandos para saber info: `cat /proc/cpuinfo` para saber los requerimientos de la máquina 

---
## Referencias 
https://documentation.ubuntu.com/public-images/public-images-how-to/run-a-vagrant-box/


