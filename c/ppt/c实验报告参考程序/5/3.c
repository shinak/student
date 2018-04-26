#include<stdio.h>
int fact(int n)
{
	if(n==0||n==1)
		return 1;
	else
		return n*fact(n-1);
}
int main()
{
	int x;
	scanf("%d",&x);
	if(x<0)
		printf("error\n");
	else
		printf("%d�Ľ׳�ֵΪ%d\n",x,fact(x));
	return 0;
}