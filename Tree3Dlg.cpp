// tree3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "tree3.h"
#include "tree3Dlg.h"
#include <math.h>
#define PI 3.1415926/180
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int dgsd=2,leaf=0,OnRadio=0;
int dgsd2=2;
float Branch_Pen=1,Leaf_Pen=1,Root_Pen=1;
int Remember_dgsd=0;
int L1=0,L2=300; //  树根
int select=0;//控制树形
int TREE2_HIGH=100,TREE2_ANGLE=90,TREE2_ANGLE2=-90,TREE2_GROW=0;
int TREE3_PIXEL=100000,TREE4_PIXEL=100000;
int TREE5_HIGH=105,TREE5_DEEP=9;
int m_bRunning=0,m_Interval=500,m_Interval2=10;
int m_bRunning2=0;
float m_C=0;
int m_dir=1;
int grow=0;			
/////////////////////////////////////////////////////////////////////////////
// CTree3Dlg dialog

CTree3Dlg::CTree3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTree3Dlg::IDD, pParent)
{
	
	//{{AFX_DATA_INIT(CTree3Dlg)
	m_bgColor = RGB(255, 255, 255);
	m_dgsd = 0;
	m_Branch_thick = 0.0f;
	m_Leaf_thick = 0.0f;
	m_Xvalue = 0;
	m_Yvalue = 0;
	m_nBlue = 0;
	m_nBlue2 = 0;
	m_nGreen = 0;
	m_nGreen2 = 0;
	m_nRed = 0;
	m_nRed2 = 0;
	m_TREE2_HIGH = 0;
	m_TREE2_ANGLE = 0;
	m_TREE2_GROW = 0;
	m_TREE2_GNGLE2 = 0;
	m_tree3_PIXEL = 0;
	m_TREE4_PIXEL = 0;
	m_TREE5_HIGH = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTree3Dlg::DoDataExchange(CDataExchange* pDX)//窗体映射变量范围限制
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTree3Dlg)
	DDX_Control(pDX, IDC_SCROLLBAR_RED2, m_ScrollBarRed2);
	DDX_Control(pDX, IDC_SCROLLBAR_RED, m_ScrollBarRed);
	DDX_Control(pDX, IDC_SCROLLBAR_GREEN2, m_ScrollBarGreen2);
	DDX_Control(pDX, IDC_SCROLLBAR_GREEN, m_ScrollBarGreen);
	DDX_Control(pDX, IDC_SCROLLBAR_BLUE2, m_ScrollBarBlue2);
	DDX_Control(pDX, IDC_SCROLLBAR_BLUE, m_ScrollBarBlue);
	DDX_Text(pDX, IDC_EDIT1, m_dgsd);
	DDV_MinMaxInt(pDX, m_dgsd, 0, 10);
	DDX_Check(pDX, IDC_CHECK1, m_Check1);
	DDX_Text(pDX, IDC_EDIT8, m_Branch_thick);
	DDV_MinMaxFloat(pDX, m_Branch_thick, 0.f, 10.f);
	DDX_Text(pDX, IDC_EDIT9, m_Leaf_thick);
	DDV_MinMaxFloat(pDX, m_Leaf_thick, 0.f, 10.f);
	DDX_Text(pDX, IDC_EDIT10, m_Xvalue);
	DDX_Text(pDX, IDC_EDIT11, m_Yvalue);
	DDX_Text(pDX, IDC_EDIT_BLUE, m_nBlue);
	DDX_Text(pDX, IDC_EDIT_BLUE2, m_nBlue2);
	DDX_Text(pDX, IDC_EDIT_GREEN, m_nGreen);
	DDX_Text(pDX, IDC_EDIT_GREEN2, m_nGreen2);
	DDX_Text(pDX, IDC_EDIT_RED, m_nRed);
	DDX_Text(pDX, IDC_EDIT_RED2, m_nRed2);
	DDX_Text(pDX, IDC_EDIT_TREE2, m_TREE2_HIGH);
	DDV_MinMaxInt(pDX, m_TREE2_HIGH, 0, 110);
	DDX_Text(pDX, IDC_EDIT3_TREE2, m_TREE2_ANGLE);
	DDV_MinMaxInt(pDX, m_TREE2_ANGLE, 0, 180);
	DDX_Text(pDX, IDC_EDIT4_TREE2, m_TREE2_GROW);
	DDV_MinMaxInt(pDX, m_TREE2_GROW, -50, 50);
	DDX_Text(pDX, IDC_EDIT5_TREE, m_TREE2_GNGLE2);
	DDV_MinMaxInt(pDX, m_TREE2_GNGLE2, 0, 180);
	DDX_Text(pDX, IDC_EDIT6_TREE3_pixel, m_tree3_PIXEL);
	DDV_MinMaxLong(pDX, m_tree3_PIXEL, 0, 200000);
	DDX_Text(pDX, IDC_EDIT6_TREE3_pixel2, m_TREE4_PIXEL);
	DDV_MinMaxLong(pDX, m_TREE4_PIXEL, 0, 500000);
	DDX_Text(pDX, IDC_EDIT13, m_TREE5_HIGH);
	DDV_MinMaxInt(pDX, m_TREE5_HIGH, 0, 110);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTree3Dlg, CDialog)
	//{{AFX_MSG_MAP(CTree3Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_EN_CHANGE(IDC_EDIT8, OnChangeBranch_thick)
	ON_EN_CHANGE(IDC_EDIT9, OnChangeLeaf_thick)
	ON_EN_CHANGE(IDC_EDIT10, OnChangeEdit10)
	ON_EN_CHANGE(IDC_EDIT11, OnChangeEdit11)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1_claytree)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2claytree2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3_drawTree3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4_drawTree4)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5_drawTree)
	ON_EN_CHANGE(IDC_EDIT_TREE2, OnChangeEditTree2_HIGH)
	ON_EN_CHANGE(IDC_EDIT3_TREE2, OnChangeEdit3Tree2_ANGLE)
	ON_EN_CHANGE(IDC_EDIT4_TREE2, OnChangeEdit4Tree2_grow)
	ON_EN_CHANGE(IDC_EDIT5_TREE, OnChangeEdit5Tree_ANGLE2)
	ON_EN_CHANGE(IDC_EDIT6_TREE3_pixel, OnChangeEDIT6TREE3pixel)
	ON_EN_CHANGE(IDC_EDIT6_TREE3_pixel2, OnChangeEDIT6TREE4pixel2)
	ON_EN_CHANGE(IDC_EDIT13, OnChangeEdit13_TREE5_HIGH)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6_TREE1_MOVE)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7_DGSZ)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTree3Dlg message handlers

