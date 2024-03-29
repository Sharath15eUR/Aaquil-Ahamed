#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(){
    int sockfd;
    struct sockaddr_in socketaddr;
    char msg[1024],output_buffer[1024];
    strcpy(msg,"");
    printf("\n Enter the message : ");
    scanf("%s",msg);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
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
   
    sendto(sockfd, msg, 1024, 0, (struct sockaddr*)NULL, sizeof(socketaddr));
    int n = recvfrom(sockfd, output_buffer, 1024, 0, (struct sockaddr*)NULL, NULL); //receive message from server 
    output_buffer[n] = '/0';
    printf("\n Server's Echo : %s\n\n",output_buffer);

    close(sockfd);
    printf("Socket closed");

    return 0;
}
