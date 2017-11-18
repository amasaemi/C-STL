
// MFC_7Dlg.h : ���� ���������
//

#pragma once
#include "SetDlg.h"


// ���������� ���� CMFC_7Dlg
class CMFC_7Dlg : public CDialogEx
{
// ��������
public:
	CMFC_7Dlg(CWnd* pParent = NULL);	// ����������� �����������

	CSetDlg m_dlg;
	int m_Radius;
	int m_Direction;


// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_7_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExitButton();
	afx_msg void OnClickedDrawgraphicsButton();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
