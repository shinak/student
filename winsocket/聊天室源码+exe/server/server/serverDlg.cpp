
// serverDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "server.h"
#include "serverDlg.h"
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


// CserverDlg 对话框




CserverDlg::CserverDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CserverDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CserverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, s_port);
	DDX_Control(pDX, IDC_EDIT2, s_messagelog);
	DDX_Control(pDX, IDC_EDIT3, s_message);
	DDX_Control(pDX, IDC_BUTTON4, b_delperson);
	DDX_Control(pDX, IDC_BUTTON1, b_start);
	DDX_Control(pDX, IDC_BUTTON5, b_choose);
	DDX_Control(pDX, IDC_BUTTON3, b_sendfile);
	DDX_Control(pDX, IDC_BUTTON2, b_sendmessage);
	DDX_Control(pDX, IDC_LIST3, s_userlist);
	DDX_Control(pDX, IDC_EDIT4, d_user);
}

BEGIN_MESSAGE_MAP(CserverDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CserverDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CserverDlg::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST3, &CserverDlg::OnLbnSelchangeList3)
	ON_BN_CLICKED(IDC_BUTTON4, &CserverDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CserverDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &CserverDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CserverDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CserverDlg 消息处理程序

BOOL CserverDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CserverDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CserverDlg::OnPaint()
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
HCURSOR CserverDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CserverDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
}

