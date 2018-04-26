#include<Windows.h>
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
class Menu          //定义菜单类
{
public:
	void set();               //类的输入
	void display();            //类的输出
	friend void create();      //友元  创建菜单函数
	friend void c_first();
	friend void inquire();     //友元  查询菜单函数
	friend void i_first(int i);
	friend void amend();       //友元  修改菜单函数
private:
	int num;//编号
	string name;//菜名
	string style;//菜系
	float price;//价格
	string supply;//供给 
};
void Menu::set()
{
	cin>>num>>name>>style>>price>>supply;
}
void Menu::display()
{
	cout<<num<<name<<style<<price<<supply<<endl;
}

Menu m[50];
void create()    //创建
{
	system("cls");
	int i;
	cout<<"请输入信息(编号/菜名/菜系/价格/供给):    *(001 麻婆豆腐 川菜 2.5 充足)"<<endl;  //菜单输入//输入例式
	for(i=0;i<50;i++)
	{
		
		cin>>m[i].num;
		if(m[i].num==0)
			break;
		cin>>m[i].name>>m[i].style>>m[i].price>>m[i].supply;
	}
	void c_first();
	c_first();
}
void inquire()        //查询
{
	void i_first(int i);
	system("cls");
	int i,n;
	cout<<"请输入要查询的菜名编号:"<<endl;
	cin>>n;
	for(i=0;i<50;i++)
	{
		if(m[i].num==n)
		{
			i_first(i);
			cout<<"请输入您想要的操作:";
		}
	}
	
}

void amend()        //修改
{
	int i,n;
	cin>>n;
	for(i=0;i<50;i++)
	{
		if(n==m[i].num)
		{
			i_first(i);
			cout<<"请输入您要修改的信息(菜单,菜系,价格,供给):"<<endl;
			cin>>m[i].name>>m[i].style>>m[i].price>>m[i].supply;
			i_first(i);
		}
	}

}

void first()      //初界面
{
	system("cls");//清屏
	cout<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓"<<endl;
	cout<<"┃    ┏━━━━━━━━━━━━━━━━━━━━━┓  ┃"<<endl;
	cout<<"┃    ┃               餐饮业务系统               ┃  ┃"<<endl;
	cout<<"┃    ┗━━━━━━━━━━━━━━━━━━━━━┛  ┃"<<endl;
	cout<<"┃                                                    ┃"<<endl;
	cout<<"┃┏━━━━━━━━━━━━━━━━━━━━━━━━┓┃"<<endl;
	cout<<"┃┃                                                ┃┃"<<endl;
	cout<<"┃┃   创建菜单(1)           查询(2)                ┃┃"<<endl;
	cout<<"┃┃                                                ┃┃"<<endl;
	cout<<"┃┃                                                ┃┃"<<endl;
	cout<<"┃┃   修改(3)               删除(4)                ┃┃"<<endl;
	cout<<"┃┃                                                ┃┃"<<endl;
	cout<<"┃┃                                                ┃┃"<<endl;
	cout<<"┃┃   菜系分类与查询(5)                            ┃┃"<<endl;
	cout<<"┃┃                                                ┃┃"<<endl;
	cout<<"┃┃              退出(0)                           ┃┃"<<endl;
	cout<<"┃┃                                                ┃┃"<<endl;
	cout<<"┃┗━━━━━━━━━━━━━━━━━━━━━━━━┛┃"<<endl;
	cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛"<<endl;
	
}

