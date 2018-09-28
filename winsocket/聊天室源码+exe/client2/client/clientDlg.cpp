
// clientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "client.h"
#include "clientDlg.h"
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


// CclientDlg 对话框




CclientDlg::CclientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CclientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CclientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, c_username);
	DDX_Control(pDX, IDC_EDIT2, c_userpassword);
	DDX_Control(pDX, IDC_IPADDRESS1, s_socketIP);
	DDX_Control(pDX, IDC_EDIT6, s_port);
	DDX_Control(pDX, IDC_BUTTON1, b_login);
	DDX_Control(pDX, IDC_LIST1, c_listuser);
	DDX_Control(pDX, IDC_EDIT3, s_senduser);
	DDX_Control(pDX, IDC_EDIT4, c_log);
	DDX_Control(pDX, IDC_EDIT5, c_message);
	DDX_Control(pDX, IDC_BUTTON2, b_senduser);
	DDX_Control(pDX, IDC_BUTTON5, b_senduserall);
}

BEGIN_MESSAGE_MAP(CclientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CclientDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CclientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CclientDlg::OnBnClickedButton5)
	ON_LBN_SELCHANGE(IDC_LIST1, &CclientDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON2, &CclientDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CclientDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CclientDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CclientDlg::OnBnClickedButton6)
END_MESSAGE_MAP()

UserAll banuser;
// CclientDlg 消息处理程序

BOOL CclientDlg::OnInitDialog()
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
	s_port.SetWindowText("9000");
	c_userpassword.SetPasswordChar('*');
	CreateUserAll(&banuser);//
	c_message.EnableWindow(FALSE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CclientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CclientDlg::OnPaint()
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
HCURSOR CclientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CclientDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}


void CclientDlg::AppendLog(CString info)
{
	c_log.SetSel(-1);
	c_log.ReplaceSel((LPCTSTR)info);
	c_log.ShowScrollBar(SB_VERT,TRUE);
	c_log.SetSel(-1);
}


void CclientDlg::SetUser(CString info)
{
	s_senduser.SetSel(-1);
	s_senduser.ReplaceSel((LPCTSTR)info);
	s_senduser.ShowScrollBar(SB_VERT,FALSE);
	s_senduser.SetSel(-1);
}

///////////////////////////////////////////
//字符串加工
char * StringProcess(char *str1,char *str2,const char * command)
{
	memset(str1, '\0', sizeof(str1));//初始化字符串str1
	strcpy(str1, command);//将口令赋值给str1
	strcat(str1, str2);//将str2添加到str1
	return str1;
}

//解析自定义口令
char * StringAnalysis(char *str1, char *command)
{
	int i=0;
	if((int)strlen(str1)<10)//无口令，为无效消息
	{
		command[i] = '\0';
		return command;
	}
	for (i=0; i < 10; i++)
	{
		command[i] = str1[i];
	}
	command[i] = '\0';
	for (i=0; i < (int)strlen(str1); i++)//剥离口令
	{
		str1[i] = str1[i+10];
		if (i+10 == (int)strlen(str1))
		{
			str1[i+11] = '\0';
			break;
		}
	}
	return command;
}

//口令类别
int CommandCategory(char *command)
{
	if (strcmp(command, PERSON) == 0)
		return 1;
	if (strcmp(command, MESSAGE) == 0)
		return 2;
	if (strcmp(command, RADIO) == 0)
		return 3;
	if (strcmp(command, ID) == 0)
		return 4;
	if (strcmp(command, PASSWORD) == 0)
		return 5;
	if (strcmp(command, FFILE) == 0)
		return 6;
	if (strcmp(command, USERLIST) == 0)
		return 7;
	return -1;
}

//判断用户是否在线或离线
int IsState(char *name)
{
	int rVal;
	if (name[0] == '1')
		rVal = 1;
	else if (name[0] == '7')
		rVal = 7;
	else
		rVal = 0;
	for (int i=0; i < (int)strlen(name); i++)//剥离口令
	{
		name[i] = name[i+1];
		if (i+1 == (int)strlen(name))
		{
			name[i+2] = '\0';
			break;
		}
	}
	return rVal;
}

