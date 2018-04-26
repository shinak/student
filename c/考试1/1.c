//已知2016年1月1日为星期一，求2016年5月10日的日期；
#include<stdio.h>；
int main()
{
	int x=1,y=1,n=5;
	if(x==5&&y==10)
		printf("%d",n);
	while(y<=30&&x<=5)
	{
		y++;
		n++;
		if(n==7)
			n=1;
		if(y>30)
		{
			y=1;
			x++;
		}
		if(x==5&&y==10)
			break;
	}
	switch(n)
	{
	case 1:printf("星期一\n");break;
	case 2:printf("星期二\n");break;
	case 3:printf("星期三\n");break;
	case 4:printf("星期四\n");break;
	case 5:printf("星期五\n");break;
    case 6:printf("星期六\n");break;
	case 7:printf("星期日\n");break;
	}
	return 0;
}
