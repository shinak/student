
// MFCUDPclientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCUDPclient.h"
#include "MFCUDPclientDlg.h"
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


// CMFCUDPclientDlg �Ի���




CMFCUDPclientDlg::CMFCUDPclientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCUDPclientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCUDPclientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS1, m_ctrlServerIP);
	DDX_Control(pDX, IDC_EDIT1, m_ctrlPort);
	DDX_Control(pDX, IDC_BUTTON1, m_ctrlClient);
	DDX_Control(pDX, IDC_EDIT2, m_ctrlLog);
	DDX_Control(pDX, IDC_EDIT3, m_ctrlMessage);
	DDX_Control(pDX, IDC_BUTTON2, m_ctrlSend);
	DDX_Control(pDX, IDC_EDIT4, m_ctrlName);
}

BEGIN_MESSAGE_MAP(CMFCUDPclientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCUDPclientDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCUDPclientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCUDPclientDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCUDPclientDlg ��Ϣ�������

BOOL CMFCUDPclientDlg::OnInitDialog()
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
	m_ctrlPort.SetWindowText("8000");
	m_ctrlServerIP.SetAddress((BYTE)127,(BYTE)0,(BYTE)0,(BYTE)1);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCUDPclientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCUDPclientDlg::OnPaint()
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
HCURSOR CMFCUDPclientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCUDPclientDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}

void recvthread(void *p)
{
	CMFCUDPclientDlg * pDlg = (CMFCUDPclientDlg *)p;

	CString info;
	char recvmsg[100]={0};
	int len=sizeof(pDlg->c.ca);

	while(true)
	{
		int rval;
		rval=recvfrom(pDlg->c.soc,recvmsg,100,0,(sockaddr*)&pDlg->c.ca,&len);
		if(rval > 0)
		{
			//printf("%s\n",recvmsg);
			info.Format("%s\n",recvmsg);
			pDlg->AppendLog(info);
		}
		else
			break;
	}
}

void CMFCUDPclientDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString txt;
	m_ctrlClient.GetWindowText(txt);//��ȡ��ť�ϵ��ı�
	if(txt == "����")
	{
		//�����׽���
		m_Socket = socket(AF_INET,SOCK_DGRAM,0);

		CString txtPort;
		m_ctrlPort.GetWindowText(txtPort);	//��ȡ�˿ںŵ��ı�
		int port = atoi(txtPort);			//ת���������˿�

		BYTE nFild[4];
		CString txtServerIP;
		m_ctrlServerIP.GetAddress(nFild[0],nFild[1],nFild[2],nFild[3]);//��ȡ������IP��ַ
		txtServerIP.Format("%d.%d.%d.%d",nFild[0],nFild[1],nFild[2],nFild[3]);

		struct sockaddr_in sa;				//����Ҫ���ӵķ�������ַ
		sa.sin_family = AF_INET;			//��ַ����
		sa.sin_port = htons(port);			//����˿�
		sa.sin_addr.s_addr = inet_addr(txtServerIP);	//��������ַ

		//�����˷�������
		c.soc = m_Socket;
		c.ca = sa;
		int len = sizeof(c.ca);
		CString name;
		char recvmsg[100]={0};
		char sendmsg[100]={0};
		char sendname[100]="#";//�û�����ʾ��

		m_ctrlName.GetWindowText(name);
		strcpy(sendmsg,name);
		strcat(sendname,sendmsg);
		sendto(m_Socket,sendname,100,0,(sockaddr*)&sa,sizeof(sa));
		recvfrom(c.soc,recvmsg,100,0,(sockaddr*)&c.ca,&len);
		c.i = atoi(recvmsg);
		//���ӳɹ�
		m_ctrlClient.SetWindowText("ȡ��");//�����Ӱ�ť�ĳɶϿ���ť
		m_ctrlPort.EnableWindow(FALSE);//��ֹ���Ķ˿ں�
		m_ctrlServerIP.EnableWindow(FALSE);//��ֹ����IP��
		AppendLog("���������ӳɹ�\n");//��ʾ��־

		_beginthread(recvthread,0,this);
	}
	else
	{
		closesocket(m_Socket);
		m_ctrlPort.EnableWindow(TRUE);		//�����޸Ķ˿ں�
		m_ctrlClient.SetWindowText("����");	//���رհ�ť�ĳ����Ӱ�ť
		AppendLog("�ͻ����ѶϿ�����!\n");		//��ʾ��־
	}
}


void CMFCUDPclientDlg::AppendLog(CString info)
{
	m_ctrlLog.SetSel(-1);
	m_ctrlLog.ReplaceSel((LPCTSTR)info);
	m_ctrlLog.ShowScrollBar(SB_VERT,true);
	m_ctrlLog.SetSel(-1);
}


void CMFCUDPclientDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString info;
	CString message;
	CString txt;
	m_ctrlSend.GetWindowText(txt);
	m_ctrlMessage.GetWindowText(message);
	m_ctrlMessage.SetWindowText(NULL);

	if(txt == "����")
	{
		char sendmsg[100]={0};
		char sendnum[100]={0};
		strcpy(sendmsg,message);
		//�ͻ����û�����ת�����ַ���ʽ
		sendnum[0] = c.i / 10000 +48;
		sendnum[1] = c.i / 1000 +48;
		sendnum[2] = c.i / 100 +48;
		sendnum[3] = c.i / 10 +48;
		sendnum[4] = c.i % 10 +48;
		sendnum[5] = '\0';

		strcat(sendnum,sendmsg);//���û����к���Ϣһ�����͸������
		sendto(m_Socket,sendnum,100,0,(sockaddr*)&c.ca,sizeof(c.ca));
		//��ȥ������Ϣ���û������ַ�
		for(int i=0;i<100;i++)
			sendnum[i] = sendnum[i+5];
		info.Format("���ͳɹ�!\n");
		AppendLog(info);
	}
}
