#!/bin/bash

# Seteamos el puerto
PORT=8080
# Lista de tamaños de datos a probar
SIZES=(10 100 1000 10000 100000 1000000)

# Compilación servidor
gcc /vagrant/server_prueba.c -o /home/vagrant/server_prueba

for SIZE in "${SIZES[@]}"; do
    # Inicia el servidor en segundo plano
    echo "Ejecutando servidor para $SIZE"
    ./server_prueba $PORT $SIZE 
done

echo "Experimento finalizado."