BOOL CTree3Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_ScrollBarRed.SetScrollRange(0,255);
	m_ScrollBarGreen.SetScrollRange(0,255);
	m_ScrollBarBlue.SetScrollRange(0,255);
	m_ScrollBarRed2.SetScrollRange(0,255);
	m_ScrollBarGreen2.SetScrollRange(0,255);
	m_ScrollBarBlue2.SetScrollRange(0,255);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTree3Dlg::OnPaint() 
{
	AfxGetMainWnd()->SetWindowText("分形树  作者：胡伟鹏 丁志成");
	if(select<5)
	dgsd=Remember_dgsd;
	dgsd2=dgsd;
	CRect rect;
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		//CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{

		m_point.x=300;//起始坐标
		m_point.y=100;
		CPaintDC dc(this);
		CPen pen1(PS_SOLID,Root_Pen,RGB(m_nRed,m_nGreen,m_nBlue));
		dc.SelectObject(pen1);
		dc.MoveTo(m_point.x+150,m_point.y+680);//根顶坐标,作为起点坐标
		dc.LineTo(m_point.x+150+L1,m_point.y+680-L2);//根头坐标	，作为终点坐标并画线
		if(select<5)
		dgsd--;
		dgsd2--;
		if(select==0)
		{
			if(dgsd>0)
			{
				drawTree(m_point.x+150+L1,m_point.y+680-L2, 50, -90, 1, dc);//ang=-90,L=50
			}
		}
		else if(select==1)
		{
			int x, y;
			x = rect.Width()/2;
			y = rect.Height()-50;
			drawLeaf(m_point.x+150+L1,m_point.y+680-L2, TREE2_HIGH,TREE2_ANGLE2,TREE2_ANGLE,TREE2_GROW, dc);
			 //L:树的高度  A:树根偏转角度； B:树枝与根的夹角； C:树的长势
			//void CTreeDlg::drawLeaf(double x, double y, double L, double A, float B, float C，CDC& dc)
		}
		else if(select==2)
		{
			int x, y;
			x = 0;
			y = 0;
			drawTree2(x, y, 9,dc);
		}
		else if(select==3)
		{
			drawTree3(&dc);
		}
		else if(select==4)
		{
			if(dgsd2>0)
			drawTree4( 450,580,TREE5_HIGH,-1.57,&dc);//(double) rect.bottom*0.35//leval调高度，num调递归深度
		}
		else if(select==5)
		{
			int x, y;
			x = rect.Width()/2;
			y = rect.Height()-50;
			drawLeaf(m_point.x+150+L1,m_point.y+680-L2, TREE2_HIGH,TREE2_ANGLE2,TREE2_ANGLE,grow, dc);
		}
		else if(select==6)
		{
			if(dgsd2>0)
			{
				drawTree4( 450,580,TREE5_HIGH,-1.57,&dc);
			}
		}
	
		//drawLeaf(m_point.x+150+L1,m_point.y+680-L2, 50, -90, 1,1,dc);
		
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTree3Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTree3Dlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	m_point = point;
	Invalidate();  //使无效
}


