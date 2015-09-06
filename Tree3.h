// Tree3.h : main header file for the TREE3 application
//

#if !defined(AFX_TREE3_H__25C0DD56_EBC6_45F7_9624_CDE7AA874A53__INCLUDED_)
#define AFX_TREE3_H__25C0DD56_EBC6_45F7_9624_CDE7AA874A53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTree3App:
// See Tree3.cpp for the implementation of this class
//

class CTree3App : public CWinApp
{
public:
	CTree3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTree3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTree3App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREE3_H__25C0DD56_EBC6_45F7_9624_CDE7AA874A53__INCLUDED_)
