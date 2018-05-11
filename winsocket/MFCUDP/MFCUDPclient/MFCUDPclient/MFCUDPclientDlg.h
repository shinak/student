
// MFCUDPclientDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CMFCUDPclientDlg 对话框
class CMFCUDPclientDlg : public CDialogEx
{
// 构造
public:
	CMFCUDPclientDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCUDPCLIENT_DIALOG };

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
	// 要连接的服务端IP
	CIPAddressCtrl m_ctrlServerIP;
	// 要连接的服务器端口
	CEdit m_ctrlPort;
	// 初始化客户端
	CButton m_ctrlClient;
	// 显示收发的消息记录和日志
	CEdit m_ctrlLog;
	// 发送消息
	CEdit m_ctrlMessage;
	CButton m_ctrlSend;
	afx_msg void OnBnClickedButton1();
	SOCKET m_Socket;
	void AppendLog(CString info);
	CEdit m_ctrlName;
	struct client
	{
		int i;//客户端顺序
		SOCKET soc;//套接字
		struct sockaddr_in ca;//客服端地址
	}c;
	afx_msg void OnBnClickedButton2();
};
