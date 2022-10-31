// server.c

#include <sys/socket.h> 
#include <arpa/inet.h> 
#define PORT 8080 
#define DOMAIN AF_INET6
#define BUFF_SIZE 1024

int main(int argc, char const *argv[]) 
{ 
    struct sockaddr_in6 address; 
    int sock = socket(DOMAIN, SOCK_STREAM, 0), opt = 1, addrlen = sizeof(address), connection ; 
    char buffer[BUFF_SIZE] = {0}; 

    address.sin6_family = DOMAIN; 
    address.sin6_port = htons(PORT); // "In practice, only the port field needs to be formatted with htons()"
    address.sin6_addr = in6addr_any; 

    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    	
    bind(sock, &address, sizeof(address));
    listen(sock, 1);
    connection = accept(sock, &address, &addrlen); 
    read(connection, buffer, BUFF_SIZE); 
	
    printf("%s\n",buffer ); 
	
    return 0; 
} 
