#include "StdAfx.h"
#include "Cclient.h"

Cclient::Cclient(void)
{
	int i;
	char ch;
	count = 0;
	FILE *fp = fopen("./users/user.txt","r");
	if (fp != NULL) //本地有user.txt文件
	{
		do{
			i=0;
			do{
				ch = fgetc(fp);
				if(ch==EOF) break;//文件为空
				users[count].object[i] = ch;
				i++;
			}while(ch != '@');
			if(ch==EOF) break;//文件为空
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
			users[count].state = 0;//离线
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


Cclient::~Cclient(void)//将新用户数据覆盖旧用户数据
{
}

int Cclient::GetCount()//总人数
{
	return count;
}

int Cclient::IsUser(char *name, char *password, int socket)  // 1~128  /  -255  / -128
{
	for (int i=0; i<count; i++)
	{
		if(strcmp(users[i].object,name) == 0)//用户名正确
		{
			if(strcmp(users[i].password,password) == 0)//密码正确
			{
				if(users[i].state != 0)//重登
				{
					return -246;
				}
				else
				{
					users[i].state = socket; //离线用户上线
					return i + 1; //返回当前用户位数 1~128
				}
			}
			else//密码错误
			{
				return -255;  //密码错误代码 -255
			}
		}
	}
	//没有匹配到用户，判定为新用户,并为新用户创建保存离线消息链接
	if (count < MAX_PERSON)  //人数未满
	{
		strcpy(users[count].object, name); //添加用户
		strcpy(users[count].password, password);  //添加密码
		users[count].state = socket;  //新用户一定在线
		if (strlen(users[count].object)>0)
		{
			char path[30]="./chat/";
			char filename[20]={0};
			strcpy(filename, users[count].object);
			strcat(filename, ".txt");
			strcat(path, filename);
			FILE *chat = fopen(path, "w+"); //创建"./chat/....txt"
			fclose(chat);
			memset(path, '\0', sizeof(path));//清空字符数组
			memset(filename, '\0', sizeof(filename));//清空字符数组
			strcpy(path, "./radio/");
			strcpy(filename, users[count].object);
			strcat(filename, ".txt");
			strcat(path, filename);
			FILE *radio = fopen(path,"w+");//创建"./radio/....txt"
			fclose(radio);
		}
		

		count++;  //人数加1
		return count;  //返回新当前用户位数 1~128
	}
	else  //人数已满
	{
		return -128;  //人数已满 -128
	}
}


bool Cclient::DeleteUser(char *name)
{
	for (int i=0; i<count; i++)
	{
		if(strcmp(users[i].object,name) == 0)//用户名正确
		{
			char path[30]="./chat/";
			char filename[20]={0};
			strcpy(filename, users[i].object);
			strcat(filename, ".txt");
			strcat(path, filename);
			remove(path);//移除 "./chat/....txt"
			memset(path, '\0', sizeof(path));//清空字符数组
			memset(filename, '\0', sizeof(filename));//清空字符数组
			strcpy(path, "./radio/");
			strcpy(filename, users[i].object);
			strcat(filename, ".txt");
			strcat(path, filename);
			remove(path);//移除 "./radio/....txt"

			for (int j=i; j<count; j++)  //删除
			{
				strcpy(users[j].object, users[j+1].object);//覆盖用户名
				strcpy(users[j].password, users[j+1].password);//覆盖密码
				users[j].state = users[j+1].state;//覆盖状态
			}
			count--;
			return true;  //成功
		}
	}
	return false;  //用户不存在，或失败（BUG）
}

bool Cclient::DeleteUser(int n)  //按用户位置
{
	for (int i=n-1; i<count; i++)  //删除
	{
		
		if(i == n-1)//删除该用户聊天文件
		{
			char path[30]="./chat/";
			char filename[20]={0};
			strcpy(filename, users[n-1].object);
			strcat(filename, ".txt");
			strcat(path, filename);
			remove(path);//移除 "./chat/....txt"
			memset(path, '\0', sizeof(path));//清空字符数组
			memset(filename, '\0', sizeof(filename));//清空字符数组
			strcpy(path, "./radio/");
			strcpy(filename, users[n-1].object);
			strcat(filename, ".txt");
			strcat(path, filename);
			remove(path);//移除 "./radio/....txt"
		}
		


		strcpy(users[i].object, users[i+1].object);//覆盖用户名
		strcpy(users[i].password, users[i+1].password);//覆盖密码
		users[i].state = users[i+1].state;//覆盖状态
	}
	return true;  //成功
}

int Cclient::IsState(char *name)
{
	for (int i=0; i<count; i++)
	{
		if(strcmp(users[i].object,name) == 0)//用户名正确
		{
			return users[i].state;  //返回状态
		}
	}
	return -123; //用户不存在
}


void Cclient::StateChange(int socket)
{
	for (int i=0; i<count; i++)
	{
		if (users[i].state == socket)  //与下线套接字相同
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
		fputs(users[i].object,fp);//写入用户
		fputs("@@@@@",fp);//换行
		fputs(users[i].password,fp);//写入密码
		fputs("@@@@@\n",fp);//换行
	}
	fclose(fp);
	return count;
}

Infor Cclient::FindUser(int socket)//BUG 只能查找已在线的用户
{
	Infor n;
	strcpy(n.object, "");
	strcpy(n.password, "");
	n.state =  0;
	for (int i=0; i<count; i++)
	{
		if(users[i].state == socket)//套接字相同
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
		if(strcmp(users[i].object, name) == 0)//用户名相同
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
		if(users[i].state == 0)//离线用户写入
		{
			char path[30]="./radio/";
			char filename[20]={0};
			strcpy(filename, users[i].object);
			strcat(filename, ".txt");
			strcat(path, filename);
			FILE *radio = fopen(path, "r+"); //创建"./radio/....txt"
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
		if(u->users[i].state == n.state)//套接字相等
		{
			memset( u->users[i].password, '\0' ,sizeof(u->users[i].password) );//初始化
			strcpy(u->users[i].password, n.password);
			return i;
		}
	}//不匹配
	u->users[u->count].state = n.state;//不可为空
	memset( u->users[u->count].object, '\0' ,sizeof(u->users[u->count].object) );//初始化
	strcpy(u->users[u->count].object, n.object);//不可为空
	u->count++;//注册中的用户加1
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
