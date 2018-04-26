#include<iostream>
using namespace std;
float area(int n)
{
	return n*n*3.14;
}
int area(int n,int h)
{
	return n*h;
}
int area(int n,int h,int l)
{
	return (n+h)*l/2;
}
int main()
{
	cout<<"the area of circle: "<<area(3)<<endl;
	cout<<"the area of rectangle: "<<area(5,3)<<endl;
	cout<<"the area of trapezoid: "<<area(3,5,7)<<endl;
	return 0;
	
}