#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <process.h>
#pragma comment (lib,"ws2_32.lib")

void sendThread(void *p);

void main(){
	printf("服务器端\n");

	//初始化动态链接库
	WSADATA wsaData;//网络库信息
	if(WSAStartup(MAKEWORD(1,1),&wsaData) != 0){
		printf("初始化动态链接库失败！\n");
		return ;
	}

	//创建套接字
	SOCKET SocServer = socket(AF_INET,SOCK_STREAM,0);
	if(SocServer == INVALID_SOCKET){
		printf("创建套接字失败!\n");
		return ;
	}

	//设置网络端口和地址
	struct sockaddr_in SockAddr;
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_port = htons(6000);
	SockAddr.sin_addr.s_addr= INADDR_ANY;

	//绑定套接字和网络地址结构体
	int rVal = bind(SocServer,(struct sockaddr *)&SockAddr,sizeof(SockAddr));
	if(rVal == SOCKET_ERROR){
		printf("绑定服务器失败!\n");
		return ;
	}

	//监听
	rVal = listen(SocServer,10);
	if(rVal == SOCKET_ERROR){
		printf("监听失败!\n");
		return ;
	}

	//等待客户端连接
	printf("服务器架设成功，等待客服端连接: \n");
	struct sockaddr_in SockAddRev;
	SOCKET SocClient = accept(SocServer,(struct sockaddr *)&SockAddRev,(int *)&(rVal=sizeof(SockAddRev)));
	printf("有客服端: %s 连接成功!\n",inet_ntoa(SockAddRev.sin_addr));
	//发送消息
	_beginthread(sendThread,0,&SocClient);
	//接收消息
	while(1){
		char msg[140];
		rVal = recv(SocClient,msg,140,0);
		if(rVal == SOCKET_ERROR){
			printf("接收失败!\n");
			break;
		}
		printf("客服端:%s\n",msg);
	}
}

void sendThread(void *p){
	SOCKET SocClient = *((SOCKET *)p);
	while(1){
		char msg[140];
		scanf("%s",msg);
		int rVal = send(SocClient,msg,140,0);
		if(rVal == SOCKET_ERROR){
			printf("发送失败!\n");
			break;
		}
	}
}