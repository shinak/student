#include<iostream>
using namespace std;
struct Bike
{
	int n;//用户人数
	float h;//使用次数
	float a;//单车制作成本
	float v;//单车盗损率
	float z;//单车维护率
	int f;//单车总数
};
int main()
{
	float b,d,q,y;
	Bike B;
	cout<<"输入共享单车的相关数据(用户人数(万) 使用次数 单车制作成本 单车盗损率 单车维护率 单车总数(万)):";
	cout<<"(结束输入0)"<<endl;
	while(1)
	{
	cin>>B.n;
	if(B.n==0)
		break;
	else
		cin>>B.h>>B.a>>B.v>>B.z>>B.f;
	cout<<"用户人数(万)"<<' '<<"使用次数"<<' '<<"单车制作成本"<<' '<<"单车盗损率"<<' '<<"单车维护率"
		<<' '<<"单车总数"<<endl;
	cout<<B.n<<'\t'<<B.h<<'\t'<<B.a<<'\t'<<B.v<<'\t'<<B.z<<'\t'<<B.f<<endl;
	b=240*B.h;//每辆单车使用收益
	q=299*B.n*10000*0.05;//总佣金收益
	d=(1/((1-B.v)*(1-B.z))+0.2)*B.a+10;//每辆单车成本支出
	y=(b-d)*B.f*10000+q;//单车总盈亏
	cout<<"单车总盈亏y="<<y<<endl;
	}
	return 0;
}