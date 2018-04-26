#include<stdio.h>
void zhuanzhi(int a[3][3])
{
	int i,j,t;
	for(i=0;i<3;i++)
		for(j=0;j<i;j++)
		{
			t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}
}
int main()
{
	int x[3][3],i,j;
	//input
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&x[i][j]);
	zhuanzhi(x);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			printf("%5d",x[i][j]);
		printf("\n");
	}
	return 0;
}