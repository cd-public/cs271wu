// server.c

#include <sys/socket.h> 
#include <arpa/inet.h> 
#define PORT 8080 
#define DOMAIN AF_INET6
#define BUFF_SIZE 1024

int main(int argc, char const *argv[]) 
{ 
    int sock; 
    struct sockaddr_in6 address; 

    sock = socket(DOMAIN, SOCK_STREAM, 0);

    address.sin6_family = DOMAIN; 
    address.sin6_port = htons(PORT); // "In practice, only the port field needs to be formatted with htons()"
    address.sin6_addr = in6addr_any; 
	
    int opt = 1; // True
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    	
    bind(sock, &address, sizeof(address));
    listen(sock, 1);
    int addrlen = sizeof(address); 
    int connection = accept(sock, &address, &addrlen); 
    char buffer[BUFF_SIZE] = {0}; 
    read(connection, buffer, BUFF_SIZE); 
	
    printf("%s\n",buffer ); 
	
    return 0; 
} 
