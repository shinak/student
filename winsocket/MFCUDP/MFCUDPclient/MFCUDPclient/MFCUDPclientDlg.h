
// MFCUDPclientDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CMFCUDPclientDlg �Ի���
class CMFCUDPclientDlg : public CDialogEx
{
// ����
public:
	CMFCUDPclientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCUDPCLIENT_DIALOG };

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
	// Ҫ���ӵķ����IP
	CIPAddressCtrl m_ctrlServerIP;
	// Ҫ���ӵķ������˿�
	CEdit m_ctrlPort;
	// ��ʼ���ͻ���
	CButton m_ctrlClient;
	// ��ʾ�շ�����Ϣ��¼����־
	CEdit m_ctrlLog;
	// ������Ϣ
	CEdit m_ctrlMessage;
	CButton m_ctrlSend;
	afx_msg void OnBnClickedButton1();
	SOCKET m_Socket;
	void AppendLog(CString info);
	CEdit m_ctrlName;
	struct client
	{
		int i;//�ͻ���˳��
		SOCKET soc;//�׽���
		struct sockaddr_in ca;//�ͷ��˵�ַ
	}c;
	afx_msg void OnBnClickedButton2();
};
