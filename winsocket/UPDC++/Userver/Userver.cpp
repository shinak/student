// Userver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SocClient.h"
#pragma comment(lib,"ws2_32.lib")

SOCKET soc;
void recvthread(void *p);

int main(int argc, char* argv[])
{
	WSADATA wsd;
	WSAStartup(MAKEWORD(1,1),&wsd);

	soc = socket(AF_INET,SOCK_DGRAM,0);

	sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_port=htons(8000);
	sa.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	bind(soc,(sockaddr*)&sa,sizeof(sa));

	printf("udp服务端已经启动\n");

	SocClient h;

	//接收客服端发送的消息多线程函数
	_beginthread(recvthread,0,&h);
	
	char sendmsg[100] = {0};
	while(1)
	{
		client *c;
		int i=1;
		gets(sendmsg);
		while((c = h.find(i)) != NULL)
		{
			sendto(soc,sendmsg,100,0,(sockaddr*)&c->ca,sizeof(c->ca));
			i++;
		}	
	}


	closesocket(soc);							
	WSACleanup();	
	return 0;
}
void recvthread(void *p)
{
	SocClient h = *((SocClient *)p);

	client c;
	
	sockaddr_in ca;
	int len=sizeof(ca);

	char recvmsg[100]={0};
	char resend[100]={0};
	char sendmsg[100]={0};
    while(recvfrom(soc,recvmsg,100,0,(sockaddr *)&ca,&len) != SOCKET_ERROR)
	{
		c.soc = soc;
		c.ca = ca;
		c.i = 0;

		if(recvmsg[0] == '#')
		{
			printf("%s已经连接上服务器，可以开始聊天\n",recvmsg);
			
			strcpy(c.name,recvmsg);//可优化
			
			itoa(h.insert(c),sendmsg,10);

			sendto(soc,sendmsg,strlen(sendmsg)+1,0,(sockaddr*)&ca,sizeof(ca));//发送该客户端为第几个用户
		}
		else
		{
			char num;
			num = recvmsg[0];
			c.i = atoi(&num);//只能接收9个客户端，可优化
			for(int i=0;i<100;i++)
				recvmsg[i] = recvmsg[i+1];
			printf("%s说%s\n",h.findClient(c),recvmsg);
			
			
			//转发
			client *s;
			int n=1;
			while((s = h.find(n)) != NULL)
			{
				if(s->i != c.i)
				{
					strcpy(resend,h.findClient(c));
					strcat(resend,":");
					strcat(resend,recvmsg);
					sendto(soc,resend,100,0,(sockaddr*)&s->ca,sizeof(s->ca));
					
					resend[0] = NULL;
				}
				n++;
			}	
		}
	}
}