
// MFCclientDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CMFCclientDlg 对话框
class CMFCclientDlg : public CDialogEx
{
// 构造
public:
	CMFCclientDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCCLIENT_DIALOG };

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
	// 要连接的服务端IP
	CIPAddressCtrl m_ctrlSeverIP;
	// 连接服务端
	CButton m_ctrlClient;
	CEdit m_ctrlLog;
	CButton m_ctrlSend;
	CEdit m_ctrlMsg;
	afx_msg void OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_ctrlPort;
	void AppendLog(CString info);
	afx_msg void OnBnClickedButton1();
	// 客户端套接字
	SOCKET m_socket;
	afx_msg void OnBnClickedButton2();
};
