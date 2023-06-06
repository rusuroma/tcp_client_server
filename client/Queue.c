#include "Queue.h"



int queueFull(struct queue *q)
{
  if(q->index == q->size)
  {
    return 4;
  }
}


void init_queue(struct queue *q, int sizeMax)
{
 q->size = sizeMax;
 q->values = malloc(sizeof(int) * q->size);
 q->index = 0; // que index
 q->tail = 0;
 q->msg_q = (struct part *)malloc(sizeof(struct msg) * q->size);
}

// check if queue is empty
int queueEmpty(struct queue *q)
{
  if (q->index == 0)
  {
    return 0;
  }
}


// Add element
void en_queue(struct queue *q, int values, struct msg *msg1)
{
 // Check if que is full
  if (queueFull(q)==4)
  {
   ; // have to add !!!!!
  }
  // add values
  q->values[q->tail] = values;
  q->msg_q[q->tail] = *msg1;
  q->tail = (q-> tail + 1) % q->size;
  q->index++;

}


// ++ Display ++
void display (struct queue * q) {
  // check if it is empty
  if (QUEUE_EMPTY == 0) {
    printf ("Your work-list is empty \n");
    return;
  }
  printf ("The number of stored messages is: %d \n", q->index );
  printf ("\nThe elements of the Queue are: \n");
  for (int i=0; i<q->index; i++) {
    printf("Message : %d\n",i+1);
    printf("%d %s\n",q->msg_q[i].data,q->msg_q[i].name);
  }
}