void CTree3Dlg::drawTree(int x, int y, int L, int a, int tt, CDC& dc)
{
	CPen pen1(PS_SOLID,Branch_Pen,RGB(m_nRed,m_nGreen,m_nBlue));
	CPen pen2(PS_SOLID,Branch_Pen,RGB(m_nRed,m_nGreen,m_nBlue));
	dgsd--;
	int X1,Y1,i;
	for( i = -1;i<=1;i++)
	{		
		X1 = x + 2*L * cos((a + i * ((float(rand())/RAND_MAX * 40) + 20)) * PI);
		Y1 = y + 2*L * sin((a + i * ((float(rand())/RAND_MAX * 40) + 20)) * PI)-5;
		dc.SelectObject(pen2);
		dc.MoveTo(x, y);
		dc.LineTo(X1, Y1);
		if(dgsd>0)//控制递归深度
		//if(L>dgsd)
		{	
			drawTree(X1, Y1, L - 8, a + i * (float(rand())/RAND_MAX * 40) + 10, tt, dc);
			dgsd++;
		}
        else if(leaf)//tt=1有雪花;tt!=1没有雪花
		{
			CPen pen3(PS_SOLID,Leaf_Pen,RGB(m_nRed2,m_nGreen2,m_nBlue2));
			dc.SelectObject(pen3);
			dc.Ellipse(X1-2, Y1-2,X1+2,Y1+2);
			dc.SelectObject(pen2);
		}
      
	}
}
void CTree3Dlg::drawLeaf(double x, double y, double L, double A, float B, float C,CDC& dc)
{
	CPen pen1(PS_SOLID,Branch_Pen,RGB(m_nRed,m_nGreen,m_nBlue));
	dc.SelectObject(pen1);
	double s1, s2, s3;
	s1 = 2;
	s2 = 3;
	s3 = 1.3;
	int x1,y1,x1L,y1L,x1R,y1R,x2,y2,x2R,y2R,x2L,y2L;
	if(L > s1)
	{
		x2 = (int)(x + L * cos(A * PI));
		y2 = (int)(y + L * sin(A * PI));
		x2R = (int)(x2 + L / s2 * cos((A + B) * PI));
		y2R = (int)(y2 + L / s2 * sin((A + B) * PI));
		x2L = (int)(x2 + L / s2 * cos((A - B) * PI));
		y2L = (int)(y2 + L / s2 * sin((A - B) * PI));
		
		x1 = (int)(x + L / s2 * cos(A * PI));
		y1 = (int)(y + L / s2 * sin(A * PI));
		x1L = (int)(x1 + L / s2 * cos((A - B) * PI));
		y1L = (int)(y1 + L / s2 * sin((A - B) * PI));
		x1R = (int)(x1 + L / s2 * cos((A + B) * PI));
		y1R = (int)(y1 + L / s2 * sin((A + B) * PI));
		
		
		dc.MoveTo((int)x,(int)y);
		dc.LineTo(x2,y2);
		dc.LineTo(x2R,y2R);
		dc.MoveTo(x2,y2);
		dc.LineTo(x2L,y2L);
		dc.MoveTo(x1,y1);
		dc.LineTo(x1L,y1L);
		dc.MoveTo(x1,y1);
		dc.LineTo(x1R,y1R);
		
		drawLeaf(x2, y2, L / s3, A + C, B, C,dc);
		drawLeaf(x2R, y2R, L / s2, A + B, B, C,dc);
		drawLeaf(x2L, y2L, L / s2, A - B, B, C,dc);
		drawLeaf(x1L, y1L, L / s2, A - B, B, C,dc);
		drawLeaf(x1R, y1R, L / s2, A + B, B, C,dc);
	}  
}

