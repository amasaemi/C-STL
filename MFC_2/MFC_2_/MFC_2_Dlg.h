
// MFC_2_Dlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"


// ���������� ���� CMFC_2_Dlg
class CMFC_2_Dlg : public CDialogEx
{
// ��������
public:
	CMFC_2_Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_2__DIALOG };
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
//	CString m_;
//	CEdit m_TestEdit;
	BOOL m_EnableCheck;
	BOOL m_VisibleCheck;
	afx_msg void OnClickedExitButton();
	afx_msg void OnClickedTestButton();
	afx_msg void OnClickedClearButton();
	CString m_TestEdit;
	afx_msg void OnClickedVisibleCheck();
	afx_msg void OnClickedEnabledCheck();
	afx_msg void OnChangeTestEdit();
};
