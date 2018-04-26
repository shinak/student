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
/*#include<stdio.h>
int main()
{
	int b[100]={1,1},a[100]={1},i,j,f,n;
	printf("%d\n",a[0]);//第一行为1
	for(i=1;i<15;i++)
	{
		printf("%d",a[0]);//每行第一个数为1
		for(j=2;j<=i;j++) //当i等于2时开始执行
		{
			if(j==2)
				n=0;
			a[j-1]=b[n]+b[n+1];
			printf("%5d",a[j-1]);
			n++;
		}             //结束后j=i+1
		j=j-1;
		for(f=1;f<j;f++)   //将数组a[]赋值于b[]
		{
			b[f]=a[f];
		}
		b[f]=a[0];
		printf("%5d\n",b[f]);//最后一个数为1
	}
	return 0;
}
*/