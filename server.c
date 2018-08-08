#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>

int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("./server IP PORT\n");
        return 1;
    }
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0)
    {
        printf("socket errno\n");
        return 2;
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if(bind(sock,(struct sockaddr *)&server,sizeof(server)) < 0)
    {
        printf("bind errno\n");
        return 3;
    }
    
    if(listen(sock,5) < 0)
    {
        printf("listen errno\n");
        return 4;
    }
    printf("wait for accept...\n");

    while(1)
    {
        struct sockaddr_in client;
        socklen_t len = sizeof(client);
    }


}
