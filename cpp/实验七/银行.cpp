//���һ�ʲ�ѯ����û��
#include<iostream>
#include<string>
using namespace std;
class Custom
{
public:
	Custom(string n,int b):name(n),balance(b){}//���캯��
	void showbalance();//��ʾ���
	void Deposit();//���
protected:
	int account;//�˺�
	string name;//�˻���
	float balance;//���
};
void Custom::showbalance()
{
	if(account!=10000 && account!=20000)
	    cout<<"�˻�:"<<account<<'\t'<<"����:"<<name<<'\t'<<'\t'<<"���:"<<balance<<"Ԫ"<<endl;
	else
		cout<<"�û�����!"<<endl;
}
void Custom::Deposit()               //���
{
	if(account!=10000 && account!=20000)
	{
		int i;
		cout<<"�˻�:"<<account<<'\t'<<"����:"<<name<<'\t'<<endl;
		cout<<"����������:";
		cin>>i;
		cout<<"�˻�:"<<account<<'\t'<<"����:"<<name<<'\t'<<'\t'<<"���:"<<i<<"Ԫ";
		balance+=i;
		cout<<'\t'<<"�˻����:"<<balance<<"Ԫ"<<endl;
	}
	else
		cout<<"�û�����!"<<endl;
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
	static int accounts;//�˻���
};
int CheckingCustom::accounts=1;
void CheckingCustom::WithDraw()
{
	int i;
	cout<<"�˻�:"<<account<<'\t'<<"����:"<<name<<'\t'<<endl;
	cout<<"������ȡ����:";
	cin>>i;

	balance=(balance*0.005)+balance;
	balance-=i;
	if(balance>=0)	
	{
		cout<<"ȡ����:"<<i<<'\t';
	    cout<<"�˻����:"<<balance<<"Ԫ"<<endl;
	}
	else
		cout<<"����!"<<endl;

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
	static int accounts;//�˻���
};
int FixedCustom::accounts=1;
void FixedCustom::WithDraw()
{
	int i;
	cout<<"�˻�:"<<account<<'\t'<<"����:"<<name<<'\t'<<endl;
	cout<<"������ȡ����:";
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
	    cout<<"�˻����:"<<balance<<"Ԫ"<<endl;
	else
		cout<<"����!"<<endl;
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