
// Speed.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CSpeedApp:
// � ���������� ������� ������ ��. Speed.cpp
//

class CSpeedApp : public CWinApp
{
public:
	CSpeedApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CSpeedApp theApp;