#if !defined(AFX_SETUP_H__1E2EE1B8_ADBD_4395_A639_C148EA5ECF8D__INCLUDED_)
#define AFX_SETUP_H__1E2EE1B8_ADBD_4395_A639_C148EA5ECF8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// setup.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// setup dialog

class setup : public CDialog
{
// Construction
public:
	setup(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(setup)
	enum { IDD = _UNKNOWN_RESOURCE_ID_ };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(setup)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(setup)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETUP_H__1E2EE1B8_ADBD_4395_A639_C148EA5ECF8D__INCLUDED_)
