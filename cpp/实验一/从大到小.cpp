#include<iostream>
using namespace std;
void printArray(int *x,int n)
{
	int *q;
	for(q=x;q<x+n;q++)
		cout<<*q<<" ";
	cout<<endl;
}
void sort(int *x,int n)
{
	int *i,*k,*j;
	int t;
	for(i=x;i<x+n-1;i++)
	{
		k=i;
		for(j=i+1;j<x+n;j++)
		{
			if(*i<*j)
			{
				k=j;
				t=*i;
				*i=*k;
				*k=t;
			}
		}
	}
}//ѡ������
int main()
{
	int i,array[10]={3,2,5,8,0,4,9,7,1,6};
	int *p=array;
	cout<<"�������ǰ: "<<endl;
	printArray(p,10);
	sort(p,10);
	cout<<"���������: "<<endl;
	printArray(p,10);
	return 0;
}
