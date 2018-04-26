#include<stdio.h>
int main()
{
	int a,b,i,j,k;
	scanf("%d",&a);
	i=a/100;
	j=a/10%10;
	k=a%10;
	b=k*100+j*10+i;
	printf("%d\n",b);
	return 0;
}