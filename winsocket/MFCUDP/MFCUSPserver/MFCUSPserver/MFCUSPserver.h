
// MFCUSPserver.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCUSPserverApp:
// �йش����ʵ�֣������ MFCUSPserver.cpp
//

class CMFCUSPserverApp : public CWinApp
{
public:
	CMFCUSPserverApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCUSPserverApp theApp;