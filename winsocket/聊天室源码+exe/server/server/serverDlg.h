
// serverDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "cclient.h"
//////////////////////////�Զ���////////////////////
#define MAX_LISTENSIZE 64
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
char* GetFileName(char *name);
//////////////////////////////////////////////////

// CserverDlg �Ի���
class CserverDlg : public CDialogEx
{
// ����
public:
	CserverDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SERVER_DIALOG };

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
	// ����˶˿ں�
	CEdit s_port;
	// ��Ϣ��־
	CEdit s_messagelog;
	CEdit s_message;
	// ɾ����Ա
	CButton b_delperson;
	// ����������
	CButton b_start;
	// ѡ���ļ�
	CButton b_choose;
	// Ⱥ���ļ�
	CButton b_sendfile;
	// Ⱥ����Ϣ
	CButton b_sendmessage;
	void AppendLog(CString info);
	afx_msg void OnBnClickedButton1();
	// ������׽���
	SOCKET s_socket;
	// �����û�
	Cclient p_userall;
	// �û��б�
	CListBox s_userlist;
	CEdit d_user;
	void DeleteUserName(CString info);
	afx_msg void OnLbnSelchangeList3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
};
