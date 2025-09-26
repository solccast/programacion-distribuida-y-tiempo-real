
#!/bin/bash

# Configuración de host y puerto
HOST="localhost"
PORT=8080
RESULT_FILE="resultados_pingpong.md"
# Lista de tamaños de datos a probar
SIZES=(10 100 1000 10000 100000 1000000)

# Compilación de los programas

gcc server_pingpong.c -o server_pingpong
if [ $? -ne 0 ]; then
    echo "Error al compilar server_pingpong.c"
    exit 1
fi

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
    echo "| Modelo | Tamaño (bytes) | Tiempo Total (s) | One way (s) |" >> $RESULT_FILE
    echo "|--------|----------------|------------------|-------------|" >> $RESULT_FILE
    ./server_pingpong $PORT $SIZE >> $RESULT_FILE &
    # Ejecuta el cliente y guarda la salida
    while [ ! -f server_ready.txt ]; do
        sleep 0.1
    done
    ./client_pingpong $HOST $PORT $SIZE >> $RESULT_FILE
    echo "" >> $RESULT_FILE
    done

echo "Experimento finalizado. Resultados en $RESULT_FILE"
