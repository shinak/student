#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	char ch;
	FILE *fp;
	if((fp = fopen("test.txt","r")) == NULL )
	{
		printf("Cannot open file, press any key to exit!");
        getch();
        exit(1);
	}
	while( (ch=fgetc(fp)) != EOF )
	{
        putchar(ch);
    }
	putchar('\n');
	fclose(fp);
	return 0;
}
