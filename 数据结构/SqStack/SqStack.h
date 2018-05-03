#define StackSize 10
#include "malloc.h"
#include "stdlib.h"
#include "stdio.h"

typedef char StackData;
typedef struct {				//˳��ջ����
    StackData data[StackSize];	//ջ����
    int top; 					//ջ��ָ��
}SeqStack;
void InitStack(SeqStack &S) {   //�ÿ�ջ
    
    S.top=0;
   
}
int StackEmpty (SeqStack S) {
//�ж�ջ�Ƿ�գ����򷵻�1�����򷵻�0
    return S.top==0;
}

int StackFull (SeqStack S) {
//�ж�ջ�Ƿ��������򷵻�1�����򷵻�0
	
    return S.top == StackSize-1; 
}


int Push (SeqStack &S, StackData x) {
//��ջ������0, ������Ԫ�� x ��ջ������1 
    if ( StackFull (S) ) return 0;	
    S.data[S.top++]=x;        //������Ԫ��
    return 1;
}

int Gettop (SeqStack S, StackData &x) {
//��ջ�շ���0, ����ջ��Ԫ�ض���x������1
    if ( StackEmpty(S) ) return 0;
    x = S.data[S.top-1];
    return 1;
}
int Pop (SeqStack &S, StackData &x) {
//��ջ�շ���0, ����ջ��Ԫ���˳���x������1
    if (StackEmpty(S)) return 0;
	
     x =S.data[--S.top];
	
    return 1;
}
void conversion(){
 int N;
 char e;
 SeqStack d;
 InitStack(d);
 scanf("%d",&N);
 while(N){
 Push(d,N%8+48);
 N=N/8;

 }

while(!StackEmpty(d))
{
 Pop(d,e);
 printf("%c",e);
}
}

