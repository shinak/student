#include<stdio.h>
int main()
{
	int year,month,day,days;
	scanf("%d%d%d",&year,&month,&day);
	if(year<=0)
		printf("����������\n");
	else
		if(month>12||month<1)
			printf("�·��������\n");
		else
		{
			switch(month)
			{
			case 2:
				if(year%4==0&&year%100!=0||year%400==0)
					days=29;
				else
					days=28;
				break;
			case 4:
			case 6:
			case 9:
			case 11:days=30;break;
			default:days=31;
			}
			if(day<1||day>days)
				printf("�����������\n");
			else
			{
				if(day<days)
					day++;
				else
				{
					day=1;
					month++;
					if(month==13)
					{
						month=1;
						year++;
					}
				}
				printf("�ڶ��������Ϊ%d-%d-%d\n",year,month,day);
			}
		}
	return 0;
}