#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include "protocolo.h"
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	
	char *ip = argv[1];
	char *porta_raw = argv[2];
	int porta = strtol(porta_raw, NULL, 10);



	int sockid = socket(AF_INET, SOCK_STREAM, 0);



    close(sockid);
    return 0;

};



