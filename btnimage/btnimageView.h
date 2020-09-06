
// btnimageView.h : CbtnimageView Ŭ������ �������̽�
//

#pragma once
#include "afxext.h"
#include "afxwin.h"
#include "afxcmn.h"
class NomalDialog;


class CbtnimageView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CbtnimageView();
	DECLARE_DYNCREATE(CbtnimageView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_BTNIMAGE_FORM };
#endif

// Ư���Դϴ�.
public:
	CbtnimageDoc* GetDocument() const;
	CString str;
	int room1_stage = 1;
	int room2_stage = 0;
	int room3_stage = 0;
	int nHint=0;
	
	BOOL room1 ;
	BOOL room1_clear ;
	BOOL room2 ;
	BOOL room2_clear ;
	BOOL room3 ;
	BOOL room3_clear;
	BOOL gameover;
	BOOL bCover, bStart, bFinish;
	BOOL bCheck_Lbutton, bScene_Done;
	int iStart_SceneNumber;
	int iStart_SceneMax;
	
	BOOL bProgress;
	//�̰� restart�ʿ����
	BOOL Caption1,Caption2;
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CbtnimageView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnDraw(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CBitmapButton m_hint;
	afx_msg void OnBnClickedHint();
	CListBox m_item;
	afx_msg void OnLbnDblclkList1();
	CStatic m_nHint;
	void Wait(DWORD dwMillisecond);
	int Call_Dialog(CString str_Caption, int height);
	void Print_Image(int Image_ID, int x_Pos, int y_Pos);
	CBitmapButton Start_Button;
	afx_msg void OnBnClickedStart();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CProgressCtrl m_progress;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void Restart();
};

#ifndef _DEBUG  // btnimageView.cpp�� ����� ����
inline CbtnimageDoc* CbtnimageView::GetDocument() const
   { return reinterpret_cast<CbtnimageDoc*>(m_pDocument); }
#endif

