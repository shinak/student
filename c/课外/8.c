#include<stdio.h>
#include<string.h>
void turn(char s[])
{
	int i,x,y;
	x=strlen(s)-1;
	for(i=0;i<strlen(s)/2;i++)
	{
		y=s[i];
		s[i]=s[x];
		s[x]=y;
		x--;
	}	
}
int main()
{
	char s[100];
	gets(s);
	turn(s);
	puts(s);
    return 0;
}