#include<iostream>
using namespace std;
int main()
{
	double a[10]={1,2,4,8,5,6,8,7,6,10},b[2][3]={1,2,3,4,5,6};
	double *p1,**p2,(*p3)[3];
	p1=a;p3=b;
	cout<<&a[1]<<endl;
	cout<<p1+1<<endl;
	cout<<a+1<<endl;
	return 0;
}