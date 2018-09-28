#include "StdAfx.h"
#include "Cclient.h"

Cclient::Cclient(void)
{
	int i;
	char ch;
	count = 0;
	FILE *fp = fopen("./users/user.txt","r");
	if (fp != NULL) //������user.txt�ļ�
	{
		do{
			i=0;
			do{
				ch = fgetc(fp);
				if(ch==EOF) break;//�ļ�Ϊ��
				users[count].object[i] = ch;
				i++;
			}while(ch != '@');
			if(ch==EOF) break;//�ļ�Ϊ��
			users[count].object[i-1] = '\0';
			do
			{
				ch = fgetc(fp);
			}while(ch =='@');
			i=0;
			do
			{
				users[count].password[i]=ch;
				i++;
				ch = fgetc(fp);
			}while(ch != '@');
			users[count].password[i] = '\0';
			users[count].state = 0;//����
			count++;
			do
			{
				ch = fgetc(fp);
			}while(ch =='@');
		}while(ch!=EOF);
	}
	else if(fp == NULL)
	{
		fp = fopen("./users/user.txt","w");
	}
	fclose(fp);
}


Cclient::~Cclient(void)//�����û����ݸ��Ǿ��û�����
{
}

int Cclient::GetCount()//������
{
	return count;
}

int Cclient::IsUser(char *name, char *password, int socket)  // 1~128  /  -255  / -128
{
	for (int i=0; i<count; i++)
	{
		if(strcmp(users[i].object,name) == 0)//�û�����ȷ
		{
			if(strcmp(users[i].password,password) == 0)//������ȷ
			{
				if(users[i].state != 0)//�ص�
				{
					return -246;
				}
				else
				{
					users[i].state = socket; //�����û�����
					return i + 1; //���ص�ǰ�û�λ�� 1~128
				}
			}
			else//�������
			{
				return -255;  //���������� -255
			}
		}
	}
	//û��ƥ�䵽�û����ж�Ϊ���û�,��Ϊ���û���������������Ϣ����
	if (count < MAX_PERSON)  //����δ��
	{
		strcpy(users[count].object, name); //����û�
		strcpy(users[count].password, password);  //�������
		users[count].state = socket;  //���û�һ������
		if (strlen(users[count].object)>0)
		{
			char path[30]="./chat/";
			char filename[20]={0};
			strcpy(filename, users[count].object);
			strcat(filename, ".txt");
			strcat(path, filename);
			FILE *chat = fopen(path, "w+"); //����"./chat/....txt"
			fclose(chat);
			memset(path, '\0', sizeof(path));//����ַ�����
			memset(filename, '\0', sizeof(filename));//����ַ�����
			strcpy(path, "./radio/");
			strcpy(filename, users[count].object);
			strcat(filename, ".txt");
			strcat(path, filename);
			FILE *radio = fopen(path,"w+");//����"./radio/....txt"
			fclose(radio);
		}
		

		count++;  //������1
		return count;  //�����µ�ǰ�û�λ�� 1~128
	}
	else  //��������
	{
		return -128;  //�������� -128
	}
}


bool Cclient::DeleteUser(char *name)
{
	for (int i=0; i<count; i++)
	{
		if(strcmp(users[i].object,name) == 0)//�û�����ȷ
		{
			char path[30]="./chat/";
			char filename[20]={0};
			strcpy(filename, users[i].object);
			strcat(filename, ".txt");
			strcat(path, filename);
			remove(path);//�Ƴ� "./chat/....txt"
			memset(path, '\0', sizeof(path));//����ַ�����
			memset(filename, '\0', sizeof(filename));//����ַ�����
			strcpy(path, "./radio/");
			strcpy(filename, users[i].object);
			strcat(filename, ".txt");
			strcat(path, filename);
			remove(path);//�Ƴ� "./radio/....txt"

			for (int j=i; j<count; j++)  //ɾ��
			{
				strcpy(users[j].object, users[j+1].object);//�����û���
				strcpy(users[j].password, users[j+1].password);//��������
				users[j].state = users[j+1].state;//����״̬
			}
			count--;
			return true;  //�ɹ�
		}
	}
	return false;  //�û������ڣ���ʧ�ܣ�BUG��
}

bool Cclient::DeleteUser(int n)  //���û�λ��
{
	for (int i=n-1; i<count; i++)  //ɾ��
	{
		
		if(i == n-1)//ɾ�����û������ļ�
		{
			char path[30]="./chat/";
			char filename[20]={0};
			strcpy(filename, users[n-1].object);
			strcat(filename, ".txt");
			strcat(path, filename);
			remove(path);//�Ƴ� "./chat/....txt"
			memset(path, '\0', sizeof(path));//����ַ�����
			memset(filename, '\0', sizeof(filename));//����ַ�����
			strcpy(path, "./radio/");
			strcpy(filename, users[n-1].object);
			strcat(filename, ".txt");
			strcat(path, filename);
			remove(path);//�Ƴ� "./radio/....txt"
		}
		


		strcpy(users[i].object, users[i+1].object);//�����û���
		strcpy(users[i].password, users[i+1].password);//��������
		users[i].state = users[i+1].state;//����״̬
	}
	return true;  //�ɹ�
}

