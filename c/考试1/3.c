/*Брвы 1 2 3 4 5
       2 4 6 8 10
       3 6 9 12 15
       4 8 12 16 20*/
#include<stdio.h>
int main()
{
	int i,n,x,y=0;
	for(i=1;i<=4;i++)
	{
		for(n=1;n<=5;n++)
		{
			x=i;
			y=y+x;
			printf("%3d",y);
		}
		y=0;
		printf("\n");
	}
	return 0;
}
