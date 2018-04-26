
// MFCserverDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFCserverDlg �Ի���
class CMFCserverDlg : public CDialogEx
{
// ����
public:
	CMFCserverDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCSERVER_DIALOG };

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
	CEdit m_ctrlPort;
	CButton m_ctrlServer;
	CEdit m_ctrlLog;
	void AppendLog(CString info);
	// ���������׽���
	SOCKET m_Socket;
	afx_msg void OnBnClickedButton1();
};
