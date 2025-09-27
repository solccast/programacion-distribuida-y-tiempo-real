#!/bin/bash

# Seteamos el puerto
PORT=8080
# Lista de tamaños de datos a probar
SIZES=(10 100 1000 10000 100000 1000000)

# Compilación servidor
cp server_prueba.c /tmp/
cd /tmp

gcc server_prueba.c -o server_prueba

if [ $? -ne 0 ]; then
    echo "Error al compilar server_prueba.c"
    exit 1
fi

for SIZE in "${SIZES[@]}"; do
    # Inicia el servidor en segundo plano
    echo "Ejecutando servidor para $SIZE"
    ./server_prueba $PORT $SIZE
    done

echo "Experimento finalizado."
