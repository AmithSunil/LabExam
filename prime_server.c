#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

void main{
    struct sockaddr_in client,server;
    int s,sock,left,right,flag;
    char b[1024];

    s= socket(AF_INET,SOCK_STREAM,0);

    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = inet_addr("127.0.5.1");


    bind(s,(struct sockaddr*)&server,sizeof server);
    listen(s,1);
    n = sizeof client;

    sock = accept(s,(struct sockaddr*)&server,&n);

    for(;;){
        recv(sock,b1,sizeof(b1),0);
        printf("the recieved string: %s",b1);

        if(strlen(b1)==0){
            flag ==1;
        }else{
            left = 0;
            right = strlen(b1)-1;
            flag =1;
            while(left<right && flag){
                if(b1[left]!=b1[right]){
                    flag ==0;
                }else{
                    left++;
                    right--;
                }
            }
        }
        send(s,flag,sizeof(int),0);
        break;
    }
    close(sock);
    close(s);
}