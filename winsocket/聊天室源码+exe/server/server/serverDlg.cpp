
// serverDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "server.h"
#include "serverDlg.h"
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


// CserverDlg �Ի���




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


// CserverDlg ��Ϣ�������

BOOL CserverDlg::OnInitDialog()
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
	s_port.SetWindowText("9000");

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CserverDlg::OnPaint()
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
HCURSOR CserverDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CserverDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}

//selectģ�Ͷ��߳�
static bool closeServer = true;
int fd_array_connect[MAX_LISTENSIZE] = {0};//�������������û��׽���
ListInfor p_usernew;// ����֤���û�
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
	fd_set fdRead;//���ڶ�����״̬�ļ���
	//fd_set fdWrite;//���ڿɶ�����״̬�ļ���
	timeval tv={10,0};//���õȴ�ʱ��Ϊ10��
	int     i = 0;
	int     nConnNum = 0;
	//selectģ��
	int nMode = 1;
	//  ������ģʽ�趨
	rVal = ioctlsocket( pDlg->s_socket, FIONBIO, (u_long FAR*)&nMode );
	if( rVal == SOCKET_ERROR )
	{
		info.Format("������ģʽ����ʧ��: %d\n", WSAGetLastError());
		pDlg->AppendLog(info);
		pDlg->AppendLog("\n");
		closesocket(pDlg->s_socket);
		return ;
	}
	/*����ʹ��
	info.Format("���÷�������ģʽ: %s\n", nMode==0? "����ģʽ":"������ģʽ");
	pDlg->AppendLog(info);
	pDlg->AppendLog("---------------------------------------------------"
		"-------------------------------------------------\n");
	info.Format("��ʼ׼����������\n");
	pDlg->AppendLog(info);
	pDlg->AppendLog("---------------------------------------------------"
		"-------------------------------------------------\n");*/
	CreateListInfor(&p_usernew);//��ʼ��
	while (pDlg->s_socket != INVALID_SOCKET)  //�����socket��������ʱ
	{
		FD_ZERO(&fdRead);//������׽��ּ������
		FD_SET( pDlg->s_socket, &fdRead );  //��sersoc����fdRead���н���select����
       
		for( i=0; i<MAX_LISTENSIZE; i++ )
		{
			if( fd_array_connect[i] != 0 )
			{
			/*	info.Format("���ӵ��׽���[%d]: %d\n",i+1,fd_array_connect[i] );
				pDlg->AppendLog(info);
				pDlg->AppendLog("---------------------------------------------------"
		"-------------------------------------------------\n");*/
				FD_SET( fd_array_connect[i], &fdRead );//�������û�����fdRead
			}
		}
		//����selectģʽ���м���
		rVal = select( 0, &fdRead, NULL, NULL, &tv );//����Ƿ����׽��ֿɶ� ���Ƿ����׽��ִ��ڶ�����״̬ select���ؿ��õ��׽��ָ���
		if( rVal == SOCKET_ERROR )
		{
			info.Format("ʧ�ܣ��������: %d\n", WSAGetLastError());
			pDlg->AppendLog(info);
			pDlg->AppendLog("\n");
			break;
		}
		else if( rVal == 0 )
		{
			/*���Գ�ʱ
			info.Format("��ʱ: %d ��\n",tv.tv_sec);
			pDlg->AppendLog(info);
			pDlg->AppendLog("---------------------------------------------------"
		"-------------------------------------------------\n");*/
			continue; //��������
		}
		else//�ɹ�����selectģ��
		{
			if (closeServer) //������δ����
			{
				break;
			}
			for( i=0; i<MAX_LISTENSIZE; i++ )
			{
				if( FD_ISSET(fd_array_connect[i], &fdRead) )//���fd_array_connect[i]�Ƿ���fdRead������
				{
					memset( recvmsg, '\0' ,sizeof(recvmsg) );//��ʼ��
					rVal = recv( fd_array_connect[i], recvmsg, 1024, 0 );//�����û����͵���Ϣ
					if( rVal == 0 )
					{
						if((int)strlen(pDlg->p_userall.FindUser(fd_array_connect[i]).object)==0)
							info.Format("�ͻ���%d�Ѿ��ر�\n",fd_array_connect[i]);//�û�����
						else
							info.Format("�û�%s������\n",pDlg->p_userall.FindUser(fd_array_connect[i]).object);//�û�����
						pDlg->AppendLog(info);
						pDlg->AppendLog("\n");
						closesocket( fd_array_connect[i] );
						//���Ѿ��رյ�SOCKET��FD����ɾ��
						FD_CLR( fd_array_connect[i], &fdRead );
						/////////////////Ⱥ��������Ϣ//////////
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
						pDlg->p_userall.StateChange(fd_array_connect[i]);//�û�����
						fd_array_connect[i] = 0;
						--nConnNum;
						
						//�����û��б�|����������������Ƴ��������û����뵽��������
						/*FindString������ȴ��������������*/
						//////////////��������û�///////////////
						pDlg->s_userlist.ResetContent();
						ListInfor duser;
						char downusername[30]={0};
						duser = pDlg->p_userall.FindAll();//�����û�
						/*����������
						info.Format("%d\n",duser.count);
						pDlg->AppendLog(info);*/
						for(int j=0; j<duser.count; j++)
						{
							if(duser.users[j].state == 0)
							{
								memset(downusername, '\0', sizeof(downusername));
								StringProcess(downusername, "(����)", duser.users[j].object);//downusername(����)
								pDlg->s_userlist.AddString((LPCTSTR)downusername);
							}
							else
							{
								memset(downusername, '\0', sizeof(downusername));
								StringProcess(downusername, "(����)", duser.users[j].object);//downusername(����)
								pDlg->s_userlist.InsertString(0,(LPCTSTR)downusername);
							}
						}
					}
					else if(rVal == SOCKET_ERROR)
					{
						if((int)strlen(pDlg->p_userall.FindUser(fd_array_connect[i]).object)==0)
							info.Format("�ͻ���ǿ�ƶϿ�������: %d\n", WSAGetLastError());
						else
							info.Format("�û�%sǿ�ƶϿ�������: %d\n", WSAGetLastError());
						pDlg->AppendLog(info);
						pDlg->AppendLog("\n");
						closesocket( fd_array_connect[i] );
						//���Ѿ��رյ�SOCKET��FD����ɾ��
						FD_CLR( fd_array_connect[i], &fdRead );
						/////////////////Ⱥ��������Ϣ//////////
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
						pDlg->p_userall.StateChange(fd_array_connect[i]);//�û�����
						fd_array_connect[i] = 0;
						--nConnNum;
						
						//�����û��б�|����������������Ƴ��������û����뵽��������
						/*FindString������ȴ��������������*/
						//////////////�����б�///////////////
						pDlg->s_userlist.ResetContent();
						ListInfor duser;
						char downusername[30]={0};
						duser = pDlg->p_userall.FindAll();
						/*����������
						info.Format("%d\n",duser.count);
						pDlg->AppendLog(info);*/
						for(int j=0; j<duser.count; j++)
						{
							if(duser.users[j].state == 0)
							{
								memset(downusername, '\0', sizeof(downusername));
								StringProcess(downusername, "(����)", duser.users[j].object);//downusername(����)
								pDlg->s_userlist.AddString((LPCTSTR)downusername);
							}
							else
							{
								memset(downusername, '\0', sizeof(downusername));
								StringProcess(downusername, "(����)", duser.users[j].object);//downusername(����)
								pDlg->s_userlist.InsertString(0,(LPCTSTR)downusername);
							}
						}
					}
					else//����Ϣ���з�������Ⱥ����˽�ġ��û��жϡ���������///////////////////////////////////////
					{

						Infor n3;
						char msg[1024]={0};
						//////////////////////////////////////////
						StringAnalysis(recvmsg,command);//������Ϣ����ÿ��ѶϢ
						switch(CommandCategory(command))//�ж����
						{
							case 1://ȱ�ݣ�ͬһʱ��ֻ��һ���û�����˽����Ϣ�����Ż���
								{
									n3 = pDlg->p_userall.FindUser(recvmsg);//�û���
									/*���Եõ����û���
									info.Format("%s\n", n3.object);
									pDlg->AppendLog(info);
									pDlg->AppendLog("---------------------------------------------------"
												"-------------------------------------------------\n");*/
								 }break;//PERSON
							case 2:
								{
									char sendmsg[1024]={0};
									char chatfile[1024]={0};
									if(n3.state != 0)//���û�����ֱ��ת��
									{
										memset(prefix, '\0', sizeof(prefix));
										strcpy(sendmsg, StringProcess(prefix, recvmsg, RADIO));
										rVal = send(n3.state, sendmsg, 1024, 0);
										info.Format("ת��˽�����\n");
										pDlg->AppendLog(info);
										pDlg->AppendLog("\n");
									}
									else
									{
										info.Format("����������Ϣ���\n");
										pDlg->AppendLog(info);
										pDlg->AppendLog("\n");
										strcpy(chatfile, "./chat/");
										strcat(chatfile, n3.object);
										strcat(chatfile, ".txt");//"./chat/name.txt"
										FILE *in = fopen(chatfile, "a+");//׷��
										fputs(recvmsg,in);
										fputs("\n",in);

										fclose(in);
									}
								}break;//MESSAGE
							case 3:
								{
									/*�����յ�������
									info.Format("%s\n", recvmsg);
									pDlg->AppendLog(info);
									pDlg->AppendLog("---------------------------------------------------"
												"-------------------------------------------------\n");*/
									for (int j=0; j<MAX_LISTENSIZE; j++)//�������û�Ⱥ�������������û���Ϣ
									{
										if(fd_array_connect[j] != 0 && fd_array_connect[j] != fd_array_connect[i])//�����û�
										{
											//��Ϣ�ӹ�
											char sendmsg[1024]={0};
											strcpy(sendmsg, StringProcess(prefix, recvmsg, RADIO));//����Ⱥ����Ϣ
											rVal = send(fd_array_connect[j], sendmsg, 1024, 0);
											if (rVal == SOCKET_ERROR)
											{
												info.Format("�û���ϢȺ���쳣���������: %d\n", WSAGetLastError());
												pDlg->AppendLog(info);
												pDlg->AppendLog("\n");
											}
										}
									}
									info.Format("ת��Ⱥ�����\n");
									pDlg->AppendLog(info);
									pDlg->AppendLog("\n");
									//Ϊ�����û����������¼
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
											FILE *in = fopen(chatfile, "a+");//׷��
											fputs(recvmsg,in);
											fputs("\n",in);
											fclose(in);
										}
									}
								}break;//

							case 4:
								{
									Infor n1;
									strcpy(n1.object, recvmsg);//����ͻ��˷��͵��û���
									n1.state = fd_array_connect[i];//����ͻ����׽���
									strcpy(n1.password, "");//��ʱ����Ϊ��
									AddNewUser(&p_usernew, n1);//��ʱ����δ��֤���û���Ϣ
									memset( recvmsg, '\0' ,sizeof(recvmsg) );//��ʼ��
									strcpy(recvmsg, StringProcess(prefix, "-255", LOGIN));//�����ͻ�����Ϣ
									rVal = send(fd_array_connect[i], recvmsg, 1024, 0);
									if (rVal == SOCKET_ERROR) //�����쳣
									{
										info.Format("�û����������쳣���������%s\n", WSAGetLastError());
										pDlg->AppendLog(info);
										pDlg->AppendLog("\n");
									}
								}break;//ID
							case 5:
								{
									Infor n2;
									strcpy(n2.object, "");//�û���Ϊ��
									strcpy(n2.password, recvmsg);//����ͻ��˷��͵�����
									n2.state = fd_array_connect[i];//����ͻ����׽���
									//�õ����Ըÿͻ��˵������û���Ϣ
									int oneuser;
									oneuser =  AddNewUser(&p_usernew, n2);
									if(oneuser != -1)//�û���Ϣ��p_usernew�еĴ洢λ��
									{//�õ��û�������Ϣ
										strcpy(n2.object, p_usernew.users[oneuser].object);
										strcpy(n2.password, p_usernew.users[oneuser].password);
										n2.state = p_usernew.users[oneuser].state;
										pDlg->AppendLog(info);
										DeleteNewUser(&p_usernew, oneuser);//ɾ�������е��û�
										//��֤�û���Ϣ
										rVal = pDlg->p_userall.IsUser(n2.object, n2.password, n2.state);
										if (rVal == -128)//��������
										{
											memset(recvmsg, 0, sizeof(recvmsg));
											strcpy(recvmsg,StringProcess(prefix, "-255", FULL));//����������Ϣ
											send( fd_array_connect[i], recvmsg, 1024, 0 );//��������������Ϣ
											closesocket( fd_array_connect[i] );//�رո��׽���
											//���Ѿ��رյ�SOCKET��FD����ɾ��
											FD_CLR( fd_array_connect[i], &fdRead );
											fd_array_connect[i] = 0;
											--nConnNum;
										}
										else if (rVal == -255)//�������
										{
											memset(recvmsg, '\0', sizeof(recvmsg));
											strcpy(recvmsg, StringProcess(prefix, "-255", PASSWORD));//�����޹���Ϣ����ʾ��¼ʧ�ܣ��������
											send( fd_array_connect[i], recvmsg, 1024, 0 );
										}
										else if (rVal == -246)//�ص�
										{
											memset(recvmsg, '\0', sizeof(recvmsg));
											strcpy(recvmsg, StringProcess(prefix, "-246", PASSWORD));//�����޹���Ϣ����ʾ��¼ʧ��
											send( fd_array_connect[i], recvmsg, 1024, 0 );
										}
										else//��¼�ɹ�
										{
											info.Format("�û�%s������~~~\n",n2.object);
											pDlg->AppendLog(info);
											pDlg->AppendLog("\n");
											//ListInfor sje = pDlg->p_userall.FindAll();
											//info.Format("��%d���û�\n",rVal);//������
											//pDlg->AppendLog(info);
											//for (int o=0;o<sje.count; o++)
											//{	
											//	if(sje.users[o].state != 0)
											//	{
											//		info.Format("�û�%s\n",sje.users[o].object);//������
											//		pDlg->AppendLog(info);
											//	}
											//}
											memset( recvmsg, '\0' ,sizeof(recvmsg) );//��ʼ��
											strcpy(recvmsg, StringProcess(prefix, "-255", LOGIN));//�����ͻ�����Ϣ
											send(fd_array_connect[i], recvmsg, 1024, 0);
											//Ϊ�û����������������û��û�����USERLIST����ѭ�����ͣ�
											ListInfor uall;//�����û�
											uall = pDlg->p_userall.FindAll();
											info.Format("�����ҵ�ǰ������%d/(���128��)\n",uall.count);
											pDlg->AppendLog(info);
											pDlg->AppendLog("\n");
											for(int s=0; s<uall.count; s++)
											{
												memset(recvmsg, '\0', sizeof(recvmsg));
												memset(prefix, '\0', sizeof(prefix));
												if(uall.users[s].state == 0)//����
												{
													StringProcess(prefix, "0", USERLIST);
												}
												else//����
												{
													StringProcess(prefix, "1", USERLIST);
												}
												strcat(prefix,uall.users[s].object);//USERLIST|1/0|username|
												strcpy(recvmsg, prefix);
												rVal = send(n2.state, recvmsg, 1024, 0);
												if(rVal == SOCKET_ERROR)
												{
													info.Format("���û�%s���������û�������Ϣ�쳣���������: %d\n", n2.object, WSAGetLastError());
													pDlg->AppendLog(info);
													pDlg->AppendLog("\n");
												}
											}
											////////////Ⱥ��������Ϣ/////////////
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
										/*	�����û��б�|����������������Ƴ��������û����뵽��������
											FindString������ȴ��������������*/
											//////////////ˢ���б�///////////////
											pDlg->s_userlist.ResetContent();
											ListInfor duser;
											char downusername[30]={0};
											duser = pDlg->p_userall.FindAll();//ȫ���û�
											/*info.Format("%d\n",duser.count);
											pDlg->AppendLog(info);*/
											for(int j=0; j<duser.count; j++)
											{
												if(duser.users[j].state == 0)
												{
													memset(downusername, '\0', sizeof(downusername));
													StringProcess(downusername, "(����)", duser.users[j].object);//downusername(����)
													pDlg->s_userlist.AddString((LPCTSTR)downusername);
												}
												else
												{
													memset(downusername, '\0', sizeof(downusername));
													StringProcess(downusername, "(����)", duser.users[j].object);//downusername(����)
													pDlg->s_userlist.InsertString(0,(LPCTSTR)downusername);
												}
											}
											///////////////����������Ϣ////////
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
											FILE *init = fopen(path, "w");//��ʼ��
											fclose(init);
										}
									}
								  }break;//PASSWORD
							case 6:{
								memset(filename, '\0', sizeof(filename));
								strcpy(filename, "./recv/");
								strcat(filename, GetFileName(recvmsg));//����ļ���
								info.Format("�����ļ�%s\n", recvmsg);
								pDlg->AppendLog(info);
								FILE *initfile = fopen(filename,"wb");//�����ļ�
								fclose(initfile);
								   }break;//FFILE
							case 7:;break;//USERLIST
							default:
								{
									memset(recvmsg, '\0', sizeof(recvmsg));
									/*info.Format("�����ļ�����%s\n", recvmsg);
									pDlg->AppendLog(info);*/
									/*info.Format("�����ļ�%s\n", filename);
									pDlg->AppendLog(info);*/
									FILE *file = fopen(filename, "ab");
									fwrite(msg,1,1024,file);
									fclose(file);
									pDlg->AppendLog("�����ļ�������\n");
								}break;
						}
					}//////////////////////////////////////////
				}
			}//for( i=0; i<MaxListenSize; ++i )
			//����Ƿ�Ϊ�µ����ӽ���
			if( FD_ISSET( pDlg->s_socket, &fdRead)) //�пͻ������ӣ���δ�����û�ʶ��
			{
				/*�������Ӳ���
				info.Format("����һ���µĿͻ�����\n");
				pDlg->AppendLog(info);
				pDlg->AppendLog("---------------------------------------------------"
				"-------------------------------------------------\n");*/
				SOCKET c_socket; 
				struct sockaddr_in ca;
				int calen = sizeof(ca);
				c_socket = accept( pDlg->s_socket, (sockaddr*)&ca, &calen);
				if( c_socket == WSAEWOULDBLOCK )
				{
					info.Format("������\n");
					pDlg->AppendLog(info);
					pDlg->AppendLog("\n");
					continue;
				}
				else if( c_socket == INVALID_SOCKET  )
				{
					info.Format("������������ʧ��: %d\n", WSAGetLastError());
					pDlg->AppendLog(info);
					pDlg->AppendLog("\n");
					continue;
				}
				//�µ����ӿ���ʹ��,�鿴�����������
				if( nConnNum<MAX_LISTENSIZE )  //��������С��MAX_LISTENSIZE
				{
					memset(recvmsg, '\0', sizeof(recvmsg));
					strcpy(recvmsg, StringProcess(prefix, "123", PASSWORD));
					rVal = send( c_socket, recvmsg, 1024, 0 );//����δ����������Ч��Ϣ
					if (rVal == SOCKET_ERROR) //�����쳣  ������BUG
					{
						info.Format("�������쳣��%d\n", WSAGetLastError());
						pDlg->AppendLog(info);
						pDlg->AppendLog("\n");
						closesocket( c_socket );//�رո��׽���
					}
					else//����¿ͻ�����Ϣ
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
						/*info.Format("�µĿͻ�����Ϣ:[%d] ��ַ��%s�˿�:%d\n", c_socket, inet_ntoa(ca.sin_addr), ntohs(ca.sin_port));
						pDlg->AppendLog(info);
						pDlg->AppendLog("---------------------------------------------------"
						"-------------------------------------------------\n");*/
					}
					
				}
				else//�����������MAX_LISTENSIZE����,�޷�����
				{
					info.Format("������������������: %d\n", c_socket);
					pDlg->AppendLog(info);
					pDlg->AppendLog("\n");
					memset(recvmsg, '\0', sizeof(recvmsg));
					strcpy(recvmsg, StringProcess(prefix, "111", FULL));
					send( c_socket, recvmsg, 1024, 0 );//��������������Ϣ
					closesocket( c_socket );//�رո��׽���
				}
			}//if( FD_ISSET( sersoc, &fdRead) )
		}
	}//while(true)
	memset(recvmsg, '\0', sizeof(recvmsg));
}