void CTree3Dlg::drawTree2(double x, double y, float C,CDC& dc)
{
	CPen pen1(PS_SOLID,Branch_Pen,RGB(m_nRed,m_nGreen,m_nBlue));
	dc.SelectObject(pen1);
	float newx,newy;
	float R;
	long n=TREE3_PIXEL;//20000
	R = (float)rand()/RAND_MAX;
    while (n > 0) 
	{
		R = (float)rand()/RAND_MAX;
		if(R<=0.1)
		{
			newx = (float)(0.05*cos((0)*PI)*x-0.60*sin((0)*PI)*y+0);
		    newy = (float)(0.05*sin((0)*PI)*x+0.60*cos((0)*PI)*y+0);
		}
        else if(R<=0.2)
		{
		    newx = (float)(0.05*cos((0)*PI)*x+0.50*sin((0)*PI)*y+0);
		    newy = (float)(0.05*sin((0)*PI)*x-0.50*cos((0)*PI)*y+1);

		}
	    else if(R<=0.4)
		{
		    newx = (float)(0.60*cos((40+C)*PI)*x-0.50*sin((40)*PI)*y+0);
		    newy = (float)(0.60*sin((40+C)*PI)*x+0.50*cos((40)*PI)*y+0.6);
		}
	    else if(R<=0.6)
		{
	  	    newx = (float)(0.55*cos((-40+C)*PI)*x-0.40*sin((-40)*PI)*y+0);
		    newy = (float)(0.55*sin((-40+C)*PI)*x+0.40*cos((-40)*PI)*y+0.7);
		}
	    else if(R<=0.8)
		{
		    newx = (float)(0.50*cos((20+C)*PI)*x-0.45*sin((20)*PI)*y+0);
		    newy = (float)(0.50*sin((20+C)*PI)*x+0.45*cos((20)*PI)*y+1.1);
		}
	    else if(R<=1.0)
		{
		    newx = (float)(0.50*cos((-30+C)*PI)*x-0.55*sin((-30)*PI)*y+0);
		    newy = (float)(0.50*sin((-30+C)*PI)*x+0.55*cos((-30)*PI)*y+1.0);
		}
        x = newx; y = newy;
		dc.SetPixelV((6750 + 2000 * x)/15, (7200 - 2000 * y)/15, RGB(m_nRed,m_nGreen,m_nBlue));		
        n--;
	}
}
void CTree3Dlg::drawTree3(CDC *pDC)
{
	CPen pen1(PS_SOLID,Branch_Pen,RGB(m_nRed,m_nGreen,m_nBlue));
	pDC->SelectObject(pen1);
	double m[4][6]={{0,0,0,0.16,0,0},{0.85,0.04,-0.04,0.85,0,1.6},{0.2,-0.25,0.23,0.22,0,1.6},{-0.15,0.28,0.26,0.24,0,0.44}};
    long n=TREE4_PIXEL,t;
	double a,b,c,d,e,f,newx,newy,x=0,y=0;
	srand((UINT)time(NULL));
	while(n>0)
	{
		t=rand()%101;
		if(t<=1)
		{	
			a=m[0][0];b=m[0][1];c=m[0][2];d=m[0][3];e=m[0][4];f=m[0][5];
		}
		else if(t<=86)
		{	
			a=m[1][0];b=m[1][1];c=m[1][2];d=m[1][3];e=m[1][4];f=m[1][5];
		}
		else if(t<=93)
		{	
			a=m[2][0];b=m[2][1];c=m[2][2];d=m[2][3];e=m[2][4];f=m[2][5];
		}
        else
		{		
			a=m[3][0];b=m[3][1];c=m[3][2];d=m[3][3];e=m[3][4];f=m[3][5];
		}
        newx=a*x+b*y+e;
		newy=c*x+d*y+f;
		x=newx;
		y=newy;
		pDC->SetPixel(int(450+50*x),int(580-50*y),RGB(m_nRed,m_nGreen,m_nBlue));
		n--;
	}
}

