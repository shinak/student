#pragma once
#define MAX_PERSON 128
#define NEW_PERSON 64
typedef struct information
{
	int state;  //����״̬Ϊ0 ����Ϊ�׽���
	char object[15];  //�û���
	char password[25];  //����
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
	Infor users[MAX_PERSON];//˳��洢
public:
	Cclient(void);
	~Cclient(void);
	int GetCount();
	//������û��������û���--�ж��û����Ƿ��ظ�
	int IsUser(char *name, char *password, int socket);//������Ϣ
	//ɾ���û�
	bool DeleteUser(char *name);  //���û���
	bool DeleteUser(int n);  //���û�socket
	//ת��������Ϣ
	//�ж��û�״̬
	int IsState(char *name);
	//�û�����(����->����)
	void StateChange(int socket);
	//�����û���Ϣ��txt�ļ�
	int UpdateUserAll();
	//ͨ���׽��ֲ������ߵ��û�
	Infor FindUser(int socket);
	//ͨ���û��������û�
	Infor FindUser(char *name);
	//���������û�
	ListInfor FindAll();
	//�������������û�
	ListInfor FindDownUser();
	//�������������û�
	ListInfor FindOnlineUser();
	//д��������Ϣ
	int RadioMessage(char *message);
};

