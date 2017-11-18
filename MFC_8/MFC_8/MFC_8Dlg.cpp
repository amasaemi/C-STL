
// MFC_8Dlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "MFC_8.h"
#include "MFC_8Dlg.h"
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


// ���������� ���� CMFC_8Dlg



CMFC_8Dlg::CMFC_8Dlg(CWnd* pParent /*=NULL*/)											//�����������
	: CDialogEx(IDD_MFC_8_DIALOG, pParent)
	, m_PenWidth(0)
	, m_PenStyle(0)
	, m_data(0)
	, m_IsDrawing(false)
	, m_pMF(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	////////////////////////////////////////
	////-��� ��� ���������� ����� -////

	m_PenColor = RGB(0, 0, 0); // ��������� ���� �����
	m_PenWidth = 1;			   // ��������� ������ �����


							   ////-��� ��� ������������� ����� -////
							   /////////////////////////////////////////
	m_BrushStyle = 0;
}

void CMFC_8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_PENWIDTH, m_PenWidth);
	DDX_Text(pDX, IDC_PENWIDTH, m_PenWidth);
	DDV_MinMaxInt(pDX, m_PenWidth, 1, 32);
	DDX_Radio(pDX, IDC_SOLID_PEN, m_PenStyle);
	DDX_CBIndex(pDX, IDC_SHAPES, m_data);
	DDX_Control(pDX, IDC_SHAPES, m_ShapesCombo);
	DDX_Control(pDX, IDC_BRUSHSTYLE, m_BrushStyleList);
}

BEGIN_MESSAGE_MAP(CMFC_8Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLEARBTN, &CMFC_8Dlg::OnBnClickedClearbtn)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_STN_CLICKED(IDC_PENCOLOR, &CMFC_8Dlg::OnStnClickedPencolor)
	ON_BN_CLICKED(IDC_CLEARBTN2, &CMFC_8Dlg::OnBnClickedClearbtn2)
	ON_CBN_SELCHANGE(IDC_SHAPES, &CMFC_8Dlg::OnCbnSelchangeShapes)
	ON_LBN_SELCHANGE(IDC_BRUSHSTYLE, &CMFC_8Dlg::OnSelchangeBrushstyle)
	ON_STN_CLICKED(IDC_BRUSHCOLOR, &CMFC_8Dlg::OnClickedBrushcolor)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// ����������� ��������� CMFC_8Dlg

BOOL CMFC_8Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();																  //��������� �������

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
			
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������
/////////////////////////////////////////////


//-----------------��� ������� �������--------------------------------
//�������� ��������� �� ������� ���������� Picture
	CWnd* p_Canvas = GetDlgItem(IDC_CANVAS);

	//�������� ���������� ���� � ���������� m_Canvas
	p_Canvas->GetWindowRect(&m_Canvas);

	//����������� ���������� ��� ���������� �������
	ScreenToClient(&m_Canvas);

	//�������� ���������� ����
	m_Canvas.DeflateRect(2, 2, 1, 1);

//--------------------��� ������������� ������ ����� 1 - �������-----------------------------

	//�������� ��������� �� ������� ����������
	CWnd* pPenColor = GetDlgItem(IDC_PENCOLOR);

	//�������� ���������� �������� ����������
	pPenColor->GetWindowRect(&m_PenColorSwatch);

	//�������� ���������� ������������ ���������� �������
	ScreenToClient(&m_PenColorSwatch);

