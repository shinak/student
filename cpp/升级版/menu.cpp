#include<Windows.h>
#include<string.h>
#include<iostream.h>
#include<fstream.h>
class Menu          //定义菜单类
{
public:
	friend istream &operator >> (istream &input,Menu &m);    //对>>重载
	friend ostream &operator << (ostream &output,Menu &m);  //对<<重载
	int getnum() const{return num;}                        //获取编号
	char *getname() const{return (char*)name;}              //获取菜名
	char *getstyle() const{return (char*)style;}                //获取菜系
	double getprice() const{return price;}                    //获取价格
	char *getsupply() const{return (char*)supply;}             //获取供给
	friend void amend();                                  //修改菜单信息
	friend void menu_create(int z);                         //创建菜单
	
private:
	int num;                                           //编号
	char name[10];                                      //菜名
	char style[4];                                        //菜系
	double price;                                        //价格
	char supply[2];                                      //供给 
};
istream &operator >> (istream &input,Menu &m)
{
	input>>m.num>>m.name>>m.style>>m.price>>m.supply;
	return input;
}
ostream &operator << (ostream &output,Menu &m)
{
	output<<m.num<<'\t'<<m.name<<'\t'<<m.style<<'\t'<<m.price<<'\t'<<m.supply<<endl;
	return output;
}

Menu m[50];

int infile_menu()                                                //从磁盘读入菜单信息
{
	int i;
	ifstream infile;
	infile.open("menu1.txt",ios::in);
	for(i=0;infile.eof()==0;i++)
	{
		infile>>m[i];
		if(m[i].getnum()==0)
			break;
	}
	infile.close();
	return i;
}

void outfile_menu()                                              //保存菜单信息
{
	int i;
	ofstream outfile;
	outfile.open("menu1.txt",ios::out);
	for(i=0;m[i].getnum()!=0;i++)
	{
		outfile<<m[i];
	}
	outfile.close();
}

void sort(int i)                                                  //根据菜单编号排序
{
	int n,j,k;
	Menu temp;
	for(n=0;n<i;n++)     
	{
		k=n;
		for(j=n+1;j<i;j++)
			if(m[k].getnum()>m[j].getnum())
				k=j;
			temp=m[n];
			m[n]=m[k];
			m[k]=temp;
	}
}

void out_menu()                                                 //输出菜单总览
{
	int i,k,n;
	for(i=0,k=1;m[i].getnum()!=0;i++,k++)
	{	
		if(i%10==0)
		{
			system("cls");
			cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
			cout<<'\t'<<'\t'<<"菜单总览"<<endl;
			cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
			cout<<"编号"<<'\t'<<"菜名"<<'\t'<<"菜系"<<'\t'<<"价格"<<'\t'<<"供给"<<endl;
			cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
		}
		cout<<m[i];
		if(k==10)
		{
			if(i==9 && m[i+1].getnum()!=0)        
			{
				cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
				cout<<'\t'<<'\t'<<"下一页(2)"<<endl;
				cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
				cout<<'\t'<<'\t'<<"操作:";
				cin>>n;
			}
			k=1;
		}
	}
}

void menu_create(int z)                                                 //菜单创建
{
	system("cls");
	int i,n,k;
	i=z;
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<"* 若输入0则结束录入 *"<<endl;
	cout<<"* 最多50种菜 *"<<endl;
	cout<<"* 输入格式为 10001 荔枝肉 福州菜 25.00 供应 *"<<endl;
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<"编号"<<'\t'<<"菜名"<<'\t'<<"菜系"<<'\t'<<"价格"<<'\t'<<"供给"<<endl;
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	for(;i<50;i++)                                                    //录入菜单信息
	{
		cin>>m[i].num;
		if(m[i].num==0)
			break;
		cin>>m[i].name>>m[i].style>>m[i].price>>m[i].supply;	
		for(n=0,k=i;n<k;n++)   //避免下次,本次录入时编号重复
		{
			if(m[i].num==m[n].num)
			{
				i--;
				cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
				cerr<<"录入重复编号,请重新录入上一条信息:"<<endl;
				cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
				break;
			}
		}
	}
	sort(i);
	outfile_menu();
	out_menu();
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<"返回首页(1)"<<'\t'<<"查询(2)"<<endl;
	cout<<"修改(3)"<<'\t'<<'\t'<<"删除(4)"<<endl;
	cout<<"分类查看(5)"<<'\t'<<"退出(0)"<<endl;
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<'\t'<<'\t'<<"操作:";
}

