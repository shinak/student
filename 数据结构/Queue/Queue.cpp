// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Queue.h"

void triangle(int n);
DataType locate(int x,int y);

int main(int argc, char* argv[])
{
	int n;
	cout<<"杨辉三角形行数:"<<endl;
	cin>>n;
	for(int i=1;i<=n;i++)
		triangle(i);
	return 0;
}

void triangle(int n)
{
	Queue q;
	int i;

	for(i=1;i<=n;i++)
	{
		q.EnQueue(locate(n,i));
	}
	
	for(i=1;i<=n;i++)
	{
		cout<<q.DeQueue()<<" ";
	}
	cout<<endl;
}
DataType locate(int x,int y)
{
	DataType a;
	if(y == 1 || y == x)
		a = 1;
	else
		a = locate(x-1,y-1)+locate(x-1,y);
	return a;
}