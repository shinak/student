#include<stdio.h>
int main()
{
	int i,j,n;
	for(i=0;i<=10;i++)
	{
		for(n=0;n<=i;n++)
		{
			printf(" ");
		}
		for(j=0;j<=10-i;j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}