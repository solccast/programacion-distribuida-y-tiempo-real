#!/bin/bash

# Ojo, el host se tiene que pasar como argumento
HOST=$1
PORT=8080
RESULT_FILE="ej4B_resultados.txt"
SIZES=(10 100 1000 10000 100000 1000000)

if [ -z "$HOST" ]; then
    HOST=192.168.56.10
fi

gcc client_prueba.c -o client_prueba

# Esperar a que el servidor esté en estado listen
until nc -z $HOST 8080; do
    echo "Esperando a que el servidor este en estado listen..."
    sleep 1
done

echo "# Resultados del experimento cliente-servidor - EJ 4B" > $RESULT_FILE
echo "Host: $HOST, Puerto: $PORT" >> $RESULT_FILE
echo "" >> $RESULT_FILE

for SIZE in "${SIZES[@]}"; do
    echo "Probando con tamaño: $SIZE"
    echo "| Modelo | Tamaño (bytes) | Tiempo write (ms) | Tiempo read (ms) | Resultado |" >> $RESULT_FILE
    echo "| ------ | -------------- | ----------------- | ---------------- | --------- |" >> $RESULT_FILE

    ./client_prueba $HOST $PORT $SIZE >> $RESULT_FILE
    echo "" >> $RESULT_FILE

done

echo "Experimento finalizado. Resultados en $RESULT_FILE"
