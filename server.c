#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "protocolo.h"
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>



int main(int argc, char *argv[]){

	if (argc!=4){
		printf("[ERRO] Esperados 3 argumentos: protocolo ([v4, v6]), porta (int), palavra (char[5])");
		return 1;
	}
	char *protocolo = argv[1];
	char *porta_raw = argv[2];
	int porta = strtol(porta_raw, NULL, 10);
	char *palavra = argv[3];

	int sockid;
	struct sockaddr_storage addr;
	memset(&addr, 0, sizeof(addr));

		if v4:
		familia = AF_INET
		ponteiro a4 = (struct sockaddr_in *)&addr
		a4->sin_family = AF_INET
		a4->sin_port = htons(porta)
		a4->sin_addr.s_addr = INADDR_ANY
		addrlen = sizeof(struct sockaddr_in)
	else if v6:
		familia = AF_INET6
		ponteiro a6 = (struct sockaddr_in6 *)&addr
		a6->sin6_family = AF_INET6
		a6->sin6_port = htons(porta)
		a6->sin6_addr = in6addr_any
		addrlen = sizeof(struct sockaddr_in6)
	else:
		erro, return 1


	// Parse protocol
	if(strcmp(protocolo,"v4") == 0){
		
		addr.ssfamily = AF_INET;
	} else if(strcmp(protocolo,"v6") == 0){
		struct sockaddr_in6 addr;
		memset(&addr, 0, sizeof(addr));		
		addr.sin6_port = htons(porta);
		addr.sin6_family = AF_INET6;
	} else {
		printf("[ERRO] Protocolo incorreto. Escolha = [ v4, v6 ]");
	}
	
	// Setup server
	sockid = socket(AF_UNIX, SOCK_STREAM, 0);		
	if (sockid < 0) {
		perror("socket");			
		close(sockid);
		return 1;
	}		
	int bind= bind(sockid, (struct sockaddr *)&addr, sizeof(addr));
	if (bind < 0){
		perror("bind");			
		close(sockid);
		return 1;
	}
	int listen = listen(sockid, 10);
	if(listen < 0){
		perror("listen");
		close(sockid);
		return 1
	}
	printf("Servidor iniciado em modo IP%s na porta %d\n", protocolo, porta);

	int cliente = accept(sockid, NULL, NULL);
	if(cliente < 0){
		perror("accept");
		close(sockid);
		return 1
	}

	
	printf("Cliente conectado\n");
	int guessed = 0;
//	while (guessed==0) {


//	}

	
	
	

	close(sockid);
	return 0;
}

