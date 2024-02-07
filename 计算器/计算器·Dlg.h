// ¼ÆËãÆ÷¡¤Dlg.h : header file
//

#if !defined(AFX_DLG_H__C251BE2E_BA53_4574_BFFF_A0FFCF968ACD__INCLUDED_)
#define AFX_DLG_H__C251BE2E_BA53_4574_BFFF_A0FFCF968ACD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CString	m_num;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onjieguo();
	afx_msg void Onchehui();
	afx_msg void On0();
	afx_msg void On1();
	afx_msg void On2();
	afx_msg void On3();
	afx_msg void On4();
	afx_msg void On5();
	afx_msg void On6();
	afx_msg void On7();
	afx_msg void On8();
	afx_msg void On9();
	afx_msg void Ondian();
	afx_msg void OnAc();
	afx_msg void OnCe();
	afx_msg void Onjia();
	afx_msg void Onjian();
	afx_msg void Oncheng();
	afx_msg void Onchu();
	afx_msg void Onmo();
	afx_msg void Onqufan();
	afx_msg void OnCheck1();
	afx_msg void Onhelp();
	afx_msg void Onmi();
	afx_msg void OnCheck2();
	afx_msg void OnE();
	afx_msg void OnPi();
	afx_msg void Onhuanyuan();
	afx_msg void OnChangeEdit1();
	afx_msg void OnCheck3();
	afx_msg void On1x();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__C251BE2E_BA53_4574_BFFF_A0FFCF968ACD__INCLUDED_)
