
// MFC_9Dlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "MFC_9.h"
#include "MFC_9Dlg.h"
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


// ���������� ���� CMFC_9Dlg



CMFC_9Dlg::CMFC_9Dlg(CWnd* pParent /*=NULL*/)			//����������� ������
	: CDialogEx(IDD_MFC_9_DIALOG, pParent)
	//, m_Cards(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

/*	m_Club = LoadBitmap(OBM_CLUB);
	m_Diamond = LoadBitmap(OBM_DIAMOND);
	m_Heart = LoadBitmap(OBM_HEART);
	m_Spade = LoadBitmap(OBM_SPADE);
	
	m_Club = AfxGetApp()->LoadImage(OBM_CLUB);
	m_Diamond = AfxGetApp()->LoadBitmap(OBM_DIAMOND);
	m_Heart = AfxGetApp()->LoadBitmap(OBM_HEART);
	m_Spade = AfxGetApp()->LoadBitmap(OBM_SPADE);*/

	m_Club = AfxGetApp()->LoadIcon(IDI_CLUB);
	m_Diamond = AfxGetApp()->LoadIcon(IDI_DIAMOND);
	m_Heart = AfxGetApp()->LoadIcon(IDI_HEART);
	m_Spade = AfxGetApp()->LoadIcon(IDI_SPADE);

	m_Amt_Remaining = 100.0;
}

void CMFC_9Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CARD3, m_Card3);
	DDX_Control(pDX, IDC_CARD4, m_Card4);
	DDX_Control(pDX, IDC_CARD1, m_Card1);
	DDX_Control(pDX, IDC_CARD2, m_Card2);
	//  DDX_Control(pDX, IDC_AMT_LEFT, m_Amt_Left);
	//  DDX_Control(pDX, IDC_AMT_LEFT, m_Amt_Left);
	DDX_Control(pDX, IDC_AMT_LEFT, m_Amt_Left);
}

BEGIN_MESSAGE_MAP(CMFC_9Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DEALCARDS, &CMFC_9Dlg::OnBnClickedDealcards)
	ON_BN_CLICKED(IDCANCEL, &CMFC_9Dlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// ����������� ��������� CMFC_9Dlg

BOOL CMFC_9Dlg::OnInitDialog()
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

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CMFC_9Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_9Dlg::OnPaint()
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
HCURSOR CMFC_9Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_9Dlg::OnBnClickedDealcards()
{
	// TODO: �������� ���� ��� ����������� �����������

	//������ ��� ������� ��� ����� ����
	m_Amt_Remaining -= 2.00;

	//����� �����
	DealCards();

	//���������� �������
	CalculateWinnings();

	//�������� ��������� �������� Group Box
	CString s;
	s.Format("Amount Remaining: $ %.2f", m_Amt_Remaining);
	m_Amt_Left.SetWindowText(s);
}


void CMFC_9Dlg::DealCards()					//����� �����
{
	//�������� ��������� �������� ���� ����� �����
	for (int i = 0; i<4; i++)m_Cards[i] = 0;

	//������ ������ � ��������� ���������� ��������
	m_Card1.SetIcon(PickRandomCard());
	m_Card2.SetIcon(PickRandomCard());
	m_Card3.SetIcon(PickRandomCard());
	m_Card4.SetIcon(PickRandomCard());
}


HICON& CMFC_9Dlg::PickRandomCard()
{
	// TODO: �������� ����� �������� return
	//������� ����� ����� ��������� �������
	int num = (rand() % 4);
	/*�������������� ���-�� �������� ���� ����� �����*/
	m_Cards[num]++;

	/*� ����������� �� ��������� ������ ������� ����� ������*/
	switch (num)
	{
	case 0: return m_Club; break;
	case 1: return m_Diamond; break;
	case 2: return m_Heart; break;
	case 3:	return m_Spade; break;
	}
}


void CMFC_9Dlg::CalculateWinnings()			//���������� �������
{
	
	for (int i = 0; i<4; i++)
	{
		if (m_Cards[i] == 2)
		{
			m_Amt_Remaining += 3.00;
			break;			
		}
		else if (m_Cards[i] == 3)
		{
			m_Amt_Remaining += 6.00;
			break;
		}
		else if (m_Cards[i] == 4)
		{
			m_Amt_Remaining += 9.00;
			break;
		}
	}
	/*int pairs = 0;
	for (int i = 0; i<4; i++)
	{
		if (m_Cards[i] == 2 )
		{
			if (pairs>0)
			{
				m_Amt_Remaining += 3.00;
				break;
			}
			else
			{
				pairs++;
			}
		}
		else if (m_Cards[i] == 3)
		{
			m_Amt_Remaining += 6.00;
			break;

		}
		else if (m_Cards[i] == 4)
		{
			m_Amt_Remaining += 9.00;
			break;
		}
	}*/
}




void CMFC_9Dlg::OnBnClickedCancel()
{
	// TODO: �������� ���� ��� ����������� �����������
	
	CString s;
	//�������� � ������ ������ ��������
	s.Format("Good game! I have $ %.2f.", m_Amt_Remaining);
	//������ ���� ��������� 
	MessageBox(s, "Thank you for game in FourUp!");

	CDialogEx::OnCancel();
}
