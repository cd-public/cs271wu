#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define DOMAIN AF_INET6
#define PORT 0xC271
#define BUFFSIZE 1024

int main(int argc, char *argv[])
{
	// set up variables
	int sock = socket(DOMAIN, SOCK_STREAM, 0), opt = 1, conx, s = sizeof(struct sockaddr_in6) ;
	struct sockaddr_in6 addr ;
	struct sockaddr *add4 ;
	char buff[BUFFSIZE] = { 0 } ;
	
	// setting up fields in addr
	addr.sin6_family = DOMAIN ;
	addr.sin6_port = htons(PORT) ; // this is a number *I* wrote leaving my computer
	addr.sin6_addr = in6addr_any ;
	
	// make testing easier
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
	
	// network connectivity
	add4 = (struct sockaddr *)&addr ;
	if (bind(sock, add4, s))
	{
		fprintf(stderr, "Binding failed.\n") ;
		exit(-1) ; // I am writing "exit" instead of "return" as a matter of style
	}
	if (listen(sock, 1))
	{	
		fprintf(stderr, "Listen failed.\n") ;
		exit(-1) ;
	}
	conx = accept(sock, add4, &s) ;
	if (conx == -1)
	{
		fprintf(stderr, "Accept failed.\n") ;
		exit(-1) ;
	}

	// read in bits
	read(conx, buff, BUFFSIZE) ;		
	
	// transmit bits
	printf("%s\n", buff) ;
	
	return 0 ;
}
