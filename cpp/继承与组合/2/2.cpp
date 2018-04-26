#include <iostream>
#include <string>
using namespace std;
class BirthDate 
{
public:
    BirthDate(int,int,int);
    void display();
    void setbirthday(int,int,int);
private:
    int year;
    int month;
    int day;
};
BirthDate::BirthDate(int y,int m,int d)
{
    year=y;month=m;day=d;
}
void BirthDate::display()
{
    cout<<"birthday:"<<year<<"/"<<month<<"/"<<day<<endl;
 
}
 
void BirthDate::setbirthday(int y,int m,int d)
{
    year=y;month=m;day=d;
}



class Teacher
{
public:
    Teacher(int,string,char);
    void display();
private:
    int num;
    string name;
    char sex;
};
Teacher::Teacher(int n ,string nam ,char c)
{
    num=n;
    name=nam;
    sex=c;
}
void Teacher::display()
{
     
    cout<<"num:"<<num<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"sex:"<<sex<<endl;
     
}


class Professor:public Teacher
{
public:
    Professor(int,string,char,BirthDate);
    void display();
    void setbirthday(int,int,int);
private:
    BirthDate birthday;
};
Professor::Professor(int n,string nam,char c,BirthDate day):Teacher(n,nam,c),birthday(day){}
 
void Professor::display()
{
    Teacher::display(); 
	birthday.display();
}
 
void Professor::setbirthday(int i,int m ,int n)
{
    birthday.setbirthday(i,m,n);
     
}
 
int main()
{
    int num;
    string name;
    char sex;
    int year,month,day;
    cin>>num>>name>>sex;
    cin>>year>>month>>day;
    Professor prof(num,name,sex,BirthDate(year,month,day));
    cin>>year>>month>>day;
    prof.setbirthday(year,month,day);
    prof.display();
    return 0;
}