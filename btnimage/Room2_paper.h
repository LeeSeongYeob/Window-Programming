#pragma once


// CRoom2_paper ��ȭ �����Դϴ�.

class CRoom2_paper : public CDialog
{
	DECLARE_DYNAMIC(CRoom2_paper)

public:
	CRoom2_paper(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRoom2_paper();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_room2_paper };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
