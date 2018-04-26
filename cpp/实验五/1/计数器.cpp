#include<iostream>
using namespace std;
class Counter
{
public:
	Counter(int=6);
	void show();
	void add();
	void sub();
private:
	int number;
};
Counter::Counter(int num):number(num){}

void Counter::show()
{
	cout<<"The num of the counter is "<<number<<endl;
}

void Counter::add()
{	number++;}

void Counter::sub()
{   number--;}

int main()
{
	Counter c(5);
	c.add();
	c.show();
	c.sub();
	c.show();
	return 0;
}