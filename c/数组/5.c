//2维数列 各行最大值；
#include<stdio.h>
int main()
{
	int a[2][4]={{4,8,6,2},{5,7,8,9}};
	int i,j,row,colum,max;
	for(i=0;i<=1;i++)
	{
		for(j=0;j<=3;j++)
			printf("%2d",a[i][j]);
		printf("\n");
	}
	for(i=0;i<=1;i++)
	{
		if(i==0)
		{
			max=a[0][0];
			for(j=0;j<=3;j++)
			{
				if(max<a[i][j])
					max=a[i][j];
				row=i;
				colum=j;
			}
			printf("第一行最大的数:\n");
			printf("max=%d,row=%d,colum=%d\n",max,i,j);
		}
		if(i==1)
		{
			max=a[1][0];
			for(j=0;j<=3;j++)
			{
				if(max<a[i][j])
					max=a[i][j];
				row=i;
				colum=j;			
			}
			printf("第二行最大的数:\n");
			printf("max=%d,row=%d,colum=%d\n",max,i,j);
		}
	}
	return 0;
}