void inquire()                                                 //根据编号查询详细信息
{
	system("cls");
	int i,n;
	cout<<"请输入要查询的菜名编号:";
	cin>>n;
	for(i=0;i<50;i++)     //查找
	{
		if(m[i].getnum()==n)
		{
			cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
			cout<<'\t'<<'\t'<<"该菜信息"<<endl;
			cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
			cout<<"编号"<<'\t'<<"菜名"<<'\t'<<"菜系"<<'\t'<<"价格"<<'\t'<<"供给"<<endl;
			cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
			cout<<m[i];
			break;
		}
	}
	if(i==50)
	{
		cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"无此菜!"<<endl;
		cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	}
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<"查询其他(1)"<<'\t'<<"返回首页(2)"<<endl;
	cout<<"修改(3)"<<'\t'<<'\t'<<"删除(4)"<<endl;
	cout<<"分类查看(5)"<<'\t'<<"退出(0)"<<endl;
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<'\t'<<'\t'<<"操作:";
}


void amend()                                                      //修改菜单信息
{
	system("cls");
	int i,n;
	cout<<"请输入需要修改的编号:";
	cin>>n;
	for(i=0;i<50;i++)
	{
		if(n==m[i].getnum())
		{
			cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
			cout<<"请输入您要修改的信息(菜系/价格/供给):"<<endl;
			cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
			cout<<"菜名"<<'\t'<<"菜系"<<'\t'<<"价格"<<'\t'<<"供给"<<endl;
			cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
			cout<<m[i].name<<'\t';
			cin>>m[i].style>>m[i].price>>m[i].supply;
			cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
			cout<<"编号"<<'\t'<<"菜名"<<'\t'<<"菜系"<<'\t'<<"价格"<<'\t'<<"供给"<<endl;
			cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
			cout<<m[i];
			break;
		}
	}
	if(i==50)
		cerr<<"无此菜!"<<endl;
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<"修改其他(1)"<<'\t'<<"返回首页(2)"<<endl;
	cout<<"查询(3)"<<'\t'<<'\t'<<"删除(4)"<<endl;
	cout<<"分类查看(5)"<<'\t'<<"退出(0)"<<endl;
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<'\t'<<'\t'<<"操作:";
}

void cancel()                                                      //删除某菜信息
{
	system("cls");
	int i,n;
	cout<<"请输入需要删除的编号:";
	cin>>n;
	for(i=0;i<50;i++)
	{
		if(n==m[i].getnum())
		{
			if(strcmp(m[i].getsupply(),"售罄")==0)
			{
				cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
				cerr<<"该菜已售罄,不可删除!"<<endl;
				cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
			}
			else
			{
				for(;i<50;i++)
					m[i]=m[i+1];
				cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
				cout<<"编号"<<'\t'<<"菜名"<<'\t'<<"菜系"<<'\t'<<"价格"<<'\t'<<"供给"<<endl;
				cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
				for(i=0;m[i].getnum()!=0;i++)
				{
					cout<<m[i];
				}
			}
			break;
		}
	}
	if(i==50)
	{
		cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cerr<<"无此菜!"<<endl;
		cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	}
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<"删除其他(1)"<<'\t'<<"返回首页(2)"<<endl;
	cout<<"查询(3)"<<'\t'<<'\t'<<"修改(4)"<<endl;
	cout<<"分类查看(5)"<<'\t'<<"退出(0)"<<endl;
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<'\t'<<'\t'<<"操作:";
}

