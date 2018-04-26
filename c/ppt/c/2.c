#include<stdio.h>
#include<string.h>
void nixu(char s[100])//void nixu(char s[100],int len)
{
	int len,i,j;
	char c;
	//len=strlen(s);
	for(len=0,i=0;s[i]!='\0';i++)
		len++;
	for(i=0,j=len-1;i<=j;i++,j--)
	{
		c=s[i];
		s[i]=s[j];
		s[j]=c;
	}
}
int main()
{
	char str[100];
	gets(str);
	nixu(str);
	puts(str);
	return 0;
}