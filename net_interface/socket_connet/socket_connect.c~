/*
 * tcp_socket.c
 *
 *  Created on: Oct 18, 2017
 *      Author: linux-downey
 */


#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>



#define DT_SERV_PORT  6786
#define DT_SERV_IP    "120.24.55.58"

int socket_connect(void)
{
	int sockfd;
	struct sockaddr_in servaddr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	memset(&servaddr,0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(DT_SERV_PORT);
	servaddr.sin_addr.s_addr=inet_addr(DT_SERV_IP);

	if(0!=connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)))
	{
		printf("connect failed!!\r\n");
	}
	else
	{
		printf("connect successed!!\r\n");
	}
	close(sockfd);
}

int main(void)
{
	socket_connect();
}

