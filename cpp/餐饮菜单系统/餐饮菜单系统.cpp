#include<Windows.h>
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
class Menu          //����˵���
{
public:
	void set();               //�������
	void display();            //������
	friend void create();      //��Ԫ  �����˵�����
	friend void c_first();
	friend void inquire();     //��Ԫ  ��ѯ�˵�����
	friend void i_first(int i);
	friend void amend();       //��Ԫ  �޸Ĳ˵�����
private:
	int num;//���
	string name;//����
	string style;//��ϵ
	float price;//�۸�
	string supply;//���� 
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
void create()    //����
{
	system("cls");
	int i;
	cout<<"��������Ϣ(���/����/��ϵ/�۸�/����):    *(001 ���Ŷ��� ���� 2.5 ����)"<<endl;  //�˵�����//������ʽ
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
void inquire()        //��ѯ
{
	void i_first(int i);
	system("cls");
	int i,n;
	cout<<"������Ҫ��ѯ�Ĳ������:"<<endl;
	cin>>n;
	for(i=0;i<50;i++)
	{
		if(m[i].num==n)
		{
			i_first(i);
			cout<<"����������Ҫ�Ĳ���:";
		}
	}
	
}

void amend()        //�޸�
{
	int i,n;
	cin>>n;
	for(i=0;i<50;i++)
	{
		if(n==m[i].num)
		{
			i_first(i);
			cout<<"��������Ҫ�޸ĵ���Ϣ(�˵�,��ϵ,�۸�,����):"<<endl;
			cin>>m[i].name>>m[i].style>>m[i].price>>m[i].supply;
			i_first(i);
		}
	}

}

void first()      //������
{
	system("cls");//����
	cout<<"��������������������������������������������������������"<<endl;
	cout<<"��    ����������������������������������������������  ��"<<endl;
	cout<<"��    ��               ����ҵ��ϵͳ               ��  ��"<<endl;
	cout<<"��    ����������������������������������������������  ��"<<endl;
	cout<<"��                                                    ��"<<endl;
	cout<<"��������������������������������������������������������"<<endl;
	cout<<"����                                                ����"<<endl;
	cout<<"����   �����˵�(1)           ��ѯ(2)                ����"<<endl;
	cout<<"����                                                ����"<<endl;
	cout<<"����                                                ����"<<endl;
	cout<<"����   �޸�(3)               ɾ��(4)                ����"<<endl;
	cout<<"����                                                ����"<<endl;
	cout<<"����                                                ����"<<endl;
	cout<<"����   ��ϵ�������ѯ(5)                            ����"<<endl;
	cout<<"����                                                ����"<<endl;
	cout<<"����              �˳�(0)                           ����"<<endl;
	cout<<"����                                                ����"<<endl;
	cout<<"��������������������������������������������������������"<<endl;
	cout<<"��������������������������������������������������������"<<endl;
	
}

void c_first()          //��������������
{
	int i;
	system("cls");//����
	cout<<"��������������������������������������������������������"<<endl;
	cout<<"��    ����������������������������������������������  ��"<<endl;
	cout<<"��    ��                  �˵�                    ��  ��"<<endl;
	cout<<"��    ����������������������������������������������  ��"<<endl;
	cout<<"��                                                    ��"<<endl;
	cout<<"�������������ש��������ש��������ש����������ש���������"<<endl;
	cout<<"����  ���  ��  �˵�  ��  ��ϵ  ��   �۸�   �� ���� ����"<<endl;
	for(i=0;m[i].num!=0;i++)        //�˵����
	{
		cout<<"���ǩ��������贈�������贈�������贈���������贈�����ϩ�"<<endl;
		cout<<"����  "<<setfill('0')<<setw(4)<<m[i].num<<setfill(' ')
			<<"  ��  "<<setiosflags(ios::left)<<setw(6)
			<<m[i].name<<"��  "<<setw(6)<<m[i].style<<"��   "<<setw(5)<<m[i].price
			<<"  ��  "<<setw(4)<<m[i].supply<<"����"<<endl;
	}
	cout<<"�������������ߩ��������ߩ��������ߩ����������ߩ���������"<<endl;
	cout<<"��                                                    ��"<<endl;
	cout<<"��   ������ҳ(1)              ��ѯ(2)                 ��"<<endl;
	cout<<"��                                                    ��"<<endl;
	cout<<"��    �޸�(3)                 ɾ��(4)                 ��"<<endl;
	cout<<"��                                                    ��"<<endl;
	cout<<"��                �˳�(0)                             ��"<<endl;
	cout<<"��������������������������������������������������������"<<endl;
	cout<<"����������Ҫ�Ĳ���:";
}

void i_first(int i)          //��ѯ������
{
	system("cls");//����
	cout<<"��������������������������������������������������������"<<endl;
	cout<<"��    ����������������������������������������������  ��"<<endl;
	cout<<"��    ��                  �˵�                    ��  ��"<<endl;
	cout<<"��    ����������������������������������������������  ��"<<endl;
	cout<<"��                                                    ��"<<endl;
	cout<<"�������������ש��������ש��������ש����������ש���������"<<endl;
	cout<<"����  ���  ��  �˵�  ��  ��ϵ  ��   �۸�   �� ���� ����"<<endl;
	cout<<"���ǩ��������贈�������贈�������贈���������贈�����ϩ�"<<endl;
	cout<<"����  "<<setfill('0')<<setw(4)<<m[i].num<<setfill(' ')
		<<"  ��  "<<setiosflags(ios::left)<<setw(6)
		<<m[i].name<<"��  "<<setw(6)<<m[i].style<<"��   "<<setw(5)<<m[i].price
		<<"  ��  "<<setw(4)<<m[i].supply<<"����"<<endl;                      //��ѯ������
	cout<<"�������������ߩ��������ߩ��������ߩ����������ߩ���������"<<endl;
	cout<<"��                                                    ��"<<endl;
	cout<<"��    ������ҳ(1)           ��ѯ����(2)               ��"<<endl;
	cout<<"��                                                    ��"<<endl;
	cout<<"��              �˳�(0)                               ��"<<endl;
	cout<<"��������������������������������������������������������"<<endl;
}

int main()
{
	int i;
	first();                  //������                   
	cout<<"����������Ҫ�Ĳ���:";//ѡ�����
	cin>>i;
	while(1)
	{
		switch(i)                 //ѡ����
		{
		case 1:
			{
				create();
				cin>>i;
				switch(i)       //2����
				{
				case 1:
					{
						first();                                     
						cout<<"����������Ҫ�Ĳ���:";
						cin>>i;
					};break;
				case 2:;break;
				default:i=0;break; 
				}
			};break;            //�����˵�
		case 2:
			{
				inquire();
				cin>>i;
				switch(i)       //2����
				{
				case 1:
					{
						first();                                     
						cout<<"����������Ҫ�Ĳ���:";
						cin>>i;
					};break;
				case 2:;break;
				case 3:;break;
				case 4:;break;
				default:i=0;break; 
				}
			};break;            //��ѯ
		case 3:{
			amend();
			   };break;            //�޸�
		case 4:;break;            //ɾ��
		case 5:;break;            //��ϵ�������ѯ
		default:break;            //�˳�
		}
		if(i==0)
			break;
	}
	return 0;
}