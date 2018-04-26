#include<stdio.h>
void copy( char *c,char *b)
{
 for (;*c!='\0';c++,b++)
 {
  *b=*c;
 }
 *b='\0';
}
void main()
{
 char *c="abc";
 char *b="123456";
        copy(c,b);
 printf("%s\n",b);
}