#include<iostream>
using namespace std;
class Date
{public:
    Date(int=1,int=1,int=2005);
	/*Date(int,int,int);
	 Date(int,int);
	 Date(int);
	 Date();*/
	 void display();
private:
	int mouth;
	int day;
	int year;

};
Date::Date(int m,int d,int y)
{
	mouth=m;
	day=d;
year=y;
}
/*Date::Date(int m,int d):mouth(m),day(d)
{year=2005;}
Date::Date(int m):mouth(m)
{day=1;
year=2005;
}
Date::Date()
{mouth=1;
day=1;
year=2005;
}*/
void Date::display()
{cout<<mouth<<"/"<<day<<"/"<<year<<endl;}
int main()
{
	Date d1(10,13,2005);
	Date d2(12,30);
	Date d3(10);
	Date d4;
	d1.display();
	d2.display();
	d3.display();
	d4.display();
	return 0;
}
