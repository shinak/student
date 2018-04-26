#include<iostream>
#include<windows.h>
using namespace std;
class Time
{
public:
	void normalshow();
	void universialhour();
	void add();
	void set();
private:
	int hour;
	int min;
	int sec;
};

void Time::set()
{
	cout<<"输入时间(时,分,秒):";
	cin>>hour>>min>>sec;
}

void Time::normalshow()
{
	if(hour>=12)
	{
		if(hour/2<10)
			cout<<'0'<<hour/2<<":";
		else
            cout<<hour/2<<":";
		if(min<10)
			cout<<'0'<<min<<":";
		else
			cout<<min<<":";
		if(sec<10)
			cout<<'0'<<sec<<" "<<"PM"<<'\t';
		else
			cout<<sec<<" "<<"PM"<<'\t';
	}
	else
	{
		if(hour<10)
			cout<<'0'<<hour<<":";
		else
            cout<<hour/2<<":";
		if(min<10)
			cout<<'0'<<min<<":";
		else
			cout<<min<<":";
		if(sec<10)
			cout<<'0'<<sec<<" "<<"AM"<<'\t';
		else
			cout<<sec<<" "<<"AM"<<'\t';
	}
}

void Time::universialhour()
{
	if(hour<10)
		cout<<'0'<<hour<<":";
	else
		cout<<hour<<":";
	if(min<10)
		cout<<'0'<<min<<":";
	else
		cout<<min<<":";
	if(sec<10)
		cout<<'0'<<sec<<" "<<endl;
	else
		cout<<sec<<" "<<endl;
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
int main()
{
	system("color f0");
	Time t;
	int i;
	t.set();
	while(1)
	{
		system("cls");
		t.add();
		t.normalshow();
		t.universialhour();
		Sleep(1000);
	}
	return 0;
}