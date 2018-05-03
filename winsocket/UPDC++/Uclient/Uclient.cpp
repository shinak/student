// Uclient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#pragma comment(lib,"ws2_32.lib")

struct client
{
	int i;//�ͻ���˳��
	SOCKET soc;//�׽���
	struct sockaddr_in ca;//�ͷ��˵�ַ
};

void recvthread(void *p);

int main(int argc, char* argv[])
{
	WSADATA wsd;
	WSAStartup(MAKEWORD(1,1),&wsd);

	SOCKET soc=socket(AF_INET,SOCK_DGRAM,0);

	sockaddr_in sa;
	sa.sin_family=AF_INET;
	sa.sin_port=htons(8000);
	sa.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");

	printf("UDP�ͻ��˿���\n");

	printf("����������ʱ���ǳ�:");
	client c;
	c.soc = soc;
	c.ca = sa;
	int len = sizeof(c.ca);
	char recvmsg[100]={0};
	char sendmsg[100]={0};
	char sendname[100]="#";//�û�����ʾ��
	
	gets(sendmsg);
	strcat(sendname,sendmsg);
	sendto(soc,sendname,100,0,(sockaddr*)&sa,sizeof(sa));

	recvfrom(c.soc,recvmsg,100,0,(sockaddr*)&c.ca,&len);
	c.i = atoi(recvmsg);

	_beginthread(recvthread,0,&c);

	while(1)
	{
		char sendnum[100]={0};
		//�ͻ����û�����ת�����ַ���ʽ
		sendnum[0] = c.i / 10000 +48;
		sendnum[1] = c.i / 1000 +48;
		sendnum[2] = c.i / 100 +48;
		sendnum[3] = c.i / 10 +48;
		sendnum[4] = c.i % 10 +48;
		sendnum[5] = '\0';

		gets(sendmsg);
		strcat(sendnum,sendmsg);//���û����к���Ϣһ�����͸������
		sendto(soc,sendnum,100,0,(sockaddr*)&c.ca,sizeof(c.ca));
	}

	return 0;
}
//������Ϣ���̺߳���
void recvthread(void *p)
{
	client c = *((client *)p);
	char recvmsg[100]={0};
	int len=sizeof(c.ca);
	while(1)
	{
		int rval;
		rval=recvfrom(c.soc,recvmsg,100,0,(sockaddr*)&c.ca,&len);
		if(rval>0)
			printf("%s\n",recvmsg);
		else
			break;
	}
}