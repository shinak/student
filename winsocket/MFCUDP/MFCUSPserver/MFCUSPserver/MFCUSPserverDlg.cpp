
// MFCUSPserverDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCUSPserver.h"
#include "MFCUSPserverDlg.h"
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


// CMFCUSPserverDlg 对话框




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


// CMFCUSPserverDlg 消息处理程序

BOOL CMFCUSPserverDlg::OnInitDialog()
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
		AfxMessageBox("初始化动态链接库失败!\n");
		return FALSE;
	}
	//设置端口号
	m_ctrlPort.SetWindowText("8000");


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCUSPserverDlg::OnPaint()
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
HCURSOR CMFCUSPserverDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCUSPserverDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CMFCUSPserverDlg::AppendLog(CString info)
{
	m_ctrlLog.SetSel(-1);//将光标定位到日志框末尾
	m_ctrlLog.ReplaceSel((LPCTSTR)info);//附加新的日志内容
	m_ctrlLog.ShowScrollBar(SB_VERT,TRUE);//显示滚动条
	m_ctrlLog.SetSel(-1);//将光标定位到日志框末尾
}

void recvthread(void *p)
{
	char recvmsg[100]={0};
	char resend[100]={0};
	char sendmsg[100]={0};
	CString info;

	CMFCUSPserverDlg * pDlg = (CMFCUSPserverDlg *)p;

	client c;//接收客户端用户信息

	sockaddr_in ca;
	int len=sizeof(ca);

	while(recvfrom(pDlg->m_Socket,recvmsg,100,0,(sockaddr *)&ca,&len) != SOCKET_ERROR)
	{
		c.soc = pDlg->m_Socket;
		c.ca = ca;
		c.i = 0;

		if(recvmsg[0] == '#')//判断是否为用户名
		{
			for(int i=0;i<strlen(recvmsg);i++)
				recvmsg[i] = recvmsg[i+1];//去掉‘#’
			strcpy(c.name,recvmsg);

			//printf("%s已经连接上服务器，可以开始聊天\n",c.name);
			info.Format("%s已经连接上服务器，可以开始聊天\n",c.name);
			pDlg->AppendLog(info);

			itoa(pDlg->m_Head.insert(c),sendmsg,10);

			sendto(pDlg->m_Socket,sendmsg,100,0,(sockaddr*)&ca,sizeof(ca));//发送该客户端用户序列
		}
		else
		{
			//只能接收99999个客户端，可优化
			c.i  = recvmsg[4]-48 +(recvmsg[3] -48)*10+(recvmsg[2] -48)+(recvmsg[1] -48)*1000+(recvmsg[0] -48)*10000;
			//除去接收消息的用户序列字符
			for(int i=0;i<100;i++)
				recvmsg[i] = recvmsg[i+5];
			//printf("%s说%s\n",h.findClient(c),recvmsg);
			info.Format("%s说:%s\n",pDlg->m_Head.findClient(c),recvmsg);
			pDlg->AppendLog(info);

			//转发
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
	
	info.Format("接收失败:%d\n",WSAGetLastError());
	pDlg->AppendLog(info);

}

void CMFCUSPserverDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString txt;
	m_ctrlServer.GetWindowText(txt);	//获取按钮上的文本
	if (txt == "启动")
	{
		//创建套接字
		m_Socket = socket(AF_INET,SOCK_DGRAM,0);

		CString txtPort;
		m_ctrlPort.GetWindowText(txtPort);	//获取端口号的文本
		int port = atoi(txtPort);			//转换成整数端口

		struct sockaddr_in sa;				//定义服务器地址
		sa.sin_family = AF_INET;			//地址家族
		sa.sin_port = htons(port);			//网络端口
		sa.sin_addr.s_addr = INADDR_ANY;	//本机地址

		 //绑定服务器
		if (bind(m_Socket,(struct sockaddr *)&sa,sizeof(sa)) == SOCKET_ERROR)
		{
			AfxMessageBox("端口号被占用!");
			return;
		}
		//到这里服务器启动成功
		m_ctrlPort.EnableWindow(FALSE);		//禁止修改端口号
		m_ctrlServer.SetWindowText("停止");	//将启动按钮改成停止按钮
		AppendLog("服务器启动成功!\n");		//显示日志
		
		_beginthread(recvthread,0,this);
	}
	else
	{
		closesocket(m_Socket);
		m_ctrlPort.EnableWindow(TRUE);		//可以修改端口号
		m_ctrlServer.SetWindowText("启动");	//将停止按钮改成启动按钮
		AppendLog("服务器已停止!\n");		//显示日志
	}
}


void CMFCUSPserverDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString txt;
	CString message;
	CString info;
	m_ctrlGroupSend.GetWindowText(txt);

	char sendmsg[100] = {0};
	if(txt == "群发")
	{
		char msgupdate[100] = "系统:";//加工消息
		client *c;
		int i=1;
		//gets(sendmsg);
		m_ctrlMessage.GetWindowText(message);
		m_ctrlMessage.SetWindowText(NULL);
		strcpy(sendmsg,message);

		strcat(msgupdate,sendmsg);

		info.Format("群发成功!\n");
		AppendLog(info);

		while((c = m_Head.find(i)) != NULL)
		{
			sendto(m_Socket,msgupdate,100,0,(sockaddr*)&c->ca,sizeof(c->ca));
			i++;
		}
		//msgupdate[0]=NULL;
	}

}