//select模型多线程
static bool closeServer = true;
int fd_array_connect[MAX_LISTENSIZE] = {0};//加入所有在线用户套接字
ListInfor p_usernew;// 待验证的用户
void selectThread(void *p)
{
	CserverDlg * pDlg = (CserverDlg *)p;
	CString info;
	int rVal;
	char command[11] = {0};
	char recvmsg[1024] = {0};
	char prefix[1024] = {0};
	char userlist[30]={0};
	char filename[100]={0};
	fd_set fdRead;//处于读就绪状态的集合
	//fd_set fdWrite;//处于可读就绪状态的集合
	timeval tv={10,0};//设置等待时间为10秒
	int     i = 0;
	int     nConnNum = 0;
	//select模型
	int nMode = 1;
	//  非阻塞模式设定
	rVal = ioctlsocket( pDlg->s_socket, FIONBIO, (u_long FAR*)&nMode );
	if( rVal == SOCKET_ERROR )
	{
		info.Format("非阻塞模式设置失败: %d\n", WSAGetLastError());
		pDlg->AppendLog(info);
		pDlg->AppendLog("\n");
		closesocket(pDlg->s_socket);
		return ;
	}
	/*测试使用
	info.Format("设置服务器端模式: %s\n", nMode==0? "阻塞模式":"非阻塞模式");
	pDlg->AppendLog(info);
	pDlg->AppendLog("---------------------------------------------------"
		"-------------------------------------------------\n");
	info.Format("开始准备接受连接\n");
	pDlg->AppendLog(info);
	pDlg->AppendLog("---------------------------------------------------"
		"-------------------------------------------------\n");*/
	CreateListInfor(&p_usernew);//初始化
	while (pDlg->s_socket != INVALID_SOCKET)  //服务端socket正常启动时
	{
		FD_ZERO(&fdRead);//将你的套接字集合清空
		FD_SET( pDlg->s_socket, &fdRead );  //将sersoc放入fdRead集中进行select监听
       
		for( i=0; i<MAX_LISTENSIZE; i++ )
		{
			if( fd_array_connect[i] != 0 )
			{
			/*	info.Format("连接的套接字[%d]: %d\n",i+1,fd_array_connect[i] );
				pDlg->AppendLog(info);
				pDlg->AppendLog("---------------------------------------------------"
		"-------------------------------------------------\n");*/
				FD_SET( fd_array_connect[i], &fdRead );//把在线用户加入fdRead
			}
		}
		//调用select模式进行监听
		rVal = select( 0, &fdRead, NULL, NULL, &tv );//检查是否有套接字可读 即是否有套接字处于读就绪状态 select返回可用的套接字个数
		if( rVal == SOCKET_ERROR )
		{
			info.Format("失败，错误代码: %d\n", WSAGetLastError());
			pDlg->AppendLog(info);
			pDlg->AppendLog("\n");
			break;
		}
		else if( rVal == 0 )
		{
			/*测试超时
			info.Format("超时: %d 秒\n",tv.tv_sec);
			pDlg->AppendLog(info);
			pDlg->AppendLog("---------------------------------------------------"
		"-------------------------------------------------\n");*/
			continue; //继续监听
		}
		else//成功启动select模型
		{
			if (closeServer) //服务器未启动
			{
				break;
			}
			for( i=0; i<MAX_LISTENSIZE; i++ )
			{
				if( FD_ISSET(fd_array_connect[i], &fdRead) )//检查fd_array_connect[i]是否在fdRead集合中
				{
					memset( recvmsg, '\0' ,sizeof(recvmsg) );//初始化
					rVal = recv( fd_array_connect[i], recvmsg, 1024, 0 );//接收用户发送的消息
					if( rVal == 0 )
					{
						if((int)strlen(pDlg->p_userall.FindUser(fd_array_connect[i]).object)==0)
							info.Format("客户端%d已经关闭\n",fd_array_connect[i]);//用户离线
						else
							info.Format("用户%s下线了\n",pDlg->p_userall.FindUser(fd_array_connect[i]).object);//用户离线
						pDlg->AppendLog(info);
						pDlg->AppendLog("\n");
						closesocket( fd_array_connect[i] );
						//将已经关闭的SOCKET从FD集中删除
						FD_CLR( fd_array_connect[i], &fdRead );
						/////////////////群发离线消息//////////
						ListInfor douser;
						douser = pDlg->p_userall.FindAll();
						for (int j=0; j<douser.count; j++)
						{
							if(douser.users[j].state != 0 && douser.users[j].state != fd_array_connect[i])
							{
								char domsg[1024]={0};
								StringProcess(prefix, "0", USERLIST);
								strcpy(domsg, prefix);
								strcat(domsg, pDlg->p_userall.FindUser(fd_array_connect[i]).object);
								send(douser.users[j].state, domsg, 1024, 0);
							}
						}
						///////////////////////////////////////
						pDlg->p_userall.StateChange(fd_array_connect[i]);//用户离线
						fd_array_connect[i] = 0;
						--nConnNum;
						
						//插入用户列表|如果在离线名单上移除该离线用户插入到在线名单
						/*FindString有数据却搜索不到？？？*/
						//////////////添加离线用户///////////////
						pDlg->s_userlist.ResetContent();
						ListInfor duser;
						char downusername[30]={0};
						duser = pDlg->p_userall.FindAll();//离线用户
						/*测试总人数
						info.Format("%d\n",duser.count);
						pDlg->AppendLog(info);*/
						for(int j=0; j<duser.count; j++)
						{
							if(duser.users[j].state == 0)
							{
								memset(downusername, '\0', sizeof(downusername));
								StringProcess(downusername, "(离线)", duser.users[j].object);//downusername(离线)
								pDlg->s_userlist.AddString((LPCTSTR)downusername);
							}
							else
							{
								memset(downusername, '\0', sizeof(downusername));
								StringProcess(downusername, "(在线)", duser.users[j].object);//downusername(离线)
								pDlg->s_userlist.InsertString(0,(LPCTSTR)downusername);
							}
						}
					}
					else if(rVal == SOCKET_ERROR)
					{
						if((int)strlen(pDlg->p_userall.FindUser(fd_array_connect[i]).object)==0)
							info.Format("客户端强制断开了连接: %d\n", WSAGetLastError());
						else
							info.Format("用户%s强制断开了连接: %d\n", WSAGetLastError());
						pDlg->AppendLog(info);
						pDlg->AppendLog("\n");
						closesocket( fd_array_connect[i] );
						//将已经关闭的SOCKET从FD集中删除
						FD_CLR( fd_array_connect[i], &fdRead );
						/////////////////群发离线消息//////////
						ListInfor douser;
						douser = pDlg->p_userall.FindAll();
						for (int j=0; j<douser.count; j++)
						{
							if(douser.users[j].state != 0 && douser.users[j].state != fd_array_connect[i])
							{
								char domsg[1024]={0};
								StringProcess(prefix, "0", USERLIST);
								strcpy(domsg, prefix);
								strcat(domsg, pDlg->p_userall.FindUser(fd_array_connect[i]).object);
								send(douser.users[j].state, domsg, 1024, 0);
							}
						}
						///////////////////////////////////////
						pDlg->p_userall.StateChange(fd_array_connect[i]);//用户离线
						fd_array_connect[i] = 0;
						--nConnNum;
						
						//插入用户列表|如果在离线名单上移除该离线用户插入到在线名单
						/*FindString有数据却搜索不到？？？*/
						//////////////更新列表///////////////
						pDlg->s_userlist.ResetContent();
						ListInfor duser;
						char downusername[30]={0};
						duser = pDlg->p_userall.FindAll();
						/*测试总人数
						info.Format("%d\n",duser.count);
						pDlg->AppendLog(info);*/
						for(int j=0; j<duser.count; j++)
						{
							if(duser.users[j].state == 0)
							{
								memset(downusername, '\0', sizeof(downusername));
								StringProcess(downusername, "(离线)", duser.users[j].object);//downusername(离线)
								pDlg->s_userlist.AddString((LPCTSTR)downusername);
							}
							else
							{
								memset(downusername, '\0', sizeof(downusername));
								StringProcess(downusername, "(在线)", duser.users[j].object);//downusername(离线)
								pDlg->s_userlist.InsertString(0,(LPCTSTR)downusername);
							}
						}
					}
					else//对消息进行分析处理（群发、私聊、用户判断。。。。）///////////////////////////////////////
					{

						Infor n3;
						char msg[1024]={0};
						//////////////////////////////////////////
						StringAnalysis(recvmsg,command);//解析消息，获得口令，讯息
						switch(CommandCategory(command))//判断类别
						{
							case 1://缺陷：同一时间只能一个用户发送私聊消息（可优化）
								{
									n3 = pDlg->p_userall.FindUser(recvmsg);//用户名
									/*测试得到的用户名
									info.Format("%s\n", n3.object);
									pDlg->AppendLog(info);
									pDlg->AppendLog("---------------------------------------------------"
												"-------------------------------------------------\n");*/
								 }break;//PERSON
							case 2:
								{
									char sendmsg[1024]={0};
									char chatfile[1024]={0};
									if(n3.state != 0)//该用户在线直接转发
									{
										memset(prefix, '\0', sizeof(prefix));
										strcpy(sendmsg, StringProcess(prefix, recvmsg, RADIO));
										rVal = send(n3.state, sendmsg, 1024, 0);
										info.Format("转发私聊完成\n");
										pDlg->AppendLog(info);
										pDlg->AppendLog("\n");
									}
									else
									{
										info.Format("保存离线消息完成\n");
										pDlg->AppendLog(info);
										pDlg->AppendLog("\n");
										strcpy(chatfile, "./chat/");
										strcat(chatfile, n3.object);
										strcat(chatfile, ".txt");//"./chat/name.txt"
										FILE *in = fopen(chatfile, "a+");//追加
										fputs(recvmsg,in);
										fputs("\n",in);

										fclose(in);
									}
								}break;//MESSAGE
							case 3:
								{
									/*测试收到的数据
									info.Format("%s\n", recvmsg);
									pDlg->AppendLog(info);
									pDlg->AppendLog("---------------------------------------------------"
												"-------------------------------------------------\n");*/
									for (int j=0; j<MAX_LISTENSIZE; j++)//对在线用户群发，保存离线用户消息
									{
										if(fd_array_connect[j] != 0 && fd_array_connect[j] != fd_array_connect[i])//在线用户
										{
											//消息加工
											char sendmsg[1024]={0};
											strcpy(sendmsg, StringProcess(prefix, recvmsg, RADIO));//发送群发消息
											rVal = send(fd_array_connect[j], sendmsg, 1024, 0);
											if (rVal == SOCKET_ERROR)
											{
												info.Format("用户消息群发异常，错误代码: %d\n", WSAGetLastError());
												pDlg->AppendLog(info);
												pDlg->AppendLog("\n");
											}
										}
									}
									info.Format("转发群聊完成\n");
									pDlg->AppendLog(info);
									pDlg->AppendLog("\n");
									//为离线用户保存聊天记录
									ListInfor userall;
									userall = pDlg->p_userall.FindAll();
									for(int j=0; j<userall.count; j++)
									{
										if(userall.users[j].state == 0)
										{
											char chatfile[100]={0};
											strcpy(chatfile, "./chat/");
											strcat(chatfile, userall.users[j].object);
											strcat(chatfile, ".txt");//"./chat/name.txt"
											FILE *in = fopen(chatfile, "a+");//追加
											fputs(recvmsg,in);
											fputs("\n",in);
											fclose(in);
										}
									}
								}break;//

							case 4:
								{
									Infor n1;
									strcpy(n1.object, recvmsg);//保存客户端发送的用户名
									n1.state = fd_array_connect[i];//保存客户端套接字
									strcpy(n1.password, "");//此时密码为空
									AddNewUser(&p_usernew, n1);//临时保存未验证的用户信息
									memset( recvmsg, '\0' ,sizeof(recvmsg) );//初始化
									strcpy(recvmsg, StringProcess(prefix, "-255", LOGIN));//反馈客户的消息
									rVal = send(fd_array_connect[i], recvmsg, 1024, 0);
									if (rVal == SOCKET_ERROR) //发送异常
									{
										info.Format("用户反馈发送异常，错误代码%s\n", WSAGetLastError());
										pDlg->AppendLog(info);
										pDlg->AppendLog("\n");
									}
								}break;//ID
							case 5:
								{
									Infor n2;
									strcpy(n2.object, "");//用户名为空
									strcpy(n2.password, recvmsg);//保存客户端发送的密码
									n2.state = fd_array_connect[i];//保存客户端套接字
									//得到来自该客户端的完整用户信息
									int oneuser;
									oneuser =  AddNewUser(&p_usernew, n2);
									if(oneuser != -1)//用户信息在p_usernew中的存储位置
									{//得到用户完整信息
										strcpy(n2.object, p_usernew.users[oneuser].object);
										strcpy(n2.password, p_usernew.users[oneuser].password);
										n2.state = p_usernew.users[oneuser].state;
										pDlg->AppendLog(info);
										DeleteNewUser(&p_usernew, oneuser);//删除队列中的用户
										//验证用户信息
										rVal = pDlg->p_userall.IsUser(n2.object, n2.password, n2.state);
										if (rVal == -128)//人数已满
										{
											memset(recvmsg, 0, sizeof(recvmsg));
											strcpy(recvmsg,StringProcess(prefix, "-255", FULL));//人数已满消息
											send( fd_array_connect[i], recvmsg, 1024, 0 );//发送人数已满消息
											closesocket( fd_array_connect[i] );//关闭该套接字
											//将已经关闭的SOCKET从FD集中删除
											FD_CLR( fd_array_connect[i], &fdRead );
											fd_array_connect[i] = 0;
											--nConnNum;
										}
										else if (rVal == -255)//密码错误
										{
											memset(recvmsg, '\0', sizeof(recvmsg));
											strcpy(recvmsg, StringProcess(prefix, "-255", PASSWORD));//发送无关消息，表示登录失败（密码错误）
											send( fd_array_connect[i], recvmsg, 1024, 0 );
										}
										else if (rVal == -246)//重登
										{
											memset(recvmsg, '\0', sizeof(recvmsg));
											strcpy(recvmsg, StringProcess(prefix, "-246", PASSWORD));//发送无关消息，表示登录失败
											send( fd_array_connect[i], recvmsg, 1024, 0 );
										}
										else//登录成功
										{
											info.Format("用户%s上线啦~~~\n",n2.object);
											pDlg->AppendLog(info);
											pDlg->AppendLog("\n");
											//ListInfor sje = pDlg->p_userall.FindAll();
											//info.Format("第%d个用户\n",rVal);//总人数
											//pDlg->AppendLog(info);
											//for (int o=0;o<sje.count; o++)
											//{	
											//	if(sje.users[o].state != 0)
											//	{
											//		info.Format("用户%s\n",sje.users[o].object);//总人数
											//		pDlg->AppendLog(info);
											//	}
											//}
											memset( recvmsg, '\0' ,sizeof(recvmsg) );//初始化
											strcpy(recvmsg, StringProcess(prefix, "-255", LOGIN));//反馈客户的消息
											send(fd_array_connect[i], recvmsg, 1024, 0);
											//为用户发送聊天室所有用户用户名“USERLIST”（循环发送）
											ListInfor uall;//所有用户
											uall = pDlg->p_userall.FindAll();
											info.Format("聊天室当前总人数%d/(最大128人)\n",uall.count);
											pDlg->AppendLog(info);
											pDlg->AppendLog("\n");
											for(int s=0; s<uall.count; s++)
											{
												memset(recvmsg, '\0', sizeof(recvmsg));
												memset(prefix, '\0', sizeof(prefix));
												if(uall.users[s].state == 0)//离线
												{
													StringProcess(prefix, "0", USERLIST);
												}
												else//在线
												{
													StringProcess(prefix, "1", USERLIST);
												}
												strcat(prefix,uall.users[s].object);//USERLIST|1/0|username|
												strcpy(recvmsg, prefix);
												rVal = send(n2.state, recvmsg, 1024, 0);
												if(rVal == SOCKET_ERROR)
												{
													info.Format("向用户%s发送其他用户在线信息异常，错误代码: %d\n", n2.object, WSAGetLastError());
													pDlg->AppendLog(info);
													pDlg->AppendLog("\n");
												}
											}
											////////////群发上线消息/////////////
											ListInfor upuser;
											upuser = pDlg->p_userall.FindAll();
											for (int j=0; j<upuser.count; j++)
											{
												if(upuser.users[j].state != 0 && upuser.users[j].state != n2.state)
												{
													char upmsg[1024]={0};
													StringProcess(prefix, "1", USERLIST);
													strcpy(upmsg, prefix);
													strcat(upmsg, n2.object);
													send(upuser.users[j].state, upmsg, 1024, 0);
												}
											}
											////////////////////////////////////
										/*	插入用户列表|如果在离线名单上移除该离线用户插入到在线名单
											FindString有数据却搜索不到？？？*/
											//////////////刷新列表///////////////
											pDlg->s_userlist.ResetContent();
											ListInfor duser;
											char downusername[30]={0};
											duser = pDlg->p_userall.FindAll();//全部用户
											/*info.Format("%d\n",duser.count);
											pDlg->AppendLog(info);*/
											for(int j=0; j<duser.count; j++)
											{
												if(duser.users[j].state == 0)
												{
													memset(downusername, '\0', sizeof(downusername));
													StringProcess(downusername, "(离线)", duser.users[j].object);//downusername(离线)
													pDlg->s_userlist.AddString((LPCTSTR)downusername);
												}
												else
												{
													memset(downusername, '\0', sizeof(downusername));
													StringProcess(downusername, "(在线)", duser.users[j].object);//downusername(离线)
													pDlg->s_userlist.InsertString(0,(LPCTSTR)downusername);
												}
											}
											///////////////发送离线消息////////
											char path[1024]={0};
											strcpy(path, "./chat/");
											strcat(path, n2.object);
											strcat(path, ".txt");
											FILE *out;
											out = fopen(path, "r");
											char ch = fgetc(out);
											if (!feof(out))
											{
												do{
													char dmsg[1024]={0};
													char downmsg[1024]={0};
													fgets(dmsg, 1013, out);
													StringProcess(downmsg, dmsg, RADIO);
													send(n2.state, downmsg, 1024, 0);
												}while(!feof(out));
											}
											fclose(out);
											FILE *init = fopen(path, "w");//初始化
											fclose(init);
										}
									}
								  }break;//PASSWORD
							case 6:{
								memset(filename, '\0', sizeof(filename));
								strcpy(filename, "./recv/");
								strcat(filename, GetFileName(recvmsg));//获得文件名
								info.Format("接收文件%s\n", recvmsg);
								pDlg->AppendLog(info);
								FILE *initfile = fopen(filename,"wb");//创建文件
								fclose(initfile);
								   }break;//FFILE
							case 7:;break;//USERLIST
							default:
								{
									memset(recvmsg, '\0', sizeof(recvmsg));
									/*info.Format("接收文件内容%s\n", recvmsg);
									pDlg->AppendLog(info);*/
									/*info.Format("接收文件%s\n", filename);
									pDlg->AppendLog(info);*/
									FILE *file = fopen(filename, "ab");
									fwrite(msg,1,1024,file);
									fclose(file);
									pDlg->AppendLog("接收文件。。。\n");
								}break;
						}
					}//////////////////////////////////////////
				}
			}//for( i=0; i<MaxListenSize; ++i )
			//检查是否为新的连接进入
			if( FD_ISSET( pDlg->s_socket, &fdRead)) //有客户端连接，但未进行用户识别
			{
				/*基本连接测试
				info.Format("发现一个新的客户连接\n");
				pDlg->AppendLog(info);
				pDlg->AppendLog("---------------------------------------------------"
				"-------------------------------------------------\n");*/
				SOCKET c_socket; 
				struct sockaddr_in ca;
				int calen = sizeof(ca);
				c_socket = accept( pDlg->s_socket, (sockaddr*)&ca, &calen);
				if( c_socket == WSAEWOULDBLOCK )
				{
					info.Format("阻塞了\n");
					pDlg->AppendLog(info);
					pDlg->AppendLog("\n");
					continue;
				}
				else if( c_socket == INVALID_SOCKET  )
				{
					info.Format("接受连接请求失败: %d\n", WSAGetLastError());
					pDlg->AppendLog(info);
					pDlg->AppendLog("\n");
					continue;
				}
				//新的连接可以使用,查看待决处理队列
				if( nConnNum<MAX_LISTENSIZE )  //在线人数小于MAX_LISTENSIZE
				{
					memset(recvmsg, '\0', sizeof(recvmsg));
					strcpy(recvmsg, StringProcess(prefix, "123", PASSWORD));
					rVal = send( c_socket, recvmsg, 1024, 0 );//人数未满，发送无效消息
					if (rVal == SOCKET_ERROR) //发送异常  可能有BUG
					{
						info.Format("新连接异常：%d\n", WSAGetLastError());
						pDlg->AppendLog(info);
						pDlg->AppendLog("\n");
						closesocket( c_socket );//关闭该套接字
					}
					else//添加新客户端信息
					{
						for(i=0; i<MAX_LISTENSIZE; i++)
						{
							if( fd_array_connect[i] == 0 )
							{
								fd_array_connect[i] = c_socket;
								break;
							}
						}
						++nConnNum;
						/*info.Format("新的客户端信息:[%d] 地址：%s端口:%d\n", c_socket, inet_ntoa(ca.sin_addr), ntohs(ca.sin_port));
						pDlg->AppendLog(info);
						pDlg->AppendLog("---------------------------------------------------"
						"-------------------------------------------------\n");*/
					}
					
				}
				else//最大在线人数MAX_LISTENSIZE已满,无法连接
				{
					info.Format("服务器端连接数已满: %d\n", c_socket);
					pDlg->AppendLog(info);
					pDlg->AppendLog("\n");
					memset(recvmsg, '\0', sizeof(recvmsg));
					strcpy(recvmsg, StringProcess(prefix, "111", FULL));
					send( c_socket, recvmsg, 1024, 0 );//发送人数已满消息
					closesocket( c_socket );//关闭该套接字
				}
			}//if( FD_ISSET( sersoc, &fdRead) )
		}
	}//while(true)
	memset(recvmsg, '\0', sizeof(recvmsg));
}

