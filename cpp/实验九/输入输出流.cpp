#include<iostream.h>
#include<fstream.h>
class employee
{
public:
	int getnum()
	{return num;}
	friend ostream &operator << (ostream &output,employee &e);
	friend istream &operator >> (istream &input,employee &e);
private:
	int num;//职工号
	char name[10];//姓名
	int age;//年龄
	float salary;//工资
};
ostream &operator << (ostream &output,employee &e)
{
	output<<e.num<<'\t'<<e.name<<'\t'<<e.age<<'\t'<<e.salary<<endl;
	return output;
}
istream &operator >> (istream &input,employee &e)
{
	input>>e.num>>e.name>>e.age>>e.salary;
	return input;
}

int savetofile()
{
	employee x[100];//
	int i,n;
	while(1)
	{
		cout<<"请输入职工的个数(1-100):";
		cin>>n;
		if(n>=1 && n<=100)
		{
			cout<<"NUM"<<'\t'<<"NAME"<<'\t'<<"AGE"<<'\t'<<"SALARY"<<endl;
			for(i=0;i<n;i++)
				cin>>x[i];
			ofstream outfile;
			outfile.open("file1.txt",ios::out);
			for(i=0;i<n;i++)
				outfile<<x[i];
			outfile.close();
			break;
		}
	}
	return i;
}
void outfromfile(int n)
{
	employee x[100];
	int i;
	ifstream infile;
	infile.open("file1.txt",ios::in);
	for(i=0;i<n;i++)
		infile>>x[i];
	infile.close();
	cout<<"NUM"<<'\t'<<"NAME"<<'\t'<<"AGE"<<'\t'<<"SALARY"<<endl;
	for(i=0;i<n;i++)
		cout<<x[i];
}
void findfile(int n)
{
	int l,i;
	employee x[100];
	ifstream infile;
	infile.open("file1.txt",ios::in);
	for(i=0;i<n;i++)
		infile>>x[i];
	infile.close();
	cout<<"请输入要查询的职工号:";
	cin>>l;
	for(i=0;i<n;i++)
	{
		if(x[i].getnum()==l)//?
		{
			cout<<"查找成功!"<<endl;
			cout<<"第"<<l<<"个职工。该职工信息如下:"<<endl;
			cout<<"NUM"<<'\t'<<"NAME"<<'\t'<<"AGE"<<'\t'<<"SALARY"<<endl;
			cout<<x[i];
			break;
		}
	}
	if(i==n)
		cout<<"无此人!"<<endl;
}
int insertfile(int n)
{
	employee x;
	ofstream outfile;
	cout<<"请输入要添加的职工信息:"<<endl;
	cout<<"NUM"<<'\t'<<"NAME"<<'\t'<<"AGE"<<'\t'<<"SALARY"<<endl;
	cin>>x;
	outfile.open("file1.txt",ios::app);
	outfile<<x;
	outfile.close();
	n++;
	return n;
}
int main()
{
	int n;
	n=savetofile();
	outfromfile(n);
	findfile(n);
	n=insertfile(n);
	findfile(n);
	return 0;
}