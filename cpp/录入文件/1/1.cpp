#include<fstream>
using namespace std;
void main()
{
	ofstream SaveFile("cpp-home.txt");
	SaveFile<<"Hello world,form www.cpp-home.com and Loo bian!";
	SaveFile.close();
}