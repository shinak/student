#include<stdio.h>
#include<string.h>
int find(char s[],char a)
{
	int i,sum=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]==a)
			sum+=1;
		else
			continue;
	}
	return sum;
}
int main()
{
	char s[10],a;
	gets(s);
	a=getchar();
	printf("%d\n",find(s,a));
	return 0;
}