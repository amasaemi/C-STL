
// MFC_9.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CMFC_9App:
// � ���������� ������� ������ ��. MFC_9.cpp
//

class CMFC_9App : public CWinApp
{
public:
	CMFC_9App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CMFC_9App theApp;