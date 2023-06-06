#include "Client.h"

 

int main(int argc, char *argv[])
{   
    
    
    //void initServer(struct addrinfo address_info, struct addrinfo *servinfo, int res_get_adr, int sockfd, int yes);
    int clientInit = initClient(argv[1]);
    if(clientInit > 0)
    {
        int serverClient =  runClient(clientInit);
    }
        
    //void clpseMainSocket(int socfd);

    return 0;
} 