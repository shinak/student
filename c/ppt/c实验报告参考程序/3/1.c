#include<stdio.h>
int main()
{
	int i,sum;
	sum=0;
	//while
/*	i=0;
	while(i<=1000)
	{
		sum=sum+i;
		i=i+2;
	}*/
	//do-while
/*	i=0;
	do
	{
		sum=sum+i;
		i=i+2;
	}while(i<=1000);*/
	//for
	for(i=0;i<=1000;i=i+2)
		sum=sum+i;
	printf("%d\n",sum);
	return 0;
}