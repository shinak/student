#include<iostream>
using namespace std;
void main()
{
	char a[200], b[200];
	char *ps, *pt;
	ps=a;
	pt=b;
	cout<<"ÇëÊäÈë×Ö·û´®: "<<endl;
	gets(a);
	while(*ps!='\0')
	{
		*pt=*ps;
		pt++;
		ps++;

	}
	*pt='\0';
	pt=b;
	while(*pt!='\0')
	{
		cout<<*pt;
		pt++;
	}
	cout<<endl;

}