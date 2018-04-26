
#include"fun.cpp"
int main()
{
	system("color f0");
	struct arrayst a[100];
	int n;
	while(1)
	{
		cout<<"please input a number between 5-100:";
		cin>>n;
		if(n>=5 && n<=100)
			break;
	}
	input(a,n);//建立学生成绩表
	cout<<endl<<"before sort:"<<endl;
	output(a,n);//输出学生成绩表
	scoresort(a,n);//按平均成绩从高到低排序学生成绩表
	cout<<endl<<"after sort:"<<endl;
	output(a,n);
	Sleep(60000);
	return 0;
} 