
// MFC_9Dlg.h : ���� ���������
//

#pragma once
#include "afxwin.h"


// ���������� ���� CMFC_9Dlg
class CMFC_9Dlg : public CDialogEx
{
// ��������
public:
	CMFC_9Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_9_DIALOG };
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
private:
	
	HICON  m_Club;
	HICON  m_Diamond;		
	HICON  m_Spade;
	HICON  m_Heart;

	CStatic m_Card3;		//���������� � ������� ������
	CStatic m_Card4;		
	CStatic m_Card1;		
	CStatic m_Card2;

	CStatic m_Amt_Left;       //����� ����� ��������
	double m_Amt_Remaining;		// ���������� ������ � ���� ����� ��������
public:
	afx_msg void OnBnClickedDealcards();
	
private:
	int m_Cards [5];			//������ � ���� ���-�� ���������� ��� ������ �����
public:
	void DealCards();
	void CalculateWinnings();
	HICON& PickRandomCard();
	afx_msg void OnBnClickedCancel();
};
