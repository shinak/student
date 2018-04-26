#include<stdio.h>
int main()
{
	int a,b,m,n;
	scanf("%d%d",&a,&b);
	if(a<=0||b<=0)
		printf("请输入两个大于0的整数\n");
	else
	{
		m=a*b;
		n=a%b;
		while(n!=0)
		{
			a=b;
			b=n;
			n=a%b;
		}
		printf("最大公约数是：%d\n",b);
		printf("最小公倍数是：%d\n",m/b);
	}
	return 0;
}