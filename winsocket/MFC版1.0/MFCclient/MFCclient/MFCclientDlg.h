
// MFCclientDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CMFCclientDlg �Ի���
class CMFCclientDlg : public CDialogEx
{
// ����
public:
	CMFCclientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCCLIENT_DIALOG };

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
	// Ҫ���ӵķ����IP
	CIPAddressCtrl m_ctrlSeverIP;
	// ���ӷ����
	CButton m_ctrlClient;
	CEdit m_ctrlLog;
	CButton m_ctrlSend;
	CEdit m_ctrlMsg;
	afx_msg void OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_ctrlPort;
	void AppendLog(CString info);
	afx_msg void OnBnClickedButton1();
	// �ͻ����׽���
	SOCKET m_socket;
	afx_msg void OnBnClickedButton2();
};
