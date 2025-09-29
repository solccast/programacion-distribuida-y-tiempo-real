#!/bin/bash

HOST="192.168.56.10"

# Ejecutar Vagrant para levantar la VM si hay un error mostrarlo en pantalla
vagrant up 

if [ $? -eq 0 ]; then
    echo "Vagrant iniciado correctamente"
else 
    echo "Error al iniciar Vagrant"
    exit 1
fi

./run_client.sh $HOST &

# Ejecutar el script server 
vagrant ssh vm1 -c "gcc /vagrant/server_prueba.c -o /home/vagrant/server_prueba 
&& chmod +x /home/vagrant/server_prueba 
&& cp /vagrant/run_server.sh /home/vagrant/run_server.sh
&& sed -i 's/\r$//' /home/vagrant/run_server.sh
&& chmod +x /home/vagrant/run_server.sh
&& /home/vagrant/run_server.sh"

# Fin script