
// MFCUDPclient.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCUDPclientApp:
// �йش����ʵ�֣������ MFCUDPclient.cpp
//

class CMFCUDPclientApp : public CWinApp
{
public:
	CMFCUDPclientApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCUDPclientApp theApp;