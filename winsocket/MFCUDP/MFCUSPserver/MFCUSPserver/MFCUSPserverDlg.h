
// MFCUSPserverDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "socclient.h"


// CMFCUSPserverDlg �Ի���
class CMFCUSPserverDlg : public CDialogEx
{
// ����
public:
	CMFCUSPserverDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCUSPSERVER_DIALOG };

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
	// ���÷������˿ں�
	CEdit m_ctrlPort;
	// ����˳�ʼ��
	CButton m_ctrlServer;
	// Ⱥ����Ϣ
	CButton m_ctrlGroupSend;
	// ���͵���Ϣ
	CEdit m_ctrlMessage;
	// ��ʾ���ա����͵���Ϣ����־
	CEdit m_ctrlLog;
	void AppendLog(CString info);
	
	afx_msg void OnBnClickedButton2();
	// �ͻ����û���Ϣ��
	SocClient m_Head;
	afx_msg void OnBnClickedButton1();
	// ������׽���
	SOCKET m_Socket;
};