void CreateUserAll(PUserAll ua)
{
	ua->count = 0;
}
int UpdateUserName(PUserAll ua, char *name)
{
	int s1;
	s1 = IsState(name);//[1/0]该用户在线状态
	for(int i=0; i<ua->count; i++)
	{
		if(strcmp(ua->u[i].name, name) == 0)//已有该用户
		{
			if(s1 == 1)
				ua->u[i].state = s1;//更新状态
			else if(s1 == 7)
				ua->u[i].state = s1;
			else
				ua->u[i].state = 0;
			return ua->u[i].state;
		}
		
	}
	ua->u[ua->count].state = s1;
	strcpy(ua->u[ua->count].name, name);
	ua->count++;
	return -1;
}
void AddUser(PUserAll ua, char *name)
{
	strcpy(ua->u[ua->count].name, name);
	ua->u[ua->count].state = 0;
	ua->count++;
}
int CountAdd(PUserAll ua, char *name)
{
	int i;
	for(i=0; i<ua->count; i++)
	{
		if (strcmp(ua->u[i].name, name) == 0)
		{
			ua->u[i].state++;
			return ua->u[i].state;
		}
	}
	return -1;
}
bool FindUser(PUserAll ua, char *name)
{
	for (int i=0; i<ua->count; i++)
	{
		if (strcmp(ua->u[i].name, name) == 0)
			return true;
	}
	return false;
}
bool IsBan(PUserAll ua, char *name)
{
	for (int i=0; i<ua->count; i++)
	{
		if (strcmp(ua->u[i].name, name) == 0)
		{
			if(ua->u[i].state == 3)
				return true;
		}
	}
	return false;
}
void initState(PUserAll ua, char *name)
{
	for (int i=0; i<ua->count; i++)
	{
		if (strcmp(ua->u[i].name, name) == 0)
		{
			ua->u[i].state = 0;
			return ;
		}
	}
	return ;
}

char* GetFileName(char *name)
{
	int rVal;
	CString path;
	path.Format("%s",name);

	rVal = path.ReverseFind('\\');
	
	memset(name, '\0', sizeof(name));
	strcpy(name, (LPSTR)(LPCTSTR)path.Mid(rVal+1));
	return name;
}


