#include "max.h"

int max(int a,int b)
{
	int t;
	if(a < b)
	{
		t=a;
		a=b;
		b=t;
	}
	return a;
}