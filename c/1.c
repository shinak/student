#include <stdio.h>
#include <windows.h>
int main(void)
{
	int a;
	int *p=&a;
	scanf("%d",&a);
	
	printf("%d\n",*p);

}


