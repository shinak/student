
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
	input(a,n);//����ѧ���ɼ���
	cout<<endl<<"before sort:"<<endl;
	output(a,n);//���ѧ���ɼ���
	scoresort(a,n);//��ƽ���ɼ��Ӹߵ�������ѧ���ɼ���
	cout<<endl<<"after sort:"<<endl;
	output(a,n);
	Sleep(60000);
	return 0;
} 