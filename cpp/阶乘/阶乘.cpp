#include<iostream.h>
class fact
{
public:
	fact(int n=0,int m=1):n(n),m(m){}
	friend ostream &operator << (ostream &output,fact &f);
	void add();
	void fun1();
private:
	int n;
	long int m;
};
ostream &operator << (ostream &output,fact &f)
{
	output<<f.n<<"!="<<f.m<<endl;
	return output;
}
void fact::add()
{
	n++;
}
void fact::fun1()
{
	int z;
	z=n;
	m=1;
	while(z>=1)
	{
		m=m*z;
		z--;
	}
}
int main()
{
	fact f;
	int i;
	for(i=0;i<20;i++)
	{
		f.add();
		f.fun1();
		cout<<f;
	}
	return 0;
}
