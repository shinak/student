#include<iostream>
#include<windows.h>
#include<ctime>
using namespace std;
int main()
{
	int i=0,j=0,h;	
	while(1)
	{
		srand(time(NULL));
		h=rand()%2;
		cout<<h<<' ';
		Sleep(1000);
	}
	return 0;
}