//------------------��� ������ ������� �����-------------------------------

	//�������� ��������� �� ������� ����������
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN1);

	/*���������� �������� �������� ��������������� ��� IDC_SPIN1*/
	pSpin->SetRange(1, 32);

	//���������� ��������� �������� �������� � 1;
	pSpin->SetPos(1);

	//--------------------��� �������������� ������ ����� 2-----------------------------

	//�������� ��������� �� ������� ����������
	CWnd* pBrushColor = GetDlgItem(IDC_BRUSHCOLOR);

	//�������� ���������� �������� ����������
	pBrushColor->GetWindowRect(&m_BrushColorSwatch);

	//�������� ���������� ������������ ���������� �������
	ScreenToClient(&m_BrushColorSwatch);

	//C����� �����
	m_BrushColorSwatch.DeflateRect(2, 2, 1, 1);

	//--------------------��� �������������� ������ ����� 3-----------------------------

	//�������� ��������� �� ������� ����������
	CWnd* pPreviewColor = GetDlgItem(IDC_BRUSHPREVIEW);

	//�������� ���������� �������� ����������
	pPreviewColor->GetWindowRect(&m_BrushPreviewSwatch);

	//�������� ���������� ������������ ���������� �������
	ScreenToClient(&m_BrushPreviewSwatch);

	//C����� �����
	m_BrushPreviewSwatch.DeflateRect(2, 2, 1, 1);

	//���������� ��������� ���� �����
	m_BrushColor = RGB(0, 0, 0);

	//������� ����� �����
	m_Brush.CreateStockObject(WHITE_BRUSH);

	
	//-----------------��������������� ������ ������--------------------------------

	m_ShapesCombo.AddString(L"FreeHand");
	m_ShapesCombo.AddString(L"Lines");
	m_ShapesCombo.AddString(L"Ovals");
	m_ShapesCombo.AddString(L"Rectangle");

	//-------------------------------------------------
	
	//���������� ��������� ������� �������
	m_ShapesCombo.SetCurSel(0);

	//----------------------------------------------

	//�������� �������� ������ � ������� ListBox
	m_BrushStyleList.AddString(L"none");
	m_BrushStyleList.AddString(L"Solid");
	m_BrushStyleList.AddString(L"LL-UR Diagonal");
	m_BrushStyleList.AddString(L"UL-LR Diagonal");
	m_BrushStyleList.AddString(L"Grid");
	m_BrushStyleList.AddString(L"Grid Diagonal");
	m_BrushStyleList.AddString(L"Horizontal");
	m_BrushStyleList.AddString(L"Vertical");
	m_BrushStyleList.AddString(L"White");
	m_BrushStyleList.AddString(L"Light Gray");
	m_BrushStyleList.AddString(L"Medium Gray");
	m_BrushStyleList.AddString(L"Dark Gray");
	m_BrushStyleList.AddString(L"Black");

	//���������� ��������� ������� ������� �� 8 ��������
	m_BrushStyleList.SetCurSel(8);

//----------------------------------------------
	//���������� � ������ ������ ���������
	m_pMF = new CMetaFileDC;
	//������� ��������
	m_pMF->Create();

/////////////////////////////////////////////////////////////
	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CMFC_8Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_8Dlg::OnPaint()												//��������� �������� �� ������, ���������������
{
	CPaintDC dc(this);

	//�������� ���������
	HMETAFILE hmf = m_pMF->Close();
	//��������������� ���������
	dc.PlayMetaFile(hmf);

	//������������ ��������� �� ������ ������ ���������� temp
	CMetaFileDC* temp = new CMetaFileDC;
	//�������� �������
	temp->Create();
	//������������ ���������
	temp->PlayMetaFile(hmf);

	//�������� ������������� � ���������
	DeleteMetaFile(hmf);
	//delete hmf;

	//������������ ���������� ��������� �����������
	m_pMF = temp;
	/*���� ������ ��� ���� ������� ������ OnPaint, �� �������� ������� ������*/
	static int(firstTime) = TRUE;
	if (firstTime)
	{
		OnBnClickedClearbtn();
		firstTime = FALSE;
	}

	/*if (IsIconic())
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
	}*/
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CMFC_8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


																						//�������� ������, ������� �� ������
void CMFC_8Dlg::OnBnClickedClearbtn()
{
	// TODO: �������� ���� ��� ����������� �����������
	//�������� ��������� �� �������� ����������
	CClientDC dc(this);

//////////////////////////	
	//������� ��������
	HMETAFILE hmf = m_pMF->Close();
	//������� ������ � ���������
	::DeleteMetaFile(hmf);
	//delete hmf;

	//C������ ����� ��������
	m_pMF = new CMetaFileDC;
	m_pMF->Create();
	m_pMF->SetAttribDC(dc);
///////////////////////////	
	
	//������� ������� ����
	dc.SelectStockObject(NULL_PEN);

	//�������� ����
	dc.Rectangle(m_Canvas);

/////////////////////////////////
//�������� ������� � ��������
	m_pMF->SelectStockObject(NULL_PEN);
	m_pMF->Rectangle(m_Canvas.left, m_Canvas.top,
	m_Canvas.right + 1, m_Canvas.bottom + 1);
}

																							//�������� ������� ����� ������ ���� �� ������� �������
void CMFC_8Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������

	/////-��� ��� ���������� �����-///

	//��������� ���� �� ������� ������ ������� ���������.
	
	if (m_Canvas.PtInRect(point))
	{
	
		//��������� ���������� ������ ���� ����������
		m_LineStart = point;
		m_LineEnd = point;
		
		//��������� �������� 

		if (m_ShapesCombo.GetCurSel() == 0) m_IsDrawing = false;
		else m_IsDrawing = true;

		//�������� � ��������� ����� ���� �����
		m_Pen.DeleteObject();
		//�������� ���������� ���������� � ���� ��������
		UpdateData(TRUE);
		//������� ����� ����� � ������ �����, ������� � �����.
		m_Pen.CreatePen(m_PenStyle, m_PenWidth, m_PenColor);

		//��������� ����
		SetCapture();
	
	}
	/////-��� ��� ������������� �����-/////

	CDialogEx::OnLButtonDown(nFlags, point);
}

																									//������ �����, �������� ����
