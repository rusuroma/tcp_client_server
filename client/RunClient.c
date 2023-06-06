#include "RunClient.h"

struct msg send_msg, recv_msg;
socklen_t addr_size;

//char buf[MAXDATASIZE];

int listen_socket;
int bytes_sent;
int sendd;
int end_conn;
int add, t;



int runClient(int sockfd)
{
    
         while(1)
    {   
        //bytes_sent = 0;
        
        scanf("%d", &send_msg.data);
        scanf("%s", send_msg.name);

        if ((bytes_sent = send(sockfd, &send_msg, sizeof (send_msg), 0)) == -1)
        { 
            perror("send");
            break;
        }
        printf("%d \n", bytes_sent);
        memset (&send_msg, 0, sizeof(send_msg));
    }

    closeSocket(sockfd);

    return 0;
        
        
    
}
