#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
	#include <winsock2.h>
	#include <ws2tcpip.h>
	#define read(sock, buf, len) recv(sock, buf, len, 0)
	#define write(sock, buf, len) send(sock, buf, len, 0)
	#define close(sock) closesocket(sock)
#else
	#include <unistd.h>
	#include <arpa/inet.h>
#endif

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_request(int client_socket) {
	char buffer[BUFFER_SIZE];
	read(client_socket, buffer, sizeof(buffer) - 1);
	printf("%s\n", buffer);

	const char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\r\n\r\n"
												 "<html><body><h1>Hello world!</h1></body></html>";
	write(client_socket, response, strlen(response));
	close(client_socket);
}

int main() {
	printf("HELLO!");
	fflush(stdout);
	
	#ifdef _WIN32 
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
			fprintf(stderr, "WSAStartup failed\n");
			return 1;
		}
	#endif	
	
	int server_socket, client_socket;
	struct sockaddr_in server_addr, client_addr;
	socklen_t addr_len = sizeof(client_addr);

	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT);

	bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)); 
	listen(server_socket, 3);
	
	printf("Server is running on port %d\n", PORT);
	fflush(stdout);

	while(1) {
		client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
		handle_request(client_socket);
	}

	#ifdef _WIN32 
		WSACleanup();
	#endif

	return 0;
}
