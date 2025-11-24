#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

double dwalltime() {
    double sec;
    struct timeval tv;

    gettimeofday(&tv, NULL);
    sec = tv.tv_sec + tv.tv_usec / 1000000.0;
    return sec;
}


int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // Crea el socket, file descriptor
    double t0, t1;
    struct sockaddr_in server;  
    memset(&server, 0, sizeof(server)); // Limpia la estructura
    server.sin_family = AF_INET; // Familia de direcciones IPv4
    server.sin_port = htons(8000); // Puerto del servidor
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr); // Dirección IP del servidor

    connect(sockfd, (struct sockaddr*)&server, sizeof(server)); // Conexión al servidor
    char buffer[256]; 
    memset(buffer, 0, sizeof(buffer)); // Limpia el buffer
    t0 = dwalltime(); // Tiempo inicial
    write(sockfd, "ping", 4); 
    read(sockfd, buffer, sizeof(buffer)-1); // Espera la respuesta del servidor 
    t1 = dwalltime(); // Tiempo final
    printf("Recibido del buffer: %s\n", buffer); // Muestra la respuesta 
    printf("Tiempo de ida y vuelta: %f segundos\n", t1 - t0); // Muestra el tiempo de ida y vuelta
    close(sockfd); // Cierra el socket

    return 0;
}