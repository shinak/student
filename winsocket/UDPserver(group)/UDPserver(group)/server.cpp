#include <iostream>
using namespace std;
#include <winsock2.h>
#include <process.h>
#pragma comment (lib,"ws2_32.lib")
//客户端信息类
class SocketSer
{
private:
	string name;
	SOCKET soc;
	struct sockaddr_in sockaddr;
public:
	SocketSer *next;
	SocketSer();
	void SetName(string n);
	void SetSocket(SOCKET s);
	void SetSockaddr(struct sockaddr_in a);
	string GetName();
	SOCKET GetSocket();
	sockaddr_in GetSockaddr();
	
	~SocketSer(){};
};

void SendThread(void *p);
void RecvName(void *p);
SocketSer *SocS;
int main()
{
	//初始化套接字
	WSADATA WSAData;
	if(WSAStartup(MAKEWORD(1,1),&WSAData) != 0)
	{
		cout<<"初始化套接字失败"<<endl;
		return -1;
	}
	//创建套接字失败
	SOCKET SocSer = socket(AF_INET,SOCK_DGRAM,0);
	if(SocSer == INVALID_SOCKET)
	{
		cout<<"创建套接字失败"<<endl;
		return -1;
	}
	//设置服务器地址和端口
	struct sockaddr_in SerAddr;
	SerAddr.sin_family = AF_INET;
	SerAddr.sin_port = htons(9000);
	SerAddr.sin_addr.s_addr = INADDR_ANY;
	if(bind(SocSer,(struct sockaddr *)&SerAddr,sizeof(SerAddr)) == SOCKET_ERROR)
	{
		cout<<"绑定失败"<<endl;
		return -1;
	}
	
	//接收客户端套接字信息
	SocS->SetName("defualt");
	SocS->SetSocket(SocSer);
	SocS->SetSockaddr(SerAddr);
	_beginthread(RecvName,0,NULL);
	//储存客户端套接字信息
	
	//向客户端发送消息

	//接收消息
	struct sockaddr_in CliAddr;
	int len = sizeof(CliAddr);
	char *RecvMsg = new char[140];
	while(true)
	{
		if(recvfrom(SocSer,RecvMsg,140,0,(struct sockaddr *)&CliAddr,&len) != SOCKET_ERROR)
		{
			if(RecvMsg[0] != '#')
				cout<<RecvMsg<<endl;
		}
		else
		{
			cout<<"接收消息失败"<<endl;
			return -1;
		}
	}
	delete RecvMsg;
	SocS->~SocketSer();
	closesocket(SocSer);
	WSACleanup();
	return 0;
}

void RecvName(void *p)
{
	SocketSer *p1,*p2;
	p1 = SocS;
	struct sockaddr_in CliAddr;
	int len = sizeof(CliAddr);
	char *RecvMsg = new char[140];
	while(true)
	{
		if(recvfrom(SocS->GetSocket(),RecvMsg,140,0,(struct sockaddr *)&CliAddr,&len) != SOCKET_ERROR)
		{
			if(RecvMsg[0] == '#')
			{
				p1->SetName(RecvMsg);
				p1->SetSockaddr(CliAddr);
				p2 = p1;
				p1 = NULL;
			}
		}
		else
		{
			cout<<"接收消息失败"<<endl;
			return ;
		}
	}
	delete RecvMsg;
}

SocketSer::SocketSer()
{
	name = "default";
	soc = socket(AF_INET,SOCK_DGRAM,0);
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(9000);
	sockaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	next = NULL;
}
void SocketSer::SetName(string n)
{
	name = n;
}
void SocketSer::SetSocket(SOCKET s)
{
	soc = s;
}
void SocketSer::SetSockaddr(struct sockaddr_in a)
{
	sockaddr = a;
}
string SocketSer::GetName()
{
	return name;
}
SOCKET SocketSer::GetSocket()
{
	return soc;
}
sockaddr_in SocketSer::GetSockaddr()
{
	return sockaddr;
}