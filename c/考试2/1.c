#include<math.h>
#include<stdio.h>
int main()
{
	int n,i=1,j,sum,c,m,x;
	float f;
	m=n;
	while(1)
	{
		scanf("%d",&n);
		if(n<0)
			printf("´íÎó£¬ÇëÖØÐÂÊäÈë:");
		else
			break;
	}
	(int)f=0;
	n%i;
	while(n%i!=0)
	{
		i=i*10;
		n%i;
	}
	
	printf("%d",++f);
	for(;f>0;f--)
	{
		j=m%(int)(pow(10,f-1));
		c=m/j;
		m=m%j;
		sum=sum+c;
	}
	printf("sum=%d\n",sum);
	return 0;
}