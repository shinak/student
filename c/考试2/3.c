#include<stdio.h>
int main()
{
	int i,j,f,k;
	k=9;
	for(i=0;i<5;i++)
	{
		for(j=1;j<=i;j++)
			printf(" ");
		for(f=k;f>i;f--)
			printf("+");
		k=k-1;
		printf("\n");
	}
	k=-2;
	for(i=0;i<4;i++)
	{
		for(j=3;j>i;j--)
			printf(" ");
		for(f=k;f<=i;f++)
			printf("+");
		k=k-1;
		printf("\n");
	}
	return 0;
}
		