#include <iostream>
using namespace std;
/***********************************************
����ͻ����û�����
***********************************************/
struct client
{
	int i;//�ͻ���˳��
	SOCKET soc;//�׽���
	struct sockaddr_in ca;//�ͷ��˵�ַ
	char name[100];//����
	char msg[100];//�����¼
};
typedef struct node
{
	struct client cli;
	node *next;
}Node,*PNode;
class SocClient
{
private:
	 PNode head;
public:
	SocClient();
	int insert(struct client c);//����һ���µ��׽���
	char* findClient(struct client c);//����
	client* find(int i);//��˳����ҵ�ַ
	void setMsg(char* m,int i);
};
SocClient::SocClient()
{
	head = new Node;
	head->next = NULL;
}
int SocClient::insert(struct client c)
{
	int n = 1;
	PNode h,p;
	h = head;
	p = new Node;
	while(h->next != NULL)
	{
		h = h->next;
		n++;
	}
	h->next = p;
	//����ͻ�������
	p->cli.i = n;
	p->cli.soc = c.soc;
	p->cli.ca = c.ca;
	strcpy(p->cli.name,c.name);
	p->next = NULL;
	return n;
}
char* SocClient::findClient(struct client c)
{
	PNode h;
	h = head;
	while(h != NULL)
	{   
		if(inet_ntoa(h->cli.ca.sin_addr) == inet_ntoa(c.ca.sin_addr) && h->cli.i == c.i)
			return h->cli.name;
		h = h->next;
	}
	return NULL;
}
client* SocClient::find(int i)
{
	PNode h;
	h = head;
	while(h != NULL)
	{
		if(h->cli.i == i)
			return &h->cli;
		h = h->next;
	}
	return NULL;
}
void SocClient::setMsg(char* m,int i)
{
	PNode h;
	h = head;
	while(h != NULL)
	{
		if(h->cli.i == i)
			break;
		h = h->next;
	}
	strcpy(h->cli.msg,m);
}