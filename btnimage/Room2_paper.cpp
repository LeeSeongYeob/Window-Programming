// Room2_paper.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "btnimage.h"
#include "Room2_paper.h"
#include "afxdialogex.h"


// CRoom2_paper ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRoom2_paper, CDialog)

CRoom2_paper::CRoom2_paper(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_room2_paper, pParent)
{

}

CRoom2_paper::~CRoom2_paper()
{
}

void CRoom2_paper::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CRoom2_paper, CDialog)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CRoom2_paper �޽��� ó�����Դϴ�.


void CRoom2_paper::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CDialog::OnOK();
}
