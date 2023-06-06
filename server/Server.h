#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <limits.h>
#include <stdbool.h>

#include "../common.h"
#include "InitServer.h"
#include "RunServer.h"
#include "StopServer.h"
#include "Queue.h"


#define BACKLOG 10
#define PORT 5000
#define QUEUE_EMPTY INT_MIN


#endif