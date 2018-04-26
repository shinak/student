#include<fstream>
#include<iostream>
using namespace std;
int main()
{
	char a[]="li ning",i;
	ofstream outfile;
	outfile.open("f2.txt",ios::out|ios::binary);
	for(i=0;i<5;i++)
	    outfile<<a[i]<<" ";
	outfile.close();
	ifstream infile;
	infile.open("f2.txt",ios::in);
	for(i=0;i<5;i++)
	    infile>>a[i];
	infile.close();
	for(i=0;i<5;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}