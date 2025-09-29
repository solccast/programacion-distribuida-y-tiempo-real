echo "=== VM2: Ping Pong Cliente ==="

cp /vagrant/run_client.sh /home/vagrant/run_client.sh
cp /vagrant/client_prueba.c /home/vagrant/client_prueba.c
sed -i 's/\r$//' /home/vagrant/run_client.sh

gcc /home/vagrant/client_prueba.c -o /home/vagrant/client_prueba
chmod +x /home/vagrant/run_client.sh
