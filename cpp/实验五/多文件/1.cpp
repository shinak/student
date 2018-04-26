#include"time.h"

Time::Time(int h,int m,int s):hour(h),min(m),sec(s) {}

Time::Time()
{
	hour=23;
	min=58;
	sec=0;
}

void Time::normalshow()
{
	if(hour>=12)
		cout<<hour/2<<":"<<min<<":"<<sec<<" "<<"PM"<<'\t';
	else
	    cout<<hour<<":"<<min<<":"<<sec<<" "<<"AM"<<'\t';

}

void Time::universialhour()
{
	cout<<hour<<":"<<min<<":"<<sec<<endl;
}

void Time::add()
{
	sec=sec+1;
	if(sec==60)
	{
		sec=0;
		min=min+1;
		if(min==60)
		{
			min=0;
			hour=hour+1;
			if(hour==24)
				hour=0;
		}
	}
}
