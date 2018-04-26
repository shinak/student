
// MFCclientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCclient.h"
#include "MFCclientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCclientDlg �Ի���




CMFCclientDlg::CMFCclientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCclientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCclientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS1, m_ctrlSeverIP);
	DDX_Control(pDX, IDC_BUTTON1, m_ctrlClient);
	DDX_Control(pDX, IDC_EDIT2, m_ctrlLog);
	DDX_Control(pDX, IDC_BUTTON2, m_ctrlSend);
	DDX_Control(pDX, IDC_EDIT3, m_ctrlMsg);
	DDX_Control(pDX, IDC_EDIT4, m_ctrlPort);
}

BEGIN_MESSAGE_MAP(CMFCclientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS1, &CMFCclientDlg::OnIpnFieldchangedIpaddress1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCclientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCclientDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCclientDlg ��Ϣ�������

BOOL CMFCclientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(1,1),&wsaData) != 0)
	{
		AfxMessageBox("��ʼ����̬���ӿ�ʧ��!");
		return FALSE;
	}
	//���ö˿ںų�ʼֵ
	m_ctrlPort.SetWindowText("9000");

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCclientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCclientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCclientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCclientDlg::OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CMFCclientDlg::AppendLog(CString info)
{
	m_ctrlLog.SetSel(-1);
	m_ctrlLog.ReplaceSel((LPCTSTR)info);
	m_ctrlLog.ShowScrollBar(SB_VERT,TRUE);
	m_ctrlLog.SetSel(-1);
}

void CMFCclientDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString txt;
	m_ctrlClient.GetWindowText(txt);//��ȡ��ť�ϵ��ı�
	if(txt == "����")
	{
		//�����׽���
		m_socket = socket(AF_INET,SOCK_STREAM,0);

		CString txtPort;
		m_ctrlPort.GetWindowText(txtPort);	//��ȡ�˿ںŵ��ı�
		int port = atoi(txtPort);			//ת���������˿�

		BYTE nFild[4];
		CString txtServerIP;
		m_ctrlSeverIP.GetAddress(nFild[0],nFild[1],nFild[2],nFild[3]);//��ȡ������IP��ַ
		txtServerIP.Format("%d.%d.%d.%d",nFild[0],nFild[1],nFild[2],nFild[3]);

		struct sockaddr_in sa;				//����Ҫ���ӵķ�������ַ
		sa.sin_family = AF_INET;			//��ַ����
		sa.sin_port = htons(port);			//����˿�
		sa.sin_addr.s_addr = inet_addr(txtServerIP);	//��������ַ

		//���ӷ�����
		if(connect(m_socket,(struct sockaddr *)&sa,sizeof(sa)) == SOCKET_ERROR)
		{
			AfxMessageBox("��������ȷ��IP��ַ!");
			return ;
		}
		else
		{
			//���ӳɹ�
			m_ctrlClient.SetWindowText("�Ͽ�");//�����Ӱ�ť�ĳɶϿ���ť
			m_ctrlPort.EnableWindow(FALSE);//��ֹ���Ķ˿ں�
			m_ctrlSeverIP.EnableWindow(FALSE);//��ֹ����IP��
			AppendLog("���������ӳɹ�\n");//��ʾ��־
		}
	}
	else
		{
			closesocket(m_socket);
			m_ctrlPort.EnableWindow(TRUE);		//�����޸Ķ˿ں�
			m_ctrlClient.SetWindowText("����");	//���رհ�ť�ĳ����Ӱ�ť
			AppendLog("�ͻ����ѶϿ�����!\n");		//��ʾ��־
		}
}


void CMFCclientDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString txt;
	m_ctrlSend.GetWindowText(txt);//��ȡ��ť�ϵ��ı�
	if(txt == "����")
	{
		CString msg;
		m_ctrlMsg.GetWindowTextA(msg);
		m_ctrlMsg.SetWindowTextA(NULL);
		if(send(m_socket,msg,1024,0) == SOCKET_ERROR)
		{
			AppendLog("����ʧ��!\n");
			return ;
		}
		else
		{
			CString info;
			info.Format("������Ϣ:%s\n",msg);
			AppendLog(info);
		}
	}
}
