// tree3Dlg.h : header file
//

#if !defined(AFX_TREE3DLG_H__8DA234C0_5B52_4241_86B0_8EF21A3A20E6__INCLUDED_)
#define AFX_TREE3DLG_H__8DA234C0_5B52_4241_86B0_8EF21A3A20E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTree3Dlg dialog

class CTree3Dlg : public CDialog
{
// Construction
public:
	void drawLeaf(double x, double y, double L, double a,float B,float C,CDC& dc);
	void drawTree(int x,int y,int L,int a,int tt, CDC& dc);
	void drawTree2(double x, double y, float C,CDC& dc);
	void drawTree3(CDC *pDC);
	void  drawTree4(int xStart, int yStart, double length, double angle,CDC *pDC);
	CTree3Dlg(CWnd* pParent = NULL);	// standard constructor
	
// Dialog Data
	//{{AFX_DATA(CTree3Dlg)
	enum { IDD = IDD_TREE3_DIALOG };
	CScrollBar	m_ScrollBarRed2;
	CScrollBar	m_ScrollBarRed;
	CScrollBar	m_ScrollBarGreen2;
	CScrollBar	m_ScrollBarGreen;
	CScrollBar	m_ScrollBarBlue2;
	CScrollBar	m_ScrollBarBlue;
	int		m_dgsd;
	BOOL	m_Check1;
	float	m_Branch_thick;
	float	m_Leaf_thick;
	int		m_Xvalue;
	int		m_Yvalue;
	UINT	m_nBlue;
	UINT	m_nBlue2;
	UINT	m_nGreen;
	UINT	m_nGreen2;
	UINT	m_nRed;
	UINT	m_nRed2;
	int		m_TREE2_HIGH;
	int		m_TREE2_ANGLE;
	int		m_TREE2_GROW;
	int		m_TREE2_GNGLE2;
	long	m_tree3_PIXEL;
	long	m_TREE4_PIXEL;
	int		m_TREE5_HIGH;
	int		m_TREE5_DEEP;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTree3Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CPoint m_point;
	HICON m_hIcon;

	//背景颜色
	COLORREF m_bgColor;
	CDC m_MemDC;
	CRect m_Rect;
	//物理画布
//	CDC m_DC;
	//内存画布
//	CDC m_MemDC;
	//窗口客户区大小
//	CRect m_Rect;

	// Generated message map functions
	//{{AFX_MSG(CTree3Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChangeEdit1();
	afx_msg void OnCheck1();
	afx_msg void OnChangeBranch_thick();
	afx_msg void OnChangeLeaf_thick();
	afx_msg void OnChangeEdit10();
	afx_msg void OnChangeEdit11();
	afx_msg void OnButton1_claytree();
	afx_msg void OnButton2claytree2();
	afx_msg void OnButton3_drawTree3();
	afx_msg void OnButton4_drawTree4();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnButton5_drawTree();
	afx_msg void OnChangeEditTree2_HIGH();
	afx_msg void OnChangeEdit3Tree2_ANGLE();
	afx_msg void OnChangeEdit4Tree2_grow();
	afx_msg void OnChangeEdit5Tree_ANGLE2();
	afx_msg void OnChangeEDIT6TREE3pixel();
	afx_msg void OnChangeEDIT6TREE4pixel2();
	afx_msg void OnChangeEdit13_TREE5_HIGH();
	afx_msg void OnButton6_TREE1_MOVE();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCancelMode();
	afx_msg void OnButton7_DGSZ();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREE3DLG_H__8DA234C0_5B52_4241_86B0_8EF21A3A20E6__INCLUDED_)
