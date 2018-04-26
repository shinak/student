#include <stdio.h>
int main()
{
	char a[20], b[20];
	char *ps, *pt;
	ps=a;pt=b;
	scanf("%s",ps);
	while ((*pt++=*ps++)!='\0');
	printf ("%s\n",b);
	return 0;
}