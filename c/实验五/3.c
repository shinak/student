#include<stdio.h>
int factorial(int n)
{
	int z;
	if(n==1||n==0)
		z=1;
	else
		z=n*factorial(n-1);
	return z;
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n<0)
		printf("error\n");
	else
		printf("%d!=%d\n",n,factorial(n));
	return 0;
}
