
// MyKey.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CMyKeyApp:
// � ���������� ������� ������ ��. MyKey.cpp
//

class CMyKeyApp : public CWinApp
{
public:
	CMyKeyApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CMyKeyApp theApp;