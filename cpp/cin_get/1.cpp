#include<iostream>
using namespace std;
int main()
{
	char ch[20];
	cout<<"enter a sentence:"<<endl;
	cin.getline(ch,10,'\n');
	cout<<ch<<endl;
	cin>>get(ch)>>ch[8];
	return 0;
}