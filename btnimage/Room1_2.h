#pragma once
#include "afxwin.h"


// CRoom1_2 ��ȭ �����Դϴ�.

class CRoom1_2 : public CDialogEx
{
	DECLARE_DYNAMIC(CRoom1_2)

public:
	CRoom1_2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRoom1_2();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_room1_2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedOk();
	BOOL box = FALSE;
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	CBitmapButton Accept_Button;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
