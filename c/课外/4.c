#include<stdio.h>
int main()
{
	int i,n=0;
	for(i=100;i>=100 && i<=200;i++)
	{
		if(i%3==0)
		{
			printf("%d ",i);
			n++;
		}
		else
			continue;
		if(n%10==0)
			printf("\n");
		
	}
	printf("\n");
	printf("%d\n",n);
	return 0;
}