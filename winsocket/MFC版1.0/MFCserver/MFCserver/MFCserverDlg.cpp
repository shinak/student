
// MFCserverDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCserver.h"
#include "MFCserverDlg.h"
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


// CMFCserverDlg 对话框




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


// CMFCserverDlg 消息处理程序

BOOL CMFCserverDlg::OnInitDialog()
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
	m_ctrlPort.SetWindowText("9000");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCserverDlg::OnPaint()
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
HCURSOR CMFCserverDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CMFCserverDlg::AppendLog(CString info)
{
	m_ctrlLog.SetSel(-1);//将光标定位到日志框末尾
	m_ctrlLog.ReplaceSel((LPCTSTR)info);//附加新的日志内容
	m_ctrlLog.ShowScrollBar(SB_VERT,TRUE);//显示滚动条
	m_ctrlLog.SetSel(-1);//将光标定位到日志框末尾
}

//接收客户端连接的多线程函数
void serverThread(void *p)
{
	CMFCserverDlg * pDlg = (CMFCserverDlg *)p;
	struct sockaddr_in from;				//用于接收客户端地址
	int len = sizeof(from);
	do
	{
		//等待客户端连接
		SOCKET soc = accept(pDlg->m_Socket, (struct sockaddr *)&from, &len);
		if (soc != INVALID_SOCKET)
		{
			CString info;

			info.Format("收到来自%s的客户端连接\n", inet_ntoa(from.sin_addr));
			pDlg->AppendLog(info);

			while (true)
			{
				char msg[1024]={0};		//定义数据存放的变量
				len = recv(soc,msg,1024,0);	//接收数据
				if (len == -1)
				{
					pDlg->AppendLog("客户端断开连接");
					break;
				}
				info.Format("收到消息:%s\n", msg);
				pDlg->AppendLog(info);
				//将消息转发回客户端
				send(soc, msg, 1024, 0);
			}
		}else
			break;
	}while(true);

}

void CMFCserverDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString txt;
	m_ctrlServer.GetWindowText(txt);	//获取按钮上的文本
	if (txt == "启动")
	{
		//创建套接字
		m_Socket = socket(AF_INET,SOCK_STREAM,0);

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
		//设置监听
		listen(m_Socket,10);

		//到这里服务器启动成功
		m_ctrlPort.EnableWindow(FALSE);		//禁止修改端口号
		m_ctrlServer.SetWindowText("停止");	//将启动按钮改成停止按钮
		AppendLog("服务器启动成功!\n");		//显示日志

		_beginthread(serverThread,0,this);
	}
	else
	{
		closesocket(m_Socket);
		m_ctrlPort.EnableWindow(TRUE);		//可以修改端口号
		m_ctrlServer.SetWindowText("启动");	//将停止按钮改成启动按钮
		AppendLog("服务器已停止!\n");		//显示日志
	}

}
