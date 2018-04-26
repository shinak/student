#include <iostream>
using namespace std;
#include <string.h>
#include <WinSock2.h>
#include <process.h>
#pragma comment (lib,"ws2_32.lib")

//�ͻ�����Ϣ��
class SocketCli
{
private:
	string name;
	SOCKET soc;
	struct sockaddr_in sockaddr;
public:
	SocketCli();
	void SetName(string n);
	void SetSocket(SOCKET s);
	void SetSockaddr(struct sockaddr_in a);
	string GetName();
	SOCKET GetSocket();
	sockaddr_in GetSockaddr();
	~SocketCli(){};
};

SocketCli SocC;
void RecvThread(void *p);
int main()
{
	//��ʼ���׽���
	WSADATA WSAData;
	if(WSAStartup(MAKEWORD(1,1),&WSAData) != 0)
	{
		cout<<"��ʼ���׽���ʧ��"<<endl;
		return -1;
	}
	//�����׽���ʧ��
	SOCKET SocCli = socket(AF_INET,SOCK_DGRAM,0);
	if(SocCli == INVALID_SOCKET)
	{
		cout<<"�����׽���ʧ��"<<endl;
		return -1;
	}
	//����Ҫ���ӵķ�������ַ�Ͷ˿�
	char serverIP[32];
	cout<<"�����IP��ַ:";
	cin>>serverIP;
	struct sockaddr_in SerAddr;
	SerAddr.sin_family = AF_INET;
	SerAddr.sin_port = htons(9000);
	SerAddr.sin_addr.s_addr = inet_addr(serverIP);

	//��������
	char *SendMsg = new char[140];
	cout<<"�������:(��#��ͷ)";
	cin>>SendMsg;
	if(sendto(SocCli,SendMsg,140,0,(struct sockaddr *)&SerAddr,sizeof(SerAddr)) == SOCKET_ERROR)
	{
		cout<<"��������ʧ��"<<endl;
		return -1;
	}

	SocC.SetName(SendMsg);
	SocC.SetSocket(SocCli);
	SocC.SetSockaddr(SerAddr);
    _beginthread(RecvThread,0,NULL);
	//������Ϣ����
	while(true)
	{
		cin>>SendMsg;
		if(sendto(SocCli,SendMsg,140,0,(struct sockaddr *)&SerAddr,sizeof(SerAddr)) == SOCKET_ERROR)
		{
			cout<<"����ʧ��"<<endl;
			return -1;
		}
		
	}
	delete SendMsg;
	SocC.~SocketCli();
	closesocket(SocCli);
	WSACleanup();
	return 0;
}

//���ն��̺߳���
void RecvThread(void *p)
{
	while(true)
	{
		char *RecvMsg = new char[140];
		int len = sizeof(SocC.GetSockaddr());
		if(recvfrom(SocC.GetSocket(),RecvMsg,140,0,(struct sockaddr *)&SocC.GetSockaddr(),&len) != SOCKET_ERROR)
			cout<<RecvMsg<<endl;
		else
		{
			cout<<"������Ϣʧ��"<<endl;
			return ;
		}
		delete RecvMsg;
	}
}



SocketCli::SocketCli()
{
	name = "default";
	soc = socket(AF_INET,SOCK_DGRAM,0);
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(9000);
	sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
}
void SocketCli::SetName(string n)
{
	name = n;
}
void SocketCli::SetSocket(SOCKET s)
{
	soc = s;
}
void SocketCli::SetSockaddr(struct sockaddr_in a)
{
	sockaddr = a;
}
string SocketCli::GetName()
{
	return name;
}
SOCKET SocketCli::GetSocket()
{
	return soc;
}
sockaddr_in SocketCli::GetSockaddr()
{
	return sockaddr;
}