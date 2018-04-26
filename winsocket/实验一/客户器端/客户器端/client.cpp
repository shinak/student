#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <process.h>
#pragma comment (lib,"ws2_32.lib")

void recvThread(void * p);

void main(){
	printf("客户器端\n");

	//初始化动态链接库
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(1,1),&wsaData) != 0){
		printf("初始化动态链接库失败!\n");
		return ;
	}

	//创建套接字
	SOCKET SocClient = socket(AF_INET,SOCK_STREAM,0);
	if (SocClient == INVALID_SOCKET){
		printf("创建套接字失败!\n");
		return ;
	}

	//接收服务器IP地址
	char serverIP[32];
	printf("输入服务器IP地址: ");
	scanf("%s",serverIP);

	//设置网络接口和位置
	struct sockaddr_in SockAddr;
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_port = htons(6000);
	SockAddr.sin_addr.s_addr = inet_addr(serverIP);

	//连接到服务器
	int rVal = connect(SocClient,(struct sockaddr *)&SockAddr,sizeof(SockAddr));
	if(rVal == SOCKET_ERROR){
		printf("连接到服务器失败!\n");
		return ;
	}
	printf("连接到服务器成功!\n");
	//接收数据
	_beginthread(recvThread,0,&SocClient);
	//发送数据
	while(1){
		char msg[140];
		scanf("%s",msg);
		rVal = send(SocClient,msg,140,0);
		if(rVal == SOCKET_ERROR){
			printf("发送失败!\n");
			break;
		}
	}
	
}

void recvThread(void *p){
	SOCKET SocClient = *((SOCKET *)p);
	while(1){
		char msg[140];
		int rVal = recv(SocClient,msg,140,0);
		if(rVal == SOCKET_ERROR){
			printf("接收失败!\n");
			break;
		}
		printf("服务端:%s\n",msg);
	}
}