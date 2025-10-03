echo "=== VM1: Ping Pong Servidor ==="

cp /vagrant/run_server.sh /home/vagrant/run_server.sh
cp /vagrant/run_server_pingpong.sh /home/vagrant/run_server_pingpong.sh
cp /vagrant/server_prueba.c /home/vagrant/server_prueba.c
cp /vagrant/server_pingpong.c /home/vagrant/server_pingpong.c

sed -i 's/\r$//' /home/vagrant/run_server.sh # Eliminar caracteres de fin de línea de Windows
sed -i 's/\r$//' /home/vagrant/run_server_pingpong.sh

# Obtenemos la IP que se le asigno a esta VM y guardamos para que el cliente la use
SERVER_IP=$(hostname -I | awk '{print $2}')
echo $SERVER_IP > /vagrant/server_ip.txt
echo "Servidor escuchará en IP: $SERVER_IP"
# Ejecutar servidor
chmod +x /home/vagrant/run_server.sh
chmod +x /home/vagrant/run_server_pingpong.sh
gcc /vagrant/server_prueba.c -o /home/vagrant/server_prueba
gcc /vagrant/server_pingpong.c -o /home/vagrant/server_pingpong
