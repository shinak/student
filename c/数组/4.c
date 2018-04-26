#include<stdio.h>
int main()
{
	int b[5],a[5]={1,3,4,5},i,x;
	for(i=0;i<5;i++)
		b[i]=a[i];
	scanf("%d",&x);
	a[4]=x;
	for(i=4;a[i]<a[i-1];i--)
	{
		a[i-1]=a[i];
		a[i]=b[i-1];
	}
	for(i=0;i<5;i++)
	{
		if(a[i]==a[i+1])
		{
			a[i]=a[i+1];
		}
		else
			printf("%d",a[i]);
	}
	printf("\n");
	return 0;
}
