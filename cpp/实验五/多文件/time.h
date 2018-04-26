#ifndef _TIME_H_
#define _TIME-H_
#include<iostream>
using namespace std;
class Time
{
public:
	Time();
	Time(int,int,int);
	void normalshow();
	void universialhour();
	void add();
private:
	int hour;
	int min;
	int sec;
};

#endif