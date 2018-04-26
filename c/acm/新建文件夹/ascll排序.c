#include<stdio.h>
int main()
{
	int i,j,f;
	char s[3][3],t;
	for(i=0;i<3;i++)
		gets(s[i]);
	for(i=0;i<3;i++)
	{
		for(f=3;f>0;f--)
		{
			for(j=0;j<f-1;j++)  
			{
				if(s[i][j]>s[i][j+1])
				{
					t=s[i][j];
					s[i][j]=s[i][j+1];
					s[i][j+1]=t;
				}
			}
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%2c",s[i][j]);
		}
		printf("\n");
	}

	return 0;

}