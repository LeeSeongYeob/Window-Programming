// Room2_1.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "btnimage.h"
#include "Room2_1.h"
#include "afxdialogex.h"


// CRoom2_1 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRoom2_1, CDialog)

CRoom2_1::CRoom2_1(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_room2_1, pParent)
{

}

CRoom2_1::~CRoom2_1()
{
}

void CRoom2_1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, Accept_Button);
}


BEGIN_MESSAGE_MAP(CRoom2_1, CDialog)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CRoom2_1 �޽��� ó�����Դϴ�.


void CRoom2_1::OnOK()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	int n = GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO3);

	if (n==IDC_RADIO3) {
		room2_1 = TRUE;
		AfxMessageBox(_T("����. ���� �ܼ� ã�ƺ���"));
		CDialog::OnOK();
	}
	else {
		AfxMessageBox(_T("�̷�, �ð��� ���µ�.."));
	}
}


BOOL CRoom2_1::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(0, 0, 0));
	return TRUE;
}


BOOL CRoom2_1::OnInitDialog()
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


HBRUSH CRoom2_1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	UINT nID = pWnd->GetDlgCtrlID();

	if (nID == IDC_Caption1)
	{
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_Caption2)
	{
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_Caption3)
	{
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_Caption4)
	{
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_Caption5)
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_Caption6)
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));
	hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_Caption7)
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_Caption9)
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_RADIO1)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_RADIO2)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_RADIO3)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_RADIO4)
	{
		pDC->SetBkMode(TRANSPARENT);
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}

	
	return hbr;
}


void CRoom2_1::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDialog::OnOK();
}
