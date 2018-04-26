#include<iostream>
using namespace std;
struct Student
{
	int num;
	float score;
	struct Student *next;
};
Student* input()
{
	struct Student *head,*p1,*p2;
	cout<<"输入学号 成绩："<<endl;
	head=NULL;
	while(p1!=NULL)
	{
		p1=new Student;
		cin>>p1->num;
		if(p1->num==0)
			break;
		else
		{
			cin>>p1->score;
			if(head==NULL)
				head=p1;
			else
				p2->next=p1;
			p2=p1;
		}
		p2->next=NULL;
	}
	return(head);
}
void output(struct Student *p)
{
	cout<<"输出学号 成绩："<<endl;
	while(p!=NULL)
		{
			cout<<p->num<<"  "<<p->score<<endl;
			p=p->next;
		}
}
int main()
{
	struct Student *p;
	p=input();
	output(p);

	return 0;
}