#include<stdio.h>
int main()
{
	int n,m,f;
	printf("��������·��գ��磺x,x,x��:");
	scanf("%d,%d,%d",&n,&m,&f);
	if(n%4==0 && n%100!=0 || n%400==0)
	{
		if(m==2)
		{
			if(f==29)
			{
				m=m+1;
			    f=1;
				printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
			}
			else if(f<29)
			{
				f=f+1;
				printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
			}
			else
				printf("��ʽ�������������롣\n");
		}
		else if(m==12)
		{
			if(f==31)
			{
				n=n+1;
				m=1;
			    f=1;
				printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
			}
			else if(f<31)
			{
				f=f+1;
				printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
			}
			else
				printf("��ʽ�������������롣\n");
		}
		else
		{
			if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10)
			{
				if(f==31)
				{
					m=m+1;
				    f=1;
					printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
				}
				else if(f<31)
				{
					f=f+1;
					printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
				}
				else
			    	printf("��ʽ�������������롣\n");
			}
			else if(m==4 || m==6 || m==9 || m==11)
			{
				if(f==30)
				{
					m=m+1;
				    f=1;
					printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
				}
				else if(f<30)
				{
					f=f+1;
					printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
				}
				else
				    printf("��ʽ�������������롣\n");
			}
			else if(m>12)
				printf("��ʽ�������������롣\n");
		}
	}
	else if(m==12)
	{
		if(f==31)
		{
			n=n+1;
			m=1;
			f=1;
			printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
		}
		else if(f<31)
		{
			f=f+1;
			printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
		}
		else
		    printf("��ʽ�������������롣\n");
	}
	else
	{
			if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10)
			{
				if(f==31)
				{
					m=m+1;
				    f=1;
					printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
				}
				else if(f<31)
				{
					f=f+1;
					printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
				}
				else
				    printf("��ʽ�������������롣\n");
			}
			else if(m==4 || m==6 || m==9 || m==11)
			{
				if(f==30)
				{
					m=m+1;
				    f=1;
					printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
				}
				else if(f<30)
				{
					f=f+1;
					printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
				}
				else
			    	printf("��ʽ�������������롣\n");
			}
				else if(m==2)
			{
				if(f==28)
				{
					m=m+1;
				    f=1;
					printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
				}
				else if(f<28)
				{
					f=f+1;
					printf("�ڶ������ڣ�%d,%d,%d\n",n,m,f);
				}
				else
			    	printf("��ʽ�������������롣\n");
			}
			else if(m>12)
				printf("��ʽ�������������롣\n");
	}
	return 0;
}