#include<iostream>
using namespace std;
struct student
{
	int num;
	float score;
	struct stduent *next;
};
int main()
{
	struct student a,b,c,*head,*p;
	a.num=111;a.score=89.5;
	b.num=102;b.score=80.5;
	c.num=1013;c.score=70.5;
	head=&a;
	a.next=&b;
	b.next=&c;
	c.next=NULL;
	p=head;
	while(p!=NULL)
	{
		cout<<p->num<<p->score;
		p->next;
	}
	return 0;
}