#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	void cat(char *s1,char *s2);
	char s1[100],s2[100];
	gets(s1);
	gets(s2);
	cat(s1,s2);
	puts(s1);
	return 0;
}
void cat(char *s1,char *s2)
{
	for(;*s1!='\0';s1++)
		;
	for(;*s2!='\0';s2++)
	{
		*s1++=*s2;
	}
	*s1='\0';
}