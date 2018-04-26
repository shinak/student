#include<iostream.h>
class NUM
{
public:
	void set();
	void show();
	int getnum(){return num;}
	friend int operator > (NUM &a,NUM &b);
	NUM *next;
private:
	int num;
};
void NUM::set()
{
	cin>>num;
}
void NUM::show()
{
	cout<<num<<' ';
}

int operator > (NUM &a,NUM &b)
{
	if(a.num>b.num)
		return 1;
	else 
		return 0;
}

NUM* intput()
{

	NUM *head,*p1,*p2;
	head=NULL;
	while(p1!=NULL)
	{
		p1=new NUM;
		cout<<"输入数据:";
		p1->set();
		if(p1->getnum()==0)
			break;
		else
		{
			if(head==NULL)
				head=p1;
			else
				p2->next=p1;
			p2=p1;
		}
		p2->next=NULL;
	}
	delete p1;
	return(head);
}
void output(NUM *p)
{
	cout<<"输出数据:";
	while(p!=NULL)
		{
			p->show();
			p=p->next;
		}
	cout<<endl;            //h2
}                          //h1 
NUM* sort(NUM *p)          //9   8 7 6 20   8 9 7 6 20
{
return p;
}
void insert()
{

}

void main()
{
	NUM *p;
	p=intput();    //链表输入
	p=sort(p);
	output(p);     //链表输出
}