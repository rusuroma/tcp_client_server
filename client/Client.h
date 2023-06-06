#ifndef _CLIENT_H_
#define _CLIENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <limits.h>

#include "../common.h"
#include "InitClient.h"
#include "RunClient.h"
#include "StopClient.h"
#include "Queue.h"


#define PORT "5000"
#define QUEUE_EMPTY INT_MIN


#endif