
// MFCclientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCclient.h"
#include "MFCclientDlg.h"
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


// CMFCclientDlg 对话框




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


// CMFCclientDlg 消息处理程序

BOOL CMFCclientDlg::OnInitDialog()
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
	m_ctrlPort.SetWindowText("9000");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCclientDlg::OnPaint()
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
HCURSOR CMFCclientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCclientDlg::OnIpnFieldchangedIpaddress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMIPADDRESS pIPAddr = reinterpret_cast<LPNMIPADDRESS>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	CString txt;
	m_ctrlClient.GetWindowText(txt);//获取按钮上的文本
	if(txt == "连接")
	{
		//创建套接字
		m_socket = socket(AF_INET,SOCK_STREAM,0);

		CString txtPort;
		m_ctrlPort.GetWindowText(txtPort);	//获取端口号的文本
		int port = atoi(txtPort);			//转换成整数端口

		BYTE nFild[4];
		CString txtServerIP;
		m_ctrlSeverIP.GetAddress(nFild[0],nFild[1],nFild[2],nFild[3]);//获取服务器IP地址
		txtServerIP.Format("%d.%d.%d.%d",nFild[0],nFild[1],nFild[2],nFild[3]);

		struct sockaddr_in sa;				//定义要连接的服务器地址
		sa.sin_family = AF_INET;			//地址家族
		sa.sin_port = htons(port);			//网络端口
		sa.sin_addr.s_addr = inet_addr(txtServerIP);	//服务器地址

		//连接服务器
		if(connect(m_socket,(struct sockaddr *)&sa,sizeof(sa)) == SOCKET_ERROR)
		{
			AfxMessageBox("请输入正确的IP地址!");
			return ;
		}
		else
		{
			//连接成功
			m_ctrlClient.SetWindowText("断开");//将连接按钮改成断开按钮
			m_ctrlPort.EnableWindow(FALSE);//禁止更改端口号
			m_ctrlSeverIP.EnableWindow(FALSE);//禁止更改IP号
			AppendLog("服务器连接成功\n");//显示日志
		}
	}
	else
		{
			closesocket(m_socket);
			m_ctrlPort.EnableWindow(TRUE);		//可以修改端口号
			m_ctrlClient.SetWindowText("连接");	//将关闭按钮改成连接按钮
			AppendLog("客户端已断开连接!\n");		//显示日志
		}
}


void CMFCclientDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString txt;
	m_ctrlSend.GetWindowText(txt);//获取按钮上的文本
	if(txt == "发送")
	{
		CString msg;
		m_ctrlMsg.GetWindowTextA(msg);
		m_ctrlMsg.SetWindowTextA(NULL);
		if(send(m_socket,msg,1024,0) == SOCKET_ERROR)
		{
			AppendLog("发送失败!\n");
			return ;
		}
		else
		{
			CString info;
			info.Format("发送消息:%s\n",msg);
			AppendLog(info);
		}
	}
}
