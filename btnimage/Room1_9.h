#pragma once
#include "afxwin.h"


// CRoom1_9 ��ȭ �����Դϴ�.

class CRoom1_9 : public CDialog
{
	DECLARE_DYNAMIC(CRoom1_9)

public:
	CRoom1_9(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRoom1_9();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_room1_9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnOK();
	BOOL door = FALSE;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual BOOL OnInitDialog();
	CBitmapButton Accept_Button;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
