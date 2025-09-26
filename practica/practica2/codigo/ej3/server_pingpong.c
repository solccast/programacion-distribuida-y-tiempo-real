#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h> 
#include <sys/time.h>

double dwalltime();
#define CANTIDAD_EXPERIMENTO 50


void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, n;
    struct sockaddr_in serv_addr, cli_addr;
    if (argc < 3) {
        fprintf(stderr,"usage %s port cantidad_bytes\n", argv[0]);
        exit(1);
    }

    /* Asignacion del puerto recibido por argumento */
    portno = atoi(argv[1]);
    int cantidad_bytes = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");


    /*Limpieza de la estructura serv_addr*/
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    int flag = 1;
    setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, &flag, sizeof(flag));
     /* Vinculacion del socket a la direccion */

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd,20); // Se setea la cantidad de conexiones en espera
    
    FILE *f = fopen("server_ready.txt", "w");
    if (f) {
        fprintf(f, "%d\n", portno);
        fclose(f);
    } else {
        perror("No se pudo crear server_ready.txt");
    }

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *)&clilen);
    if (newsockfd < 0)
        error("ERROR on accept");

    setsockopt(newsockfd, IPPROTO_TCP, TCP_NODELAY, &flag, sizeof(flag));

    /*Preparación del búffer*/
    char *buffer = (char *)malloc(cantidad_bytes * sizeof(char));
    bzero(buffer, cantidad_bytes);
    

    for (int i = 0; i < CANTIDAD_EXPERIMENTO; i++){
        /*Recibimiento de datos*/
        int bytes_recibidos = 0;

        while (bytes_recibidos < cantidad_bytes) {
            n = read(newsockfd, &buffer[bytes_recibidos], cantidad_bytes - bytes_recibidos);
            if (n < 0)
                error("ERROR reading from socket");
            bytes_recibidos += n;
        }
    
        // Reenviar los datos recibidos al cliente (ping-pong)
        n = write(newsockfd, buffer, bytes_recibidos);
        if (n < 0)
            error("ERROR writing to socket");
    
    }
    close(newsockfd);

    close(sockfd);
    free(buffer);
    remove("server_ready.txt");
    return 0;
}

double dwalltime()
{
    double sec;
    struct timeval tv;

    gettimeofday(&tv, NULL);
    sec = tv.tv_sec + tv.tv_usec / 1000000.0;
    return sec;
}