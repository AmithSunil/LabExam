#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

void main(){
    struct sockaddr_in client;
    int s,flag;
    char buff[20];

    s = socket(AF_INET,SOCK_STREAM,0);

    client.sin_family = AF_INET;
    client.sin_port =2000;
    client.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(s,(struct sockaddr*)&client,sizeof client);

    for(;;){
        printf("enter the string:");
        scanf("%s",buff);
        printf("client: %s",buff);

        send(s,buff,sizeof(buff),0);
        recv(s,flag,sizeof(int),0);

        if (flag == 1){
            printf("pali");
            break;
        }else{
            printf(not pal);
            break;
        }
    }
    close(s);
}