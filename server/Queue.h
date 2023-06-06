#ifndef _QUEUE_H_
#define _QUEUE_H_


#include "Server.h"


#define QUEUE_EMPTY INT_MIN


struct queue
{
  int *values;
  int tail, index, size;
  struct msg *msg_q;
};



int queueFull(struct queue *q);
void init_queue(struct queue *q, int sizeMax);
int queueEmpty(struct queue *q);
void en_queue(struct queue *q, int values, struct msg *msg1);
void display (struct queue * q);

#endif