// Room2_2.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "btnimage.h"
#include "Room2_2.h"
#include "afxdialogex.h"


// CRoom2_2 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRoom2_2, CDialogEx)

CRoom2_2::CRoom2_2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_room2_2, pParent)
{

}

CRoom2_2::~CRoom2_2()
{
}

void CRoom2_2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRoom2_2, CDialogEx)
	ON_WM_LBUTTONDOWN()
	ON_WM_GETMINMAXINFO()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CRoom2_2 �޽��� ó�����Դϴ�.


BOOL CRoom2_2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CRoom2_2::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	CPen pen;
	CRgn rgn_1, rgn_2, rgn_3, rgn_4, rgn_5;
	dc.SelectStockObject(NULL_BRUSH);
	pen.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	dc.SelectObject(&pen);

	rgn_1.CreateEllipticRgn(327,47,347,62);
	rgn_2.CreateEllipticRgn(216,117,244,140);
	rgn_3.CreateEllipticRgn(398,71,420,93);
	rgn_4.CreateEllipticRgn(317,149,346,166);
	rgn_5.CreateRectRgn(349, 94, 367, 104);

	if (rgn_1.PtInRegion(point) && p1 != TRUE) {
		p1 = TRUE;
		rgn_1.DeleteObject();
		dc.Ellipse(point.x - 10, point.y - 10, point.x + 10, point.y + 10);
		n++;
	}
	else if (rgn_2.PtInRegion(point) && p2 != TRUE) {
		p2 = TRUE;
		rgn_2.DeleteObject();
		dc.Ellipse(point.x - 10, point.y - 10, point.x + 10, point.y + 10);
		n++;
	}
	else if (rgn_3.PtInRegion(point) && p3 != TRUE) {
		p3 = TRUE;
		rgn_3.DeleteObject();
		dc.Ellipse(point.x - 10, point.y - 10, point.x + 10, point.y + 10);
		n++;
	}
	else if (rgn_4.PtInRegion(point) && p4 != TRUE) {
		p4 = TRUE;
		rgn_4.DeleteObject();
		dc.Ellipse(point.x - 10, point.y - 10, point.x + 10, point.y + 10);
		n++;
	}
	else if (rgn_5.PtInRegion(point) && p5 != TRUE) {
		p5 = TRUE;
		rgn_5.DeleteObject();
		dc.Ellipse(point.x - 10, point.y - 10, point.x + 10, point.y + 10);
		n++;
	}

	if (n==3){
		room2_2 = TRUE;
		CDialog::OnOK();
	}
	//CDialogEx::OnLButtonDown(nFlags, point);
}


