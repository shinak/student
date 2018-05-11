#pragma once
struct client
{
	int i;//客户端顺序
	SOCKET soc;//套接字
	struct sockaddr_in ca;//客服端地址
	char name[100];//姓名
	char msg[100];//聊天记录
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
	int insert(struct client c);//插入一个新的套接字
	char* findClient(struct client c);//查找
	client* find(int i);//按顺序查找地址
	void setMsg(char* m,int i);
};