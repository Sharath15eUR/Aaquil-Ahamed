#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(){
    //ports
    int serverfd;
    //address
    struct sockaddr_in serveraddr, clientaddr;
    int clientaddrlen;

    // creation
    serverfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(serverfd == -1){
        printf("socket Creation Failed!");
        exit(1);
    }

    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port=htons(1234);

    if(bind(serverfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) != 0){
        printf("binding Failed!");
        exit(1);
    }
    printf("Running....");
  
    char buf[1024];
    int n;
    while(1){
        printf("\n");
        clientaddrlen = sizeof(clientaddr); 

        n = recvfrom(serverfd, buf, 1024, 0, (struct sockaddr*)&clientaddr, &clientaddrlen); //receive message from server  
        printf("\n Client's Message : %s\n",buf);
        sendto(serverfd, buf, n, 0, (struct sockaddr*)&clientaddr, sizeof(clientaddr));
    }

    close(serverfd);
    printf("Closed Server Socket\n");
    return 0;
}
