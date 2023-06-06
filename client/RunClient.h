#ifndef _RUN_CLIENT_H_
#define _RUN_CLIENT_H_


#include "Client.h"



int runClient(int sockfd);
void *get_in_addr(struct sockaddr *sa);


#endif