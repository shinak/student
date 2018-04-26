#include"time.h"
int main()
{
	Time t(23,59,0);
	int i;
	for(i=0;i<60;i++)
	{
		t.add();
		t.normalshow();
		t.universialhour();
	}
	return 0;
}