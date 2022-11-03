#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DOMAIN AF_INET6
#define PORT 0xC271

int main(int argc, char *argv[])
{
	// set up variables
	int sock = socket(DOMAIN, SOCK_STREAM, 0);
	struct sockaddr_in6 addr ;
	struct sockaddr *add4 ;
	
	// setting up fields in addr
	addr.sin6_family = DOMAIN ;
	addr.sin6_port = htons(PORT) ; // this is a number *I* wrote leaving my computer
	inet_pton(DOMAIN, "::1", &addr.sin6_addr); // leave this as boilerplate
	
	// network connectivity
	add4 = (struct sockaddr *)&addr ;
	if (connect(sock, add4, sizeof(addr)))
	{
		fprintf(stderr, "Connect failed.\n") ;
		exit(-1) ; // I am writing "exit" instead of "return" as a matter of style
	}
	
	// transmit bits
	write(sock, argv[1], strlen(argv[1]));
	return 0 ;
}
