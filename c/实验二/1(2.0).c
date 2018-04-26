#include<stdio.h>
int main()
{
	int n,m,f;
	printf("输入年份月份日（如：x,x,x）:");
    scanf("%d,%d,%d",&n,&m,&f);
	if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10)
	{
		if(f==31)
		{
			m++;
			f=1;
		}
		else if(f<=31)
		{
			f++;
		}
		if(f<1 || f>31)
			printf("day is error\n");
		else
		    printf("第二天日期：%d,%d,%d\n",n,m,f);

	}
	else if(m==4 || m==6 || m==9 || m==11)
	{
		if(f==30)
		{
			m++;
			f=1;
		}
		else if(f<=30)
		{
			f++;
		}
		if(f<1 || f>30)
			printf("day is error\n");
		else
		    printf("第二天日期：%d,%d,%d\n",n,m,f);
	}
	else  if(m==12)
	{
		if(f==31)
		{
			m=1;
			f=1;
		}
		if(f<=31)
		{
			f++;
		}
		if(f<1 || f>31)
	        printf("day is error\n");
		else
		    printf("第二天日期：%d,%d,%d\n",n,m,f);
	}
	if(m==2)
	{
		if(n%4==0 && n%100!=0 || n%400==0)
		{
			if(f==29)
			{
				m++;
				f=1;
			}
			else if(f<29)
			{
				f++;
			}
			if(f<1 || f>29)
				printf("day is error\n");
			else
				printf("第二天日期：%d,%d,%d\n",n,m,f);
		}
		else
		{
			if(f==28)
		{
			m++;
			f=1;
		}
		else if(f<28)
		{
			f++;
		}
		if(f<1 || f>28)
			printf("day is error\n");
		else
		    printf("第二天日期：%d,%d,%d\n",n,m,f);
		}
	}
	if(m<1 || m>12)
		printf("year is error\n");
	return 0;
}