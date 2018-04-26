#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
	int i;
	for(i=0;i<1000;i++)
	{
			Sleep(1000);
			system("cls");
			if(i <= 199)
				printf("倒计时:%d\n",199-i);
			if(i > 199 && i <= 592) 
				printf("倒计时:%d\n",592-i);
			if(i > 592 && i <= 984)
				printf("倒计时:%d\n",984-i);
			if(i == 199)
				printf("\a\n");
			if(i == 592)
				printf("\a\n");
			if(i == 984)
				printf("\a\n");
	}
	return 0;
}