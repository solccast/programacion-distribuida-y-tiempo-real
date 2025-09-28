echo "=== VM2: Ping Pong Cliente ==="
# Esperar que el archivo de IP del servidor exista

while [ ! -f /vagrant/server_ip.txt ]; do
    echo "Esperando IP del servidor..."
    sleep 1
done
          
SERVER_IP=$(cat /vagrant/server_ip.txt)
echo "IP del servidor detectada: $SERVER_IP"

# Esperar a que el servidor esté en estado listen
until nc -z $SERVER_IP 8080; do
    echo "Esperando a que el servidor este en estado listen..."
    sleep 1
done

# Ejecutamos cliente
cp /vagrant/run_client.sh /home/vagrant/run_client.sh
cp /vagrant/client_prueba.c /home/vagrant/client_prueba.c
sed -i 's/\r$//' /home/vagrant/run_client.sh

gcc /home/vagrant/client_prueba.c -o /home/vagrant/client_prueba
chmod +x /home/vagrant/run_client.sh
