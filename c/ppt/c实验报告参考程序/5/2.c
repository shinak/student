#include<stdio.h>
int find(char s[],char a)
{
	int i,count=0;
	for(i=0;s[i]!='\0';i++)
		if(s[i]==a)
			count++;
	return count;
}
int main()
{
	char c[100];
	int n=0;
	gets(c);
	n=find(c,'a');
	printf("字符串%s中字符%c出现的次数为%d\n",c,'a',n);
	return 0;
}