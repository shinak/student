#include<stdio.h>
void main()
{
	/*char *s="abcde";
	for(int i=0;i<5;i++)
	{
		s+=i;
		printf();
		s-=i;
	}
	printf("%d\n%d\n%d\n",'c','d','e');*/
	int *p;
	int a[5]={0,1,2,3,4};
	printf("%o\n",&p);
	p=a;
	printf("%d\n",a);
	printf("%d\n",*p);
}