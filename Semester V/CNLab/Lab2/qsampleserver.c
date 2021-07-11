//Server program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
int main()
{
	int sd,nd,n,len,reult;
	struct sockaddr_in seraddress, cliaddr;
	char buf[256];
	sd=socket(AF_INET, SOCK_STREAM,0);
	seraddress.sin_family=AF_INET;
	seraddress.sin_addr.s_addr=INADDR_ANY;
	seraddress.sin_port=htons(10200);
	bind(sd,(struct sockaddr*)&seraddress,sizeof(seraddress));
	listen(sd,5);
	len=sizeof(cliaddr);
    printf("This is the Server by Dhruv Bhat 180905088\n");
	while(1)
	{
	nd=accept(sd,(struct sockaddr*)&cliaddr,&len);
	if (fork()==0){
			close(sd);
	n=read(nd,buf,sizeof(buf));
	printf("Message from client: '%s'\n",buf);
	getchar();}
	close(nd);
    }
}