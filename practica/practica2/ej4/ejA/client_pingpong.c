#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h> 
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

double dwalltime();
#define CANTIDAD_EXPERIMENTO 100

void error(char *msg)
{
    perror(msg);
    exit(1);
}

double calcularPromedio(double *tiempos, int cantidad) {
    double suma = 0.0;
    for (int i = 0; i < cantidad; i++) {
        suma += tiempos[i];
    }
    return suma / cantidad;
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    double t0, t1;
    double tiempos[CANTIDAD_EXPERIMENTO];

    if (argc < 4) {
       fprintf(stderr,"usage %s hostname port cantidad_bytes\n", argv[0]);
       exit(1);
    }

    portno = atoi(argv[2]);
    int cantidad_bytes = atoi(argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    
    int flag = 1;
    setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, &flag, sizeof(flag));

    /*Se toma la dirección del servidor de los argumentos*/
    server = gethostbyname(argv[1]); 
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    /*Limpieza de la estructure serv_addr*/
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    
    /* Preparacion de la estructura*/    
    char *buffer = (char *)malloc(cantidad_bytes * sizeof(char));
    bzero(buffer, cantidad_bytes);
    for (int j = 0; j < cantidad_bytes; j++) {
        buffer[j] = 'A';
    }

    for (int i = 0; i < CANTIDAD_EXPERIMENTO; i++){
        t0 = dwalltime();
        n = write(sockfd, buffer, cantidad_bytes);

        if (n < 0)
            error("ERROR writing to socket");    

        // Esperar la respuesta del servidor
        int bytes_recibidos = 0;
        while (bytes_recibidos < cantidad_bytes) {
            n = read(sockfd, &buffer[bytes_recibidos], cantidad_bytes - bytes_recibidos);
            if (n < 0)
                error("ERROR reading from socket");
            bytes_recibidos += n;
        }
        t1 = dwalltime();
        double tiempo_total = (t1 - t0) * 1000.0; // Tiempo en milisegundos
        tiempos[i] = tiempo_total; // Guardar el tiempo total del ping-pong
        printf("| CLIENTE:: | % d | %f |\n", cantidad_bytes, tiempo_total);
    }

    double one_way_tiempo = calcularPromedio(tiempos, CANTIDAD_EXPERIMENTO) / 2.0;
    /* Envío del mensaje al socket y espera de respuesta (ping-pong) */
    printf("| [PROMEDIO FINAL] CLIENTE:: | %d | %f | %f |\n", cantidad_bytes, calcularPromedio(tiempos, CANTIDAD_EXPERIMENTO), one_way_tiempo);

    close(sockfd);
    free(buffer);
    return 0;
}


/* Función para obtener el tiempo actual en segundos */
double dwalltime()
{
    double sec;
    struct timeval tv;

    gettimeofday(&tv,NULL);
    sec = tv.tv_sec + tv.tv_usec/1000000.0;
    return sec;
}