void CserverDlg::AppendLog(CString info)
{
	s_messagelog.SetSel(-1);//����궨λ����־��ĩβ
	s_messagelog.ReplaceSel((LPCTSTR)info);//�����µ���־����
	s_messagelog.ShowScrollBar(SB_VERT,TRUE);//��ʾ������
	s_messagelog.SetSel(-1);//����궨λ����־��ĩβ
}

void CserverDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString txt;
	b_start.GetWindowText(txt);	//��ȡ��ť�ϵ��ı�
	if (txt == "����������")
	{
		//�����׽���
		s_socket = socket(AF_INET,SOCK_STREAM,0);

		CString txtPort;
		s_port.GetWindowText(txtPort);	//��ȡ�˿ںŵ��ı�
		int port = atoi(txtPort);			//ת���������˿�

		struct sockaddr_in sa;				//�����������ַ
		sa.sin_family = AF_INET;			//��ַ����
		sa.sin_port = htons(port);			//����˿�
		sa.sin_addr.s_addr = INADDR_ANY;	//������ַ

		CString info;
		 //�󶨷�����
		if (bind(s_socket,(struct sockaddr *)&sa,sizeof(sa)) == SOCKET_ERROR)
		{
			AfxMessageBox("�˿ںű�ռ��!");
			info.Format("��ʧ�ܣ��������: %d\n", WSAGetLastError());
			AppendLog(info);
			AppendLog("\n");
			closesocket(s_socket);
			return;
		}
		AppendLog("�����������ɹ�!\n");		//��ʾ��־
		AppendLog("\n");
		//���ü���
		AppendLog("��������ʼ�����˿�\n");
		AppendLog("\n");
		listen(s_socket,MAX_LISTENSIZE);
		//����������������ɹ�
		s_port.EnableWindow(FALSE);		//��ֹ�޸Ķ˿ں�
		b_start.SetWindowText("ֹͣ������");	//��������ť�ĳ�ֹͣ��ť

		closeServer = false; //����������
		////////////��������û�///////////////
		s_userlist.ResetContent();
		ListInfor duser;
		char downusername[30]={0};
		duser = p_userall.FindAll();//ȫ���û�
		/*info.Format("%d\n",duser.count);
		AppendLog(info);*/
		for(int j=0; j<duser.count; j++)
		{	
			if(duser.users[j].state != 0)
			{
				memset(downusername, '\0', sizeof(downusername));
				StringProcess(downusername, "(����)", duser.users[j].object);//downusername(����)
				/*info.Format("%s\n",downusername);
				AppendLog(info);*/
				s_userlist.InsertString(0,(LPCTSTR)downusername);
			}
			if(duser.users[j].state == 0)
			{
				memset(downusername, '\0', sizeof(downusername));
				StringProcess(downusername, "(����)", duser.users[j].object);//downusername(����)
				s_userlist.AddString((LPCTSTR)downusername);
			}
		}
		/////////////////////////////////////
		_beginthread(selectThread,0,this);
	}
	else
	{
		s_userlist.ResetContent();//����б������û�
		p_userall.UpdateUserAll();//�û���Ϣд���ļ�
		closeServer = true;  //�رշ�����
		shutdown(s_socket, SD_BOTH);
		closesocket(s_socket);
		s_port.EnableWindow(TRUE);		//�����޸Ķ˿ں�
		b_start.SetWindowText("����������");	//��ֹͣ��ť�ĳ�������ť
		AppendLog("��������ֹͣ!\n");		//��ʾ��־
		AppendLog("\n");
	}
}


