#include<stdio.h>
int main()
{
	int a,b,i,x,y,c,f,d;
	printf("输入两个大于0的整数:");
	scanf("%d%d",&a,&b);
	if(a<=b)
	{
		c=a;
		a=b;
		b=c;
	}
	f=b;
	if(a>b)
	{
		if(a%b==0)
		{
			printf("最大公约数%d\n",b);
			printf("最大公倍数%d\n",a);
		}
		else
		{
			x=1;
			i=a/b;
			d=a%b;
			while(i!=0)
			{   
				x=x*i;
				i=d/a;
				d=d%a;	
			}
			printf("最大公约数%d\n",x);
			y=(a/x)*(f/x)*x;
			printf("最大公倍数%d\n",y);
		}
	}
	return 0;
}
				

