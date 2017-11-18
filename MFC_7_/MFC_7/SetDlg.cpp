// SetDlg.cpp: ���� ����������
//

#include "stdafx.h"
#include "MFC_7.h"
#include "SetDlg.h"
#include "afxdialogex.h"


// ���������� ���� CSetDlg

IMPLEMENT_DYNAMIC(CSetDlg, CDialogEx)

CSetDlg::CSetDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_RedRadio(0)
{

}

CSetDlg::~CSetDlg()
{
}

void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RED_RADIO, m_RedRadio);
	DDV_MinMaxInt(pDX, m_RedRadio, 0, 3);
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RED_RADIO, &CSetDlg::OnBnClickedRedRadio)
	ON_BN_CLICKED(IDC_GREEN_RADIO, &CSetDlg::OnBnClickedGreenRadio)
	ON_BN_CLICKED(IDC_BLUE_RADIO, &CSetDlg::OnBnClickedBlueRadio)
END_MESSAGE_MAP()


// ����������� ��������� CSetDlg


void CSetDlg::OnBnClickedRedRadio()
{
	// TODO: �������� ���� ��� ����������� �����������
	UpdateData(TRUE);
}


void CSetDlg::OnBnClickedGreenRadio()
{
	// TODO: �������� ���� ��� ����������� �����������
	UpdateData(TRUE);
}


void CSetDlg::OnBnClickedBlueRadio()
{
	// TODO: �������� ���� ��� ����������� �����������
	UpdateData(TRUE);
}
