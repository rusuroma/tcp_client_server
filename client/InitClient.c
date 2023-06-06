#include "InitClient.h"


static struct addrinfo address_info, *servinfo;
int sockfd;
int numbytes;
int rv;
char s[INET_ADDRSTRLEN];
char buf[MAXDATASIZE];

void *get_in_addr(struct sockaddr *sa)
{
    return &(((struct sockaddr_in*)sa)->sin_addr);
}


int initClient(char hostname[100])
{
    memset(&address_info, 0, sizeof address_info);
    address_info.ai_family = AF_UNSPEC;
    address_info.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, PORT, &address_info, &servinfo)) != 0) 
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    if ((sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol)) == -1) 
    {
        perror("client error: socket");
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) 
    {
        //closeSocket(sockfd);
        perror("client: connect");
    }

    inet_ntop(servinfo->ai_family, get_in_addr((struct sockaddr *)servinfo->ai_addr), s, sizeof s);
    printf("client: connecting to %s\n", s);
    
    freeaddrinfo(servinfo);
    
    if ((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) 
    {
        perror("recv");
        exit(1);
    }

    buf[numbytes] = '\0';
    printf("Server sent:  %s \n", buf);

    return sockfd;
}



