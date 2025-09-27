#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>  // Para strlen y otras funciones de cadenas
#include <unistd.h>  // Para read, write y otras funciones de E/S
#include <stdlib.h>  // Para exit y otras funciones estándar

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int size_buffer[6] = {10, 100, 1000, 10000, 100000, 1000000};
    //char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(1);
    }

    // TOMA EL NÚMERO DE PUERTO DE LOS ARGUMENTOS
    portno = atoi(argv[2]);
	
    // CREA EL FILE DESCRIPTOR DEL SOCKET PARA LA CONEXIÓN
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    // AF_INET - FAMILIA DEL PROTOCOLO - IPV4 PROTOCOLS INTERNET
    // SOCK_STREAM - TIPO DE SOCKET 
	
    if (sockfd < 0) 
        error("ERROR opening socket");
	
    // TOMA LA DIRECCIÓN DEL SERVIDOR DE LOS ARGUMENTOS
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // LIMPIA LA ESTRUCTURA serv_addr
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
	
    // COPIA LA DIRECCIÓN IP Y EL PUERTO DEL SERVIDOR A LA ESTRUCTURA DEL SOCKET
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
	
    // DESCRIPTOR - DIRECCIÓN - TAMAÑO DIRECCIÓN
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    // Acá es donde se modificará la entrada de datos. 
    int i, j; 
    for (i = 0; i < sizeof(size_buffer); i++){
        // Reservo el espacio del buffer
        char buffer[size_buffer[i]];
        bzero(buffer, size_buffer[i]);
        // Llenamos completamente el buffer sin la entrada estándar  
        for (j = 0; j < size_buffer[i]; j++) {
            buffer[j] = 'A';
        }

        // ENVÍA UN MENSAJE AL SOCKET
        n = write(sockfd, buffer, size_buffer[i]);
        if (n < 0) 
             error("ERROR writing to socket");
        else 
            printf("Mensaje de tamaño %d enviado\n", n);

        //Limpio el buffer
        bzero(buffer, size_buffer[i]);

        printf("Mensaje de tamaño %d enviado\n", size_buffer[i]);
    }


    // CIERRA EL SOCKET
    close(sockfd);
    return 0;
}
