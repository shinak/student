#include<stdio.h>
int main()
{
	int a,b,i,x,y,c,f,d;
	printf("������������0������:");
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
			printf("���Լ��%d\n",b);
			printf("��󹫱���%d\n",a);
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
			printf("���Լ��%d\n",x);
			y=(a/x)*(f/x)*x;
			printf("��󹫱���%d\n",y);
		}
	}
	return 0;
}
				

