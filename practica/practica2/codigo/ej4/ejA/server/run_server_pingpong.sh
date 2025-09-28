#!/bin/bash

# Configuración de puerto
PORT=8080
# Lista de tamaños de datos a probar
SIZES=(10 100 1000 10000 100000 1000000)

# Compilación servidor
gcc server_pingpong.c -o server_pingpong
if [ $? -ne 0 ]; then
    echo "Error al compilar server_pingpong.c"
    exit 1
fi

for SIZE in "${SIZES[@]}"; do
    # Inicia el servidor en segundo plano
    echo "Ejecutando servidor para $SIZE"
    ./server_pingpong $PORT $SIZE
    done

echo "Experimento finalizado."