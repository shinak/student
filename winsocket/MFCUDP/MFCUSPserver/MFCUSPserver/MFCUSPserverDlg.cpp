
// MFCUSPserverDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCUSPserver.h"
#include "MFCUSPserverDlg.h"
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


// CMFCUSPserverDlg �Ի���




CMFCUSPserverDlg::CMFCUSPserverDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCUSPserverDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCUSPserverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ctrlPort);
	DDX_Control(pDX, IDC_BUTTON2, m_ctrlServer);
	DDX_Control(pDX, IDC_BUTTON1, m_ctrlGroupSend);
	DDX_Control(pDX, IDC_EDIT3, m_ctrlMessage);
	DDX_Control(pDX, IDC_EDIT2, m_ctrlLog);
}

BEGIN_MESSAGE_MAP(CMFCUSPserverDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCUSPserverDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCUSPserverDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCUSPserverDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCUSPserverDlg ��Ϣ�������

BOOL CMFCUSPserverDlg::OnInitDialog()
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
		AfxMessageBox("��ʼ����̬���ӿ�ʧ��!\n");
		return FALSE;
	}
	//���ö˿ں�
	m_ctrlPort.SetWindowText("8000");


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCUSPserverDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCUSPserverDlg::OnPaint()
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
HCURSOR CMFCUSPserverDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCUSPserverDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void CMFCUSPserverDlg::AppendLog(CString info)
{
	m_ctrlLog.SetSel(-1);//����궨λ����־��ĩβ
	m_ctrlLog.ReplaceSel((LPCTSTR)info);//�����µ���־����
	m_ctrlLog.ShowScrollBar(SB_VERT,TRUE);//��ʾ������
	m_ctrlLog.SetSel(-1);//����궨λ����־��ĩβ
}

void recvthread(void *p)
{
	char recvmsg[100]={0};
	char resend[100]={0};
	char sendmsg[100]={0};
	CString info;

	CMFCUSPserverDlg * pDlg = (CMFCUSPserverDlg *)p;

	client c;//���տͻ����û���Ϣ

	sockaddr_in ca;
	int len=sizeof(ca);

	while(recvfrom(pDlg->m_Socket,recvmsg,100,0,(sockaddr *)&ca,&len) != SOCKET_ERROR)
	{
		c.soc = pDlg->m_Socket;
		c.ca = ca;
		c.i = 0;

		if(recvmsg[0] == '#')//�ж��Ƿ�Ϊ�û���
		{
			for(int i=0;i<strlen(recvmsg);i++)
				recvmsg[i] = recvmsg[i+1];//ȥ����#��
			strcpy(c.name,recvmsg);

			//printf("%s�Ѿ������Ϸ����������Կ�ʼ����\n",c.name);
			info.Format("%s�Ѿ������Ϸ����������Կ�ʼ����\n",c.name);
			pDlg->AppendLog(info);

			itoa(pDlg->m_Head.insert(c),sendmsg,10);

			sendto(pDlg->m_Socket,sendmsg,100,0,(sockaddr*)&ca,sizeof(ca));//���͸ÿͻ����û�����
		}
		else
		{
			//ֻ�ܽ���99999���ͻ��ˣ����Ż�
			c.i  = recvmsg[4]-48 +(recvmsg[3] -48)*10+(recvmsg[2] -48)+(recvmsg[1] -48)*1000+(recvmsg[0] -48)*10000;
			//��ȥ������Ϣ���û������ַ�
			for(int i=0;i<100;i++)
				recvmsg[i] = recvmsg[i+5];
			//printf("%s˵%s\n",h.findClient(c),recvmsg);
			info.Format("%s˵:%s\n",pDlg->m_Head.findClient(c),recvmsg);
			pDlg->AppendLog(info);

			//ת��
			client *s;
			for(int n=1;(s = pDlg->m_Head.find(n)) != NULL;n++)
			{
				if(s->i != c.i)
				{
					strcpy(resend,pDlg->m_Head.findClient(c));
					strcat(resend,":");
					strcat(resend,recvmsg);
					sendto(pDlg->m_Socket,resend,100,0,(sockaddr*)&s->ca,sizeof(s->ca));
					
					resend[0] = NULL;
				}
			}	
		}
	}
	
	info.Format("����ʧ��:%d\n",WSAGetLastError());
	pDlg->AppendLog(info);

}

void CMFCUSPserverDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString txt;
	m_ctrlServer.GetWindowText(txt);	//��ȡ��ť�ϵ��ı�
	if (txt == "����")
	{
		//�����׽���
		m_Socket = socket(AF_INET,SOCK_DGRAM,0);

		CString txtPort;
		m_ctrlPort.GetWindowText(txtPort);	//��ȡ�˿ںŵ��ı�
		int port = atoi(txtPort);			//ת���������˿�

		struct sockaddr_in sa;				//�����������ַ
		sa.sin_family = AF_INET;			//��ַ����
		sa.sin_port = htons(port);			//����˿�
		sa.sin_addr.s_addr = INADDR_ANY;	//������ַ

		 //�󶨷�����
		if (bind(m_Socket,(struct sockaddr *)&sa,sizeof(sa)) == SOCKET_ERROR)
		{
			AfxMessageBox("�˿ںű�ռ��!");
			return;
		}
		//����������������ɹ�
		m_ctrlPort.EnableWindow(FALSE);		//��ֹ�޸Ķ˿ں�
		m_ctrlServer.SetWindowText("ֹͣ");	//��������ť�ĳ�ֹͣ��ť
		AppendLog("�����������ɹ�!\n");		//��ʾ��־
		
		_beginthread(recvthread,0,this);
	}
	else
	{
		closesocket(m_Socket);
		m_ctrlPort.EnableWindow(TRUE);		//�����޸Ķ˿ں�
		m_ctrlServer.SetWindowText("����");	//��ֹͣ��ť�ĳ�������ť
		AppendLog("��������ֹͣ!\n");		//��ʾ��־
	}
}


void CMFCUSPserverDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString txt;
	CString message;
	CString info;
	m_ctrlGroupSend.GetWindowText(txt);

	char sendmsg[100] = {0};
	if(txt == "Ⱥ��")
	{
		char msgupdate[100] = "ϵͳ:";//�ӹ���Ϣ
		client *c;
		int i=1;
		//gets(sendmsg);
		m_ctrlMessage.GetWindowText(message);
		m_ctrlMessage.SetWindowText(NULL);
		strcpy(sendmsg,message);

		strcat(msgupdate,sendmsg);

		info.Format("Ⱥ���ɹ�!\n");
		AppendLog(info);

		while((c = m_Head.find(i)) != NULL)
		{
			sendto(m_Socket,msgupdate,100,0,(sockaddr*)&c->ca,sizeof(c->ca));
			i++;
		}
		//msgupdate[0]=NULL;
	}

}
