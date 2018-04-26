#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <winsock.h>
#pragma comment (lib,"ws2_32.lib")

void sendThread(void *p);
void main()
{
	printf("服务端\n");
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(1,1),&wsaData) != 0)
	{
		printf("初始化动态链接库失败\n");
		return ;
	}
	
	SOCKET serSocket = socket(AF_INET,SOCK_STREAM,0); 
	if(serSocket == INVALID_SOCKET)
	{
		printf("创建socket失败\n");
		return ;
	}
	
	struct sockaddr_in serSockAddr;
	serSockAddr.sin_family = AF_INET;
	serSockAddr.sin_port = htons(6000);
	serSockAddr.sin_addr.s_addr = INADDR_ANY;
	if(bind(serSocket,(struct sockaddr *)&serSockAddr,sizeof(serSockAddr)) == SOCKET_ERROR)
	{
		printf("绑定socket失败\n");
		return ;
	}
	
	if(listen(serSocket,10) == SOCKET_ERROR)
	{
		printf("监听失败\n");
		return ;
	}
	
	int rVal;
	printf("等待客户端连接...\n");
	struct sockaddr_in cilSockAddr;
	SOCKET cilSocket = accept(serSocket,(struct sockaddr *)&cilSockAddr,(int *)&(rVal = sizeof(cilSockAddr)));
	printf("有客服端: %s 连接成功!\n",inet_ntoa(cilSockAddr.sin_addr));
	
	_beginthread(sendThread,0,&cilSocket);
	
	while(1)
	{
		char msg[140];
		rVal = recv(cilSocket,msg,140,0);
		if(rVal == SOCKET_ERROR)
		{
			printf("接收失败!\n");
			break;
		}
		printf("客服端:%s\n",msg);
	}
	closesocket(serSocket);
}

void sendThread(void *p)
{
	SOCKET cilSocket = *((SOCKET *)p);
	while(1)
	{
		char msg[140];
		scanf("%s",msg);
		int rVal = send(cilSocket,msg,140,0);
		if(rVal == SOCKET_ERROR)
		{
			printf("发送失败!\n");
			break;
		}
	}
}
