#!/bin/bash

# Variables para los parámetros originales
HOST="localhost"
PORT=12345
RESULT_FILE="resultados.txt"
# Lista de tamaños de datos a probar
SIZES=(10 100 1000 10000 100000 1000000)

# Preparación del archivo de resultados 
echo "# Resultados del experimento de transferencia de datos" > $RESULT_FILE 
echo "" >> $RESULT_FILE 


# Compilación
gcc client_prueba.c -o client_prueba
gcc server_prueba.c -o server_prueba

# Ejecuta el servidor en segundo plano
./server_prueba $PORT ${SIZES[0]} & # Parámetros enviados: puerto y tamaño inicial
SERVER_PID=$!
sleep 10 # Espera a que el servidor esté listo

# Pruebas para cada tamaño
for SIZE in "${SIZES[@]}"; do
    echo "Probando con tamaño: $SIZE"
    # Ejecuta el cliente
    ./client_prueba $HOST $PORT $SIZE
    # Reinicia el servidor para cada prueba
    kill $SERVER_PID
    ./server_prueba $PORT $SIZE &
    SERVER_PID=$!
    sleep 10
done

# Finaliza el servidor
kill $SERVER_PID