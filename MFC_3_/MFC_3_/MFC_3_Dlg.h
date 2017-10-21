
// MFC_3_Dlg.h : ���� ���������
//

#pragma once


// ���������� ���� CMFC_3_Dlg
class CMFC_3_Dlg : public CDialogEx
{
// ��������
public:
	CMFC_3_Dlg(CWnd* pParent = NULL);	// ����������� �����������


	int m_PrevX;
	int m_PrevY;

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_3__DIALOG };
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
	afx_msg void OnClickedExitButton();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