int Cclient::IsState(char *name)
{
	for (int i=0; i<count; i++)
	{
		if(strcmp(users[i].object,name) == 0)//�û�����ȷ
		{
			return users[i].state;  //����״̬
		}
	}
	return -123; //�û�������
}


void Cclient::StateChange(int socket)
{
	for (int i=0; i<count; i++)
	{
		if (users[i].state == socket)  //�������׽�����ͬ
		{
			users[i].state = 0;
		}
	}
}


int Cclient::UpdateUserAll()
{
	FILE *fp = fopen("./users/user.txt","w");
	for (int i = 0; i<count; i++)
	{
		fputs(users[i].object,fp);//д���û�
		fputs("@@@@@",fp);//����
		fputs(users[i].password,fp);//д������
		fputs("@@@@@\n",fp);//����
	}
	fclose(fp);
	return count;
}

Infor Cclient::FindUser(int socket)//BUG ֻ�ܲ��������ߵ��û�
{
	Infor n;
	strcpy(n.object, "");
	strcpy(n.password, "");
	n.state =  0;
	for (int i=0; i<count; i++)
	{
		if(users[i].state == socket)//�׽�����ͬ
		{
			strcpy(n.object, users[i].object);
			strcpy(n.password, users[i].password);
			n.state =  users[i].state;
			break;
		}
	}
	return n;
}
Infor Cclient::FindUser(char *name)
{
	Infor n;
	strcpy(n.object, "");
	strcpy(n.password, "");
	n.state =  0;
	for (int i=0; i<count; i++)
	{
		if(strcmp(users[i].object, name) == 0)//�û�����ͬ
		{
			strcpy(n.object, users[i].object);
			strcpy(n.password, users[i].password);
			n.state =  users[i].state;
			return n;
		}
	}
	
	return n;
}



ListInfor Cclient::FindAll()
{
	ListInfor n;
	
	for (n.count = 0; n.count<count; n.count++)
	{
		n.users[n.count] = users[n.count];
	}
	return n;
}

ListInfor Cclient::FindDownUser()
{
	ListInfor n;
	n.count = 0;
	for (int i=0; i<count; i++)
	{
		if(IsState(users[i].object) == 0)
		{
			n.users[i] = users[i];
			n.count++;
		}
	}
	return n;
}

ListInfor Cclient::FindOnlineUser()
{
	ListInfor n;
	for (int i=0; i<count; i++)
	{
		if(IsState(users[i].object) != 0)
		{
			n.users[i] = users[i];
			n.count++;
		}
	}
	return n;
}


int Cclient::RadioMessage(char *message)
{
	char radiomsg[1024]={0};
	strcpy(radiomsg,message);
	for (int i=0; i<count; i++)
	{
		if(users[i].state == 0)//�����û�д��
		{
			char path[30]="./radio/";
			char filename[20]={0};
			strcpy(filename, users[i].object);
			strcat(filename, ".txt");
			strcat(path, filename);
			FILE *radio = fopen(path, "r+"); //����"./radio/....txt"
			fputs(radiomsg,radio);
			fputs("@@@\n",radio);
			fclose(radio);
		}
	}
	return 1;
}


int CreateListInfor(PListInfor user)
{
	user->count = 0;
	return user->count;
}
int AddNewUser(PListInfor u, Infor n)
{
	int i;
	for (i=0; i<NEW_PERSON; i++)
	{
		if(u->users[i].state == n.state)//�׽������
		{
			memset( u->users[i].password, '\0' ,sizeof(u->users[i].password) );//��ʼ��
			strcpy(u->users[i].password, n.password);
			return i;
		}
	}//��ƥ��
	u->users[u->count].state = n.state;//����Ϊ��
	memset( u->users[u->count].object, '\0' ,sizeof(u->users[u->count].object) );//��ʼ��
	strcpy(u->users[u->count].object, n.object);//����Ϊ��
	u->count++;//ע���е��û���1
	return u->count;
	/*return -1;*/
}
void DeleteNewUser(PListInfor u, int count)
{
	memset(u->users[count].object, '\0', sizeof(u->users[count].object));
	memset(u->users[count].password, '\0', sizeof(u->users[count].password));
	u->users[count].state = 0;
	u->count--;
}
