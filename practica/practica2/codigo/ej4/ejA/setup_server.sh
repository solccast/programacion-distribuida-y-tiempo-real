echo "=== VM1: Ping Pong Servidor ==="
cp /vagrant/server/run_server.sh /home/vagrant/run_server.sh
cp /vagrant/server/server_prueba.c /home/vagrant/server_prueba.c
sed -i 's/\r$//' /home/vagrant/run_server.sh # Eliminar caracteres de fin de línea de Windows
chmod +x /home/vagrant/run_server.sh

# Obtenemos la IP que se le asigno a esta VM y guardamos para que el cliente la use
SERVER_IP=$(hostname -I | awk '{print $2}')
echo $SERVER_IP > /vagrant/server_ip.txt
echo "Servidor escuchará en IP: $SERVER_IP"
# Ejecutar servidor
nohup /home/vagrant/run_server.sh > /vagrant/server/server.log 2>&1 &