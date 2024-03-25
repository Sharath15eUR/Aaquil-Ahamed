#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int isPalindrome(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main(){
    //ports
    int serverfd, clientfd;
    //address
    struct sockaddr_in serveraddr, clientaddr;
    int clientaddrlen;

    // creation
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverfd == -1){
        printf("socket Creation Failed!");
        exit(1);
    }

    //bind
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port=htons(1234);

    if(bind(serverfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) != 0){
        printf("binding Failed!");
        exit(1);
    }

    //listen
    if(listen(serverfd, 1) != 0){
        printf("listening Failed!");
        exit(1);
    }
    else{
        printf("listening...\n");
    }

    //accept
    bzero(&clientaddr, sizeof(clientaddr));
    clientfd = accept(serverfd, (struct sockaddr*)&clientaddr, &clientaddrlen);
    if(clientfd == -1){
        printf("Accept Failed!");
        exit(1);
    }


    char buf[1024];
    read(clientfd, buf, 1024);
    printf("Recived msg from Client: \"%s\"\n", buf);
    int result  = isPalindrome(buf);
    send(clientfd, &result, sizeof(result), 0);

    close(clientfd);
    printf("Closed Client Socket\n");
    close(serverfd);
    printf("Closed Server Socket\n");
    return 0;
}
