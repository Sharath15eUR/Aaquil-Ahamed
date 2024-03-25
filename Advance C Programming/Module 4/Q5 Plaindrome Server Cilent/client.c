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

    //connect
    bzero(&socketaddr, sizeof(socketaddr));
    socketaddr.sin_family = AF_INET;
    socketaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    socketaddr.sin_port=htons(1234);

    if(connect(sockfd, (struct sockaddr*)&socketaddr, sizeof(socketaddr)) != 0){
        printf("Connection Failed!");
        exit(1);
    }

    // Connected -> Read/Write

    char* msg = "levels";

    write(sockfd, msg, sizeof(msg));
    printf("Message sent\n");
    
    int result;
    recv(sockfd, &result, sizeof(result), 0);

    if(result == 1)
        printf("%s is a plaindrome\n", msg);
    else
         printf("%s is a  not plaindrome\n", msg);

    close(sockfd);
    printf("Socket cloesed");

    return 0;
}
