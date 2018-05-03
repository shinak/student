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
		char msgupdate[100] = "系统:";//加工消息
		client *c;
		int i=1;
		gets(sendmsg);
		strcat(msgupdate,sendmsg);
		while((c = h.find(i)) != NULL)
		{
			sendto(soc,msgupdate,100,0,(sockaddr*)&c->ca,sizeof(c->ca));
			i++;
		}
		msgupdate[0]=NULL;
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

		if(recvmsg[0] == '#')//判断是否为用户名
		{
			for(int i=0;i<strlen(recvmsg);i++)
				recvmsg[i] = recvmsg[i+1];//去掉‘#’
			strcpy(c.name,recvmsg);

			printf("%s已经连接上服务器，可以开始聊天\n",c.name);

			itoa(h.insert(c),sendmsg,10);

			sendto(soc,sendmsg,100,0,(sockaddr*)&ca,sizeof(ca));//发送该客户端用户序列
		}
		else
		{
			//只能接收99999个客户端，可优化
			c.i  = recvmsg[4]-48 +(recvmsg[3] -48)*10+(recvmsg[2] -48)+(recvmsg[1] -48)*1000+(recvmsg[0] -48)*10000;
			//除去接收消息的用户序列字符
			for(int i=0;i<100;i++)
				recvmsg[i] = recvmsg[i+5];
			printf("%s说%s\n",h.findClient(c),recvmsg);
			
			
			//转发
			client *s;
			for(int n=1;(s = h.find(n)) != NULL;n++)
			{
				if(s->i != c.i)
				{
					strcpy(resend,h.findClient(c));
					strcat(resend,":");
					strcat(resend,recvmsg);
					sendto(soc,resend,100,0,(sockaddr*)&s->ca,sizeof(s->ca));
					
					resend[0] = NULL;
				}
			}	
		}
	}
}