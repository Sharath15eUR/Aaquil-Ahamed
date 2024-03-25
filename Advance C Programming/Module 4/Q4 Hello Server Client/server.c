#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(){
    int serverfd, clientfd;
    struct sockaddr_in serveraddr, clientaddr;
    int clientaddrlen;

    serverfd = socket(AF_INET, SOCK_STREAM, 0);
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

    if(listen(serverfd, 1) != 0){
        printf("listening Failed!");
        exit(1);
    }else{
        printf("listening...\n");
    }

    bzero(&clientaddr, sizeof(clientaddr));
    clientfd = accept(serverfd, (struct sockaddr*)&clientaddr, &clientaddrlen);
    if(clientfd == -1){
        printf("Accept Failed!");
        exit(1);
    }

    char* msg = "Hello";
    write(clientfd, msg, sizeof(msg));
    printf("message Sent\n");

    char buf[128];
    read(clientfd, buf, 128);
    printf("Recived msg from Client: \"%s\"\n", buf);

    close(clientfd);
    printf("Closed Client Socket\n");
    close(serverfd);
    printf("Closed Server Socket\n");
    return 0;
}
