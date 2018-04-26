#include<stdio.h>
int main()
{
	int i,n,m,f;
	i=100;
	while(i<=999)
	{		
		n=i/100;
		m=(i/10)%10;
		f=i%10;
		{
			if(i==n*n*n+m*m*m+f*f*f)
			{
				printf("%d=%d^3+%d^3+%d^3\n",i,n,m,f);
				i++;
			}
			else
				i++;
		}
	}
	return 0;
}
