#ifndef _RUN_SERVER_H_
#define _RUN_SERVER_H_


#include "Server.h"



int runServer(int sockfd);
void *get_in_addr(struct sockaddr *sa);

#endif