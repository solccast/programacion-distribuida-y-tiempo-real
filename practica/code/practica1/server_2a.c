/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>   // Para exit, atoi y otras funciones estándar
#include <string.h>   // Para bzero y otras funciones de cadenas
#include <unistd.h>   // Para read, write y otras funciones de E/S
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;

     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
	 
	 // CREA EL FILE DESCRIPTOR DEL SOCKET PARA LA CONEXIÓN
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
	 // AF_INET - FAMILIA DEL PROTOCOLO - IPV4 PROTOCOLS INTERNET
	 // SOCK_STREAM - TIPO DE SOCKET 
	 
     if (sockfd < 0) 
        error("ERROR opening socket");
		
     // LIMPIA LA ESTRUCTURA serv_addr
     bzero((char *) &serv_addr, sizeof(serv_addr));
     
     // ASIGNA EL PUERTO PASADO POR ARGUMENTO
     // ASIGNA LA IP EN DONDE ESCUCHA (SU PROPIA IP)
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
	 
	// VINCULA EL FILE DESCRIPTOR CON LA DIRECCIÓN Y EL PUERTO
     /*
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
		
     */

     // SETEA LA CANTIDAD QUE PUEDEN ESPERAR MIENTRAS SE MANEJA UNA CONEXIÓN
     
     listen(sockfd, 5);
     
     struct sockaddr_in addr;
     socklen_t len = sizeof(addr);
     getsockname(sockfd, (struct sockaddr *)&addr, &len);
     printf("Estoy escuchando en el puerto %d\n", ntohs(addr.sin_port));

	 // SE BLOQUEA A ESPERAR UNA CONEXIÓN
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
				 
     // DEVUELVE UN NUEVO DESCRIPTOR POR EL CUAL SE VAN A REALIZAR LAS COMUNICACIONES
	 if (newsockfd < 0) 
          error("ERROR on accept");
		  
     bzero(buffer, 256);

	 // LEE EL MENSAJE DEL CLIENTE
     n = read(newsockfd, buffer, 255);
     if (n < 0) error("ERROR reading from socket");
     printf("Here is the message: %s\n", buffer);
	 
	 // RESPONDE AL CLIENTE
     n = write(newsockfd, "I got your message", 18);
     if (n < 0) error("ERROR writing to socket");

     // CIERRA LOS SOCKETS
     close(newsockfd);
     close(sockfd);

     return 0; 
}
