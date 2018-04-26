#include<Windows.h>
#include<string.h>
#include<iostream.h>
#include<fstream.h>
class Menu          //����˵���
{
public:
	friend istream &operator >> (istream &input,Menu &m);    //��>>����
	friend ostream &operator << (ostream &output,Menu &m);  //��<<����
	char *getnum() const{return (char*)num;}                        //��ȡ���
	char *getname() const{return (char*)name;}              //��ȡ����
	char *getstyle() const{return (char*)style;}                //��ȡ��ϵ
	double getprice() const{return price;}                    //��ȡ�۸�
	char *getsupply() const{return (char*)supply;}             //��ȡ����
	friend void amend();                                  //�޸Ĳ˵���Ϣ
	friend void menu_create(int z);                         //�����˵�

private:
	char num[10];                                           //���
	char name[10];                                      //����
	char style[4];                                        //��ϵ
	double price;                                        //�۸�
	char supply[2];                                      //���� 
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

int infile_menu()                                                //�Ӵ��̶���˵���Ϣ
{
	int i;
	char n[2]="0";
	ifstream infile;
	infile.open("menu1.txt",ios::in);
	for(i=0;infile.eof()==0;i++)
	{
		if(strcmp(m[i].getnum(),n)==0)
			break;
		infile>>m[i];
		
	}
	infile.close();
	return i;
}

void outfile_menu()                                              //����˵���Ϣ
{
	int i;
	char n[2]="0";
	ofstream outfile;
	outfile.open("menu1.txt",ios::out);
	for(i=0;strcmp(m[i].getnum(),n)!=0;i++)
	{
		outfile<<m[i];
	}
	outfile.close();
}

void sort(int i)                                                  //���ݲ˵��������
{
	int n,j,k;
	Menu temp;
	for(n=0;n<i;n++)     
	{
		k=n;
		for(j=n+1;j<i;j++)
			if(strcmp(m[k].getnum(),m[j].getnum())>0)
				k=j;
			temp=m[n];
			m[n]=m[k];
			m[k]=temp;
	}
}

void out_menu()                                                 //����˵�����
{
	int i,k,f;
	char n[2]="0";
	for(i=0,k=1;strcmp(m[i].getnum(),n)!=0;i++,k++)
	{	
		if(i%10==0)
		{
			system("cls");
			cout<<"��������������������������������������������"<<endl;
			cout<<'\t'<<'\t'<<"�˵�����"<<endl;
			cout<<"��������������������������������������������"<<endl;
			cout<<"���"<<'\t'<<"����"<<'\t'<<"��ϵ"<<'\t'<<"�۸�"<<'\t'<<"����"<<endl;
			cout<<"��������������������������������������������"<<endl;
		}
		cout<<m[i];
		if(k==10)
		{
			if(i==9 && strcmp(m[i+1].getnum(),n)!=0)        
			{
				cout<<"��������������������������������������������"<<endl;
				cout<<'\t'<<'\t'<<"��һҳ(2)"<<endl;
				cout<<"��������������������������������������������"<<endl;
				cout<<'\t'<<'\t'<<"����:";
				cin>>f;
			}
			k=1;
		}
	}
}

void menu_create(int z)                                                 //�˵�����
{
	system("cls");
	int i,n,k;
	char s[2]="0";
	i=z;
	cout<<"��������������������������������������������"<<endl;
	cout<<"* ������0�����¼�� *"<<endl;
	cout<<"* ���50�ֲ� *"<<endl;
	cout<<"* �����ʽΪ 10001 ��֦�� ���ݲ� 25.00 ��Ӧ *"<<endl;
	cout<<"��������������������������������������������"<<endl;
	cout<<"���"<<'\t'<<"����"<<'\t'<<"��ϵ"<<'\t'<<"�۸�"<<'\t'<<"����"<<endl;
	cout<<"��������������������������������������������"<<endl;
	for(;i<50;i++)                                                    //¼��˵���Ϣ
	{
		cin>>m[i].num;
		if(strcmp(m[i].getnum(),s)==0)
			break;
		cin>>m[i].name>>m[i].style>>m[i].price>>m[i].supply;	
		for(n=0,k=i;n<k;n++)   //�����´�,����¼��ʱ����ظ�
		{
			if(strcmp(m[i].getnum(),m[n].getnum())==0)
			{
				i--;
				cout<<"��������������������������������������������"<<endl;
				cerr<<"¼���ظ����,������¼����һ����Ϣ:"<<endl;
				cout<<"��������������������������������������������"<<endl;
				break;
			}
		}
	}
	sort(i);
	outfile_menu();
	out_menu();
	cout<<"��������������������������������������������"<<endl;
	cout<<"������ҳ(1)"<<'\t'<<"��ѯ(2)"<<endl;
	cout<<"�޸�(3)"<<'\t'<<'\t'<<"ɾ��(4)"<<endl;
	cout<<"��������������������������������������������"<<endl;
	cout<<'\t'<<"�˳�(0)"<<endl;
	cout<<"��������������������������������������������"<<endl;
	cout<<'\t'<<'\t'<<"����:";
}

void inquire()                                                 //���ݱ�Ų�ѯ��ϸ��Ϣ
{
	system("cls");
	int i;
	char n[10];
	cout<<"������Ҫ��ѯ�Ĳ������:";
	cin>>n;
	for(i=0;i<50;i++)     //����
	{
		if(strcmp(m[i].getnum(),n)==0)
		{
			cout<<"��������������������������������������������"<<endl;
			cout<<'\t'<<'\t'<<"�ò���Ϣ"<<endl;
			cout<<"��������������������������������������������"<<endl;
			cout<<"���"<<'\t'<<"����"<<'\t'<<"��ϵ"<<'\t'<<"�۸�"<<'\t'<<"����"<<endl;
			cout<<"��������������������������������������������"<<endl;
			cout<<m[i];
			break;
		}
	}
	if(i==50)
	{
		cout<<"��������������������������������������������"<<endl;
		cout<<"�޴˲�!"<<endl;
		cout<<"��������������������������������������������"<<endl;
	}
	cout<<"��������������������������������������������"<<endl;
	cout<<"��ѯ����(1)"<<'\t'<<"������ҳ(2)"<<endl;
	cout<<"�޸�(3)"<<'\t'<<'\t'<<"ɾ��(4)"<<endl;
	cout<<"��������������������������������������������"<<endl;
	cout<<'\t'<<"�˳�(0)"<<endl;
	cout<<"��������������������������������������������"<<endl;
	cout<<'\t'<<'\t'<<"����:";
}


void amend()                                                      //�޸Ĳ˵���Ϣ
{
	system("cls");
	int i;
	char n[10];
	cout<<"��������Ҫ�޸ĵı��:";
	cin>>n;
	for(i=0;i<50;i++)
	{
		if(strcmp(m[i].getnum(),n)==0)
		{
			cout<<"��������������������������������������������"<<endl;
			cout<<"��������Ҫ�޸ĵ���Ϣ(��ϵ/�۸�/����):"<<endl;
			cout<<"��������������������������������������������"<<endl;
			cout<<"����"<<'\t'<<"��ϵ"<<'\t'<<"�۸�"<<'\t'<<"����"<<endl;
			cout<<"��������������������������������������������"<<endl;
			cout<<m[i].name<<'\t';
			cin>>m[i].style>>m[i].price>>m[i].supply;
			cout<<"��������������������������������������������"<<endl;
			cout<<"���"<<'\t'<<"����"<<'\t'<<"��ϵ"<<'\t'<<"�۸�"<<'\t'<<"����"<<endl;
			cout<<"��������������������������������������������"<<endl;
			cout<<m[i];
			break;
		}
	}
	if(i==50)
		cerr<<"�޴˲�!"<<endl;
	cout<<"��������������������������������������������"<<endl;
	cout<<"�޸�����(1)"<<'\t'<<"������ҳ(2)"<<endl;
	cout<<"��ѯ(3)"<<'\t'<<'\t'<<"ɾ��(4)"<<endl;
	cout<<"��������������������������������������������"<<endl;
	cout<<'\t'<<"�˳�(0)"<<endl;
	cout<<"��������������������������������������������"<<endl;
	cout<<'\t'<<'\t'<<"����:";
}

void cancel()                                                      //ɾ��ĳ����Ϣ
{
	system("cls");
	int i;
	char n[10],k[2]="0";
	cout<<"��������Ҫɾ���ı��:";
	cin>>n;
	for(i=0;i<50;i++)
	{
		if(strcmp(m[i].getnum(),n)==0)
		{
			if(strcmp(m[i].getsupply(),"����")==0)
			{
				cout<<"��������������������������������������������"<<endl;
				cerr<<"�ò�������,����ɾ��!"<<endl;
				cout<<"��������������������������������������������"<<endl;
			}
			else
			{
				for(;i<50;i++)
					m[i]=m[i+1];
				cout<<"��������������������������������������������"<<endl;
				cout<<"���"<<'\t'<<"����"<<'\t'<<"��ϵ"<<'\t'<<"�۸�"<<'\t'<<"����"<<endl;
				cout<<"��������������������������������������������"<<endl;
				for(i=0;strcmp(m[i].getnum(),k)!=0;i++)
				{
					cout<<m[i];
				}
			}
			break;
		}
	}
	if(i==50)
	{
		cout<<"��������������������������������������������"<<endl;
		cerr<<"�޴˲�!"<<endl;
		cout<<"��������������������������������������������"<<endl;
	}
	cout<<"��������������������������������������������"<<endl;
	cout<<"ɾ������(1)"<<'\t'<<"������ҳ(2)"<<endl;
	cout<<"��ѯ(3)"<<'\t'<<'\t'<<"�޸�(4)"<<endl;
	cout<<"��������������������������������������������"<<endl;
	cout<<'\t'<<"�˳�(0)"<<endl;
	cout<<"��������������������������������������������"<<endl;
	cout<<'\t'<<'\t'<<"����:";
}

void look2()                                                 //������ҳ����
{
	system("cls");
	cout<<"��������������������������������������������"<<endl;
	cout<<'\t'<<'\t'<<"�����˵�ϵͳ"<<endl;
	cout<<"��������������������������������������������"<<endl;
	cout<<endl<<'\t'<<'\t'<<"�����˵�(1)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"��ѯ(2)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"�޸�(3)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"ɾ��(4)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"�˳�(0)"<<endl<<endl;
	cout<<"��������������������������������������������"<<endl;
	cout<<endl<<'\t'<<'\t'<<"����:";
}

void look1(int z)                                                 //��ҳ����
{
	if(z==0)
	{
		cout<<"��������������������������������������������"<<endl;
		cout<<"*����û�в�����Ϣ�����ȴ����˵�!"<<endl;	
	}
	else
	{
		out_menu();
		cout<<"��������������������������������������������"<<endl;
		system("pause");
		system("cls");
	}
	cout<<"��������������������������������������������"<<endl;
	cout<<'\t'<<'\t'<<"�����˵�ϵͳ"<<endl;
	cout<<"��������������������������������������������"<<endl;
	cout<<endl<<'\t'<<'\t'<<"�����˵�(1)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"��ѯ(2)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"�޸�(3)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"ɾ��(4)"<<endl;
	cout<<endl<<'\t'<<'\t'<<"�˳�(0)"<<endl<<endl;
	cout<<"��������������������������������������������"<<endl;
	cout<<endl<<'\t'<<'\t'<<"����:";
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
		case 1:{                                               //����
			menu_create(z);
			cin>>i;
			switch(i)
			{
			case 1:i=5;break;
			case 2:i=2;break;
			case 3:i=3;break;
			case 4:i=4;break;
			default:i=0;break;
			}
			   }break;
		case 2:{                                               //��ѯ
			inquire();
			cin>>i;
			switch(i)
			{
			case 1:i=2;break;
			case 2:i=5;break;
			case 3:i=3;break;
			case 4:i=4;break;
			default:i=0;break;
			}
			   }break;
		case 3:{                                                       //�޸�
			amend();
			cin>>i;
			switch(i)
			{
			case 1:i=3;break;
			case 2:i=5;break;
			case 3:i=2;break;
			case 4:i=4;break;
			default:i=0;break;
			}
			   }break;
		case 4:{                                                     //ɾ��
			cancel();
			cin>>i;
			switch(i)
			{
			case 1:i=4;break;
			case 2:i=5;break;
			case 3:i=2;break;
			case 4:i=3;break;
			default:i=0;break;
			}
			   }break; 
		case 5:{                                                    //��ҳ
			look2();
			cin>>i;
			switch(i)
			{
			case 1:i=1;break;
			case 2:i=2;break;
			case 3:i=3;break;
			case 4:i=4;break;
			default:i=0;break;
			}
			   }break;
		default:{
			outfile_menu();
			cout<<"���ڹرճ���..."<<endl;
			Sleep(2000);
			exit(1);
				} break;
		}
	}
	return 0;
}