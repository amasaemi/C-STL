
// SpeedDlg.h : ���� ���������
//

#pragma once


// ���������� ���� CSpeedDlg
class CSpeedDlg : public CDialogEx
{
// ��������
public:
	CSpeedDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SPEED_DIALOG };
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
//	int m_SpeedEdit;
	int m_SpeedEdit;
	afx_msg void OnChangeSpeedEdit();
	afx_msg void OnFileCurrentspeed();
	afx_msg void OnHelpAdding();
	afx_msg void OnFileExit();
	afx_msg void OnFileSayhello();
};
