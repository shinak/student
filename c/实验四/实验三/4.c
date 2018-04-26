#include <stdio.h>
int main()
{
	int i=2,sum=0;
	while(i<=1000)
	{
		sum=sum+i;
		i=i+2;
	}
	printf("sum=%d\n",sum);
	return 0;
}