/////////////////////////////////////
static bool state = false;
UserAll ua;//所有用户名
void recvThread(void *p)//接收服务端发送的消息
{
	
	CclientDlg  * pDlg= (CclientDlg *)p;
	CString info;
	int rVal;
	char command[11] = {0};
	char recvmsg[1030] = {0};
	char prefix[1024] = {0};
	char filename[1024] = {0};
	CreateUserAll(&ua);//初始化ua结构体储存所有用户名
	while(pDlg->c_socket != INVALID_SOCKET)
	{
		memset(recvmsg, '\0', sizeof(recvmsg));
		rVal = recv(pDlg->c_socket, recvmsg, 1024,0);
		if(!state)
		{
			return ;
		}
		if (rVal == SOCKET_ERROR)//接收异常
		{
			info.Format("服务端强制关闭,错误代码: %d\n", WSAGetLastError());
			pDlg->AppendLog(info);
			pDlg->AppendLog("\n");
			///////////////////////////////////////////////////
			pDlg->c_listuser.ResetContent();
			shutdown(pDlg->c_socket, SD_BOTH);
			closesocket(pDlg->c_socket);
			pDlg->c_message.EnableWindow(FALSE);//禁止发送消息
			pDlg->c_username.EnableWindow(TRUE);//可以修改用户名
			pDlg->c_userpassword.EnableWindow(TRUE);//可以修改密码
			pDlg->s_socketIP.EnableWindow(TRUE);//可以修改要连接的IP
			pDlg->s_port.EnableWindow(TRUE);//可以修改端口号
			pDlg->b_login.SetWindowText("登录");	//将关闭按钮改成连接按钮
			///////////////////////////////////////////////////
			return ;
		}
		else if (rVal == 0)//服务端关闭
		{
			info.Format("服务端已关闭\n");
			pDlg->AppendLog(info);
			pDlg->AppendLog("\n");
			closesocket(pDlg->c_socket);
			///////////////////////////////////////////////////
			pDlg->c_listuser.ResetContent();
			shutdown(pDlg->c_socket, SD_BOTH);
			closesocket(pDlg->c_socket);
			pDlg->c_message.EnableWindow(FALSE);//禁止发送消息
			pDlg->c_username.EnableWindow(TRUE);//可以修改用户名
			pDlg->c_userpassword.EnableWindow(TRUE);//可以修改密码
			pDlg->s_socketIP.EnableWindow(TRUE);//可以修改要连接的IP
			pDlg->s_port.EnableWindow(TRUE);//可以修改端口号
			pDlg->b_login.SetWindowText("登录");//将关闭按钮改成连接按钮
			///////////////////////////////////////////////////
			return ;
		}
		else//对消息进行处理
		{
			char name[30]={0};
			char fmsg[1512]={0};
			strcpy(fmsg,recvmsg);
			StringAnalysis(recvmsg,command);//解析消息，获得口令，讯息
			switch(CommandCategory(command))//判断类别
			{
				case 1:;
					break;//PERSON
				case 2:;
					break;//MESSAGE
				case 3:
					{
						info.Format("%s\n",recvmsg);
						pDlg->AppendLog(info);
						pDlg->AppendLog("\n");
						//保存聊天记录
						char path[100]={0};
						strcpy(path, "./chat/");
						CString puser;
						pDlg->c_username.GetWindowText(puser);
						strcat(path, (LPSTR)(LPCTSTR)puser);
						strcat(path, ".txt");
						FILE *chat = fopen(path, "a");
						fputs(recvmsg, chat);
						fputs("\n", chat);
						fclose(chat);
					}break;//RADIO
				case 4:
					{
						
					}break;//ID
				case 5:;
					break;//PASSWORD
				case 6:
					{
						memset(filename, '\0', sizeof(filename));
						strcpy(filename, "./recv/");
						strcat(filename, GetFileName(recvmsg));//获得文件名
						info.Format("接收文件%s\n",recvmsg);
						pDlg->AppendLog(info);
						FILE *initfile = fopen(filename,"wb");//创建文件
						fclose(initfile);
					}break;//FFILE(接受的识别文件名)
				case 7:
					{
						int n;
						strcpy(name, recvmsg);
						if((int)strlen(name) == 0)
							break;
						UpdateUserName(&ua,name);//更新
					}break;//USERLIST
				default:
					{
						FILE *file = fopen(filename, "ab");
						if (filename != NULL)
						{
							fwrite(fmsg,1,1024,file);
							fclose(file);
							pDlg->AppendLog("接收文件。。。\n");
						}
						memset(fmsg, '\0', sizeof(fmsg));
					}break;
			}
			/////////////////////////////
			pDlg->c_listuser.ResetContent();
			for(int i=0; i<ua.count; i++)
			{
				memset(name, '\0',sizeof(name));
				if(ua.u[i].state == 0)//线
				{
					strcpy(name,ua.u[i].name);
					strcat(name,"(离线)");

					pDlg->c_listuser.AddString((LPCTSTR)name);
				}
				else if(ua.u[i].state == 1)//在线
				{
					strcpy(name,ua.u[i].name);
					strcat(name,"(在线)");
					pDlg->c_listuser.InsertString(0,(LPCTSTR)name);
				}
				else if(ua.u[i].state == 7)
					continue;
			}
			////////////////////////////
		}
	}
	memset(recvmsg, '\0', sizeof(recvmsg));
}

