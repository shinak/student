#include<iostream>
using namespace std;
void printArray(int *x,int n)
{
	int *q;
	for(q=x;q<x+n;q++)
		cout<<*q<<" ";
	cout<<endl;
}
void inv(int *x,int n)
{
	int *i;
	int t;
	for(i=x+n;i>x;i--,x++)
	{
		t=*(i-1);
		*(i-1)=*x;
		*x=t;

	}
}//?????????????????????
int main()
{
	int i,array[10]={3,7,9,4,2,0,8,1,6,5};
	int *p=array;
	cout<<"逆序输出前: "<<endl;
	printArray(p,10);
	inv(p,10);
	cout<<"逆序输出后: "<<endl;
	printArray(p,10);
	return 0;
}