#pragma once
#include "afxwin.h"


// CRoom2_2 ��ȭ �����Դϴ�.

class CRoom2_2 : public CDialogEx
{
	DECLARE_DYNAMIC(CRoom2_2)

public:
	CRoom2_2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRoom2_2();
	BOOL room2_2=FALSE;
	int n = 0;
	BOOL p1 = FALSE;
	BOOL p2 = FALSE;
	BOOL p3 = FALSE;
	BOOL p4 = FALSE;
	BOOL p5 = FALSE;
// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_room2_2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CStatic m_room2_2_picture;
};