void CserverDlg::AppendLog(CString info)
{
	s_messagelog.SetSel(-1);//将光标定位到日志框末尾
	s_messagelog.ReplaceSel((LPCTSTR)info);//附加新的日志内容
	s_messagelog.ShowScrollBar(SB_VERT,TRUE);//显示滚动条
	s_messagelog.SetSel(-1);//将光标定位到日志框末尾
}

void CserverDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString txt;
	b_start.GetWindowText(txt);	//获取按钮上的文本
	if (txt == "启动服务器")
	{
		//创建套接字
		s_socket = socket(AF_INET,SOCK_STREAM,0);

		CString txtPort;
		s_port.GetWindowText(txtPort);	//获取端口号的文本
		int port = atoi(txtPort);			//转换成整数端口

		struct sockaddr_in sa;				//定义服务器地址
		sa.sin_family = AF_INET;			//地址家族
		sa.sin_port = htons(port);			//网络端口
		sa.sin_addr.s_addr = INADDR_ANY;	//本机地址

		CString info;
		 //绑定服务器
		if (bind(s_socket,(struct sockaddr *)&sa,sizeof(sa)) == SOCKET_ERROR)
		{
			AfxMessageBox("端口号被占用!");
			info.Format("绑定失败！错误代码: %d\n", WSAGetLastError());
			AppendLog(info);
			AppendLog("\n");
			closesocket(s_socket);
			return;
		}
		AppendLog("服务器启动成功!\n");		//显示日志
		AppendLog("\n");
		//设置监听
		AppendLog("服务器开始监听端口\n");
		AppendLog("\n");
		listen(s_socket,MAX_LISTENSIZE);
		//到这里服务器启动成功
		s_port.EnableWindow(FALSE);		//禁止修改端口号
		b_start.SetWindowText("停止服务器");	//将启动按钮改成停止按钮

		closeServer = false; //开启服务器
		////////////添加离线用户///////////////
		s_userlist.ResetContent();
		ListInfor duser;
		char downusername[30]={0};
		duser = p_userall.FindAll();//全部用户
		/*info.Format("%d\n",duser.count);
		AppendLog(info);*/
		for(int j=0; j<duser.count; j++)
		{	
			if(duser.users[j].state != 0)
			{
				memset(downusername, '\0', sizeof(downusername));
				StringProcess(downusername, "(在线)", duser.users[j].object);//downusername(在线)
				/*info.Format("%s\n",downusername);
				AppendLog(info);*/
				s_userlist.InsertString(0,(LPCTSTR)downusername);
			}
			if(duser.users[j].state == 0)
			{
				memset(downusername, '\0', sizeof(downusername));
				StringProcess(downusername, "(离线)", duser.users[j].object);//downusername(离线)
				s_userlist.AddString((LPCTSTR)downusername);
			}
		}
		/////////////////////////////////////
		_beginthread(selectThread,0,this);
	}
	else
	{
		s_userlist.ResetContent();//清空列表所有用户
		p_userall.UpdateUserAll();//用户信息写入文件
		closeServer = true;  //关闭服务器
		shutdown(s_socket, SD_BOTH);
		closesocket(s_socket);
		s_port.EnableWindow(TRUE);		//可以修改端口号
		b_start.SetWindowText("启动服务器");	//将停止按钮改成启动按钮
		AppendLog("服务器已停止!\n");		//显示日志
		AppendLog("\n");
	}
}


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

