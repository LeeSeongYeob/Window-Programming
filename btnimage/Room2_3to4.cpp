// Room2_3to4.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "btnimage.h"
#include "Room2_3to4.h"
#include "afxdialogex.h"


// CRoom2_3to4 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRoom2_3to4, CDialog)

CRoom2_3to4::CRoom2_3to4(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_room2_3to4, pParent)
{

}

CRoom2_3to4::~CRoom2_3to4()
{
}

void CRoom2_3to4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRoom2_3to4, CDialog)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CRoom2_3to4 �޽��� ó�����Դϴ�.


void CRoom2_3to4::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	CRgn rgn_position;
	rgn_position.CreateRectRgn(222, 13, 310, 92);
	CBrush brush;
	

	if (rgn_position.PtInRegion(point)) {
		brush.CreateSolidBrush(RGB(0, 0, 255));
		room2_3to4 = TRUE;
		dc.FillRgn(&rgn_position,&brush);
		AfxMessageBox(_T("���� ��ȣ�� �ص��߾�."));
		CDialog::OnOK();
	}
	else {
		AfxMessageBox(_T("�̷��� �ɸ��ھ�..���θ���"));
		CDialog::OnOK();
	}
}