void classify()                                             //分类查看(菜系分类)
{
	system("cls");
	int i,k=1;
	char n[4];
	cout<<"请输入要查询的菜系:";
	cin>>n;
	for(i=0;i<50;i++)     //查找
	{
		if(strcmp(m[i].getstyle(),n)==0)
		{
			if(k==1)
			{
				system("cls");
				cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
				cout<<'\t'<<'\t'<<"该菜系列表"<<endl;
				cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
				cout<<"编号"<<'\t'<<"菜名"<<'\t'<<"菜系"<<'\t'<<"价格"<<'\t'<<"供给"<<endl;
				cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
			}
			cout<<m[i];
			k++;
			if(k==10)
			{
				cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
				cout<<'\t'<<'\t'<<"下一页(2)"<<endl;
				cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
				cout<<'\t'<<'\t'<<"操作:";
				cin>>n;
				k=1;
			}
		}
	}
	if(k==1)
	{
		cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"无此菜系!"<<endl;
		cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	}
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<"其他菜系(1)"<<'\t'<<"返回首页(2)"<<endl;
	cout<<"查询(3)"<<'\t'<<'\t'<<"修改(4)"<<endl;
	cout<<"删除(5)"<<'\t'<<'\t'<<"退出(0)"<<endl;
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<'\t'<<'\t'<<"操作:";
}


void look2()                                                 //返回首页界面
{
	system("cls");
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<'\t'<<'\t'<<"餐饮菜单系统"<<endl;
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<endl<<'\t'<<'\t'<<"创建菜单(1)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"查询(2)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"修改(3)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"删除(4)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"分类查看(5)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"退出(0)"<<endl<<endl;
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<endl<<'\t'<<'\t'<<"操作:";
}

void look1(int z)                                                 //首页界面
{
	int n;
	if(z==0)
	{
		cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
		cout<<"*当期没有菜类信息，请先创建菜单!"<<endl;	
	}
	else
	{
		out_menu();
		cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
		system("pause");
		system("cls");
	}
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<'\t'<<'\t'<<"餐饮菜单系统"<<endl;
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<endl<<'\t'<<'\t'<<"创建菜单(1)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"查询(2)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"修改(3)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"删除(4)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"分类查看(5)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"退出(0)"<<endl<<endl;
	cout<<"━━━━━━━━━━━━━━━━━━━━━━"<<endl;
	cout<<endl<<'\t'<<'\t'<<"操作:";
}

int main()
{
	system("mode con cols=45 lines=25");
	system("color f0");
	int i,z;
	z=infile_menu();
	look1(z);
	cin>>i;
	while(1)
	{	
		switch(i)
		{
		case 1:{                                               //创建
			menu_create(z);
			cin>>i;
			switch(i)
			{
			case 1:i=6;break;
			case 2:i=2;break;
			case 3:i=3;break;
			case 4:i=4;break;
			case 5:i=5;break;
			default:i=0;break;
			}
			   }break;
		case 2:{                                               //查询
			inquire();
			cin>>i;
			switch(i)
			{
			case 1:i=2;break;
			case 2:i=6;break;
			case 3:i=3;break;
			case 4:i=4;break;
			case 5:i=5;break;
			default:i=0;break;
			}
			   }break;
		case 3:{                                                       //修改
			amend();
			cin>>i;
			switch(i)
			{
			case 1:i=3;break;
			case 2:i=6;break;
			case 3:i=2;break;
			case 4:i=4;break;
			case 5:i=5;break;
			default:i=0;break;
			}
			   }break;
		case 4:{                                                     //删除
			cancel();
			cin>>i;
			switch(i)
			{
			case 1:i=4;break;
			case 2:i=6;break;
			case 3:i=2;break;
			case 4:i=3;break;
			case 5:i=5;break;
			default:i=0;break;
			}
			   }break;
		case 5:{                                                     //分类
			classify();
			cin>>i;
			switch(i)
			{
			case 1:i=5;break;
			case 2:i=6;break;
			case 3:i=2;break;
			case 4:i=3;break;
			case 5:i=4;break;
			default:i=0;break;
			}
			   }break;
		case 6:{                                                    //首页
			look2();
			cin>>i;
			switch(i)
			{
			case 1:i=1;break;
			case 2:i=2;break;
			case 3:i=3;break;
			case 4:i=4;break;
			case 5:i=5;break;
			default:i=0;break;
			}
			   }break;
		default:{
			outfile_menu();
			cout<<"正在关闭程序..."<<endl;
			Sleep(2000);
			exit(1);
				} break;
		}
	}
	return 0;
}