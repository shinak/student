
// MFCUDPclientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCUDPclient.h"
#include "MFCUDPclientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCUDPclientDlg 对话框




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


// CMFCUDPclientDlg 消息处理程序

BOOL CMFCUDPclientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	WSADATA wsaData;
	if(WSAStartup(MAKEWORD(1,1),&wsaData) != 0)
	{
		AfxMessageBox("初始化动态链接库失败!");
		return FALSE;
	}
	//设置端口号初始值
	m_ctrlPort.SetWindowText("8000");
	m_ctrlServerIP.SetAddress((BYTE)127,(BYTE)0,(BYTE)0,(BYTE)1);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCUDPclientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCUDPclientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCUDPclientDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	CString txt;
	m_ctrlClient.GetWindowText(txt);//获取按钮上的文本
	if(txt == "启动")
	{
		//创建套接字
		m_Socket = socket(AF_INET,SOCK_DGRAM,0);

		CString txtPort;
		m_ctrlPort.GetWindowText(txtPort);	//获取端口号的文本
		int port = atoi(txtPort);			//转换成整数端口

		BYTE nFild[4];
		CString txtServerIP;
		m_ctrlServerIP.GetAddress(nFild[0],nFild[1],nFild[2],nFild[3]);//获取服务器IP地址
		txtServerIP.Format("%d.%d.%d.%d",nFild[0],nFild[1],nFild[2],nFild[3]);

		struct sockaddr_in sa;				//定义要连接的服务器地址
		sa.sin_family = AF_INET;			//地址家族
		sa.sin_port = htons(port);			//网络端口
		sa.sin_addr.s_addr = inet_addr(txtServerIP);	//服务器地址

		//向服务端发送名称
		c.soc = m_Socket;
		c.ca = sa;
		int len = sizeof(c.ca);
		CString name;
		char recvmsg[100]={0};
		char sendmsg[100]={0};
		char sendname[100]="#";//用户名表示符

		m_ctrlName.GetWindowText(name);
		strcpy(sendmsg,name);
		strcat(sendname,sendmsg);
		sendto(m_Socket,sendname,100,0,(sockaddr*)&sa,sizeof(sa));
		recvfrom(c.soc,recvmsg,100,0,(sockaddr*)&c.ca,&len);
		c.i = atoi(recvmsg);
		//连接成功
		m_ctrlClient.SetWindowText("取消");//将连接按钮改成断开按钮
		m_ctrlPort.EnableWindow(FALSE);//禁止更改端口号
		m_ctrlServerIP.EnableWindow(FALSE);//禁止更改IP号
		AppendLog("服务器连接成功\n");//显示日志

		_beginthread(recvthread,0,this);
	}
	else
	{
		closesocket(m_Socket);
		m_ctrlPort.EnableWindow(TRUE);		//可以修改端口号
		m_ctrlClient.SetWindowText("启动");	//将关闭按钮改成连接按钮
		AppendLog("客户端已断开连接!\n");		//显示日志
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
	// TODO: 在此添加控件通知处理程序代码
	CString info;
	CString message;
	CString txt;
	m_ctrlSend.GetWindowText(txt);
	m_ctrlMessage.GetWindowText(message);
	m_ctrlMessage.SetWindowText(NULL);

	if(txt == "发送")
	{
		char sendmsg[100]={0};
		char sendnum[100]={0};
		strcpy(sendmsg,message);
		//客户端用户序列转换成字符形式
		sendnum[0] = c.i / 10000 +48;
		sendnum[1] = c.i / 1000 +48;
		sendnum[2] = c.i / 100 +48;
		sendnum[3] = c.i / 10 +48;
		sendnum[4] = c.i % 10 +48;
		sendnum[5] = '\0';

		strcat(sendnum,sendmsg);//将用户序列和消息一并发送给服务端
		sendto(m_Socket,sendnum,100,0,(sockaddr*)&c.ca,sizeof(c.ca));
		//除去接收消息的用户序列字符
		for(int i=0;i<100;i++)
			sendnum[i] = sendnum[i+5];
		info.Format("发送成功!\n");
		AppendLog(info);
	}
}
