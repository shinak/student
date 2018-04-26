#include<iostream>
#include<string>
using namespace std;
typedef char(*AP)[5];
AP foo(char *p)
{
	for(int i=0;i<3;i++)
	{
		p[strlen(p)]='A';
	}
	return (AP)p+1;
}
int main()
{
	char s[]="FROG\0SEAL\0LION\0LAMB";
	puts(foo(s)[1]+2);
	return 0;
}