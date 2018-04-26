#include<iostream.h>
class complex
{
public:
	complex(){real=0;imag=0;}
	complex(int r,int i):real(r),imag(i){}
	void show();
	friend istream& operator >> (istream &input,complex &z);
	friend complex operator + (complex& x,complex& y);
	friend complex operator - (complex& x,complex& y);
	friend complex operator * (complex& x,complex& y);
	friend complex operator / (complex& x,complex& y);
private:
	float real;
	float imag;
};

void complex::show()
{
	cout<<real;
	if(imag>0)
		cout<<"+"<<imag<<"i";
	if(imag<0)
		cout<<imag<<"i";
	cout<<endl;
}

istream & operator >> (istream &input,complex &z)
{
	cout<<"输入实部与虚部(如:5 4):";
	input>>z.real>>z.imag;
	return input;
}

complex operator + (complex &x,complex &y)
{
	return complex(x.real+y.real,x.imag+y.imag);
}

complex operator - (complex &x,complex &y)
{
	return complex(x.real-y.real,x.imag-y.imag);
}

complex operator * (complex &x,complex &y)
{
	return complex(x.real*y.real-x.imag*y.imag,y.real*x.imag+x.real*y.imag);
}

complex operator / (complex &x,complex &y)
{
	complex z,c;
	float n;
	z=complex(x.real*y.real+x.imag*y.imag,-(y.real)*x.imag+x.real*y.imag);
	n=y.real*y.real+y.imag*y.imag;
	c.real=z.real/n;
	c.imag=z.imag/n;
	return c;
}

int main()
{
	complex c1,c2;//c1(7,8),c2(5,10);
	cin>>c1>>c2;
	(c1+c2).show();
	(c1-c2).show();
	(c1*c2).show();
	(c1/c2).show();
	return 0;
}