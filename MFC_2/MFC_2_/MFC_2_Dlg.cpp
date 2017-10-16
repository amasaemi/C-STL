
// MFC_2_Dlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "MFC_2_.h"
#include "MFC_2_Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CMFC_2_Dlg



CMFC_2_Dlg::CMFC_2_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_2__DIALOG, pParent)
//	, m_(_T(""))
	, m_EnableCheck(FALSE)
	, m_VisibleCheck(FALSE)
	, m_TestEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_2_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_TEST_EDIT, m_);
	//  DDX_Control(pDX, IDC_TEST_EDIT, m_TestEdit);
	DDX_Check(pDX, IDC_ENABLED_CHECK, m_EnableCheck);
	DDX_Check(pDX, IDC_VISIBLE_CHECK, m_VisibleCheck);
	DDX_Text(pDX, IDC_TEST_EDIT, m_TestEdit);
}

BEGIN_MESSAGE_MAP(CMFC_2_Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT_BUTTON, &CMFC_2_Dlg::OnClickedExitButton)
	ON_BN_CLICKED(IDC_TEST_BUTTON, &CMFC_2_Dlg::OnClickedTestButton)
	ON_BN_CLICKED(IDC_CLEAR_BUTTON, &CMFC_2_Dlg::OnClickedClearButton)
	ON_BN_CLICKED(IDC_VISIBLE_CHECK, &CMFC_2_Dlg::OnClickedVisibleCheck)
	ON_BN_CLICKED(IDC_ENABLED_CHECK, &CMFC_2_Dlg::OnClickedEnabledCheck)
	ON_EN_CHANGE(IDC_TEST_EDIT, &CMFC_2_Dlg::OnChangeTestEdit)
END_MESSAGE_MAP()


// ����������� ��������� CMFC_2_Dlg

BOOL CMFC_2_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	//��������� ���������� ������ VisibleCheck � EnabledCheck � ���������
	//TRUE
	m_VisibleCheck = TRUE;
	m_EnableCheck = TRUE;
	//�������� �����
	UpdateData(FALSE);

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CMFC_2_Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CMFC_2_Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CMFC_2_Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_2_Dlg::OnClickedExitButton()
{
	// TODO: �������� ���� ��� ����������� �����������
	OnOK();
}


void CMFC_2_Dlg::OnClickedTestButton()
{
	// TODO: �������� ���� ��� ����������� �����������
	///��������� ���������� ���� �������������� IDC_TEST_EDIT �������� This is a Test. 
	m_TestEdit = "This is a Test";
	//// �������� ����� UpdateData(FALSE);
	UpdateData(FALSE);
}


void CMFC_2_Dlg::OnClickedClearButton()
{
	// TODO: �������� ���� ��� ����������� �����������
	///��������� ���������� ���� �������������� IDC_TEST_EDIT �������� NULL. 
	m_TestEdit = " ";
	//// �������� �����
	UpdateData(FALSE);
}


void CMFC_2_Dlg::OnClickedVisibleCheck()
{
	// TODO: �������� ���� ��� ����������� �����������
	////(���������� ����� ���������� ���������� ��������� ����������)
	UpdateData(TRUE);
	///���� ������� ������ Visible ������� ���� �������������� �������
	///� ���� ��� - �� ���������
	if (m_VisibleCheck == TRUE)
		GetDlgItem(IDC_TEST_EDIT)->ShowWindow(SW_SHOW);
	else
		GetDlgItem(IDC_TEST_EDIT)->ShowWindow(SW_HIDE);
}


void CMFC_2_Dlg::OnClickedEnabledCheck()
{
	// TODO: �������� ���� ��� ����������� �����������
	////�������� �������� ���������� ��������� ����������,
	////(���������� ����� ���������� ���������� ��������� ����������)
	UpdateData(TRUE);
	///���� ������� ������ Enable ������� ���� �������������� �������
	///� ���� ��� - �� ���������
	if (m_EnableCheck == TRUE)
		GetDlgItem(IDC_TEST_EDIT)->EnableWindow(SW_SHOW);
	else
		GetDlgItem(IDC_TEST_EDIT)->EnableWindow(SW_HIDE);
}


void CMFC_2_Dlg::OnChangeTestEdit()
{
		// TODO:  �������� ��� �������� ����������
		///�������� ����������
	UpdateData(TRUE);
	///������ ���������� ���� CString, ��������� �� ��������
	///���������� m_TestEdit � ��������� ������� �������� � �������
	///�������.
	CString UpperValue;
	UpperValue = m_TestEdit;
	UpperValue.MakeUpper();

	///���� � ���� �������������� ���������� PAINT 
	///����������� �������� PAINT � ���� �������������� ���������� ������.
	if (UpperValue == "PAINT")
	{
		system("mspaint.exe");
		m_TestEdit = " ";
		UpdateData(FALSE);
	}

	///���� � ���� �������������� ���������� CALCULATOR 
	///����������� ����������� � ���� �������������� ���������� ������.
	if (UpperValue == "CALCULATOR")
	{
		system("calc.exe");
		m_TestEdit = " ";
		UpdateData(FALSE);
	}
}
