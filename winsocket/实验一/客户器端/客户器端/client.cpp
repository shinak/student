#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <process.h>
#pragma comment (lib,"ws2_32.lib")

void recvThread(void * p);

void main(){
	printf("�ͻ�����\n");

	//��ʼ����̬���ӿ�
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(1,1),&wsaData) != 0){
		printf("��ʼ����̬���ӿ�ʧ��!\n");
		return ;
	}

	//�����׽���
	SOCKET SocClient = socket(AF_INET,SOCK_STREAM,0);
	if (SocClient == INVALID_SOCKET){
		printf("�����׽���ʧ��!\n");
		return ;
	}

	//���շ�����IP��ַ
	char serverIP[32];
	printf("���������IP��ַ: ");
	scanf("%s",serverIP);

	//��������ӿں�λ��
	struct sockaddr_in SockAddr;
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_port = htons(6000);
	SockAddr.sin_addr.s_addr = inet_addr(serverIP);

	//���ӵ�������
	int rVal = connect(SocClient,(struct sockaddr *)&SockAddr,sizeof(SockAddr));
	if(rVal == SOCKET_ERROR){
		printf("���ӵ�������ʧ��!\n");
		return ;
	}
	printf("���ӵ��������ɹ�!\n");
	//��������
	_beginthread(recvThread,0,&SocClient);
	//��������
	while(1){
		char msg[140];
		scanf("%s",msg);
		rVal = send(SocClient,msg,140,0);
		if(rVal == SOCKET_ERROR){
			printf("����ʧ��!\n");
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
			printf("����ʧ��!\n");
			break;
		}
		printf("�����:%s\n",msg);
	}
}