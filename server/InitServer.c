#include "InitServer.h"


static struct addrinfo address_info, *servinfo;
int sockfd;
int res_get_adr;
int yes = 1;

int initServer()
{

    
    memset(&address_info, 0, sizeof address_info);
    address_info.ai_family = AF_UNSPEC; // use IPv4 or IPv6, whichever
    address_info.ai_socktype = SOCK_STREAM;
    address_info.ai_flags = AI_PASSIVE;

    if((res_get_adr = getaddrinfo("localhost", "5000", &address_info, &servinfo)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(res_get_adr));
        return 1;
    }

    if((sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol)) == -1)
    {
        perror("server error: socket");
        return 2;
    }

    if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof yes) == -1) 
    {
        perror("setsockopt");
        exit(1);
    }

    if(bind(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1)
    {
        perror("server error: bind ");
        return 3;
    }
    freeAdressInfo(servinfo);
    return sockfd;
}



