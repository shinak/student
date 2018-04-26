#include<stdio.h>
int main()
{
	int b[5],a[5]={1,2,3,4,5},i,j;
	for(j=0;j<5;j++)
		b[j]=a[j];
	for(i=0;i<5;i++)
	{
		if(i>2)
			a[i]=b[4-i];
		else
			a[i]=a[4-i];
		printf("%2d",a[i]);
	}
	printf("\n");
	return 0;
}
/*2.0
{
	int b[5],a[5],i,j;
	printf("ÊäÈë5¸öÊı:");
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	for(j=0;j<5;j++)
		b[j]=a[j];
	for(i=0;i<5;i++)
	{
		if(i>2)
			a[i]=b[4-i];
		else
			a[i]=a[4-i];
		printf("%2d",a[i]);
	}
	printf("\n");
	return 0;
}
*/