void CclientDlg::OnBnClickedButton1()//login...
{
	// TODO: 在此添加控件通知处理程序代码
	int rVal = 0;
	CString txt;
	CString info;
	CString user;
	CString password;
	char prefix[1024] = {0};//消息加工
	char command[11] = {0};//口令
	b_login.GetWindowText(txt);//获取按钮上的文本
	
	if (txt == "登录")
	{
		c_socket = socket(AF_INET,SOCK_STREAM,0);
		if (c_socket == INVALID_SOCKET)
		{
			info.Format("套接字创建失败,错误代码: %d\n", WSAGetLastError());
			AppendLog(info);
			AppendLog("\n");
			closesocket(c_socket);//关闭错误套接字
			return ;
		}
		//判断用户名、密码的正确性
		c_username.GetWindowText(user);//获得用户名
		if ((int)strlen((LPSTR)(LPCTSTR)user) == 0)//用户名为空
		{
			AfxMessageBox("用户名为空");
			return ;
		}
		else if (strlen((LPSTR)(LPCTSTR)user) > 14)//超过15字符
		{
			AfxMessageBox("用户名太长(应小于14字符)");
			c_username.SetWindowText("");
			return ;
		}
		if(FindUser(&banuser, (LPSTR)(LPCTSTR)user) == true)//找到该用户名
		{
			if(IsBan(&banuser, (LPSTR)(LPCTSTR)user) == true)//3次错误
			{
				AfxMessageBox("密码输入错误3次，已禁止登录");
				return ;
			}
		}
		if(FindUser(&banuser, (LPSTR)(LPCTSTR)user) == false)//未找到该用户名
		{
			AddUser(&banuser, (LPSTR)(LPCTSTR)user);
		}
		c_userpassword.GetWindowText(password);
		if(strlen((LPSTR)(LPCTSTR)password) == 0)//密码为空
		{
			AfxMessageBox("密码为空");
			return ;
		}
		else if (strlen((LPSTR)(LPCTSTR)password) > 24)
		{
			AfxMessageBox("密码太长(应小于24字符)");
			c_userpassword.SetWindowText("");
			return ;
		}
		//获取端口号
		CString txtPort;
		s_port.GetWindowText(txtPort);	//获取端口号的文本
		int port = atoi(txtPort);   	//转换成整数端口
		//获取服务端IP地址
		BYTE nFild[4];
		CString txtIP;
		s_socketIP.GetAddress(nFild[0],nFild[1],nFild[2],nFild[3]);//获取服务器IP地址
		txtIP.Format("%d.%d.%d.%d",
			nFild[0],nFild[1],nFild[2],nFild[3]);
		//设置要连接的服务端IP地址和端口号
		struct sockaddr_in sa;				//定义要连接的服务器地址
		sa.sin_family = AF_INET;			//地址家族
		sa.sin_port = htons(port);			//网络端口
		sa.sin_addr.s_addr = inet_addr(txtIP);	//服务器地址
		//连接服务器
		if(connect(c_socket,(struct sockaddr *)&sa,sizeof(sa)) == SOCKET_ERROR)
		{//如果异常
			info.Format("请输入正确的IP地址,错误代码: %d\n", WSAGetLastError());
			AppendLog(info);
			AppendLog("\n");
			return ;
		}
		else//连接成功,发送用户姓名和密码进行验证
		{
			//判断人数是否已满
			char sendmsg[1024] = {0};
			rVal = recv(c_socket, sendmsg, 1024, 0);//接收服务端发来的确认
			if (rVal == SOCKET_ERROR)//异常
			{
				info.Format("服务端发送人数确认失败,错误代码: %d\n", WSAGetLastError());
				AppendLog(info);
				AppendLog("\n");
				return ;
			}
			else if (rVal == 0)//服务端关闭
			{
				info.Format("服务端已关闭，充钱才能打开\n");
				AppendLog(info);
				AppendLog("\n");
				closesocket(c_socket);
				return ;
			}
			else//验证
			{
				if (strcmp(StringAnalysis(sendmsg, command), FULL) == 0)//人数已满
				{
					info.Format("服务器过于拥挤\n");
					AppendLog(info);
					AppendLog("\n");
					closesocket(c_socket);
					return ;
				}
				else
				{
					/////////////////////登录//////////////////
					memset( sendmsg, '\0' ,sizeof(sendmsg) );//初始化
					strcpy(sendmsg, StringProcess(prefix, (LPSTR)(LPCTSTR)user,ID));//加工后消息
					rVal = send(c_socket, sendmsg, 1024, 0);//发送用户名
					if (rVal == SOCKET_ERROR)//发送异常
					{
						AfxMessageBox("登录失败1");
						info.Format("登录失败,错误代码: %d\n", WSAGetLastError());
						AppendLog(info);
						AppendLog("\n");
						return ;
					}
					memset( sendmsg, '\0' ,sizeof(sendmsg) );//初始化
					rVal = recv(c_socket, sendmsg, 1024, 0);//等待服务端确认
					if (rVal == SOCKET_ERROR)//发送异常
					{
						AfxMessageBox("登录失败2");
						info.Format("用户名认证异常,错误代码: %d\n", WSAGetLastError());
						AppendLog(info);
						AppendLog("\n");
						closesocket(c_socket);
						return ;
					}
					else if (rVal == 0)//服务端关闭
					{
						AfxMessageBox("登录失败3");
						info.Format("服务端已关闭\n");
						AppendLog(info);
						AppendLog("\n");
						closesocket(c_socket);
						return ;
					}
					else//收到服务端返回确认消息
					{
						if (strcmp(StringAnalysis(sendmsg, command), LOGIN) == 0)//口令匹配，用户名验证成功
						{
							memset( sendmsg, '\0' ,sizeof(sendmsg) );//初始化
							strcpy(sendmsg, StringProcess(prefix, (LPSTR)(LPCTSTR)password, PASSWORD));
			  				rVal = send(c_socket, sendmsg, 1024, 0);//发送密码
							if (rVal == SOCKET_ERROR)//发送异常
							{
								AfxMessageBox("登录失败4");
								info.Format("用户名认证异常,错误代码: %d\n", WSAGetLastError());
								AppendLog(info);
								AppendLog("\n");
								closesocket(c_socket);
								return ;
							}
							else
							{
								//优化：其他判断
								memset( sendmsg, '\0',sizeof(sendmsg) );//初始化
								rVal = recv(c_socket, sendmsg, 1024, 0);
								if (rVal == 0)
								{
									AfxMessageBox("登录失败5");
									info.Format("服务端已关闭\n");
									AppendLog(info);
									AppendLog("\n");
									closesocket(c_socket);
									return ;
								}
								else if (rVal == SOCKET_ERROR)
								{
									AfxMessageBox("登录失败6");
									info.Format("用户名认证异常,错误代码: %d\n", WSAGetLastError());
									AppendLog(info);
									AppendLog("\n");
									closesocket(c_socket);
									return ;
								}
								else
								{
									if (strcmp(StringAnalysis(sendmsg, command), LOGIN) == 0)//口令匹配，密码验证成功，登录成功
									{
										/////////////////////初始化///////////////////////
										initState(&banuser, (LPSTR)(LPCTSTR)user);//清空计数
										b_login.SetWindowText("退出");//将连接按钮改成断开按钮
										c_message.EnableWindow(TRUE);//允许发送消息
										c_username.EnableWindow(FALSE);//禁止修改用户名
										c_userpassword.EnableWindow(FALSE);//禁止修改密码
										s_socketIP.EnableWindow(FALSE);//禁止更改IP号
										s_port.EnableWindow(FALSE);//禁止更改端口号
										AppendLog("服务器连接成功\n");//显示日志
										AppendLog("\n");
										info.Format("登录成功\n");
										AppendLog(info);
										AppendLog("\n");
										///////////创建保存聊天记录文件"./chat/name.txt"
										char path[100] = {0};
										strcpy(path, "./chat/");
										strcat(path, (LPSTR)(LPCTSTR)user);
										strcat(path, ".txt");
										FILE *init = fopen(path, "r");//试着打开
										if(init == NULL)//不存在
											init=fopen(path,"w");//创建
										fclose(init);
										state = true;
										_beginthread(recvThread,0,this);
										////////////////////////////////////////////////////////////
									}
									else//不匹配
									{
										/////////////////计数
										rVal = CountAdd(&banuser, (LPSTR)(LPCTSTR)user);//密码错误计数加一
										/////////////////
										info.Format("登录失败,密码错误%d次\n",rVal);
										AfxMessageBox(info);
										closesocket(c_socket);
										return ;
									}
								}
							}
						}
					}
				}
			}
		}
	 }//最。。。的判断
	else
	{
		c_listuser.ResetContent();
		state = false;
		shutdown(c_socket, SD_BOTH);
		closesocket(c_socket);
		c_message.EnableWindow(FALSE);//禁止发送消息
		c_username.EnableWindow(TRUE);//可以修改用户名
		c_userpassword.EnableWindow(TRUE);//可以修改密码
		s_socketIP.EnableWindow(TRUE);//可以修改要连接的IP
		s_port.EnableWindow(TRUE);//可以修改端口号
		b_login.SetWindowText("登录");	//将关闭按钮改成连接按钮
		AppendLog("用户已退出登录\n");		//显示日志
		AppendLog("\n");
	}
}


