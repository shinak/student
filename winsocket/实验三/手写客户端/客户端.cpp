#include <stdio.h>
#include <process.h>
#include <windows.h>
#include <winsock.h>
#pragma comment (lib,"ws2_32.lib")

void sendThread(void *p);
void main()
{
	printf("�ͻ���\n");
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(1,1),&wsaData) != 0)
	{
		printf("��ʼ����̬���ӿ�ʧ��\n");
		return ;
	}
	
	SOCKET cilSocket = socket(AF_INET,SOCK_STREAM,0);
	if(cilSocket == INVALID_SOCKET)
	{
		printf("�����׽���ʧ��\n");
		return ;
	}
	
	char serverIP[32];
	printf("���������IP:");
	scanf("%s",serverIP);
	
	struct sockaddr_in serSockAddr;
	serSockAddr.sin_family = AF_INET;
	serSockAddr.sin_port = htons(6000);
	serSockAddr.sin_addr.s_addr = inet_addr(serverIP);
	int rVal;
	rVal = connect(cilSocket,(struct sockaddr *)&serSockAddr,sizeof(serSockAddr));
	if( rVal == SOCKET_ERROR)
	{
		printf("���ӷ�����ʧ��\n");
		return ;
	}
	printf("���ӵ��������ɹ�!\n");
	
	_beginthread(sendThread,0,&cilSocket);
	
	while(1)
	{
		char msg[140];
		rVal = recv(cilSocket,msg,140,0);
		if(rVal == SOCKET_ERROR)
		{
			printf("����ʧ��!\n");
			break;
		}
		printf("�ͷ���:%s\n",msg);
	}
	closesocket(cilSocket);
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
			printf("����ʧ��!\n");
			break;
		}
	}
}
