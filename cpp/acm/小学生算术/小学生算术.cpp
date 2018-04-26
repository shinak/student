#include<stdio.h>
int main()
{
	int m,n,a,b,c,i=0;
	while(1)
	{
		scanf("%d %d",&m,&n);
		if(m==0 && n==0)
			break;
		a=m%10+n%10;
		if(a>=10)
		{
			i++;
			b=m%100/10+n%100/10+1;
			if(b>=10)
			{
				i++;
				c=m/100+n/100+1;
				if(c>=10)
					i++;
			}
			else
			{
				c=m/100+n/100;
				if(c>=10)
					i++;
			}

		}
		else
		{
			b=m%100/10+n%100/10;
			if(b>=10)
			{
				i++;
				c=m/100+n/100+1;
				if(c>=10)
					i++;
			}
			else
			{
				c=m/100+n/100;
				if(c>=10)
					i++;
			}
		}
		printf("%d\n",i);
		i=0;
	}
	return 0;
}