void CclientDlg::OnBnClickedButton5()//群发
{
	// TODO: 在此添加控件通知处理程序代码
	int rVal;
	char sendmsg[1024]={0};
	char prefix[1024]={0};
	CString info;
	CString txt;
	CString name;
	c_message.GetWindowText(txt);//获得消息框消息
	c_username.GetWindowText(name);//用户名
	c_message.SetWindowText("");
	if((int)strlen((LPSTR)(LPCTSTR)txt) == 0)
	{
		AfxMessageBox("发送消息为空");
		return ;
	}

	strcpy(sendmsg, StringProcess(prefix, (LPSTR)(LPCTSTR)name, RADIO));//RADIO|username
	strcat(sendmsg, "(大声地说):");
	strcat(sendmsg, (LPSTR)(LPCTSTR)txt);//消息
	rVal = send(c_socket, sendmsg, 1024, 0);
	if (rVal == SOCKET_ERROR)
	{
		info.Format("发送异常,错误代码: %d\n", WSAGetLastError());
		AppendLog(info);
		AppendLog("\n");
		return ;
	}
	AppendLog("发送成功\n");
	//保存聊天记录
	char path[100]={0};
	char cmsg[1024]={0};
	strcpy(path, "./chat/");
	CString puser;
	c_username.GetWindowText(puser);
	strcpy(cmsg, (LPSTR)(LPCTSTR)puser);
	strcat(cmsg, ":");
	strcat(cmsg, (LPSTR)(LPCTSTR)txt);
	strcat(path, (LPSTR)(LPCTSTR)puser);
	strcat(path, ".txt");
	FILE *chat = fopen(path, "a");
	fputs(cmsg, chat);
	fputs("\n", chat);
	fclose(chat);
}


void CclientDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString user;
	char username[30]={0};
	int nCurSel;
    nCurSel = c_listuser.GetCurSel(); 
	c_listuser.GetText(nCurSel, user);
	s_senduser.SetWindowText("");

	strcpy(username, (LPSTR)(LPCTSTR)user);
	for(int i=0; i<(int)strlen(username); i++)//剥离用户名
	{
		if(username[i] == '(')
		{
			username[i] = '\0';
			break;
		}
	}
	user.Format("%s", username);
	SetUser(user);
}


void CclientDlg::OnBnClickedButton2()//私聊
{
	// TODO: 在此添加控件通知处理程序代码
	int rVal;
	char sendmsg[1024]={0};
	char prefix[1024]={0};
	CString user;
	CString info;
	CString msg;
	CString name;
	s_senduser.GetWindowText(user);//获得要私聊的用户名
	strcpy(sendmsg, StringProcess(prefix, (LPSTR)(LPCTSTR)user, PERSON));
	rVal = send(c_socket, sendmsg, 1024, 0);
	if (rVal == SOCKET_ERROR)
	{
		info.Format("发送用户名异常,%d\n", WSAGetLastError());
		AppendLog(info);
		AppendLog("\n");
	}
	memset(sendmsg, '\0', sizeof(sendmsg));
	memset(prefix, '\0', sizeof(prefix));
	c_username.GetWindowText(name);
	c_message.GetWindowText(msg);
	c_message.SetWindowText("");
	if((int)strlen((LPSTR)(LPCTSTR)msg) == 0)
	{
		AfxMessageBox("发送消息为空");
		return ;
	}
	strcpy(sendmsg, StringProcess(prefix, (LPSTR)(LPCTSTR)name, MESSAGE));//MESSAGE|username
	strcat(sendmsg, "(悄悄地对你说):");
	strcat(sendmsg, (LPSTR)(LPCTSTR)msg);//消息

	rVal = send(c_socket, sendmsg, 1024, 0);
	if (rVal == SOCKET_ERROR)
	{
		info.Format("私聊消息发送异常,%d\n", WSAGetLastError());
		AppendLog(info);
		AppendLog("\n");
	}
	AppendLog("发送成功\n");
	//保存聊天记录
	char path[100]={0};
	char cmsg[1024]={0};
	strcpy(path, "./chat/");
	CString puser;
	c_username.GetWindowText(puser);
	strcpy(cmsg, (LPSTR)(LPCTSTR)puser);
	strcat(cmsg, ":");
	strcat(cmsg, (LPSTR)(LPCTSTR)msg);
	strcat(path, (LPSTR)(LPCTSTR)puser);
	strcat(path, ".txt");
	FILE *chat = fopen(path, "a");
	fputs(cmsg, chat);
	fputs("\n", chat);
	fclose(chat);

}