//�ַ����ӹ�
char * StringProcess(char *str1,char *str2,const char * command)
{
	memset(str1, '\0', sizeof(str1));//��ʼ���ַ���str1
	strcpy(str1, command);//�����ֵ��str1
	strcat(str1, str2);//��str2��ӵ�str1
	return str1;
}

//�����Զ������
char * StringAnalysis(char *str1, char *command)
{
	int i=0;
	if((int)strlen(str1)<10)//�޿��Ϊ��Ч��Ϣ
	{
		command[i] = '\0';
		return command;
	}
	for (i=0; i < 10; i++)
	{
		command[i] = str1[i];
	}
	command[i] = '\0';
	for (i=0; i < (int)strlen(str1); i++)//�������
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

//�������
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

//switch(CommandCategory(command))//�ж����
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString user;
	char username[30]={0};
	int nCurSel;
    nCurSel = s_userlist.GetCurSel(); 
	s_userlist.GetText(nCurSel, user);
	d_user.SetWindowText("");

	strcpy(username, (LPSTR)(LPCTSTR)user);
	for(int i=0; i<(int)strlen(username); i++)//�����û���
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


void CserverDlg::OnBnClickedButton4()//ɾ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char name[30]={0};
	CString info;
	CString txt;
	d_user.GetWindowText(txt);//�õ�Ҫɾ�����û���
	strcpy(name, (LPSTR)(LPCTSTR)txt);
	p_userall.DeleteUser(name);
	d_user.SetWindowText("");
	/////////////////Ⱥ��������Ϣ//////////
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
	//////////////�����û��б�///////////////
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
			StringProcess(downusername, "(����)", duser.users[j].object);//downusername(����)
			s_userlist.AddString((LPCTSTR)downusername);
		}
		else
		{
			memset(downusername, '\0', sizeof(downusername));
			StringProcess(downusername, "(����)", duser.users[j].object);//downusername(����)
			s_userlist.InsertString(0,(LPCTSTR)downusername);
		}
	}
	///////////////////////////////////////
}


