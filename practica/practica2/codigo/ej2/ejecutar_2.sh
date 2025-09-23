#!/bin/bash

# Configuración de host y puerto
HOST="localhost"
PORT=5001
RESULT_FILE="resultados.md"
# Lista de tamaños de datos a probar
SIZES=(10 100 1000 10000 100000 1000000)

# Compilación de los programas

gcc server_prueba.c -o server_prueba
if [ $? -ne 0 ]; then
    echo "Error al compilar server_prueba.c"
    exit 1
fi

gcc client_prueba.c -o client_prueba
if [ $? -ne 0 ]; then
    echo "Error al compilar client_prueba.c"
    exit 1
fi

echo "Resultados del experimento cliente-servidor" > $RESULT_FILE
echo "Host: $HOST, Puerto: $PORT" >> $RESULT_FILE
echo "" >> $RESULT_FILE
 
for SIZE in "${SIZES[@]}"; do
    echo "Probando con tamaño: $SIZE"
    echo "| Modelo | Tamaño (bytes) | Tiempo Write(s) | Tiempo Read (s) | Notas |" >> $RESULT_FILE
    echo "| ------ | -------------- | --------------- | --------------- |-------|" >> $RESULT_FILE
    # Inicia el servidor en segundo plano
    ./server_prueba $PORT $SIZE >> $RESULT_FILE & # Ejecución en segundo plano
    sleep 3 # Espera a que el servidor esté listo
    # Ejecuta el cliente y guarda la salida
    ./client_prueba $HOST $PORT $SIZE >> $RESULT_FILE
    echo "" >> $RESULT_FILE
    done

echo "Experimento finalizado. Resultados en $RESULT_FILE"