// Room2_3.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "btnimage.h"
#include "Room2_3.h"
#include "afxdialogex.h"


// CRoom2_3 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRoom2_3, CDialog)

CRoom2_3::CRoom2_3(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_room2_3, pParent)
{

}

CRoom2_3::~CRoom2_3()
{
}

void CRoom2_3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, Accept_Button);
}


BEGIN_MESSAGE_MAP(CRoom2_3, CDialog)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CRoom2_3 �޽��� ó�����Դϴ�.


void CRoom2_3::OnOK()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CString edit1, edit2;
	GetDlgItemText(IDC_EDIT1, edit1);
	GetDlgItemText(IDC_EDIT2, edit2);

	if (edit1 == _T("*") && edit2 == _T("-")) {
		room2_3 = TRUE;
		AfxMessageBox(_T("����. �ذ��߾�"));
		CDialog::OnOK();
	}
	else {
		AfxMessageBox(_T("ħ���ϰ� �ٽ� �����غ���."));
	}
}


BOOL CRoom2_3::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(0, 0, 0));
	return TRUE;
}


BOOL CRoom2_3::OnInitDialog()
{
	CDialog::OnInitDialog();
	BOOL bResult = FALSE;

	LONG lResult = SetWindowLong(this->GetSafeHwnd()
		, GWL_EXSTYLE
		, GetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE) | WS_EX_LAYERED);
	bResult = SetLayeredWindowAttributes(0, 210, LWA_ALPHA);
	Accept_Button.LoadBitmaps(IDB_ADMIT, IDB_ADMIT, NULL, NULL);
	Accept_Button.SizeToContent();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


HBRUSH CRoom2_3::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	UINT nID = pWnd->GetDlgCtrlID();

	if (nID == IDC_Question)
	{
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_Num1)
	{
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_Num2)
	{
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_Num3)
	{
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_Num4)
	{
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_Num5)
	{
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	return hbr;
}


void CRoom2_3::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialog::OnOK();
}
