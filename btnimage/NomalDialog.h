#pragma once


// NomalDialog ��ȭ �����Դϴ�.
class  CbtnimageView;
class NomalDialog : public CDialog
{
	DECLARE_DYNAMIC(NomalDialog)

public:
	NomalDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~NomalDialog();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NOMAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:

	int x_Pos, y_Pos;
	int width, height;
	CbtnimageView *view;
	CString  str_Caption;
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

