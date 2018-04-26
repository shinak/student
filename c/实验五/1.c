#include<stdio.h>
int main()
{
	int square(int x);
	int cube(int x);
	int quartic(int x);
	int quintic(int x);
	int x;
	printf("A TABLE OF POWERS\n");
	printf("%10s","No.");
	printf("%10s","square");
	printf("%10s","cube");
	printf("%10s","quartic");
	printf("%10s\n","quintic");
	for(x=1;x<=20;x++)
	{
		printf("%10d",x);
		printf("%10d",square(x));
		printf("%10d",cube(x));
		printf("%10d",quartic(x));
		printf("%10d\n",quintic(x));
	}
	return 0;
}
int square(int x)
{
	int z;
	z=x*x;
	return z; 
}
int cube(int x)
{
	int z;
	z=x*x*x;
	return z;
}
int quartic(int x)
{
	int z;
	z=square(x)*square(x);
	return z;
}
int quintic(int x)
{
	int z;
	z=square(x)*cube(x);
	return z;
}