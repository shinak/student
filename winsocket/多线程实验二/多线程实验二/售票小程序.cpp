#include <stdio.h>
#include <process.h>
#include <Windows.h>

HANDLE mutex;   //������
int ticket = 1000;  //��Ʊ��
//A��Ʊ����
void TicketA(void *p)  
{
	int i = 0;  //�۳�Ʊ��
	WaitForSingleObject(mutex,INFINITE);
	while(ticket>0)
	{
		
		printf("A�۳���\t%d��Ʊ����ʣ\t%d��Ʊ\n",++i,--ticket);
		
		ReleaseMutex(mutex);
	}
	WaitForSingleObject(mutex,INFINITE);
	if (ticket==0)
	{
		printf("CƱ������\n");
		--ticket;
	}
	ReleaseMutex(mutex);
}
//B��Ʊ����
void TicketB(void *p)  
{
	int i = 0;  //�۳�Ʊ��
	WaitForSingleObject(mutex,INFINITE);
	while(ticket>0)
	{
		
		printf("B�۳���\t%d��Ʊ����ʣ\t%d��Ʊ\n",++i,--ticket);
		
		ReleaseMutex(mutex);
	}
	WaitForSingleObject(mutex,INFINITE);
	if (ticket==0)
	{
		printf("BƱ������\n");
		--ticket;
	}
	ReleaseMutex(mutex);
	
}
//C��Ʊ����
void TicketC(void *p)  
{
	int i = 0;  //�۳�Ʊ��
	WaitForSingleObject(mutex,INFINITE);
	while(ticket>0)
	{
		
		printf("C�۳���\t%d��Ʊ����ʣ\t%d��Ʊ\n",++i,--ticket);
		
		ReleaseMutex(mutex);
	}
	WaitForSingleObject(mutex,INFINITE);
	if (ticket==0)
	{
		printf("CƱ������\n");
		--ticket;
	}
	ReleaseMutex(mutex);
}

void main()
{
	mutex = CreateMutex(NULL,false,NULL);  //����������
	_beginthread(TicketA,0,NULL);  //A��Ʊ���ڣ��߳�һ��
	_beginthread(TicketB,0,NULL);  //B��Ʊ���ڣ��̶߳���
	_beginthread(TicketC,0,NULL);  //C��Ʊ���ڣ��߳�����
	system("pause");
}