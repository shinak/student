#include<stdio.h>
int main()
{
	int x,y,i,n;
	for(i=1;i<=9;i++)
	{
		for(n=1;n<=i;n++)
		{
			x=i;
			y=n;
			printf("%2d*%d=%2d",x,y,x*y);
		}
		printf("\n");
	}
	return 0;
}