void CserverDlg::OnBnClickedButton5()//ѡ���ļ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE);
	if(IDCANCEL == dlg.DoModal())
		return ;
	CString filename;
	filename = dlg.GetPathName();
	s_message.SetWindowText("");
	s_message.SetWindowText(filename);
}


void CserverDlg::OnBnClickedButton3()//�����ļ�(ȱ�ݣ�ֻ�������û�����)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
			FILE *file = fopen((LPSTR)(LPCTSTR)filename, "rb");//��ȡ
			if(file != NULL)
			{
				while (fread(buffer,1,1024,file) >= 0)
				{
					send(fd_array_connect[i],buffer,1024,0);
					if(feof(file))
						break;
				}
				fclose(file);
				AppendLog("�����ļ��ɹ�\n\n");
			}
		}
	}
	
}

void CserverDlg::OnBnClickedButton2()//����ϵͳ��Ϣ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString txt;
	CString info;
	char sendmsg[1024]={0};
	char prefix[1024]={0};
	int rVal;
	s_message.GetWindowText(txt);//��ȡϵͳ��Ϣ
	s_message.SetWindowText("");
	if((int)strlen((LPSTR)(LPCTSTR)txt) == 0)
	{
		AfxMessageBox("������ϢΪ��");
		return ;
	}
	strcpy(sendmsg, "ϵͳ:");
	strcat(sendmsg, (LPSTR)(LPCTSTR)txt);
	StringProcess(prefix, sendmsg, RADIO);
	for (int j=0; j<MAX_LISTENSIZE; j++)//�������û�Ⱥ�������������û���Ϣ
	{
		if(fd_array_connect[j] != 0)//�����û�
		{
			rVal = send(fd_array_connect[j], prefix, 1024, 0);
			if (rVal == SOCKET_ERROR)
			{
				info.Format("�û���ϢȺ���쳣���������: %d\n", WSAGetLastError());
				AppendLog(info);
				AppendLog("\n");
			}
		}
	}
	AppendLog("����ϵͳ��Ϣ�ɹ�\n\n");
	//Ϊ�����û����������¼
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
			FILE *in = fopen(chatfile, "a+");//׷��
			fputs(sendmsg,in);
			fputs("\n",in);
			fclose(in);
		}
	}
}
