#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <ctype.h>
#define PORT 7000
#define sa struct sockaddr
int main()
{
    int sockid = socket(AF_INET, SOCK_STREAM, 0);
    int m = 0, n = 0, data_len, sockid_new;
    char buff[100];
    unsigned int len;
    struct sockaddr_in serv_addr, cli_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockid, (sa *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Could not bind socket");
        exit(0);
    }
    listen(sockid, 5);
    len = sizeof(cli_addr);
    sockid_new = accept(sockid, (sa *)&cli_addr, &len);
    printf("Client with IP %s and port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
    for(;;)
    {
        bzero(buff, sizeof(buff));
        read(sockid_new, buff, sizeof(buff));
        printf("Received Message from Client is: %s\n", buff);
        for (int i = 0; i < strlen(buff); i++)
            buff[i] = toupper(buff[i]);
        // write(sockid_new, buff, sizeof(buff));
        printf("Uppercase is: %s\n", buff);
        if (strncmp(buff, "QUIT", 4) == 0)
            break;
    }
    printf("Server connection closed\n");
    close(sockid);
    return 0;
}
