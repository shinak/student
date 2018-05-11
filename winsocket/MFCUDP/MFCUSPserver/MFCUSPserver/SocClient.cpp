#include "StdAfx.h"
#include "SocClient.h"


SocClient::SocClient(void)
{
	head = new Node;
	head->next = NULL;
}


SocClient::~SocClient(void)
{
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
	//插入客户端数据
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