void CTree3Dlg::drawTree4(int xStart, int yStart, double length, double angle,CDC *pDC)
{
	CPen pen1(PS_SOLID,Branch_Pen,RGB(m_nRed,m_nGreen,m_nBlue));
	pDC->SelectObject(pen1);
	int xEnd,yEnd;
	dgsd2--;

	xEnd=xStart+(int)(length*cos(angle));
	yEnd=yStart+(int)(length*sin(angle));
	//POINT point1={xStart,yStart},point2={xEnd,yEnd};
	pDC->MoveTo(xStart,yStart);
	pDC->LineTo(xEnd,yEnd);
	//if(num==0) return 1;

	if(dgsd2>=0)
	{	

		drawTree4(xEnd,yEnd,length*0.6,angle+0.624,pDC);
		dgsd2++;
		drawTree4(xEnd,yEnd,length*0.85,angle+0.08,pDC);
		dgsd2++;
		drawTree4(xEnd,yEnd,length*0.65,angle-0.6,pDC);
		dgsd2++;
	}
	else if(leaf)//tt=1有雪花;tt!=1没有雪花
	{
		CPen pen3(PS_SOLID,Leaf_Pen,RGB(m_nRed2,m_nGreen2,m_nBlue2));
		pDC->SelectObject(pen3);
		pDC->Ellipse(xEnd-2, yEnd-2,xEnd+2,yEnd+2);
		pDC->SelectObject(pen1);
	}

}

void CTree3Dlg::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	dgsd=m_dgsd;
	Remember_dgsd=m_dgsd;
}


void CTree3Dlg::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_Check1==FALSE)	leaf=0;	
	else leaf=1;
	
}


void CTree3Dlg::OnChangeBranch_thick() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	Branch_Pen=m_Branch_thick;
	Root_Pen=Branch_Pen*1.5;
}

void CTree3Dlg::OnChangeLeaf_thick() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	Leaf_Pen=m_Leaf_thick;
}

void CTree3Dlg::OnChangeEdit10() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	L1=m_Xvalue;
}

void CTree3Dlg::OnChangeEdit11() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	L2=m_Yvalue;	
}


void CTree3Dlg::OnButton5_drawTree() 
{
	select=0;
	Invalidate(); 
}

void CTree3Dlg::OnButton1_claytree() 
{
	// TODO: Add your control notification handler code here
	select=1;
	Invalidate();  //使无效
}


void CTree3Dlg::OnButton2claytree2() 
{
	// TODO: Add your control notification handler code here
	select=2;
	Invalidate();  //使无效
}

void CTree3Dlg::OnButton3_drawTree3() 
{
	// TODO: Add your control notification handler code here
	select=3;
	Invalidate();  //使无效
}

void CTree3Dlg::OnButton4_drawTree4() 
{
	// TODO: Add your control notification handler code here
	select=4;
	Invalidate();  //使无效
}

void CTree3Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	int nCurrentPos=pScrollBar->GetScrollPos();
	switch(nSBCode)
	{
	case SB_THUMBTRACK:
	case SB_THUMBPOSITION:
		pScrollBar->SetScrollPos(nPos);
		break;
	case SB_LINELEFT:
		pScrollBar->SetScrollPos(nCurrentPos-1);
		break;
	case SB_LINERIGHT:
		pScrollBar->SetScrollPos(nCurrentPos+1);
		break;
	case SB_PAGEUP:
		pScrollBar->SetScrollPos(nCurrentPos-10);
		break;
	case SB_PAGEDOWN:
		pScrollBar->SetScrollPos(nCurrentPos+10);
		break;
	}
	CWnd *pWnd=GetDlgItem(IDC_PICTURE);        //picture1接收颜色
	CRect rect;
	pWnd->GetClientRect(rect);
	CDC *pdc=pWnd->GetDC();
	m_nRed=m_ScrollBarRed.GetScrollPos();
	m_nBlue=m_ScrollBarBlue.GetScrollPos();
	m_nGreen=m_ScrollBarGreen.GetScrollPos();
	COLORREF Color=RGB(m_nRed,m_nGreen,m_nBlue);
	pdc->FillSolidRect(&rect,Color);
	UpdateData(FALSE);
	ReleaseDC(pdc);
	
	
	CWnd *pWnd2=GetDlgItem(IDC_PICTURE2);			//picture2接收颜色
	CRect rect2;
	pWnd2->GetClientRect(rect2);
	CDC *pdc2=pWnd2->GetDC();
	m_nRed2=m_ScrollBarRed2.GetScrollPos();
	m_nBlue2=m_ScrollBarBlue2.GetScrollPos();
	m_nGreen2=m_ScrollBarGreen2.GetScrollPos();
	COLORREF Color2=RGB(m_nRed2,m_nGreen2,m_nBlue2);
	pdc2->FillSolidRect(&rect2,Color2);
	UpdateData(FALSE);
	ReleaseDC(pdc2);
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CTree3Dlg::OnChangeEditTree2_HIGH() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	TREE2_HIGH=m_TREE2_HIGH;
}

