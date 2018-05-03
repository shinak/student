#include <iostream.h>
#include <stdio.h>
//-------线性表的链式存储结构-------// 
#define DataType int

typedef struct node 
{ 
	DataType data; 
	struct node *next; 
}Node,*Pnode; 
class LinkList 
{ 
	Node *head; 
public: 
	LinkList( ) { head=new Node; head->next=NULL;} 
	void Clear();       //清空 
	bool IsEmpty( );
	Pnode GetElem(int i)           //返回第i个元素的值 
	{
		Pnode p;int k; 
		if(head->next==NULL) 
		{cout<<"表为空"<<endl;return NULL;
		}//空链表，返回空值 
		else
		{ 
			p=head; k=0; 
			while( p && k<i) 
			{
				p=p->next;k++;
			} 
			return p;
		}
	}
	int Locate(DataType e)
	{ Pnode p; 
	int i=1;
	p=head->next;
	while(p&&p->data!=e)
	{
		p=p->next;
		i++;
	}
	if(p==NULL)
		return 0;
	else
		return i;
	}
	int Length()
	{
		Pnode p;
		int i=0;
		p=head->next;
		while(p)
		{
			i++;
			p=p->next;
		}
		return i;
	}        
	DataType Prior ( DataType e);   //返回e 的前驱 
	DataType Next (DataType e);    //返回e 的后继
	bool Insert (DataType e, int i )
	{ 
		Node *p = head; 
		int k = 0; 
		while ( p && k< i -1 ) 
		{ 
			p = p->next; k++; 
		} 
		if(p)
		{
			Node *newnode= new Node; 
			newnode->data=e; 
			newnode->next=p->next; 
			p->next=newnode; 
			return true;
		}
		return false;
	} 
	bool Delete ( int i )
	{ 
		Pnode p,q;
		int k;
		p = head; k=0; 
		while ( p && k< i-1 ) 
		{ 
			p = p->next; k++; 
		} 
		if ( p == NULL ) 
		{ 
			cout << "删除位置非法"<<endl; 
			return false;
		} 
		q = p->next; 
		p->next = q->next; 
		delete q; 
		return true; 
	}//Delete
	
	void Print()              //输出线性表中的元素值
	{
		Pnode p;
		cout<<"线性表的元素有"<<Length()<<"个：";
		p=head->next;
		while(p)
		{
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
	void Create(int n)
	{
		int i;
		Pnode p;
		cout<<"Please input "<< n <<" Elements! "<<endl;
		for(i=1;i<=n;i++)
		{
			p=new Node; 
			cin>>p->data; 
			p->next=head->next;
			head->next=p; 
		}
		cout<<"Finish Input"<<endl;
	}
	void Reverse()
	{
		Pnode p,q,t;
		p=head;
		q=head->next;
		head->next=NULL;
		while(q!=NULL)
		{
			t=q;
			q=q->next;
			t->next=p->next;
			p->next=t;
		}
		
	}
	int Same(DataType x)
	{
		Pnode p;
		int n=0;
		p=head->next;
		while(p)
		{
			if(p->data==x)
				n++;
			p=p->next;
		}
		return n;
	}
	void Seqence()
	{
		Pnode q,p,t,f,l;
		q = head;
		l = head;
		p = head->next;
		f = p->next;
		while(p)
		{
			q = p->next;
			t = q;
			while(q)
			{
				if(p->data > q->data)
				{
					l->next = q;
					t->next = q->next;
					q->next = p->next;
					p->next = t->next;
					q->next = t;
					p->next = t->next;
					t->next = p;
				}
				else
				{
					t = q;
					q = q->next;
				}
			}
			l = p;
			p = p->next;
			f = p->next;
		}
	}
};