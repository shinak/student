#include<iostream.h>
class Point
{
public:
	Point(float a=0,float b=0):x(a),y(b){}
	void setPoint(float a,float b);
	float getX() const {return x;}
	float getY() const {return y;}
	friend ostream & operator << (ostream &output,const Point &p);
protected:
	float x,y;
};
void Point::setPoint(float a,float b)
{
	x=a;
	y=b;
}
ostream & operator << (ostream &output,const Point &p)
{
	output<<"["<<p.x<<","<<p.y<<"]"<<endl;
	return output; 
}


class Circle:public Point
{
public:
	Circle(float a=0,float b=0,float r=0):Point(a,b),radius(r){}
	void setRadius(float);
	float getRadius() const;
	float area() const;
	friend ostream & operator << (ostream &,const Circle &);
private:
	float radius;
};
ostream & operator << (ostream &output,const Circle &c)
{
	output
}

int main()
{
	Point p(3.5,6.4);
	cout<<"x="<<p.getX()<<",y="<<p.getY()<<endl;
	p.setPoint(8.5,6.8);
	cout<<"p(new):"<<p;
	return 0;
}
