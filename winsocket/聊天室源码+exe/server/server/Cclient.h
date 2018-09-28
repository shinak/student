#pragma once
#define MAX_PERSON 128
#define NEW_PERSON 64
typedef struct information
{
	int state;  //离线状态为0 在线为套接字
	char object[15];  //用户名
	char password[25];  //密码
}Infor,*PInfor;

typedef struct ArrayListInfor
{
	int count;
	Infor users[NEW_PERSON];
}ListInfor,*PListInfor;
int CreateListInfor(PListInfor user);
int AddNewUser(PListInfor u, Infor n);
void DeleteNewUser(PListInfor u, int count);

class Cclient
{
private:
	int count;
	Infor users[MAX_PERSON];//顺序存储
public:
	Cclient(void);
	~Cclient(void);
	int GetCount();
	//添加新用户（在线用户）--判断用户名是否重复
	int IsUser(char *name, char *password, int socket);//完整信息
	//删除用户
	bool DeleteUser(char *name);  //按用户名
	bool DeleteUser(int n);  //按用户socket
	//转发离线消息
	//判断用户状态
	int IsState(char *name);
	//用户下线(在线->离线)
	void StateChange(int socket);
	//更新用户信息到txt文件
	int UpdateUserAll();
	//通过套接字查找在线的用户
	Infor FindUser(int socket);
	//通过用户名查找用户
	Infor FindUser(char *name);
	//查找所有用户
	ListInfor FindAll();
	//查找所有离线用户
	ListInfor FindDownUser();
	//查找所有在线用户
	ListInfor FindOnlineUser();
	//写入离线消息
	int RadioMessage(char *message);
};

