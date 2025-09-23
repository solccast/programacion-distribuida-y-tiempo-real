#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

#define CANTIDAD_EXPERIMENTO 10 
double dwalltime();

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
    double t0, t1, t2, t3, tiempo_write, tiempo_read, tiempo_acumulado = 0.0, elapsed; 
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
        buffer[j] = 'A'; // Nos aseguramos que el buffer no esté vacío
    }

    char respuesta[10];
    /* Envío del mensaje al socket */
    
    for (int i = 0; i < CANTIDAD_EXPERIMENTO; i++){
        t0 = dwalltime(); 
        n = write(sockfd, &buffer[0], cantidad_bytes);
        // Esperar respuesta del servidor
        n = read(sockfd, respuesta, sizeof(respuesta)-1);
        t1 = dwalltime();
        tiempos[i] = t1 - t0;
        respuesta[n] = '\0';
        printf("| CLIENTE:: | %d | %f | %f | %s |\n", cantidad_bytes, tiempos[i], tiempos[i]/2.0, respuesta);
    }
    
    double promedio = calcularPromedio(tiempos, CANTIDAD_EXPERIMENTO);
    printf("Promedio de tiempo para %d bytes: %f segundos\n", cantidad_bytes, promedio);

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
