//��֪2016��1��1��Ϊ����һ����2016��5��10�յ����ڣ�
#include<stdio.h>��
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
	case 1:printf("����һ\n");break;
	case 2:printf("���ڶ�\n");break;
	case 3:printf("������\n");break;
	case 4:printf("������\n");break;
	case 5:printf("������\n");break;
    case 6:printf("������\n");break;
	case 7:printf("������\n");break;
	}
	return 0;
}
