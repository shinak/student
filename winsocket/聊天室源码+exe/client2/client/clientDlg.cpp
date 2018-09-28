
// clientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "client.h"
#include "clientDlg.h"
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


// CclientDlg �Ի���




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
// CclientDlg ��Ϣ�������

BOOL CclientDlg::OnInitDialog()
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
	c_userpassword.SetPasswordChar('*');
	CreateUserAll(&banuser);//
	c_message.EnableWindow(FALSE);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CclientDlg::OnPaint()
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
HCURSOR CclientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CclientDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

//�ж��û��Ƿ����߻�����
int IsState(char *name)
{
	int rVal;
	if (name[0] == '1')
		rVal = 1;
	else if (name[0] == '7')
		rVal = 7;
	else
		rVal = 0;
	for (int i=0; i < (int)strlen(name); i++)//�������
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
	s1 = IsState(name);//[1/0]���û�����״̬
	for(int i=0; i<ua->count; i++)
	{
		if(strcmp(ua->u[i].name, name) == 0)//���и��û�
		{
			if(s1 == 1)
				ua->u[i].state = s1;//����״̬
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
UserAll ua;//�����û���
void recvThread(void *p)//���շ���˷��͵���Ϣ
{
	
	CclientDlg  * pDlg= (CclientDlg *)p;
	CString info;
	int rVal;
	char command[11] = {0};
	char recvmsg[1030] = {0};
	char prefix[1024] = {0};
	char filename[1024] = {0};
	CreateUserAll(&ua);//��ʼ��ua�ṹ�崢�������û���
	while(pDlg->c_socket != INVALID_SOCKET)
	{
		memset(recvmsg, '\0', sizeof(recvmsg));
		rVal = recv(pDlg->c_socket, recvmsg, 1024,0);
		if(!state)
		{
			return ;
		}
		if (rVal == SOCKET_ERROR)//�����쳣
		{
			info.Format("�����ǿ�ƹر�,�������: %d\n", WSAGetLastError());
			pDlg->AppendLog(info);
			pDlg->AppendLog("\n");
			///////////////////////////////////////////////////
			pDlg->c_listuser.ResetContent();
			shutdown(pDlg->c_socket, SD_BOTH);
			closesocket(pDlg->c_socket);
			pDlg->c_message.EnableWindow(FALSE);//��ֹ������Ϣ
			pDlg->c_username.EnableWindow(TRUE);//�����޸��û���
			pDlg->c_userpassword.EnableWindow(TRUE);//�����޸�����
			pDlg->s_socketIP.EnableWindow(TRUE);//�����޸�Ҫ���ӵ�IP
			pDlg->s_port.EnableWindow(TRUE);//�����޸Ķ˿ں�
			pDlg->b_login.SetWindowText("��¼");	//���رհ�ť�ĳ����Ӱ�ť
			///////////////////////////////////////////////////
			return ;
		}
		else if (rVal == 0)//����˹ر�
		{
			info.Format("������ѹر�\n");
			pDlg->AppendLog(info);
			pDlg->AppendLog("\n");
			closesocket(pDlg->c_socket);
			///////////////////////////////////////////////////
			pDlg->c_listuser.ResetContent();
			shutdown(pDlg->c_socket, SD_BOTH);
			closesocket(pDlg->c_socket);
			pDlg->c_message.EnableWindow(FALSE);//��ֹ������Ϣ
			pDlg->c_username.EnableWindow(TRUE);//�����޸��û���
			pDlg->c_userpassword.EnableWindow(TRUE);//�����޸�����
			pDlg->s_socketIP.EnableWindow(TRUE);//�����޸�Ҫ���ӵ�IP
			pDlg->s_port.EnableWindow(TRUE);//�����޸Ķ˿ں�
			pDlg->b_login.SetWindowText("��¼");//���رհ�ť�ĳ����Ӱ�ť
			///////////////////////////////////////////////////
			return ;
		}
		else//����Ϣ���д���
		{
			char name[30]={0};
			char fmsg[1512]={0};
			strcpy(fmsg,recvmsg);
			StringAnalysis(recvmsg,command);//������Ϣ����ÿ��ѶϢ
			switch(CommandCategory(command))//�ж����
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
						//���������¼
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
						strcat(filename, GetFileName(recvmsg));//����ļ���
						info.Format("�����ļ�%s\n",recvmsg);
						pDlg->AppendLog(info);
						FILE *initfile = fopen(filename,"wb");//�����ļ�
						fclose(initfile);
					}break;//FFILE(���ܵ�ʶ���ļ���)
				case 7:
					{
						int n;
						strcpy(name, recvmsg);
						if((int)strlen(name) == 0)
							break;
						UpdateUserName(&ua,name);//����
					}break;//USERLIST
				default:
					{
						FILE *file = fopen(filename, "ab");
						if (filename != NULL)
						{
							fwrite(fmsg,1,1024,file);
							fclose(file);
							pDlg->AppendLog("�����ļ�������\n");
						}
						memset(fmsg, '\0', sizeof(fmsg));
					}break;
			}
			/////////////////////////////
			pDlg->c_listuser.ResetContent();
			for(int i=0; i<ua.count; i++)
			{
				memset(name, '\0',sizeof(name));
				if(ua.u[i].state == 0)//��
				{
					strcpy(name,ua.u[i].name);
					strcat(name,"(����)");

					pDlg->c_listuser.AddString((LPCTSTR)name);
				}
				else if(ua.u[i].state == 1)//����
				{
					strcpy(name,ua.u[i].name);
					strcat(name,"(����)");
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int rVal = 0;
	CString txt;
	CString info;
	CString user;
	CString password;
	char prefix[1024] = {0};//��Ϣ�ӹ�
	char command[11] = {0};//����
	b_login.GetWindowText(txt);//��ȡ��ť�ϵ��ı�
	
	if (txt == "��¼")
	{
		c_socket = socket(AF_INET,SOCK_STREAM,0);
		if (c_socket == INVALID_SOCKET)
		{
			info.Format("�׽��ִ���ʧ��,�������: %d\n", WSAGetLastError());
			AppendLog(info);
			AppendLog("\n");
			closesocket(c_socket);//�رմ����׽���
			return ;
		}
		//�ж��û������������ȷ��
		c_username.GetWindowText(user);//����û���
		if ((int)strlen((LPSTR)(LPCTSTR)user) == 0)//�û���Ϊ��
		{
			AfxMessageBox("�û���Ϊ��");
			return ;
		}
		else if (strlen((LPSTR)(LPCTSTR)user) > 14)//����15�ַ�
		{
			AfxMessageBox("�û���̫��(ӦС��14�ַ�)");
			c_username.SetWindowText("");
			return ;
		}
		if(FindUser(&banuser, (LPSTR)(LPCTSTR)user) == true)//�ҵ����û���
		{
			if(IsBan(&banuser, (LPSTR)(LPCTSTR)user) == true)//3�δ���
			{
				AfxMessageBox("�����������3�Σ��ѽ�ֹ��¼");
				return ;
			}
		}
		if(FindUser(&banuser, (LPSTR)(LPCTSTR)user) == false)//δ�ҵ����û���
		{
			AddUser(&banuser, (LPSTR)(LPCTSTR)user);
		}
		c_userpassword.GetWindowText(password);
		if(strlen((LPSTR)(LPCTSTR)password) == 0)//����Ϊ��
		{
			AfxMessageBox("����Ϊ��");
			return ;
		}
		else if (strlen((LPSTR)(LPCTSTR)password) > 24)
		{
			AfxMessageBox("����̫��(ӦС��24�ַ�)");
			c_userpassword.SetWindowText("");
			return ;
		}
		//��ȡ�˿ں�
		CString txtPort;
		s_port.GetWindowText(txtPort);	//��ȡ�˿ںŵ��ı�
		int port = atoi(txtPort);   	//ת���������˿�
		//��ȡ�����IP��ַ
		BYTE nFild[4];
		CString txtIP;
		s_socketIP.GetAddress(nFild[0],nFild[1],nFild[2],nFild[3]);//��ȡ������IP��ַ
		txtIP.Format("%d.%d.%d.%d",
			nFild[0],nFild[1],nFild[2],nFild[3]);
		//����Ҫ���ӵķ����IP��ַ�Ͷ˿ں�
		struct sockaddr_in sa;				//����Ҫ���ӵķ�������ַ
		sa.sin_family = AF_INET;			//��ַ����
		sa.sin_port = htons(port);			//����˿�
		sa.sin_addr.s_addr = inet_addr(txtIP);	//��������ַ
		//���ӷ�����
		if(connect(c_socket,(struct sockaddr *)&sa,sizeof(sa)) == SOCKET_ERROR)
		{//����쳣
			info.Format("��������ȷ��IP��ַ,�������: %d\n", WSAGetLastError());
			AppendLog(info);
			AppendLog("\n");
			return ;
		}
		else//���ӳɹ�,�����û����������������֤
		{
			//�ж������Ƿ�����
			char sendmsg[1024] = {0};
			rVal = recv(c_socket, sendmsg, 1024, 0);//���շ���˷�����ȷ��
			if (rVal == SOCKET_ERROR)//�쳣
			{
				info.Format("����˷�������ȷ��ʧ��,�������: %d\n", WSAGetLastError());
				AppendLog(info);
				AppendLog("\n");
				return ;
			}
			else if (rVal == 0)//����˹ر�
			{
				info.Format("������ѹرգ���Ǯ���ܴ�\n");
				AppendLog(info);
				AppendLog("\n");
				closesocket(c_socket);
				return ;
			}
			else//��֤
			{
				if (strcmp(StringAnalysis(sendmsg, command), FULL) == 0)//��������
				{
					info.Format("����������ӵ��\n");
					AppendLog(info);
					AppendLog("\n");
					closesocket(c_socket);
					return ;
				}
				else
				{
					/////////////////////��¼//////////////////
					memset( sendmsg, '\0' ,sizeof(sendmsg) );//��ʼ��
					strcpy(sendmsg, StringProcess(prefix, (LPSTR)(LPCTSTR)user,ID));//�ӹ�����Ϣ
					rVal = send(c_socket, sendmsg, 1024, 0);//�����û���
					if (rVal == SOCKET_ERROR)//�����쳣
					{
						AfxMessageBox("��¼ʧ��1");
						info.Format("��¼ʧ��,�������: %d\n", WSAGetLastError());
						AppendLog(info);
						AppendLog("\n");
						return ;
					}
					memset( sendmsg, '\0' ,sizeof(sendmsg) );//��ʼ��
					rVal = recv(c_socket, sendmsg, 1024, 0);//�ȴ������ȷ��
					if (rVal == SOCKET_ERROR)//�����쳣
					{
						AfxMessageBox("��¼ʧ��2");
						info.Format("�û�����֤�쳣,�������: %d\n", WSAGetLastError());
						AppendLog(info);
						AppendLog("\n");
						closesocket(c_socket);
						return ;
					}
					else if (rVal == 0)//����˹ر�
					{
						AfxMessageBox("��¼ʧ��3");
						info.Format("������ѹر�\n");
						AppendLog(info);
						AppendLog("\n");
						closesocket(c_socket);
						return ;
					}
					else//�յ�����˷���ȷ����Ϣ
					{
						if (strcmp(StringAnalysis(sendmsg, command), LOGIN) == 0)//����ƥ�䣬�û�����֤�ɹ�
						{
							memset( sendmsg, '\0' ,sizeof(sendmsg) );//��ʼ��
							strcpy(sendmsg, StringProcess(prefix, (LPSTR)(LPCTSTR)password, PASSWORD));
			  				rVal = send(c_socket, sendmsg, 1024, 0);//��������
							if (rVal == SOCKET_ERROR)//�����쳣
							{
								AfxMessageBox("��¼ʧ��4");
								info.Format("�û�����֤�쳣,�������: %d\n", WSAGetLastError());
								AppendLog(info);
								AppendLog("\n");
								closesocket(c_socket);
								return ;
							}
							else
							{
								//�Ż��������ж�
								memset( sendmsg, '\0',sizeof(sendmsg) );//��ʼ��
								rVal = recv(c_socket, sendmsg, 1024, 0);
								if (rVal == 0)
								{
									AfxMessageBox("��¼ʧ��5");
									info.Format("������ѹر�\n");
									AppendLog(info);
									AppendLog("\n");
									closesocket(c_socket);
									return ;
								}
								else if (rVal == SOCKET_ERROR)
								{
									AfxMessageBox("��¼ʧ��6");
									info.Format("�û�����֤�쳣,�������: %d\n", WSAGetLastError());
									AppendLog(info);
									AppendLog("\n");
									closesocket(c_socket);
									return ;
								}
								else
								{
									if (strcmp(StringAnalysis(sendmsg, command), LOGIN) == 0)//����ƥ�䣬������֤�ɹ�����¼�ɹ�
									{
										/////////////////////��ʼ��///////////////////////
										initState(&banuser, (LPSTR)(LPCTSTR)user);//��ռ���
										b_login.SetWindowText("�˳�");//�����Ӱ�ť�ĳɶϿ���ť
										c_message.EnableWindow(TRUE);//��������Ϣ
										c_username.EnableWindow(FALSE);//��ֹ�޸��û���
										c_userpassword.EnableWindow(FALSE);//��ֹ�޸�����
										s_socketIP.EnableWindow(FALSE);//��ֹ����IP��
										s_port.EnableWindow(FALSE);//��ֹ���Ķ˿ں�
										AppendLog("���������ӳɹ�\n");//��ʾ��־
										AppendLog("\n");
										info.Format("��¼�ɹ�\n");
										AppendLog(info);
										AppendLog("\n");
										///////////�������������¼�ļ�"./chat/name.txt"
										char path[100] = {0};
										strcpy(path, "./chat/");
										strcat(path, (LPSTR)(LPCTSTR)user);
										strcat(path, ".txt");
										FILE *init = fopen(path, "r");//���Ŵ�
										if(init == NULL)//������
											init=fopen(path,"w");//����
										fclose(init);
										state = true;
										_beginthread(recvThread,0,this);
										////////////////////////////////////////////////////////////
									}
									else//��ƥ��
									{
										/////////////////����
										rVal = CountAdd(&banuser, (LPSTR)(LPCTSTR)user);//������������һ
										/////////////////
										info.Format("��¼ʧ��,�������%d��\n",rVal);
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
	 }//��������ж�
	else
	{
		c_listuser.ResetContent();
		state = false;
		shutdown(c_socket, SD_BOTH);
		closesocket(c_socket);
		c_message.EnableWindow(FALSE);//��ֹ������Ϣ
		c_username.EnableWindow(TRUE);//�����޸��û���
		c_userpassword.EnableWindow(TRUE);//�����޸�����
		s_socketIP.EnableWindow(TRUE);//�����޸�Ҫ���ӵ�IP
		s_port.EnableWindow(TRUE);//�����޸Ķ˿ں�
		b_login.SetWindowText("��¼");	//���رհ�ť�ĳ����Ӱ�ť
		AppendLog("�û����˳���¼\n");		//��ʾ��־
		AppendLog("\n");
	}
}


void CclientDlg::OnBnClickedButton5()//Ⱥ��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int rVal;
	char sendmsg[1024]={0};
	char prefix[1024]={0};
	CString info;
	CString txt;
	CString name;
	c_message.GetWindowText(txt);//�����Ϣ����Ϣ
	c_username.GetWindowText(name);//�û���
	c_message.SetWindowText("");
	if((int)strlen((LPSTR)(LPCTSTR)txt) == 0)
	{
		AfxMessageBox("������ϢΪ��");
		return ;
	}

	strcpy(sendmsg, StringProcess(prefix, (LPSTR)(LPCTSTR)name, RADIO));//RADIO|username
	strcat(sendmsg, "(������˵):");
	strcat(sendmsg, (LPSTR)(LPCTSTR)txt);//��Ϣ
	rVal = send(c_socket, sendmsg, 1024, 0);
	if (rVal == SOCKET_ERROR)
	{
		info.Format("�����쳣,�������: %d\n", WSAGetLastError());
		AppendLog(info);
		AppendLog("\n");
		return ;
	}
	AppendLog("���ͳɹ�\n");
	//���������¼
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString user;
	char username[30]={0};
	int nCurSel;
    nCurSel = c_listuser.GetCurSel(); 
	c_listuser.GetText(nCurSel, user);
	s_senduser.SetWindowText("");

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
	SetUser(user);
}


void CclientDlg::OnBnClickedButton2()//˽��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int rVal;
	char sendmsg[1024]={0};
	char prefix[1024]={0};
	CString user;
	CString info;
	CString msg;
	CString name;
	s_senduser.GetWindowText(user);//���Ҫ˽�ĵ��û���
	strcpy(sendmsg, StringProcess(prefix, (LPSTR)(LPCTSTR)user, PERSON));
	rVal = send(c_socket, sendmsg, 1024, 0);
	if (rVal == SOCKET_ERROR)
	{
		info.Format("�����û����쳣,%d\n", WSAGetLastError());
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
		AfxMessageBox("������ϢΪ��");
		return ;
	}
	strcpy(sendmsg, StringProcess(prefix, (LPSTR)(LPCTSTR)name, MESSAGE));//MESSAGE|username
	strcat(sendmsg, "(���ĵض���˵):");
	strcat(sendmsg, (LPSTR)(LPCTSTR)msg);//��Ϣ

	rVal = send(c_socket, sendmsg, 1024, 0);
	if (rVal == SOCKET_ERROR)
	{
		info.Format("˽����Ϣ�����쳣,%d\n", WSAGetLastError());
		AppendLog(info);
		AppendLog("\n");
	}
	AppendLog("���ͳɹ�\n");
	//���������¼
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


void CclientDlg::OnBnClickedButton3()//ѡ���ļ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE);
	if(IDCANCEL == dlg.DoModal())
		return ;
	CString filename;
	filename = dlg.GetPathName();
	c_message.SetWindowText("");
	c_message.SetWindowText(filename);
}


void CclientDlg::OnBnClickedButton4()//˽���ļ�
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString filename;
	char prefix[1024]={0};
	char buffer[1024]={0};
	c_message.GetWindowText(filename);
	c_message.SetWindowText("");
	memset(prefix, '\0',sizeof(prefix));
	StringProcess(prefix,(LPSTR)(LPCTSTR)filename, FFILE);
	send(c_socket,prefix,1024,0);//path
	FILE *file = fopen((LPSTR)(LPCTSTR)filename, "rb");//��ȡ
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
	AppendLog("���ͳɹ�\n");
}


void CclientDlg::OnBnClickedButton6()//�鿴������Ϣ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
