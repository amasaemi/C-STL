
// MFC_7.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CMFC_7App:
// � ���������� ������� ������ ��. MFC_7.cpp
//

class CMFC_7App : public CWinApp
{
public:
	CMFC_7App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CMFC_7App theApp;