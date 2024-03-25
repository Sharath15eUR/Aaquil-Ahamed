#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(){
    int sockfd;
    struct sockaddr_in socketaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        printf("socket Creation Failed!");
        exit(1);
    }

    bzero(&socketaddr, sizeof(socketaddr));
    socketaddr.sin_family = AF_INET;
    socketaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    socketaddr.sin_port=htons(1234);

    if(connect(sockfd, (struct sockaddr*)&socketaddr, sizeof(socketaddr)) != 0){
        printf("Connection Failed!");
        exit(1);
    }

    char buf[128];
    read(sockfd, buf, 128);
    printf("Recived msg from server: \"%s\"\n", buf);

    char* msg = "Hello";

    write(sockfd, msg, sizeof(msg));
    printf("Message sent\n");

    close(sockfd);
    printf("Socket cloesed");

    return 0;
}
