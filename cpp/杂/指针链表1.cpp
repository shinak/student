#include<iostream>
using namespace std;
struct student
{
	int num;
	float score;
	struct student *next;
};
int main()
{
	struct student a,b,c,*head,*p;
	a.num=10101;a.score=89;
	b.num=10103;b.score=90;
	c.num=10107;c.score=85;
	head=&a;
	a.next=&b;
	b.next=&c;
	c.next=NULL;
	p=head;
	while(p!=NULL)
	{
		cout<<p->num<<"  "<p->score<<endl;
		p=p->next;
	}
	
	return 0;
}