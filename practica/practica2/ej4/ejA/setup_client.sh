echo "=== VM2: Ping Pong Cliente ==="

cp /vagrant/run_client.sh /home/vagrant/run_client.sh
cp /vagrant/run_client_pingpong.sh /home/vagrant/run_client_pingpong.sh
cp /vagrant/client_prueba.c /home/vagrant/client_prueba.c
cp /vagrant/client_pingpong.c /home/vagrant/client_pingpong.c
sed -i 's/\r$//' /home/vagrant/run_client.sh
sed -i 's/\r$//' /home/vagrant/run_client_pingpong.sh

gcc /home/vagrant/client_prueba.c -o /home/vagrant/client_prueba
gcc /home/vagrant/client_pingpong.c -o /home/vagrant/client_pingpong
chmod +x /home/vagrant/run_client.sh
