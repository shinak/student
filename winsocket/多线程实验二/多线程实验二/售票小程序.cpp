#include <stdio.h>
#include <process.h>
#include <Windows.h>

HANDLE mutex;   //互斥锁
int ticket = 1000;  //总票数
//A售票窗口
void TicketA(void *p)  
{
	int i = 0;  //售出票数
	WaitForSingleObject(mutex,INFINITE);
	while(ticket>0)
	{
		
		printf("A售出第\t%d张票，还剩\t%d张票\n",++i,--ticket);
		
		ReleaseMutex(mutex);
	}
	WaitForSingleObject(mutex,INFINITE);
	if (ticket==0)
	{
		printf("C票已售完\n");
		--ticket;
	}
	ReleaseMutex(mutex);
}
//B售票窗口
void TicketB(void *p)  
{
	int i = 0;  //售出票数
	WaitForSingleObject(mutex,INFINITE);
	while(ticket>0)
	{
		
		printf("B售出第\t%d张票，还剩\t%d张票\n",++i,--ticket);
		
		ReleaseMutex(mutex);
	}
	WaitForSingleObject(mutex,INFINITE);
	if (ticket==0)
	{
		printf("B票已售完\n");
		--ticket;
	}
	ReleaseMutex(mutex);
	
}
//C售票窗口
void TicketC(void *p)  
{
	int i = 0;  //售出票数
	WaitForSingleObject(mutex,INFINITE);
	while(ticket>0)
	{
		
		printf("C售出第\t%d张票，还剩\t%d张票\n",++i,--ticket);
		
		ReleaseMutex(mutex);
	}
	WaitForSingleObject(mutex,INFINITE);
	if (ticket==0)
	{
		printf("C票已售完\n");
		--ticket;
	}
	ReleaseMutex(mutex);
}

void main()
{
	mutex = CreateMutex(NULL,false,NULL);  //创建互斥锁
	_beginthread(TicketA,0,NULL);  //A售票窗口（线程一）
	_beginthread(TicketB,0,NULL);  //B售票窗口（线程二）
	_beginthread(TicketC,0,NULL);  //C售票窗口（线程三）
	system("pause");
}