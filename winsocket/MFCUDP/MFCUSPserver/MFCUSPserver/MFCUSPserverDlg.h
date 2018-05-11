
// MFCUSPserverDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "socclient.h"


// CMFCUSPserverDlg 对话框
class CMFCUSPserverDlg : public CDialogEx
{
// 构造
public:
	CMFCUSPserverDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCUSPSERVER_DIALOG };

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
	// 设置服务器端口号
	CEdit m_ctrlPort;
	// 服务端初始化
	CButton m_ctrlServer;
	// 群发消息
	CButton m_ctrlGroupSend;
	// 发送的消息
	CEdit m_ctrlMessage;
	// 显示接收、发送的消息和日志
	CEdit m_ctrlLog;
	void AppendLog(CString info);
	
	afx_msg void OnBnClickedButton2();
	// 客户端用户信息表
	SocClient m_Head;
	afx_msg void OnBnClickedButton1();
	// 服务端套接字
	SOCKET m_Socket;
};
