#include "RunServer.h"

struct sockaddr_storage their_addr; // connector's address information
struct queue q1;
struct msg send_msg, recv_msg;
socklen_t addr_size;

char s[INET_ADDRSTRLEN];
char buf[MAXDATASIZE];

int listen_socket;

int numbytes;
int sendd;
int end_conn;
int add, t;


void *get_in_addr(struct sockaddr *sa)
{
    return &(((struct sockaddr_in*)sa)->sin_addr);
}

int runServer(int sockfd)
{
    printf("Run begin \n");
    listen_label:
    if(listen(sockfd, BACKLOG) == -1)
    {
        perror("server error: listen");
        exit(1);
    }

    printf("Server: waiting for connections...\n");

    addr_size = sizeof their_addr;

    if((listen_socket = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size)) == -1){
        perror("Server error: accept ");
        closeSocket(listen_socket);
        closeSocket(sockfd);
    }   

    inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr *)&their_addr), s, sizeof s);
    printf("Server: got connection from %s\n", s);  
    // init que for messages
    init_queue(&q1, 10);

    if ((send(listen_socket, "Client can send messages !\n", 28, 0)) == -1)
    {
        perror("Server error: send");
        closeSocket(listen_socket);
        closeSocket(sockfd);
    }
    memset(&recv_msg, 0, sizeof recv_msg);
    printf("%d \n", recv_msg.data);
    printf("%s \n", recv_msg.name);
    while(1) //accept loop
    {   
        //numbytes=0;
        
        if ((numbytes = recv(listen_socket, &recv_msg, sizeof (recv_msg), 0)) == -1) 
        {
            perror("recv");
            closeSocket(listen_socket);
        }else if((end_conn = recv(listen_socket, &recv_msg, sizeof (recv_msg), 0)) == 0)
        {
            printf("End connection from client !\n");
            //close(listen_socket);
            closeSocket(listen_socket);
            //display(&q1);
            goto listen_label;
        }
        printf("%d \n",numbytes);

        en_queue(&q1, add,&recv_msg);
        printf("%d \n", recv_msg.data);
        printf("%s \n", recv_msg.name);
        memset(&recv_msg, 0, sizeof recv_msg);
        
        
    }// end infinite loop
    return 0;
}