//switch(CommandCategory(command))//判断类别
//{
	//case 1:;
	//	break;//PERSON
	//case 2:;
	//	break;//MESSAGE
	//case 3:;
	//	break;//RADIO
	//case 4:;
	//	break;//ID
	//case 5:;
	//	break;//PASSWORD
	//default:;
	//	break;//FULL
//}	


void CserverDlg::DeleteUserName(CString info)
{
	d_user.SetSel(-1);
	d_user.ReplaceSel((LPCTSTR)info);
	d_user.ShowScrollBar(SB_VERT,FALSE);
	d_user.SetSel(-1);
}


void CserverDlg::OnLbnSelchangeList3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString user;
	char username[30]={0};
	int nCurSel;
    nCurSel = s_userlist.GetCurSel(); 
	s_userlist.GetText(nCurSel, user);
	d_user.SetWindowText("");

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
	DeleteUserName(user);
}


void CserverDlg::OnBnClickedButton4()//删除
{
	// TODO: 在此添加控件通知处理程序代码
	char name[30]={0};
	CString info;
	CString txt;
	d_user.GetWindowText(txt);//得到要删除的用户名
	strcpy(name, (LPSTR)(LPCTSTR)txt);
	p_userall.DeleteUser(name);
	d_user.SetWindowText("");
	/////////////////群发离线消息//////////
	char prefix[1024]={0};
	ListInfor deuser;
	deuser = p_userall.FindAll();
	for (int j=0; j<deuser.count; j++)
	{
		if(deuser.users[j].state != 0)
		{
			char demsg[1024]={0};
			StringProcess(prefix, "7", USERLIST);
			strcpy(demsg, prefix);
			strcat(demsg, name);
			send(deuser.users[j].state, demsg, 1024, 0);
		}
	}
	///////////////////////////////////////
	//////////////更新用户列表///////////////
	s_userlist.ResetContent();
	ListInfor duser;
	char downusername[30]={0};
	duser = p_userall.FindAll();
	info.Format("%d\n",duser.count);
	AppendLog(info);
	for(int j=0; j<duser.count; j++)
	{
		if(duser.users[j].state == 0)
		{
			memset(downusername, '\0', sizeof(downusername));
			StringProcess(downusername, "(离线)", duser.users[j].object);//downusername(离线)
			s_userlist.AddString((LPCTSTR)downusername);
		}
		else
		{
			memset(downusername, '\0', sizeof(downusername));
			StringProcess(downusername, "(在线)", duser.users[j].object);//downusername(离线)
			s_userlist.InsertString(0,(LPCTSTR)downusername);
		}
	}
	///////////////////////////////////////
}


