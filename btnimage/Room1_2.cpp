// Room1_2.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "btnimage.h"
#include "Room1_2.h"
#include "afxdialogex.h"

// CRoom1_2 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRoom1_2, CDialogEx)

CRoom1_2::CRoom1_2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_room1_2, pParent)
{

}

CRoom1_2::~CRoom1_2()
{
}

void CRoom1_2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, Accept_Button);
}


BEGIN_MESSAGE_MAP(CRoom1_2, CDialogEx)
//	ON_BN_CLICKED(ID_OK, &CRoom1_2::OnBnClickedOk)
ON_WM_ERASEBKGND()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CRoom1_2 �޽��� ó�����Դϴ�.







void CRoom1_2::OnOK()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	int m_answer1,m_answer2,m_answer3;
	m_answer1 = GetDlgItemInt(IDC_ANSWER1);
	m_answer2 = GetDlgItemInt(IDC_ANSWER2);
	m_answer3 = GetDlgItemInt(IDC_ANSWER3);

	if (m_answer1 == 2 && m_answer2 == 2 && m_answer3 == 1) {
		box = TRUE;
		CDialogEx::OnOK();
	}
	else
		AfxMessageBox(_T("�ٽ� Ǯ���"));
	CDialog::OnOK();
}


BOOL CRoom1_2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

BOOL bResult = FALSE;

	LONG lResult = SetWindowLong(this->GetSafeHwnd()
		, GWL_EXSTYLE
		, GetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE) | WS_EX_LAYERED);
	bResult = SetLayeredWindowAttributes(0, 210, LWA_ALPHA);
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
		Accept_Button.LoadBitmaps(IDB_ADMIT, IDB_ADMIT, NULL, NULL);
		Accept_Button.SizeToContent();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BOOL CRoom1_2::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(rect);
	pDC->FillSolidRect(rect, RGB(0, 0, 0));
	return TRUE;
}


void CRoom1_2::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialog::OnOK();
}
