#!/bin/bash

SERVER_IP="192.168.56.10"

# Levantar VMs
#vagrant up

# Ejecutar el servidor en vm1
echo "Ejecutando servidor en vm1..."
vagrant ssh vm1 -c "/home/vagrant/run_server.sh > /vagrant/server.log"

# Ejecutar el cliente en vm2
echo "Ejecutando cliente en vm2..."
vagrant ssh vm2 -c "/home/vagrant/run_client.sh $SERVER_IP > /vagrant/client_results.txt"

echo "Experimento finalizado. Revisá /vagrant/client_results.txt y /vagrant/server.log"
