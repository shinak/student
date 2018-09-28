
// clientDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
//////////////////////////�Զ���//////////////////////
#define MAX_USER 64
const char PERSON[11] = "####PERSON";//ʶ��˽���û� 1
const char MESSAGE[11] = "###MESSAGE";//ʶ��˽����Ϣ 2
const char RADIO[11] = "#####RADIO";//ʶ��Ⱥ����Ϣ 3
const char ID[11] = "########ID"; //ʶ������û��� 4
const char PASSWORD[11] = "##PASSWORD"; //ʶ������ 5
const char FFILE[11] = "#####FFILE"; //ʶ������Ϣ 6
const char USERLIST[11] = "##USERLIST"; //ʶ�������������û� 7
const char LOGIN[11] = "######TURE";//��֤�ɹ�
const char FULL[11] = "######FULL";//��������
//�ַ����ӹ�
char * StringProcess(char *str1,char *str2,const char * command);
char * StringAnalysis(char *str1, char *command);//��������
int CommandCategory(char *command);//�������
int IsState(char *name);//�ж��û��Ƿ�����
char* GetFileName(char *name); //�����ļ���

typedef struct user
{
	int state;
	char name[30];
}User,*PUser;

typedef struct userallname//���������û���Ϣ
{
	int count;
	User u[MAX_USER];
}UserAll,*PUserAll;
void CreateUserAll(PUserAll ua);//����
int UpdateUserName(PUserAll ua,char *name);//�����û�״̬
void AddUser(PUserAll ua, char *name);//����û�(����state=0---ֻ����û���)
int CountAdd(PUserAll ua, char *name);//����������3�ν�ֹ��¼
bool FindUser(PUserAll ua, char *name);//�����û�
bool IsBan(PUserAll ua, char *name);//�ж��Ƿ񱻽�ֹ��¼
void initState(PUserAll ua, char *name);//��������
///////////////////////////////////////////////////

// CclientDlg �Ի���
class CclientDlg : public CDialogEx
{
// ����
public:
	CclientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	// �û���
	CEdit c_username;
	// ����
	CEdit c_userpassword;
	// �����IP
	CIPAddressCtrl s_socketIP;
	// �˿ں�
	CEdit s_port;
	// ��¼��ť
	CButton b_login;
	// �û��б�
	CListBox c_listuser;
	// ���Ͷ���
	CEdit s_senduser;
	// ��־��Ϣ
	CEdit c_log;
	// ������Ϣ
	CEdit c_message;
	// ˽�İ�ť
	CButton b_senduser;
	// Ⱥ��
	CButton b_senduserall;
	// �׽���
	SOCKET c_socket;
	void AppendLog(CString info);
	void SetUser(CString info);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton6();
};
