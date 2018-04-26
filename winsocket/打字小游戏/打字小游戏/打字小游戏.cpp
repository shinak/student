
#include "stdio.h"
#include <windows.h>
#include <time.h>
#include <process.h>
#include <conio.h>
#define N 10
char a[N][N]={0};
//在矩阵第一行的任意位置产生任意一个大写字母
void createChar()
{
	srand(time(NULL));	
	a[0][rand()%10]=rand()%26+'A';	
}
//显示矩阵
void display()
{
	int i,k;
	for(i=0;i<N;i++)
	{
		for(k=0;k<N;k++)
			printf("%c\t",a[i][k]);
		printf("\n");
	}
}
//更新矩阵
void update(void *p)
{
	int i,k;
	while(1)
	{
		system("cls");
		createChar();
		for(i=N-1;i>=0;i--)
			for(k=0;k<N;k++)
			{
				if(a[i][k]!=0)
				{
					a[(i+1)%10][k]=a[i][k];
					a[i][k]=0;
				}
			}
			display();
			Sleep(1000);
	}

}




void main()
{
	char ch;
	int i,k;
	_beginthread(update,0,NULL);
	while(1)
	{
		ch=getch();
		for(i=0;i<N;i++)
			for(k=0;k<N;k++)
				if(a[i][k]==ch)
					a[i][k]=0;

	}


}