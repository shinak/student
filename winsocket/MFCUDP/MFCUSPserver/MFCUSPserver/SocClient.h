#pragma once
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
	SocClient(void);
	~SocClient(void);
	int insert(struct client c);//����һ���µ��׽���
	char* findClient(struct client c);//����
	client* find(int i);//��˳����ҵ�ַ
	void setMsg(char* m,int i);
};