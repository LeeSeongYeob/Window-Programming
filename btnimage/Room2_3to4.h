#pragma once


// CRoom2_3to4 ��ȭ �����Դϴ�.

class CRoom2_3to4 : public CDialog
{
	DECLARE_DYNAMIC(CRoom2_3to4)

public:
	CRoom2_3to4(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRoom2_3to4();
	BOOL room2_3to4 = FALSE;
// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_room2_3to4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
