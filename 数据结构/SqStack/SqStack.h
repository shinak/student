#define StackSize 10
#include "malloc.h"
#include "stdlib.h"
#include "stdio.h"

typedef char StackData;
typedef struct {				//顺序栈定义
    StackData data[StackSize];	//栈数组
    int top; 					//栈顶指针
}SeqStack;
void InitStack(SeqStack &S) {   //置空栈
    
    S.top=0;
   
}
int StackEmpty (SeqStack S) {
//判断栈是否空？空则返回1，否则返回0
    return S.top==0;
}

int StackFull (SeqStack S) {
//判断栈是否满？满则返回1，否则返回0
	
    return S.top == StackSize-1; 
}


int Push (SeqStack &S, StackData x) {
//若栈满返回0, 否则新元素 x 进栈并返回1 
    if ( StackFull (S) ) return 0;	
    S.data[S.top++]=x;        //加入新元素
    return 1;
}

int Gettop (SeqStack S, StackData &x) {
//若栈空返回0, 否则栈顶元素读到x并返回1
    if ( StackEmpty(S) ) return 0;
    x = S.data[S.top-1];
    return 1;
}
int Pop (SeqStack &S, StackData &x) {
//若栈空返回0, 否则栈顶元素退出到x并返回1
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

