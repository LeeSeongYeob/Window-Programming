// NomalDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "btnimage.h"
#include "NomalDialog.h"
#include "afxdialogex.h"


// NomalDialog ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(NomalDialog, CDialog)

NomalDialog::NomalDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_NOMAL, pParent)
{

}

NomalDialog::~NomalDialog()
{
}

void NomalDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NomalDialog, CDialog)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// NomalDialog �޽��� ó�����Դϴ�.


BOOL NomalDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	BOOL bResult = FALSE;

	LONG lResult = SetWindowLong(this->GetSafeHwnd()
		, GWL_EXSTYLE
		, GetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE) | WS_EX_LAYERED);
	bResult = SetLayeredWindowAttributes(0, 170 ,LWA_ALPHA);
	MoveWindow(x_Pos, y_Pos, width, height);

	//��Ʈ
	CFont font1, font2;
	font1.CreatePointFont(30, _T("����"));
	font2.CreatePointFont(20, _T("����"));
	GetDlgItem(IDC_EXPLAIN)->SetFont(&font1);
	GetDlgItem(IDC_ENTER)->SetFont(&font2);
	GetDlgItem(IDC_EXPLAIN)->SetWindowText(str_Caption);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BOOL NomalDialog::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(0, 0, 0));
	return TRUE;
}


HBRUSH NomalDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	UINT nID = pWnd->GetDlgCtrlID();

	if (nID == IDC_EXPLAIN)
	{
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_ENTER)
	{
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	return hbr;
}


void NomalDialog::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDialog::OnOK();
}