void CclientDlg::OnBnClickedButton3()//选择文件
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE);
	if(IDCANCEL == dlg.DoModal())
		return ;
	CString filename;
	filename = dlg.GetPathName();
	c_message.SetWindowText("");
	c_message.SetWindowText(filename);
}


void CclientDlg::OnBnClickedButton4()//私发文件
{
	// TODO: 在此添加控件通知处理程序代码
	CString filename;
	char prefix[1024]={0};
	char buffer[1024]={0};
	c_message.GetWindowText(filename);
	c_message.SetWindowText("");
	memset(prefix, '\0',sizeof(prefix));
	StringProcess(prefix,(LPSTR)(LPCTSTR)filename, FFILE);
	send(c_socket,prefix,1024,0);//path
	FILE *file = fopen((LPSTR)(LPCTSTR)filename, "rb");//读取
	if (file != NULL)
	{
		while (fread(buffer,1,1024,file) >= 0)
		{
			send(c_socket,buffer,1024,0);
			if(feof(file))
				break;
		}
		fclose(file);
	}
	AppendLog("发送成功\n");
}


void CclientDlg::OnBnClickedButton6()//查看离线消息
{
	// TODO: 在此添加控件通知处理程序代码
	CString info;
	char path[100]={0};
	strcpy(path, "./chat/");
	CString puser;
	c_username.GetWindowText(puser);
	strcat(path, (LPSTR)(LPCTSTR)puser);
	strcat(path, ".txt");//"./chat/name.txt"
	FILE *chat = fopen(path, "r");
	if (chat != NULL)
	{
		char ch = fgetc(chat);
		do{
			char msg[1024]={0};
			fgets(msg, 1024, chat);
			AppendLog("\n");
			info.Format("%s", msg);
			AppendLog(info);
		
		}while(!feof(chat));
		fclose(chat);
	}
	
}
