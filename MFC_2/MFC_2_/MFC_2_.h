
// MFC_2_.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CMFC_2_App:
// � ���������� ������� ������ ��. MFC_2_.cpp
//

class CMFC_2_App : public CWinApp
{
public:
	CMFC_2_App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CMFC_2_App theApp;