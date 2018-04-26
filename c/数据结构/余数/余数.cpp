#include<stdio.h>
int main()
{
	while(1)
	{
		printf("ÊäÈëÁ©¸öÊı\n");
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d  %% %d = %d ... %d\n",a,b,a/b,a%b);
	}
	return 0;
}