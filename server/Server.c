#include "Server.h"



int main()
{   
    
    
    //void initServer(struct addrinfo address_info, struct addrinfo *servinfo, int res_get_adr, int sockfd, int yes);
    int serverInit = initServer();
    if(serverInit > 0)
    {
        int serverRun =  runServer(serverInit);
    }
        
    //void clpseMainSocket(int socfd);

    return 1;
} 