void CserverDlg::OnBnClickedButton5()//选择文件
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE);
	if(IDCANCEL == dlg.DoModal())
		return ;
	CString filename;
	filename = dlg.GetPathName();
	s_message.SetWindowText("");
	s_message.SetWindowText(filename);
}


void CserverDlg::OnBnClickedButton3()//发送文件(缺陷：只对在线用户发送)
{
	// TODO: 在此添加控件通知处理程序代码
	CString filename;
	char prefix[1024]={0};
	char buffer[1024]={0};
	s_message.GetWindowText(filename);
	s_message.SetWindowText("");
	for (int i=0; i<MAX_LISTENSIZE; i++)
	{
		if (fd_array_connect[i] != 0)
		{
			memset(prefix, '\0',sizeof(prefix));
			StringProcess(prefix,(LPSTR)(LPCTSTR)filename, FFILE);
			send(fd_array_connect[i],prefix,1024,0);//path
			FILE *file = fopen((LPSTR)(LPCTSTR)filename, "rb");//读取
			if(file != NULL)
			{
				while (fread(buffer,1,1024,file) >= 0)
				{
					send(fd_array_connect[i],buffer,1024,0);
					if(feof(file))
						break;
				}
				fclose(file);
				AppendLog("发送文件成功\n\n");
			}
		}
	}
	
}

