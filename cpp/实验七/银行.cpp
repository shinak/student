//最后一问查询功能没做
#include<iostream>
#include<string>
using namespace std;
class Custom
{
public:
	Custom(string n,int b):name(n),balance(b){}//构造函数
	void showbalance();//显示余额
	void Deposit();//存款
protected:
	int account;//账号
	string name;//账户名
	float balance;//余额
};
void Custom::showbalance()
{
	if(account!=10000 && account!=20000)
	    cout<<"账户:"<<account<<'\t'<<"户名:"<<name<<'\t'<<'\t'<<"余额:"<<balance<<"元"<<endl;
	else
		cout<<"用户已满!"<<endl;
}
void Custom::Deposit()               //余额
{
	if(account!=10000 && account!=20000)
	{
		int i;
		cout<<"账户:"<<account<<'\t'<<"户名:"<<name<<'\t'<<endl;
		cout<<"请输入存款金额:";
		cin>>i;
		cout<<"账户:"<<account<<'\t'<<"户名:"<<name<<'\t'<<'\t'<<"存款:"<<i<<"元";
		balance+=i;
		cout<<'\t'<<"账户余额:"<<balance<<"元"<<endl;
	}
	else
		cout<<"用户已满!"<<endl;
}

class CheckingCustom:public Custom
{
public:
    CheckingCustom(string n,int b):Custom(n,b)
	{
		account=10000;
		if(accounts<=9999)
		{account+=accounts;accounts++;}
	}
	void WithDraw(); 
private:
	static int accounts;//账户数
};
int CheckingCustom::accounts=1;
void CheckingCustom::WithDraw()
{
	int i;
	cout<<"账户:"<<account<<'\t'<<"户名:"<<name<<'\t'<<endl;
	cout<<"请输入取款金额:";
	cin>>i;

	balance=(balance*0.005)+balance;
	balance-=i;
	if(balance>=0)	
	{
		cout<<"取款金额:"<<i<<'\t';
	    cout<<"账户余额:"<<balance<<"元"<<endl;
	}
	else
		cout<<"余额不足!"<<endl;

}

class FixedCustom:public Custom
{
public:
    FixedCustom(string n,int b):Custom(n,b)
	{
		account=20000;
		if(accounts<=9999)
		{account+=accounts;accounts++;}
	}
	void WithDraw(); 
private:
	static int accounts;//账户数
};
int FixedCustom::accounts=1;
void FixedCustom::WithDraw()
{
	int i;
	cout<<"账户:"<<account<<'\t'<<"户名:"<<name<<'\t'<<endl;
	cout<<"请输入取款金额:";
	cin>>i;
	if(balance<=500)
	{
		balance=(balance*0.03)+balance;
		balance-=i;
	}
	else
	{
		balance=(balance*0.06)+balance;
		balance-=i;
	}
	if(balance>=0)
	    cout<<"账户余额:"<<balance<<"元"<<endl;
	else
		cout<<"余额不足!"<<endl;
}

int main()
{
	CheckingCustom cc1("aa",200),cc2("ee",139000);
	FixedCustom fc1("bb",300),fc2("cc",20),fc3("dd",1300);
	cc1.showbalance();
	cc1.Deposit();
	cc2.WithDraw();
	fc1.Deposit();
	fc2.WithDraw();
	fc3.WithDraw(); 
	return 0;
}