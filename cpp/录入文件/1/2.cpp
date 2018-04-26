#include<fstream>
#include<iostream>
using namespace std;
void main()
{	
	ifstream OpenFile("cpp-home.txt");
	char ch;
	while(OpenFile.get(ch))
	{
		cout<<ch;
	}
	cout<<endl;
	OpenFile.close();
}