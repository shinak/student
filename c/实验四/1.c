#include<stdio.h>
int main()
{
	int a[20]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19},n,i,x=0,y=19,c;//10
	printf("输入一个随机数:");
	scanf("%d",&n);
	if(n<a[x]||n>a[y])
		printf("no found\n");
	else if(n==a[19])
		printf("该数所在位置:%d\n",20);
	else
	{
		i=(x+y)/2;
		while(n<a[i])
		{
			c=i;
			i=(x+i)/2;
			while(n>a[i])
			{
				x=i;
				i=(c+i)/2;
			}
		}
		while(n>a[i])
		{
			c=i;
			i=(i+y)/2;
			while(n<a[i])
			{
				x=i;
				i=(i+c)/2;
			}
		}
		if(n==a[i])
			printf("该数所在位置:%d\n ",++i);
	}
	return 0;
}
