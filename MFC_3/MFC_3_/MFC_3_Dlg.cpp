
// MFC_3_Dlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "MFC_3_.h"
#include "MFC_3_Dlg.h"
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


// ���������� ���� CMFC_3_Dlg



CMFC_3_Dlg::CMFC_3_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_3__DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_3_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFC_3_Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT_BUTTON, &CMFC_3_Dlg::OnClickedExitButton)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// ����������� ��������� CMFC_3_Dlg

BOOL CMFC_3_Dlg::OnInitDialog()
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

	ShowWindow(SW_MAXIMIZE);

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CMFC_3_Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_3_Dlg::OnPaint()
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
HCURSOR CMFC_3_Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_3_Dlg::OnClickedExitButton()
{
	// TODO: �������� ���� ��� ����������� �����������
	OnOK();
}




void CMFC_3_Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON)
	{
		CClientDC dc(this);

		// dc.SetPixel(point.x, point.y, RGB(123,211,98));

		CPen NewPen(PS_SOLID, 100, RGB(0, 255, 255));
		dc.SelectObject(&NewPen);

		dc.MoveTo(m_PrevX, m_PrevY);
		dc.LineTo(point.x, point.y);
		m_PrevX = point.x;
		m_PrevY = point.y;
	}

}


void CMFC_3_Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	m_PrevX = point.x;
	m_PrevY = point.y;
	CDialogEx::OnLButtonDown(nFlags, point);
}
