#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <process.h>
#pragma comment (lib,"ws2_32.lib")

void sendThread(void *p);

void main(){
	printf("��������\n");

	//��ʼ����̬���ӿ�
	WSADATA wsaData;//�������Ϣ
	if(WSAStartup(MAKEWORD(1,1),&wsaData) != 0){
		printf("��ʼ����̬���ӿ�ʧ�ܣ�\n");
		return ;
	}

	//�����׽���
	SOCKET SocServer = socket(AF_INET,SOCK_STREAM,0);
	if(SocServer == INVALID_SOCKET){
		printf("�����׽���ʧ��!\n");
		return ;
	}

	//��������˿ں͵�ַ
	struct sockaddr_in SockAddr;
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_port = htons(6000);
	SockAddr.sin_addr.s_addr= INADDR_ANY;

	//���׽��ֺ������ַ�ṹ��
	int rVal = bind(SocServer,(struct sockaddr *)&SockAddr,sizeof(SockAddr));
	if(rVal == SOCKET_ERROR){
		printf("�󶨷�����ʧ��!\n");
		return ;
	}

	//����
	rVal = listen(SocServer,10);
	if(rVal == SOCKET_ERROR){
		printf("����ʧ��!\n");
		return ;
	}

	//�ȴ��ͻ�������
	printf("����������ɹ����ȴ��ͷ�������: \n");
	struct sockaddr_in SockAddRev;
	SOCKET SocClient = accept(SocServer,(struct sockaddr *)&SockAddRev,(int *)&(rVal=sizeof(SockAddRev)));
	printf("�пͷ���: %s ���ӳɹ�!\n",inet_ntoa(SockAddRev.sin_addr));
	//������Ϣ
	_beginthread(sendThread,0,&SocClient);
	//������Ϣ
	while(1){
		char msg[140];
		rVal = recv(SocClient,msg,140,0);
		if(rVal == SOCKET_ERROR){
			printf("����ʧ��!\n");
			break;
		}
		printf("�ͷ���:%s\n",msg);
	}
}

void sendThread(void *p){
	SOCKET SocClient = *((SOCKET *)p);
	while(1){
		char msg[140];
		scanf("%s",msg);
		int rVal = send(SocClient,msg,140,0);
		if(rVal == SOCKET_ERROR){
			printf("����ʧ��!\n");
			break;
		}
	}
}