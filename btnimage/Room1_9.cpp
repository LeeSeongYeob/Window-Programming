// Room1_9.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "btnimage.h"
#include "Room1_9.h"
#include "afxdialogex.h"


// CRoom1_9 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRoom1_9, CDialog)

CRoom1_9::CRoom1_9(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_room1_9, pParent)
{

	
}

CRoom1_9::~CRoom1_9()
{
}

void CRoom1_9::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, Accept_Button);
}


BEGIN_MESSAGE_MAP(CRoom1_9, CDialog)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CRoom1_9 �޽��� ó�����Դϴ�.





void CRoom1_9::OnOK()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	int answer1, answer2, answer3, answer4;
	answer1 = GetDlgItemInt(IDC_ANSWER1);
	answer2 = GetDlgItemInt(IDC_ANSWER2);
	answer3 = GetDlgItemInt(IDC_ANSWER3);
	answer4 = GetDlgItemInt(IDC_ANSWER4);

	if (answer1 == 1 && answer2 == 0 && answer3 == 2 && answer4 == 4) {
		door = TRUE;
		CDialog::OnOK();
	}
	else
		AfxMessageBox(_T("�ٽ� Ǯ���."));
}


BOOL CRoom1_9::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(0, 0, 0));
	return TRUE;
}


BOOL CRoom1_9::OnInitDialog()
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


void CRoom1_9::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialog::OnOK();
}
