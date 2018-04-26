#include<iostream>
using namespace std;
void detfun1(float n[100][100],int &b)   //行列式的模
{
	float z;
	if(b==1)
		z=n[0][0];
	if(b==2)
		z=n[0][0]*n[1][1]-n[0][1]*n[1][0];
	if(b==3)
		z=n[0][0]*n[1][1]*n[2][2]+n[0][1]*n[1][2]*n[2][0]+n[0][2]*n[1][0]*n[2][1]
		-n[0][0]*n[1][2]*n[2][1]-n[0][1]*n[1][0]*n[2][2]-n[0][2]*n[1][1]*n[2][0];
	cout<<z<<'\n';
}
/*void detfun2(float n[100][100],int &b)    //代数余子式
{
	int i,j;
	float q[100][100]={0},p[100][100]={0};
	for(i=0;i<b;i++)
		for(j=0;j<b;j++)
		{
			if()
		}
	for(i=0;i<b;i++)
	{
		for(j=0;j<b;j++)
			cout<<q[i][j]<<' ';
		cout<<'\n';
	}
}*/
void matfun(float n[100][100],int &c0,int &l0,float m[100][100],int &c1,int &l1)
{
	int i,j,f;
	float q[100][100]={0};
	for(i=0;i<c0;i++)
	{
		for(j=0;j<l1;j++)
		{
			for(f=0;f<l0;f++)
				q[i][j]=n[i][f]*m[f][j]+q[i][j];
		}
	}
	cout<<"输出2矩阵相乘\n";
	for(i=0;i<c0;i++)
	{
		for(j=0;j<l1;j++)
			cout<<q[i][j]<<' ';
	    cout<<'\n';
	}
}
void main()
{
	int b,i,j,c0,l0,c1,l1,v;
	float n[100][100],m[100][100];
	char a;
	while(1)
	{
		cout<<"行列式或矩阵(d/m)  ";
		cin>>a;
		switch(a)
		{
		case 'd':
			{
				cout<<"行列式阶数(n)  ";
				cin>>b;
				cout<<"输入行列式\n";
				for(i=0;i<b;i++)
					for(j=0;j<b;j++)
						cin>>n[i][j];
				detfun1(n,b);
					
			}break;     //行列式计算
		case 'm':
			{
				cout<<"矩阵个数(v<3) ";
				cin>>v;
				cout<<"矩阵的行与列(c l) ";
				cin>>c0>>l0;
				cout<<"输入矩阵\n";
				for(i=0;i<c0;i++)
					for(j=0;j<l0;j++)
						cin>>n[i][j];
				if(v==2)
				{
					cout<<"矩阵的行与列(c l) ";
					cin>>c1>>l1;
					cout<<"输入矩阵\n";
					for(i=0;i<c1;i++)
						for(j=0;j<l1;j++)
							cin>>m[i][j];
					matfun(n,c0,l0,m,c1,l1);
				}
			}break;     //矩阵计算
		default:cout<<"error!";
		}
		if(a=='o')
			break;
	}
}