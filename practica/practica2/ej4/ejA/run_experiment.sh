#!/bin/bash

SERVER_IP=192.168.56.10

vagrant up
echo "Arranca el experimento"
vagrant ssh vm2 -c "./run_client.sh $SERVER_IP > /vagrant/client_results.txt"

echo "Experimento finalizado. Revisá /vagrant/client_results.txt y /vagrant/server.log"
