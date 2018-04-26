#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;
struct student
{
	long int num;
	char name[8];
	double score[3];
};
struct arrayst
{
	struct student stu;
	double nums;
};
void input(struct arrayst a[],int n)
{
	int i;
	cout<<setiosflags(ios::left)<<setw(8)<<a[i].stu.num
		<<setiosflags(ios::left)<<setw(8)<<a[i].stu.name
		<<setiosflags(ios::left)<<setw(8)<<a[i].stu.score[0]
		<<setiosflags(ios::left)<<setw(8)<<a[i].stu.score[1]
		<<setiosflags(ios::left)<<setw(8)<<a[i].stu.score[2]
		<<setiosflags(ios::left)<<setw(8)<<a[i].nums<<endl;
	for(i=0;i<n;i++)
	{
		cin>>a[i].stu.num
			>>a[i].stu.name
			>>a[i].stu.score[0]
			>>a[i].stu.score[1]
			>>a[i].stu.score[2];
	}
	for(i=0;i<n;i++)
	{
		a[i].nums=(a[i].stu.score[0]
			+a[i].stu.score[1]+a[i].stu.score[2])/3;
	}
}
void output(struct arrayst a[],int n)
{
	int i;
	cout<<setiosflags(ios::left)<<setw(8)<<"NUM"
		<<setiosflags(ios::left)<<setw(8)<<"NAME"
		<<setiosflags(ios::left)<<setw(8)<<"SCORE1"
		<<setiosflags(ios::left)<<setw(8)<<"SCORE2"
		<<setiosflags(ios::left)<<setw(8)<<"SCORE3"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<setiosflags(ios::left)<<setw(8)<<a[i].stu.num
			<<setiosflags(ios::left)<<setw(8)<<a[i].stu.name
			<<setiosflags(ios::left)<<setw(8)<<a[i].stu.score[0]
			<<setiosflags(ios::left)<<setw(8)<<a[i].stu.score[1]
			<<setiosflags(ios::left)<<setw(8)<<a[i].stu.score[2]
			<<setiosflags(ios::left)<<setw(8)<<a[i].nums<<endl;
	}
}
void scoresort(struct arrayst a[],int n)
{
	int i,j;
	struct arrayst s[1];
	for(j=n;j>0;j--)
		for(i=0;i<n;i++)
		{
			if(a[i].nums<a[i+1].nums)
			{
				s[0]=a[i];
				a[i]=a[i+1];
				a[i+1]=s[0];
			}	
		}
}
int main()
{
	system("color f0");
	struct arrayst a[100];
	int n;
	while(1)
	{
		cout<<"please input a number between 5-100:";
		cin>>n;
		if(n>=5 && n<=100)
			break;
	}
	input(a,n);//建立学生成绩表
	cout<<endl<<"before sort:"<<endl;
	output(a,n);//输出学生成绩表
	scoresort(a,n);//按平均成绩从高到低排序学生成绩表
	cout<<endl<<"after sort:"<<endl;
	output(a,n);
	Sleep(60000);
	return 0;
} 
