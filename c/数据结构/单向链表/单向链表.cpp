/**************************************************************************************************
                       单向链表的相关操作 
			链表的创建、插入、修改、删除、输出。
 							@ k			  
 							2018/2/13     
 							vs2010        
****************************************************************************************************/


#include<iostream>
#include<Windows.h>
using namespace std;
struct num
{
	int n;
	num *next;
};
num* initList(int l)
{
	num *head;
	num *p = new num;
	p->next = NULL;
	head = p;
	for(int i = 0; i < l; i++)
	{
		num *q = new num;
		cout<<"请输入第"<<i+1<<"个数"<<endl;
		cin>>q->n;
		q->next = NULL;
		p->next = q;
		p = q;
	}
	return head; 
}
num* outList(num *head)
{
	num *p = head->next;
	cout<<"单向链表 ";
	if(head->next == NULL)
		cout<<"NULL";
	else
	{
		while(head->next != NULL)
		{
			cout<<p->n<<' ';
			if(p->next != NULL)
			{
				p = p->next;
			}
			else
				break;
		}
	}
	cout<<endl;
	return head;
}
num* selectList(num* head)
{
	int elem;
	int i = 0, j = 0;
	cout<<"请输入要查找的数 ";
	cin>>elem;
	num *p = head->next;
	while(head->next != NULL)
	{
		i++;
		if(p->n == elem)
		{ 
			j++;
			cout<<"该数第"<<j<<"次出现在第"<<i<<"位"<<endl;
		}
		if(p->next != NULL)
		{
			p = p->next;
		}
		else
			break;
	}
	if(j == 0)
	{
		cout<<"该数不在链表中"<<endl;
	}
	return head;
}
int insertData(num *head, int l)
{
	int loca;
	num *p1 = head;
	num *p2 = head->next;
	num *q = new num;
	cout<<"请输入要插入的数据 ";
	cin>>q->n;
	cout<<"请输入要插入的位置 ";
	cin>>loca;
	while(loca > l+1)
	{
		cout<<"插入位置不符合现有长度!请重新输入!"<<endl;
		cout<<"请输入要插入的位置 ";
		cin>>loca;
	}
	if(head->next != NULL)
	{
		for(int i = 1; i<loca; i++)
		{
			p1 = p2;
			p2 = p2->next;
		}
		q->next = p2;
		p1->next = q;
	}
	return ++l;
}
num* deleteList(num *head)
{
	int elem;
	num *p = head;
	num *p1 = p->next;
	cout<<"请输入你要删除的数 ";
	cin>>elem;
	while(p->next !=NULL)
	{
		if(p1->n == elem)
		{
			num *del = p1;
			p->next = p->next->next;
			p1 = p1->next;
			delete del;
		}
		else
		{
			p1 = p1->next;
			p = p->next;
		}
		/*
		if(p1->n == elem)
		{   
			p->next = p->next->next;
	
		}
		if(p->next == NULL)
			break;
		p = p->next;
		if(p->next == NULL)
			break;
		p1 = p->next;*/
	}
	return head;
}
int main()
{
	int l;   //链表长度
	num *head;   //头指针
	cout<<"请输入链表长度 ";   //没有考虑0 的情况
	cin>>l;
	head = initList(l);   //创建链表
	head = selectList(head);   //查找数据
	l = insertData(head,l);   //插入数据
	head = deleteList(head);   //删除数据
	head = outList(head);  //输出链表
	system("pause");
	return 0;
}
