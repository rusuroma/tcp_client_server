#include "StopServer.h"



void closeSocket(int listenn_socket)
{
    close(listenn_socket);
}


void freeAdressInfo(struct addrinfo *servinfoo;){

      freeaddrinfo(servinfoo);
}

