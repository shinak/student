/**************************************************************************************************
                       �����������ز��� 
			����Ĵ��������롢�޸ġ�ɾ���������
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
		cout<<"�������"<<i+1<<"����"<<endl;
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
	cout<<"�������� ";
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
	cout<<"������Ҫ���ҵ��� ";
	cin>>elem;
	num *p = head->next;
	while(head->next != NULL)
	{
		i++;
		if(p->n == elem)
		{ 
			j++;
			cout<<"������"<<j<<"�γ����ڵ�"<<i<<"λ"<<endl;
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
		cout<<"��������������"<<endl;
	}
	return head;
}
int insertData(num *head, int l)
{
	int loca;
	num *p1 = head;
	num *p2 = head->next;
	num *q = new num;
	cout<<"������Ҫ��������� ";
	cin>>q->n;
	cout<<"������Ҫ�����λ�� ";
	cin>>loca;
	while(loca > l+1)
	{
		cout<<"����λ�ò��������г���!����������!"<<endl;
		cout<<"������Ҫ�����λ�� ";
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
	cout<<"��������Ҫɾ������ ";
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
	int l;   //������
	num *head;   //ͷָ��
	cout<<"������������ ";   //û�п���0 �����
	cin>>l;
	head = initList(l);   //��������
	head = selectList(head);   //��������
	l = insertData(head,l);   //��������
	head = deleteList(head);   //ɾ������
	head = outList(head);  //�������
	system("pause");
	return 0;
}
