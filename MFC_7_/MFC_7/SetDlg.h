#pragma once


// ���������� ���� CSetDlg

class CSetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetDlg)

public:
	CSetDlg(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CSetDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRedRadio();
	afx_msg void OnBnClickedGreenRadio();
	afx_msg void OnBnClickedBlueRadio();
	int m_RedRadio;
};
