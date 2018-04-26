#include <stdio.h>
int main()
{
	int i=2,sum=0;
	do
	{
		sum=sum+i;
		i=i+2;
	}while(i<=1000);
	printf("sum=%d\n",sum);
	return 0;
}