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
## Referencias 
https://documentation.ubuntu.com/public-images/public-images-how-to/run-a-vagrant-box/

