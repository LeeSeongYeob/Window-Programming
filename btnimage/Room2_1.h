#pragma once
#include "afxwin.h"


// CRoom2_1 ��ȭ �����Դϴ�.

class CRoom2_1 : public CDialog
{
	DECLARE_DYNAMIC(CRoom2_1)

public:
	CRoom2_1(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRoom2_1();
	BOOL room2_1 = FALSE;
// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_room2_1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	CBitmapButton Accept_Button;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
