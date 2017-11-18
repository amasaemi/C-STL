
// MFC_8Dlg.h : ���� ���������
//

#pragma once
#include "atltypes.h"
#include "afxwin.h"


// ���������� ���� CMFC_8Dlg
class CMFC_8Dlg : public CDialogEx
{
// ��������
public:
	CMFC_8Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_8_DIALOG };
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
	CRect m_Canvas;			//������� �������
	COLORREF m_PenColor;	//���� �����
	CRect m_PenColorSwatch;	//������� ������������� - �������
	CPen m_Pen;				//����
	CPoint m_LineStart;		//������� �� �����, ����
	CPoint m_LineEnd;		//������� �� �����, ����
public:
	afx_msg void OnBnClickedClearbtn();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnStnClickedPencolor();

	
	int m_PenWidth;			//����� ������
	int m_PenStyle;
	afx_msg void OnBnClickedClearbtn2();
	afx_msg void OnCbnSelchangeShapes();
	int m_data;
	CComboBox m_ShapesCombo;
private:
	//bool DrawShape;
public:
	void DrawShape(bool stretch = false);
	bool m_IsDrawing;
private:
	CBrush m_Brush;				//������ �����
	COLORREF m_BrushColor;		//���� �������
	CRect m_BrushColorSwatch;	//���������� ���������� �����
	CRect m_BrushPreviewSwatch;	//���������� ���������
	int m_BrushStyle;			//����� ��������
public:
	CListBox m_BrushStyleList;
	afx_msg void OnSelchangeBrushstyle();
	void PaintBrushPreview();
	afx_msg void OnClickedBrushcolor();
	CMetaFileDC* m_pMF;
	afx_msg void OnDestroy();
};