void c_first()          //创建——初界面
{
	int i;
	system("cls");//清屏
	cout<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓"<<endl;
	cout<<"┃    ┏━━━━━━━━━━━━━━━━━━━━━┓  ┃"<<endl;
	cout<<"┃    ┃                  菜单                    ┃  ┃"<<endl;
	cout<<"┃    ┗━━━━━━━━━━━━━━━━━━━━━┛  ┃"<<endl;
	cout<<"┃                                                    ┃"<<endl;
	cout<<"┃┏━━━━┳━━━━┳━━━━┳━━━━━┳━━━┓┃"<<endl;
	cout<<"┃┃  编号  ┃  菜单  ┃  菜系  ┃   价格   ┃ 供给 ┃┃"<<endl;
	for(i=0;m[i].num!=0;i++)        //菜单输出
	{
		cout<<"┃┣━━━━╋━━━━╋━━━━╋━━━━━╋━━━┫┃"<<endl;
		cout<<"┃┃  "<<setfill('0')<<setw(4)<<m[i].num<<setfill(' ')
			<<"  ┃  "<<setiosflags(ios::left)<<setw(6)
			<<m[i].name<<"┃  "<<setw(6)<<m[i].style<<"┃   "<<setw(5)<<m[i].price
			<<"  ┃  "<<setw(4)<<m[i].supply<<"┃┃"<<endl;
	}
	cout<<"┃┗━━━━┻━━━━┻━━━━┻━━━━━┻━━━┛┃"<<endl;
	cout<<"┃                                                    ┃"<<endl;
	cout<<"┃   返回首页(1)              查询(2)                 ┃"<<endl;
	cout<<"┃                                                    ┃"<<endl;
	cout<<"┃    修改(3)                 删除(4)                 ┃"<<endl;
	cout<<"┃                                                    ┃"<<endl;
	cout<<"┃                退出(0)                             ┃"<<endl;
	cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛"<<endl;
	cout<<"请输入您想要的操作:";
}

void i_first(int i)          //查询初界面
{
	system("cls");//清屏
	cout<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓"<<endl;
	cout<<"┃    ┏━━━━━━━━━━━━━━━━━━━━━┓  ┃"<<endl;
	cout<<"┃    ┃                  菜单                    ┃  ┃"<<endl;
	cout<<"┃    ┗━━━━━━━━━━━━━━━━━━━━━┛  ┃"<<endl;
	cout<<"┃                                                    ┃"<<endl;
	cout<<"┃┏━━━━┳━━━━┳━━━━┳━━━━━┳━━━┓┃"<<endl;
	cout<<"┃┃  编号  ┃  菜单  ┃  菜系  ┃   价格   ┃ 供给 ┃┃"<<endl;
	cout<<"┃┣━━━━╋━━━━╋━━━━╋━━━━━╋━━━┫┃"<<endl;
	cout<<"┃┃  "<<setfill('0')<<setw(4)<<m[i].num<<setfill(' ')
		<<"  ┃  "<<setiosflags(ios::left)<<setw(6)
		<<m[i].name<<"┃  "<<setw(6)<<m[i].style<<"┃   "<<setw(5)<<m[i].price
		<<"  ┃  "<<setw(4)<<m[i].supply<<"┃┃"<<endl;                      //查询结果输出
	cout<<"┃┗━━━━┻━━━━┻━━━━┻━━━━━┻━━━┛┃"<<endl;
	cout<<"┃                                                    ┃"<<endl;
	cout<<"┃    返回首页(1)           查询其他(2)               ┃"<<endl;
	cout<<"┃                                                    ┃"<<endl;
	cout<<"┃              退出(0)                               ┃"<<endl;
	cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛"<<endl;
}

int main()
{
	int i;
	first();                  //初界面                   
	cout<<"请输入您想要的操作:";//选择操作
	cin>>i;
	while(1)
	{
		switch(i)                 //选择功能
		{
		case 1:
			{
				create();
				cin>>i;
				switch(i)       //2界面
				{
				case 1:
					{
						first();                                     
						cout<<"请输入您想要的操作:";
						cin>>i;
					};break;
				case 2:;break;
				default:i=0;break; 
				}
			};break;            //创建菜单
		case 2:
			{
				inquire();
				cin>>i;
				switch(i)       //2界面
				{
				case 1:
					{
						first();                                     
						cout<<"请输入您想要的操作:";
						cin>>i;
					};break;
				case 2:;break;
				case 3:;break;
				case 4:;break;
				default:i=0;break; 
				}
			};break;            //查询
		case 3:{
			amend();
			   };break;            //修改
		case 4:;break;            //删除
		case 5:;break;            //菜系分类与查询
		default:break;            //退出
		}
		if(i==0)
			break;
	}
	return 0;
}