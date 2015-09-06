// setup.cpp : implementation file
//

#include "stdafx.h"
#include "Tree3.h"
#include "setup.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// setup dialog


setup::setup(CWnd* pParent /*=NULL*/)
	: CDialog(setup::IDD, pParent)
{
	//{{AFX_DATA_INIT(setup)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void setup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(setup)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(setup, CDialog)
	//{{AFX_MSG_MAP(setup)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// setup message handlers
