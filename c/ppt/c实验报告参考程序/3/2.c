#include<stdio.h>
int main()
{
	int a,b,m,n;
	scanf("%d%d",&a,&b);
	if(a<=0||b<=0)
		printf("��������������0������\n");
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
		printf("���Լ���ǣ�%d\n",b);
		printf("��С�������ǣ�%d\n",m/b);
	}
	return 0;
}