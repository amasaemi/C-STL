
// MFC_3_.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CMFC_3_App:
// � ���������� ������� ������ ��. MFC_3_.cpp
//

class CMFC_3_App : public CWinApp
{
public:
	CMFC_3_App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������



	DECLARE_MESSAGE_MAP()
};

extern CMFC_3_App theApp;