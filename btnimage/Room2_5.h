#pragma once
#include "afxwin.h"


// CRoom2_5 ��ȭ �����Դϴ�.

class CRoom2_5 : public CDialog
{
	DECLARE_DYNAMIC(CRoom2_5)

public:
	CRoom2_5(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRoom2_5();
	BOOL room2_5 = FALSE;

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_room2_5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
public:
	CBitmapButton Accept_Button;
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
