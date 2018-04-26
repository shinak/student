#include<stdio.h>
int square(int n)
{
	return n*n;
}
int cube(int n)
{
	return n*n*n;
}
int quartic(int n)
{
	return n*cube(n);
}
int quintic(int n)
{
	return square(n)*cube(n);
}
int main()
{
	int i;
	printf("A TABLE OF POWERS\n");
	printf("\tNo.\tSquare\tCube\tQuartic\tQuintic\n");
	for(i=1;i<=20;i++)
			printf("\t%d\t%d\t%d\t%d\t%d\n",i,square(i),cube(i),quartic(i),quintic(i));
	return 0;
}