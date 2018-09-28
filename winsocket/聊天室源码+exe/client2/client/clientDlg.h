
// clientDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
//////////////////////////自定义//////////////////////
#define MAX_USER 64
const char PERSON[11] = "####PERSON";//识别私聊用户 1
const char MESSAGE[11] = "###MESSAGE";//识别私聊消息 2
const char RADIO[11] = "#####RADIO";//识别群发消息 3
const char ID[11] = "########ID"; //识别登入用户名 4
const char PASSWORD[11] = "##PASSWORD"; //识别密码 5
const char FFILE[11] = "#####FFILE"; //识别发送消息 6
const char USERLIST[11] = "##USERLIST"; //识别聊天室所有用户 7
const char LOGIN[11] = "######TURE";//认证成功
const char FULL[11] = "######FULL";//人数已满
//字符串加工
char * StringProcess(char *str1,char *str2,const char * command);
char * StringAnalysis(char *str1, char *command);//解析口令
int CommandCategory(char *command);//口令类别
int IsState(char *name);//判断用户是否在线
char* GetFileName(char *name); //接受文件名

typedef struct user
{
	int state;
	char name[30];
}User,*PUser;

typedef struct userallname//保存其他用户信息
{
	int count;
	User u[MAX_USER];
}UserAll,*PUserAll;
void CreateUserAll(PUserAll ua);//创建
int UpdateUserName(PUserAll ua,char *name);//更新用户状态
void AddUser(PUserAll ua, char *name);//添加用户(设置state=0---只添加用户名)
int CountAdd(PUserAll ua, char *name);//密码错误计数3次禁止登录
bool FindUser(PUserAll ua, char *name);//查找用户
bool IsBan(PUserAll ua, char *name);//判断是否被禁止登录
void initState(PUserAll ua, char *name);//计数清零
///////////////////////////////////////////////////

// CclientDlg 对话框
class CclientDlg : public CDialogEx
{
// 构造
public:
	CclientDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	// 用户名
	CEdit c_username;
	// 密码
	CEdit c_userpassword;
	// 服务端IP
	CIPAddressCtrl s_socketIP;
	// 端口号
	CEdit s_port;
	// 登录按钮
	CButton b_login;
	// 用户列表
	CListBox c_listuser;
	// 发送对象
	CEdit s_senduser;
	// 日志消息
	CEdit c_log;
	// 发送消息
	CEdit c_message;
	// 私聊按钮
	CButton b_senduser;
	// 群发
	CButton b_senduserall;
	// 套接字
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
