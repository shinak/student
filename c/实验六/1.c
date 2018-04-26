#include<stdio.h>
void first()
{
	printf("________________________________________\n");
	printf("Which pattern would you like to ptint?\n");
	printf("________________________________________\n");
}
void two()
{
	printf("%-9s","1. a");
	printf("%-9s","2. a b c");
	printf("%-9s","3.     a");
	printf("%-9s\n","4. c b a");
}
void three()
{
	printf("%-9s","   a b");
	printf("%-9s","   a b");
	printf("%-9s","     b a");
	printf("%-9s\n","   b a");
}
void four()
{
	printf("%-9s","   a b c");
	printf("%-9s","   a");
	printf("%-9s","   c b a");
	printf("%-9s\n","   a");
}
void five()
{
	printf("%-9s\n","5.Quit");
}
int main()
{
	first();
	two();
	three();
	four();
	five();
	return 0;
}