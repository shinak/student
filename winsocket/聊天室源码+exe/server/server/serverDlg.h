
// serverDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "cclient.h"
//////////////////////////自定义////////////////////
#define MAX_LISTENSIZE 64
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
char* GetFileName(char *name);
//////////////////////////////////////////////////

// CserverDlg 对话框
class CserverDlg : public CDialogEx
{
// 构造
public:
	CserverDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SERVER_DIALOG };

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
	// 服务端端口号
	CEdit s_port;
	// 消息日志
	CEdit s_messagelog;
	CEdit s_message;
	// 删除成员
	CButton b_delperson;
	// 启动服务器
	CButton b_start;
	// 选择文件
	CButton b_choose;
	// 群发文件
	CButton b_sendfile;
	// 群发消息
	CButton b_sendmessage;
	void AppendLog(CString info);
	afx_msg void OnBnClickedButton1();
	// 服务端套接字
	SOCKET s_socket;
	// 所有用户
	Cclient p_userall;
	// 用户列表
	CListBox s_userlist;
	CEdit d_user;
	void DeleteUserName(CString info);
	afx_msg void OnLbnSelchangeList3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
};
