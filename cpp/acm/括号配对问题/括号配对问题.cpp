#include <stdio.h>  
#include <string.h>  
  
int Peidui(char *p)  
{  
 int xx,yy;  
 char *ptmp;  
 ptmp=p;  
 while( *ptmp !='\0')  
 {  
  xx=yy=0;  
  if( *ptmp == '(' )  
  {  
   xx=1;  
  }  
  else if( *ptmp == '[')  
  {  
   yy=1;  
  }  
  else return -1;  
  if(xx)  
  {  
   while((*(++ptmp) !='\0') && (xx != 0))  
   {  
    if(*ptmp == '(')  
     xx++;  
    if(*ptmp == '[')  
     yy++;  
    if(*ptmp == ')')  
     {  
      xx--;  
      if(xx<0)  
       return -1;  
     }  
       
    if(*ptmp == ']')  
     {  
      yy--;  
      if(yy<0)  
       return -1;  
     }  
   }  
   if(yy)  
   {  
    return -1;  
   }  
  }  
  if(yy)  
  {  
   while((*(++ptmp) !='\0')&&(yy != 0))  
   {  
    if(*ptmp == '(')  
     xx++;  
    if(*ptmp == '[')  
     yy++;  
    if(*ptmp == ')')  
     {  
      xx--;  
      if(xx<0)  
       return -1;  
     }  
    if(*ptmp == ']')  
     {  
      yy--;  
      if(yy<0)  
       return -1;  
     }  
   }  
   if(xx)  
   {  
    return -1;  
   }  
  }  
 }  
 return 0;  
   
}  
  
int main()  
{  
 int testNum,res,i=0,j=0;  
 int x=0,y=0,len;  
 char testData[10010];  
 scanf("%d",&testNum);  
 if((testNum<=0) || (testNum>100))  
  return 0;  
 for(i=0;i<testNum;i++)  
 {  
  scanf("%s",testData);   
  len=strlen(testData);  
  if((len>=10000) && (len==0))  
  {  
   i--;  
   continue;  
  }  
  j=0;  
  while(testData[j] !='\0')  
  {  
   switch(testData[j])  
   {  
    case '(':x++;break;  
    case ')':x--;break;  
    case '[':y++;break;  
    case ']':y--;break;  
    //default:return 0;  
   }  
   j++;  
  }  
  if(x==0 && y==0)  
  {  
   res=Peidui(testData);  
   if(res==0)  
    printf("Yes\n");  
   else  
    printf("No\n");  
  }  
  else   
   printf("No\n");  
  x=y=0;  
 }  
 return 0;  
}