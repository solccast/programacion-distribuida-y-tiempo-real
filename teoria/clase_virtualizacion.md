# [NOTAS] Clase 01/09: Virtualización
Entender a Vagrant como un gestor de varias máquinas virtuales (equivalente a Docker pero con aplicaciones).
Vagrant es una herramienta para crear y gestionar entornos de desarrollo virtualizados. Sus características principales son:
- Enfocado en máquinas virtuales completas
- Permite crear entornos de desarrollo consistentes y reproducibles
- Utiliza un archivo Vagrantfile para definir la configuración
- Trabaja principalmente con proveedores de virtualización como VirtualBox, VMware, etc.

El baremetal es el hardware físico sin la capa de abstracción. Lo que es Hardware es lo que ve cuando administra el sistema operativo. HAL -> Hardware Abstraction Level, esta venía en el sistema operativo. Es la parte que se especializaba en el hardware subyacente. 
En el caso del hipervisor de tipo 1 es el que provee la capa de abstracción (no los so guests). 

Comandos usados en la clase: 
- `vagrant up`: levanta los entornos desde el `vagrantfile`
- `vagrant ssh`: conexión por ssh de las máquinas virtuales 
- `vagrant destroy`: borra todas las VMs 
- `vagrant poweroff`: apaga las VMs 
