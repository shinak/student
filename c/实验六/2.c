#include<stdio.h>
#include<string.h>
void pattern1(int n)   
{
	int j;
	char c;
	for(;n>0;n--)
	{
		c='a';
		for(j=0;j<n;j++)
		{
			printf("%-2c",c);
			c++;
		}
		printf("\n");
	}
}
void pattern2(int n)
{
	int j,m,f;
	char c;
	for(f=0;f<n;f++)
	{
		for(m=n-1;m>f;m--)
			printf("  ");
		c='a'+f;
		for(j=0;j<=f;j++)
		{	
			printf("%-2c",c);
			c--;
		}
		printf("\n");
	}
}
int main()
{
	int n,Pattern;
	printf("Pattern=");
	scanf("%d",&Pattern);
	if(Pattern==1)
	{
		printf("Pattern I\n");
		n=11;
		pattern2(n);
	}
	if(Pattern==2)
	{
		printf("Pattern II\n");
		n=9;
		pattern1(n);
	}
	if(Pattern==3)
	{
		printf("Pattern III\n");
		n=7;
		pattern2(n);
	}
	if(Pattern==4)
	{
		printf("Pattern IV\n");
		n=5;
		pattern1(n);
	}
	else
		printf("error\n");
	return 0;
}
