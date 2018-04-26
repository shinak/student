#include<iostream>
using namespace std;
void input(char *str)
{
	gets(str);
}
void trim(char *str)
{
	int i;
	while(*str!='\0')
	{
		i=0;
		if(*str==32)
		{
			while(*str!='\0')
			{
			    *str=*(str+1);
				str++;
				i++;
			}
			str=str-i;
		}
		else
			str++;
	}
}
void length(char *str,int *l)
{
	int i=0;
	while(*str!='\0')
	{
		str++;
		i++;
	}
	*l=i;
}
int main()
{
	char str[100];
	int l;
	cout<<"Please input a string:";
	input(str);
	trim(str);
	cout<<"The string after triming is:"<<str<<endl;
	length(str,&l);
	cout<<"The length of the string is:"<<l<<endl;
	return 0;
}