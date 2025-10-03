#!/bin/bash

# El host se tiene que pasar como argumento
HOST=$1
PORT=8080
RESULT_FILE="resultados_pingpong5.md"
# Lista de tamaños de datos a probar
SIZES=(10 100 1000 10000 100000 1000000)

if [ -z "$HOST" ]; then
    echo "Uso: $0 <IP_SERVIDOR>"
    exit 1
fi

# Compilación de los programas

gcc client_pingpong.c -o client_pingpong
if [ $? -ne 0 ]; then
    echo "Error al compilar client_pingpong.c"
    exit 1
fi

# Preparación del archivo de resultados

echo "# Resultados del experimento ping-pong" > $RESULT_FILE
echo "Host: $HOST, Puerto: $PORT" >> $RESULT_FILE
echo "" >> $RESULT_FILE

for SIZE in "${SIZES[@]}"; do
    echo "Probando con tamaño: $SIZE"
    # Inicia el servidor en segundo plano
    echo "| Modelo | Tamaño (bytes) | Tiempo Total (ms) | One way (s) |" >> $RESULT_FILE
    echo "|--------|----------------|------------------|-------------|" >> $RESULT_FILE
    ./client_pingpong $HOST $PORT $SIZE >> $RESULT_FILE
    echo "" >> $RESULT_FILE
    done

echo "Experimento finalizado. Resultados en $RESULT_FILE"
