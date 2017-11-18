
// MFC_6_Dlg.h : ���� ���������
//

#pragma once


// ���������� ���� CMFC_6_Dlg
class CMFC_6_Dlg : public CDialogEx
{
// ��������
public:
	CMFC_6_Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_6__DIALOG };
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
	CString m_ResultsEdit;
	afx_msg void OnBnClickedExitButton();
	afx_msg void OnClickedOkcancelButton();
	afx_msg void OnChangeResultsEdit();
	afx_msg void OnClickedRetrycancelButton();
	afx_msg void OnClickedYesnoButton();
	afx_msg void OnClickedYesnocancelButton();
};
