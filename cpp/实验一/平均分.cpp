#include<iostream>
using namespace std;
double average(double *p,int n)
{
	double sum=0;
	double *q;
	for(q=p;q<p+n;q++)
	{
		sum+=*q;
	}
	sum=sum/n;
	return sum;
}
int main()
{
	double *p;
	double array[10]={70,72,75,78,76,74,80,77,73,75};
	p=array;
	cout<<"ƽ���ɼ�: "<<average(p,10)<<endl;
	cout<<"ƽ���ɼ�: "<<average(array,10)<<endl;
	return 0;
}