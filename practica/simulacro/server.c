#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(){
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // crea el file descriptor
    
    struct sockaddr_in server, client; // las dos estructuras necesarias 
    memset(&server, 0, sizeof(server)); // limpia la estructura
    server.sin_family = AF_INET; // familia de direcciones IPv4
    server.sin_addr.s_addr = INADDR_ANY; // acepta conexiones de cualquier IP
    server.sin_port = htons(8000); // puerto del servidor

    bind(sockfd, (struct sockaddr*)&server, sizeof(server)); // asocia el socket a la dirección y puerto
    printf("Server listening on port 8000...\n");
    listen(sockfd, 5); // escucha conexiones entrantes
    
    socklen_t client_len = sizeof(client); // tamaño de la estructura client
    int newsockfd = accept(sockfd, (struct sockaddr*)&client, &client_len); // acepta una conexión entrante, crea un nuevo file descriptor
    
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));

    read(newsockfd, buffer, sizeof(buffer)-1); // lee el mensaje del cliente
    printf("Received from client: %s\n", buffer);
    char *response = "Hello, Client!";
    write(newsockfd, response, strlen(response)); // envía la respuesta al cliente
    close(newsockfd); // cierra el socket con el cliente
    close(sockfd); // cierra el socket del servidor
    return 0;
}