void CMFC_8Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������

	////-��� ��� ���������� �����-////	
	
	if ((nFlags & MK_LBUTTON) && m_Canvas.PtInRect(point))
	{

		if (m_IsDrawing && (nFlags & MK_LBUTTON) && m_Canvas.PtInRect(point))
		{

			//���������� ������ ������� ��������� ����
			DrawShape(true);

			//�������� ���������� ����� �� ������� ��������� �������
			m_LineStart = m_LineEnd;

			//������� ���������� � ���������� ����� ������
			DrawShape(true);
		}

		else
		{
			//�������� ��������� �� �������� ����������
			CClientDC dc(this);

			dc.SelectObject(&m_Pen);

			//��������� ���������� ������ ���������� m_LineEnd
			m_LineEnd = point;

			//���������� �����
			dc.MoveTo(m_LineStart);
			dc.LineTo(m_LineEnd);

			//��������� ������� ���������� m_LineStart �������� ������� �������
			m_LineStart = m_LineEnd;
		}	
		
	}	
	
	////-��� ��� ������������ �����-////
	
	CDialogEx::OnMouseMove(nFlags, point);
}

																						//�������� �� ���������� ������ ����
void CMFC_8Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������
	
	////-��� ��� ���������� �����-////

	//��������� ����� ���������
	m_IsDrawing = FALSE;

	/*���� ����� �������� ������ ������� ���������, �� ���������� ������ ������������*/
	if (m_Canvas.PtInRect(point))
	{
		m_LineEnd = point;
		DrawShape();
	}
	//���� ���, �� �������
	else
	{
		DrawShape(true);
	}
	m_LineStart = point;

	//��������� ����
	ReleaseCapture();

	////-��� ��� ������������� �����-////
	
	CDialogEx::OnLButtonUp(nFlags, point);
}

																									//����� �����, ������������� 1
void CMFC_8Dlg::OnStnClickedPencolor()
{
	// TODO: �������� ���� ��� ����������� �����������

	/*������� ������ ������ ���������� ������ ������ ����� � �������� ��� � ������������ ������� �������� �����*/ 
	CColorDialog dlg(m_PenColor);

	//����� ����������� ����
	if (dlg.DoModal() == IDOK)
	{
		//��������� �����
		m_PenColor = dlg.GetColor();

		//�������� �����
		CBrush swatch;
		swatch.CreateSolidBrush(m_PenColor);

		//�������� ������ ��������� ����������
		CClientDC dc(this);

		//������������ ���������� ��������� ������
		dc.FillRect(&m_PenColorSwatch, &swatch);
	}
}


void CMFC_8Dlg::OnBnClickedClearbtn2()
{
	// TODO: �������� ���� ��� ����������� �����������
	OnOK();
}


void CMFC_8Dlg::OnCbnSelchangeShapes()
{
	// TODO: �������� ���� ��� ����������� �����������
}

																								//��������� ��������� �����
