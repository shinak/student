#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Employee
{
public:
	Employee(char nam[],int b):birthmonth(b){strcpy(name,nam);}
	string getname()
	{return name;}
	virtual float getSalary(int month) =0;
protected:
	char name[10];//员工姓名(vc的bug不能用string)
	int birthmonth;//月份
};


class SalariedEmployee:public Employee
{
public:
	SalariedEmployee(char nam[],int b,float s):Employee(nam,b),salaried(s){strcpy(name,nam);}
	virtual float getSalary(int month);
private:
	float salaried;//月薪
};
float SalariedEmployee::getSalary(int month)
{
	if(birthmonth==month)
	{
		salaried+=100;
	}
	return salaried;
}

class HourlyEmployee:public Employee
{
public:
	HourlyEmployee(char nam[],int b,float hs,float h):Employee(nam,b),hsalaried(hs),hour(h){strcpy(name,nam);}
	virtual float getSalary(int month);
private:
	float hsalaried;//每小时工资
	float hour;//小时
};
float HourlyEmployee::getSalary(int month)
{
	if(hour>160)
		hsalaried=hsalaried*160+hsalaried*(hour-160);
	else
		hsalaried=hsalaried*hour;
	if(birthmonth==month)
		hsalaried+=100;//总工资+100
	return hsalaried;
}

class SalesEmployee:public Employee
{
public:
	SalesEmployee(char nam[],int b,float ms,float p):Employee(nam,b),msalaried(ms),promote(p){strcpy(name,nam);}
	virtual float getSalary(int month);
private:
	float msalaried;//月销售额
	float promote;//提升率
};
float SalesEmployee::getSalary(int month)
{
	msalaried=msalaried*promote;
	if(birthmonth==month)
		msalaried+=100;//总工资+100
	return msalaried;
}

int main()
{
	int month,i;
	Employee
		*e[5]={&SalariedEmployee("Mike",3,2789),&HourlyEmployee("Jack",7,30,100),
	&SalesEmployee("Rotus",2,1.5e7,0.12),&HourlyEmployee("Lin",12,235,100),
	&SalariedEmployee("Lin",12,3122)};
	cout<<"Please input the month:";
	cin>>month;
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	for(i=0;i<5;i++)
		cout<<(*e[i]).getname()<<":"<<(*e[i]).getSalary(month)<<endl;
	return 0;
}