#include<stdio.h>
int main()
{
	int n,m,i,j,k,a,b,sum=0;
	int x[20],y[20],t;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%d %d",&x[i],&y[i]);
		for(i=0;i<m;i++)
		{
			k=i;
			for(j=i+1;j<m;j++)
				if(x[k]>x[j])
					k=j;
			t=x[i];
			x[i]=x[k];
			x[k]=t;
		}
		for(i=0;i<m;i++)
		{
			k=i;
			for(j=i+1;j<m;j++)
				if(y[k]>y[j])
					k=j;
			t=y[i];
			y[i]=y[k];
			y[k]=t;
		}
		a=x[(m-1)/2];
		b=y[(m-1)/2];
		for(i=0;i<m;i++)
		{
			if(a-x[i]<0 && b-y[i]<0)
				sum=sum+(x[i]-a)+(y[i]-b);
			else
			{
				if(a-x[i]<0)
					sum=sum+(x[i]-a)+(b-y[i]);
				if(b-y[i]<0)
					sum=sum+(a-x[i])+(y[i]-b);
				else
					sum=sum+(a-x[i])+(b-y[i]);
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}