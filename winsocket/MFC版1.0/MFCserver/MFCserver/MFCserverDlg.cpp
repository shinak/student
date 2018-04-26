
// MFCserverDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCserver.h"
#include "MFCserverDlg.h"
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


// CMFCserverDlg �Ի���




CMFCserverDlg::CMFCserverDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCserverDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCserverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ctrlPort);
	DDX_Control(pDX, IDC_BUTTON1, m_ctrlServer);
	DDX_Control(pDX, IDC_EDIT2, m_ctrlLog);
}

BEGIN_MESSAGE_MAP(CMFCserverDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCserverDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCserverDlg ��Ϣ�������

BOOL CMFCserverDlg::OnInitDialog()
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
	m_ctrlPort.SetWindowText("9000");

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCserverDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCserverDlg::OnPaint()
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
HCURSOR CMFCserverDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CMFCserverDlg::AppendLog(CString info)
{
	m_ctrlLog.SetSel(-1);//����궨λ����־��ĩβ
	m_ctrlLog.ReplaceSel((LPCTSTR)info);//�����µ���־����
	m_ctrlLog.ShowScrollBar(SB_VERT,TRUE);//��ʾ������
	m_ctrlLog.SetSel(-1);//����궨λ����־��ĩβ
}

//���տͻ������ӵĶ��̺߳���
void serverThread(void *p)
{
	CMFCserverDlg * pDlg = (CMFCserverDlg *)p;
	struct sockaddr_in from;				//���ڽ��տͻ��˵�ַ
	int len = sizeof(from);
	do
	{
		//�ȴ��ͻ�������
		SOCKET soc = accept(pDlg->m_Socket, (struct sockaddr *)&from, &len);
		if (soc != INVALID_SOCKET)
		{
			CString info;

			info.Format("�յ�����%s�Ŀͻ�������\n", inet_ntoa(from.sin_addr));
			pDlg->AppendLog(info);

			while (true)
			{
				char msg[1024]={0};		//�������ݴ�ŵı���
				len = recv(soc,msg,1024,0);	//��������
				if (len == -1)
				{
					pDlg->AppendLog("�ͻ��˶Ͽ�����");
					break;
				}
				info.Format("�յ���Ϣ:%s\n", msg);
				pDlg->AppendLog(info);
				//����Ϣת���ؿͻ���
				send(soc, msg, 1024, 0);
			}
		}else
			break;
	}while(true);

}

void CMFCserverDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString txt;
	m_ctrlServer.GetWindowText(txt);	//��ȡ��ť�ϵ��ı�
	if (txt == "����")
	{
		//�����׽���
		m_Socket = socket(AF_INET,SOCK_STREAM,0);

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
		//���ü���
		listen(m_Socket,10);

		//����������������ɹ�
		m_ctrlPort.EnableWindow(FALSE);		//��ֹ�޸Ķ˿ں�
		m_ctrlServer.SetWindowText("ֹͣ");	//��������ť�ĳ�ֹͣ��ť
		AppendLog("�����������ɹ�!\n");		//��ʾ��־

		_beginthread(serverThread,0,this);
	}
	else
	{
		closesocket(m_Socket);
		m_ctrlPort.EnableWindow(TRUE);		//�����޸Ķ˿ں�
		m_ctrlServer.SetWindowText("����");	//��ֹͣ��ť�ĳ�������ť
		AppendLog("��������ֹͣ!\n");		//��ʾ��־
	}

}
