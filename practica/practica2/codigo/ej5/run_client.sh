#!/bin/bash

# Ojo, el host se tiene que pasar como argumento
HOST=198.168.56.50
PORT=8080
RESULT_FILE="/vagrant/resultados_ej5.txt"
SIZES=(10 100 1000 10000 100000 1000000)


until nc -z $HOST $PORT; do
  echo "Esperando a que el servidor esté disponible en $HOST:$PORT..."
  sleep 1
done

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