void CTree3Dlg::OnChangeEdit3Tree2_ANGLE() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	TREE2_ANGLE=m_TREE2_ANGLE;
}

void CTree3Dlg::OnChangeEdit4Tree2_grow() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	TREE2_GROW=m_TREE2_GROW;
}

void CTree3Dlg::OnChangeEdit5Tree_ANGLE2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	TREE2_ANGLE2=-m_TREE2_GNGLE2;	
}

void CTree3Dlg::OnChangeEDIT6TREE3pixel() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	TREE3_PIXEL=m_tree3_PIXEL;
}

void CTree3Dlg::OnChangeEDIT6TREE4pixel2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
	TREE4_PIXEL=m_TREE4_PIXEL;
}

void CTree3Dlg::OnChangeEdit13_TREE5_HIGH() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData(TRUE);
	// TODO: Add your control notification handler code here
		
	TREE5_HIGH=m_TREE5_HIGH;
}


void CTree3Dlg::OnButton6_TREE1_MOVE() 
{
	// TODO: Add your control notification handler code here
	select=5;
	if (m_bRunning) 
	{
		KillTimer(10);
		m_bRunning = FALSE;
	}
	else 
	{
		SetTimer(10, m_Interval2, NULL);
		m_bRunning = TRUE;
	}
}
//定时器处理函数，在这个函数里绘制树
void CTree3Dlg::OnTimer(UINT nIDEvent) 
{
//	dgsd=Remember_dgsd;
//	CRect m_Rect;

	//在内存画布中清屏
//	m_MemDC.FillSolidRect(&m_Rect, m_bgColor);

/*	m_point.x=300;//起始坐标
	m_point.y=100;
	CPaintDC dc(this);
	CPen pen1(PS_SOLID,Root_Pen,RGB(m_nRed,m_nGreen,m_nBlue));
	dc.SelectObject(pen1);
	dc.MoveTo(m_point.x+150,m_point.y+680);//根顶坐标,作为起点坐标
	dc.LineTo(m_point.x+150+L1,m_point.y+680-L2);//根头坐标	，作为终点坐标并画线
	dgsd--;
	if(dgsd>0)
	{
		drawTree(m_point.x+150+L1,m_point.y+680-L2, 50, -90, 1, dc);//ang=-90,L=50
	}
*/
	if(select==5)
	{
		Invalidate(); 
		if (m_dir) {
			//m_C -= 30;
			grow-=3;
			if (grow <-30 )
				m_dir = FALSE;
		} else {
			//m_C += 30;
			grow+=3;
			if (grow > 30)
				m_dir = TRUE;
		}
	}
	else if(select==6)
	{	
		Invalidate(); 
		if (m_dir) {
			//m_C -= 30;
			dgsd+=1;
			if (dgsd >9 )
				m_dir = FALSE;
		} else {
			//m_C += 30;
			dgsd-=1;
			if (dgsd <2)
				m_dir = TRUE;
		}
	}

}

void CTree3Dlg::OnButton7_DGSZ() 
{
	// TODO: Add your control notification handler code here
	select=6;
	if (m_bRunning2) 
	{
		KillTimer(10);
		m_bRunning2 = FALSE;
	}
	else 
	{
		SetTimer(10, m_Interval, NULL);
		m_bRunning2 = TRUE;
	}
}
