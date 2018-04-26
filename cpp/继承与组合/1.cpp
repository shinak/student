#include<iostream>
#include<string>
using namespace std;
class teacher
{
public:
	teacher()
	{
		num=2016057;
		name='k';
		sex='w';
	}
	void display();
private:
	int num;
	string name;
	char sex;	
};
void teacher::display()
{cout<<num<<" "<<name<<" "<<sex<<" "<<endl;}
class birthdate
{
public:
	birthdate()
	{
		year=2017;
		mouth=3;
		day=22;
	}
	void display();
private:
	int year;
	int mouth;
	int day;
};
void birthdate::display()
{cout<<year<<" "<<mouth<<" "<<day<<endl;}
class professor:public teacher
{
public:
	professor(int n,string nam,char c,BirthDate day):Teacher(n,nam,c),birthday(day){}
	void display();
private:
	birthdate birthday;
};
void professor::display();
{
	teacher::display();
	birthday::display();
}