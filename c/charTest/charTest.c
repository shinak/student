#include<stdio.h>
#include<wchar.h>
#include<string.h>
void main()
{
	/*char c = 'A';
	char * p = "Hello!";
	static char a[] = "Hello!";*/
	wchar_t c= 'A';
	wchar_t * p = L"Hello!";
    printf("%d\n",wcslen(p));
}