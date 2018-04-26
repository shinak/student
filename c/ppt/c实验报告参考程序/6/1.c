#include<stdio.h>
#include<windows.h>
void menu()
{
	system("cls");
	printf("————————————————————————\n");
	printf("Which pattern would you like to print?\n");
	printf("————————————————————————\n");
	printf("1. a      2. a b c  3.    a  4. c b a\n");
	printf("   a b       a b        b a     b a\n");
	printf("   a b c     a        c b a     a\n");
	printf("\n");
	printf("5.Quit\n");
}
void patter1(int line)
{
	char c='a';
	int i,j;
	for(i=0;i<line;i++)
	{
		for(j=0;j<=i;j++)
			printf("%c ",c+j);
		printf("\n");
	}
}
void patter2(int line)
{
	char c;
	int i,j;
	for(i=0;i<line;i++)
	{
		c='a';
		for(j=0;j<line-i;j++)
			printf("%c ",c+j);
		printf("\n");
	}
}
void patter3(int line)
{
	char c;
	int i,j;
	for(i=0;i<line;i++)
	{	
		for(j=i+1;j<line;j++)
			printf("%c ",' ');
		c='a'+i;
		for(j=0;j<=i;j++,c--)
			printf("%c ",c);
		printf("\n");
	}
}
void patter4(int line)
{
	char c;
	int i,j;
	for(i=1;i<=line;i++)
	{
		c='a'+line-i;
		for(j=i;j<=line;j++,c--)
			printf("%c ",c);
		printf("\n");
	}
}
void print(int num,int line)
{
	switch(num)
	{
	case 1:patter1(line);break;
	case 2:patter2(line);break;
	case 3:patter3(line);break;
	case 4:patter4(line);break;
	}
	Sleep(3000);
}
int main()
{
	int num;//菜单编号1-5
	int line;//行数
	while(1)
	{
		menu();
		scanf("%d",&num);
		if(num>5||num<1)
		{
			printf("输入错误，请重新输入！\n");
			Sleep(3000);
		}
		else
			if(num==5)
				exit(0);
			else
			{
				printf("请输入行数：");
				scanf("%d",&line);
				if(line>0)
					print(num,line);
				else
				{
					printf("行数小于1，无法输出\n");
					Sleep(3000);
				}
			}
	}
	return 0;
}