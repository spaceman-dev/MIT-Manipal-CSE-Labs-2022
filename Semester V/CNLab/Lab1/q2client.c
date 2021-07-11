#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#define PORT 7000
#define sa struct sockaddr
int main()
{
    int sockid = socket(AF_INET, SOCK_STREAM, 0);
    int data_len;
    unsigned int len;
    struct sockaddr_in serv_addr, temp;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    connect(sockid, (sa *)&serv_addr, sizeof(serv_addr));
    char buff[100], line[100];
    for(;;)
    {
        printf("Enter Message to send to Server or QUIT: \n");
        bzero(line, sizeof(line));
        bzero(buff, sizeof(buff));
        scanf("%s", line);
        write(sockid, line, strlen(line));
        // read(sockid, buff, sizeof(buff));
        // printf("\nServer says: %s\n", buff);
        if (strncmp(buff, "QUIT", 4) == 0)
            break;
    }
    printf("Client connection closed\n");
    close(sockid);
    return 0;
}