void CMFC_8Dlg::DrawShape(bool stretch)
{
	//�������� ������ ��������� ����������
	CClientDC dc(this);

	//���������� �������� DC
	dc.SetAttribDC(dc);
	dc.IntersectClipRect(m_Canvas);

	m_pMF->SetAttribDC(dc);
	dc.IntersectClipRect(m_Canvas);
	m_pMF->IntersectClipRect(m_Canvas);

	//�������� ����� ������� �� ����� �������� �����
	int drawmode = m_ShapesCombo.GetCurSel();

	//������� ����
	dc.SelectObject(&m_Pen);
	dc.SelectObject(&m_Brush); 

	//�������� ��������� � ��������
	m_pMF->SelectObject(&m_Pen);
	m_pMF->SelectObject(&m_Brush);

	//����� ��������� ����
	if (stretch && drawmode != 0)
	{
		//���������� ����� ��������� ����
		dc.SetROP2(R2_NOT);
	}

	//����������� ������ ������
	switch (drawmode)
	{
		//��������� ���������
	case 0:
		dc.MoveTo(m_LineStart);
		dc.LineTo(m_LineEnd);
		
		//�������� ��������� � ��������
		m_pMF->MoveTo(m_LineStart);
		m_pMF->LineTo(m_LineEnd);

		m_LineStart = m_LineEnd;
		break;
		//��������� �����
	case 1:
		dc.MoveTo(m_LineStart);
		dc.LineTo(m_LineEnd);		
		/*�������� ��������� � ��������, ���� �� ������ ����� ��������� ����*/
		if (!stretch)
		{
			m_pMF->MoveTo(m_LineStart);
			m_pMF->LineTo(m_LineEnd);
		}
		break;
		//��������� �������
	case 2:
		dc.Ellipse(CRect(m_LineStart, m_LineEnd));
		//�������� ��������� � ��������
		if (!stretch)
		{
			m_pMF->Ellipse(CRect(m_LineStart, m_LineEnd));
		}
		break;
		//��������� ��������������
	case 3:
		dc.Rectangle(CRect(m_LineStart, m_LineEnd));
		//�������� ��������� � ��������
		if (!stretch)
		{
			m_pMF->Rectangle(CRect(m_LineStart, m_LineEnd));
		}
		break;
	}
}

																							//���������� ������ �������
void CMFC_8Dlg::OnSelchangeBrushstyle()
{
	// TODO: �������� ���� ��� ����������� �����������

	//������� ���������� ������
	m_Brush.DeleteObject();

	//�������� ����� ��������� �������
	int style = m_BrushStyleList.GetCurSel();

	//�� ������ ������� �����, � ��������� ������
	switch (style)
	{
	case 0:
		m_Brush.CreateStockObject(NULL_BRUSH);
		break;

	case 1:
		m_Brush.CreateSolidBrush(m_BrushColor);
		break;

	case 2:
		m_Brush.CreateHatchBrush(HS_BDIAGONAL, m_BrushColor);
		break;

	case 3:
		m_Brush.CreateHatchBrush(HS_FDIAGONAL, m_BrushColor);
		break;

	case 4:
		m_Brush.CreateHatchBrush(HS_CROSS, m_BrushColor);
		break;

	case 5:
		m_Brush.CreateHatchBrush(HS_DIAGCROSS, m_BrushColor);
		break;

	case 6:
		m_Brush.CreateHatchBrush(HS_HORIZONTAL, m_BrushColor);
		break;

	case 7:
		m_Brush.CreateHatchBrush(HS_VERTICAL, m_BrushColor);
		break;

	case 9:
		m_Brush.CreateStockObject(LTGRAY_BRUSH);
		break;


	case 10:
		m_Brush.CreateStockObject(GRAY_BRUSH);
		break;

	case 11:
		m_Brush.CreateStockObject(DKGRAY_BRUSH);
		break;

	case 12:
		m_Brush.CreateStockObject(BLACK_BRUSH);
		break;

		//������� ����� �� ���������
	default:
		m_Brush.CreateStockObject(WHITE_BRUSH);
		break;
	}

	//������� ������� ��������� ���� Preview
	PaintBrushPreview();
}


void CMFC_8Dlg::PaintBrushPreview()										// ����������� � �������������� ������
{
	////-��� ��� ���������� �����-////

	CClientDC dc(this);
	dc.FillRect(&m_BrushPreviewSwatch, &m_Brush);

	////-��� ��� ������������� �����-////
}


void CMFC_8Dlg::OnClickedBrushcolor()								//������� ������������� 2 ��� ������
{
	// TODO: �������� ���� ��� ����������� �����������
	////-��� ��� ���������� �����-////

	//������� ������ ����������� ���� ����� �����
	CColorDialog dlg(m_BrushColor);

	/*���� ���� ������ ������ ��, �� ��������� ��������� �����*/
	if (dlg.DoModal() == IDOK)
	{
		m_BrushColor = dlg.GetColor();
		CClientDC dc(this);
		CBrush b(m_BrushColor);

		//������������ ���������� ����� �����
		dc.FillRect(&m_BrushColorSwatch, &b);
	}

	/*��������� ������� �������� �����, ��������� ������*/
	OnSelchangeBrushstyle();

	////-��� ��� ������������� �����-////
}


void CMFC_8Dlg::OnDestroy()																	//�������������
{
	CDialogEx::OnDestroy();

	// TODO: �������� ���� ��� ����������� ���������

	CDialog::OnDestroy();
	////-��� ��� ���������� �����-////

	//������� � ������� ��������
	m_pMF->Close();
	delete m_pMF;

	////-��� ��� ���������� �����-////
}
