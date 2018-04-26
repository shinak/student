#include<stdio.h>
int main()
{
	int a[20]={1,6,10,15,20,11,12,15,19,21,24,25,29,30,34,36,39,40,45,90};
	int i,j,mid,x;
	scanf("%d",&x);
	for(i=0,j=19;i<=j;)
	{
		mid=(i+j)/2;
		if(a[mid]==x)
			break;
		else
			if(a[mid]>x)
				j=mid-1;
			else
				i=mid+1;
	}
	if(i<=j)
		printf("数%d在数组中的下标为%d\n",x,mid);
	else
		printf("找不到\n");
	return 0;
}