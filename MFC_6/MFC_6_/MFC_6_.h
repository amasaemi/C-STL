
// MFC_6_.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CMFC_6_App:
// � ���������� ������� ������ ��. MFC_6_.cpp
//

class CMFC_6_App : public CWinApp
{
public:
	CMFC_6_App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CMFC_6_App theApp;