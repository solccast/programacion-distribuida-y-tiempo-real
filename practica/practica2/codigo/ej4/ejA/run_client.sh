#!/bin/bash

# Ojo, el host se tiene que pasar como argumento
HOST=$1
PORT=8080
RESULT_FILE="/vagrant/resultados_ej2.txt"
SIZES=(10 100 1000 10000 100000 1000000)

if [ -z "$HOST" ]; then
    echo "Uso: $0 <IP_SERVIDOR>"
    exit 1
fi

./client_prueba $HOST $PORT 1 &
CLIENT_PID=$!
kill $CLIENT_PID

echo "# Resultados del experimento cliente-servidor - EJ 2" > $RESULT_FILE
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