void CserverDlg::OnBnClickedButton2()//发送系统消息
{
	// TODO: 在此添加控件通知处理程序代码
	CString txt;
	CString info;
	char sendmsg[1024]={0};
	char prefix[1024]={0};
	int rVal;
	s_message.GetWindowText(txt);//获取系统消息
	s_message.SetWindowText("");
	if((int)strlen((LPSTR)(LPCTSTR)txt) == 0)
	{
		AfxMessageBox("发送消息为空");
		return ;
	}
	strcpy(sendmsg, "系统:");
	strcat(sendmsg, (LPSTR)(LPCTSTR)txt);
	StringProcess(prefix, sendmsg, RADIO);
	for (int j=0; j<MAX_LISTENSIZE; j++)//对在线用户群发，保存离线用户消息
	{
		if(fd_array_connect[j] != 0)//在线用户
		{
			rVal = send(fd_array_connect[j], prefix, 1024, 0);
			if (rVal == SOCKET_ERROR)
			{
				info.Format("用户消息群发异常，错误代码: %d\n", WSAGetLastError());
				AppendLog(info);
				AppendLog("\n");
			}
		}
	}
	AppendLog("发送系统消息成功\n\n");
	//为离线用户保存聊天记录
	ListInfor userall;
	userall = p_userall.FindAll();
	for(int j=0; j<userall.count; j++)
	{
		if(userall.users[j].state == 0)
		{
			char chatfile[100]={0};
			strcpy(chatfile, "./chat/");
			strcat(chatfile, userall.users[j].object);
			strcat(chatfile, ".txt");//"./chat/name.txt"
			FILE *in = fopen(chatfile, "a+");//追加
			fputs(sendmsg,in);
			fputs("\n",in);
			fclose(in);
		}
	}
}
