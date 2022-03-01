Sockets and addresses

	socket
		socket(DOMAIN, SOCK_STREAM, 0);
	
	struct sockaddr_in
		address.sin6_family = DOMAIN; 
		address.sin6_port = htons(PORT); // "In practice, only the port field needs to be formatted with htons()"
		SERVER: address.sin6_addr = in6addr_any;
		CLIENT: inet_pton(DOMAIN, "::1", &address.sin6_addr);

	use headers
		#include <sys/socket.h> 
		#include <arpa/inet.h> 

	socket functions
		ususally have 1-3 arguments, the first being a socket, and latter being addresses, flags, or payload


Servers go through "bla(r)"	
	
	bind
		bind(sock, &address, addrlen);

	listen
		listen(sock, 1); // 1 is backlog size
	
	accept
		connection = accept(sock, &address, &addrlen); 

	(read)
		read(connection, buffer, BUFF_SIZE); 
			i do:
				#define BUFF_SIZE 1024
				char buffer[BUFF_SIZE] = {0}; 

Clients go through "c(w)"

	connect (same as bind)
		connect(sock, &address, sizeof(address));
	
	(write)
		write(sock, str, strlen(str));
		
Niceties:

	Timing is bla(cw)r

	Can make your life easier with: setsockopt
		SERVER: int opt = 1; setsockopt(<socket>, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
		
	*Should* error check everything
		if (connect(...) < 0) { printf("connect() failed"; exit(-1); }
		
	Can cast function inputs to remove gcc warnings
		connect(sock, (struct sockaddr *)&serv_addr, sizeof(address))
		
	Compose "bla" and "sock+addr" into helper functions
	
	Get/free addrinfo
		getaddrinfo(hostname, "http", &hints, &server_list)
