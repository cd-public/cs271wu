// client.c 

#include <sys/socket.h> 
#include <arpa/inet.h> 
#define PORT 8080 
#define DOMAIN AF_INET6

int main(int argc, char const *argv[]) 
{ 
	int sock;
	struct sockaddr_in6 address; 
	
	sock = socket(DOMAIN, SOCK_STREAM, 0);

	address.sin6_family = DOMAIN; 
	address.sin6_port = htons(PORT); // "In practice, only the port field needs to be formatted with htons()"
	inet_pton(DOMAIN, "::1", &address.sin6_addr); // "::1" is IPv^ "loopback" address

	connect(sock, &address, sizeof(address));
	
	write(sock, argv[1], strlen(argv[1]));
	
	return 0; 
} 
