#include<stdio.h>
int main()
{
	int i,sum;
	for(i=2,sum=0;i<=1000;i++,i++)	
		sum+=i;
	printf("sum=%d\n",sum);
	return 0;
}