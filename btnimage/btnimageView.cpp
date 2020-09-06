
// btnimageView.cpp : CbtnimageView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "btnimage.h"
#endif

#include "btnimageDoc.h"
#include "btnimageView.h"
#include "Room1_2.h"
#include "Room1_9.h"
#include "Room2_1.h"
#include "Room2_2.h"
#include "Room2_3.h"
#include "Room2_3to4.h"
#include "Room2_5.h"
#include "Room2_paper.h"
#include "NomalDialog.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CbtnimageView

IMPLEMENT_DYNCREATE(CbtnimageView, CFormView)

BEGIN_MESSAGE_MAP(CbtnimageView, CFormView)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_HINT, &CbtnimageView::OnBnClickedHint)
	ON_LBN_DBLCLK(IDC_LIST1, &CbtnimageView::OnLbnDblclkList1)
	ON_BN_CLICKED(IDC_START, &CbtnimageView::OnBnClickedStart)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CbtnimageView ����/�Ҹ�

CbtnimageView::CbtnimageView()
	: CFormView(IDD_BTNIMAGE_FORM)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
room1 = FALSE;
 room1_clear = FALSE;
 room2 = FALSE;
 room2_clear = FALSE;
 room3 = FALSE;
 Caption1 = TRUE;
	 Caption2 = TRUE;
 bProgress = FALSE;
 bCover = TRUE;
 gameover = FALSE;
 bStart, bFinish, bCheck_Lbutton, bScene_Done = FALSE;
 iStart_SceneNumber = 1;
 iStart_SceneMax = 14;
}

CbtnimageView::~CbtnimageView()
{
}

void CbtnimageView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HINT, m_hint);
	DDX_Control(pDX, IDC_LIST1, m_item);
	DDX_Control(pDX, IDC_nHint, m_nHint);
	DDX_Control(pDX, IDC_START, Start_Button);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
}

BOOL CbtnimageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.
	return CFormView::PreCreateWindow(cs);
}

void CbtnimageView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	//stime = GetCurrentTime();
	str.Format(_T("%d"), 3);
	m_nHint.SetWindowText(str);

	m_item.AddString(_T("light"));

	Start_Button.LoadBitmaps(IDB_STARTBUTTON, IDB_STARTBUTTON, NULL, NULL);
	Start_Button.SizeToContent();

	m_hint.LoadBitmaps(IDB_HINT, IDB_HINT, NULL, NULL);
	m_hint.SizeToContent();
}


// CbtnimageView ����

#ifdef _DEBUG
void CbtnimageView::AssertValid() const
{
	CFormView::AssertValid();
}

void CbtnimageView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CbtnimageDoc* CbtnimageView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CbtnimageDoc)));
	return (CbtnimageDoc*)m_pDocument;
}
#endif //_DEBUG


// CbtnimageView �޽��� ó����

void CbtnimageView::OnDraw(CDC* pDC)
{
	CClientDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	if ((gameover == TRUE )&& (bCover==FALSE)) {
		CClientDC dc(this);
		CRect rect;
		GetClientRect(&rect);
		dc.SelectStockObject(BLACK_BRUSH);
		dc.Rectangle(&rect);
		dc.SetTextColor(RGB(255, 255, 255));
		gameover = FALSE;
		
		(GetDlgItem(IDC_LIST1))->ShowWindow(FALSE);
		GetDlgItem(IDC_LIST1)->EnableWindow(FALSE);
		(GetDlgItem(IDC_HINT))->ShowWindow(FALSE);
		GetDlgItem(IDC_HINT)->EnableWindow(FALSE);
		(GetDlgItem(IDC_nHint))->ShowWindow(FALSE);
		GetDlgItem(IDC_nHint)->EnableWindow(FALSE);
		GetDlgItem(IDC_PROGRESS1)->ShowWindow(FALSE);
		GetDlgItem(IDC_PROGRESS1)->EnableWindow(FALSE);

		Print_Image(IDB_explorer, 50, 0);
		Call_Dialog(_T("�ڳ� ���� ���� �ϴ� �ǰ�?"),170);
		Print_Image(IDB_GameOver, 0, 0);
		Wait(1500);
		bCover = TRUE;
		Caption1 = TRUE;
		Caption2 = TRUE;
		GetDlgItem(IDC_START)->ShowWindow(TRUE);
		GetDlgItem(IDC_START)->EnableWindow(TRUE);
		room1_stage = 1;
		room2_stage = 0;
		room3_stage = 0;
		
		int count = m_item.GetCount();
		m_item.SetCurSel(count - 1);
		for (int i = 1; i < count ; i++) {
			m_item.DeleteString(i);
		}
		
	}
	else if (bCover == TRUE)
	{
		Print_Image(IDB_COVER, 0, 0);
		bCover = FALSE;
	}
	else if (bStart == TRUE) {
		int iStr_length = 0, iMoveleft = 0;;
		CString tmpStory, Story;
		//���� ������, ���� ��� ��� ����, ��������
		//	GetClientRect(&rect);
		dc.SelectStockObject(BLACK_BRUSH);
		dc.Rectangle(&rect);
		dc.SetBkColor(TRANSPARENT);
		dc.SetTextColor(RGB(255, 255, 255));
		dc.SetTextAlign(TA_CENTER | TA_BOTTOM);

		//�� ������ 13����
		if (iStart_SceneNumber == 1)
		{
			Story = _T("[MFC �߰� ���� ��ǥ��..]");
			iStr_length = Story.GetLength();
			iMoveleft = 140;
		}
		else if (iStart_SceneNumber == 2)
		{
			Print_Image(IDB_Score, 250, 50);
			Story = _T("�̹� ���� ������ 1���̳�.");
			iStr_length = Story.GetLength();
			iMoveleft = 160;
		}
		else if (iStart_SceneNumber == 3) {
			Story = _T("�̹����� ���б��� �纸�������..�� �����༮");
			iStr_length = Story.GetLength();
			iMoveleft = 200;
		}
		else if (iStart_SceneNumber == 4) {
			Story = _T("�������� �����Ե� �λ� ����� �����Ͻô� �κ�~");
			iStr_length = Story.GetLength();
			iMoveleft = 200;
		}
		else if (iStart_SceneNumber == 5) {
			//			Print_Image(IDB_ME, 250, 50);
			Story = _T("���� �ų��� ������");
			iStr_length = Story.GetLength();
			iMoveleft = 100;
		}
		else if (iStart_SceneNumber == 6) {
			Story = _T("<���� �뱳>");
			iStr_length = Story.GetLength();
			iMoveleft = 90;
		}
		else if (iStart_SceneNumber == 7) {
			Print_Image(IDB_MAPO, 200, 50);
			Story = _T("�Ѱ����̶� �����ϸ� ���ڴ�..���� ");
			iStr_length = Story.GetLength();
			iMoveleft = 180;
		}
		else if (iStart_SceneNumber == 8) {
			Print_Image(IDB_MAPO, 200, 50);
			Story = _T(" ���־�� ������....����ߴ� MFC..");
			iStr_length = Story.GetLength();
			iMoveleft = 200;
		}
		else if (iStart_SceneNumber == 9) {
			bScene_Done = FALSE;
			Print_Image(IDB_EYE3, 200, 50);
			Wait(1000);
			Print_Image(IDB_EYE2, 200, 50);
			Wait(1000);
			Print_Image(IDB_EYE1, 200, 50);
			Wait(1200);
			Story = _T("�׼���.....");
			dc.Rectangle(&rect);

			iStr_length = Story.GetLength();
			iMoveleft = 40;
		}
		else if (iStart_SceneNumber == 10) {
			bScene_Done = FALSE;
			for (int i = 0; i < 3;i++)
			{
				dc.SelectStockObject(WHITE_BRUSH);
				dc.Rectangle(&rect);
				Wait(50);
				dc.SelectStockObject(BLACK_BRUSH);
				dc.Rectangle(&rect);
				Wait(50);
			}
			Story = _T("��� : mfc �⸻��� �������� ��ġ�� ���ݾ�!");
			iStr_length = Story.GetLength();
			iMoveleft = 200;
		}
		else if (iStart_SceneNumber == 11) {
			Story = _T("������?! ����� Ȥ�� �Ϲ���?!");
			iStr_length = Story.GetLength();
			iMoveleft = 160;
		}
		else if (iStart_SceneNumber == 12) {
			Story = _T("����.. ��κ��� GO..");
			iStr_length = Story.GetLength();
			iMoveleft = 130;
		}
		else if (iStart_SceneNumber == 13) {
			Story = _T("������.. �⸻���� 100���̶�!..");
			iStr_length = Story.GetLength();
			iMoveleft = 160;
		}
		//���� �ѱ��ھ� ��ºκ�
		if (iStart_SceneNumber < iStart_SceneMax) {
			int yPos = rect.bottom - 30;
			if (iStart_SceneNumber == 1 || iStart_SceneNumber == 6 || iStart_SceneNumber == 9)
				yPos = rect.bottom / 2;
			bCheck_Lbutton = FALSE;
			bScene_Done = FALSE;
			int xPos = 19;
			for (int i = 0; i < iStr_length; i++) {
				tmpStory = Story.GetAt(i);
				dc.TextOut(rect.right / 2 - iMoveleft + xPos * i, yPos, tmpStory);
				if (!bCheck_Lbutton)
					Wait(70);
			}
			dc.DrawText(_T("Click ��"), &rect, DT_BOTTOM | DT_RIGHT | DT_SINGLELINE);
			bScene_Done = TRUE;
		}
		if (iStart_SceneNumber == iStart_SceneMax) {
			for (int i = 0; i < 256;) {
				CBrush brush = RGB(i, i, i);
				dc.SelectObject(&brush);
				dc.Rectangle(&rect);
				Wait(30);
				i += 5;
			}
			bStart = FALSE;
			Print_Image(IDB_pro_clear, 0, 0);
			Wait(2000);
			room1 = TRUE;
			Invalidate();
		}
	}
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	else if (room1 == TRUE) {
		GetDlgItem(IDC_LIST1)->ShowWindow(TRUE);
		GetDlgItem(IDC_LIST1)->EnableWindow(TRUE);
		GetDlgItem(IDC_HINT)->ShowWindow(TRUE);
		GetDlgItem(IDC_HINT)->EnableWindow(TRUE);
		GetDlgItem(IDC_nHint)->ShowWindow(TRUE);
		GetDlgItem(IDC_nHint)->EnableWindow(TRUE);
		GetDlgItem(IDC_PROGRESS1)->ShowWindow(TRUE);
		CFont font;
		font.CreatePointFont(200, _T("Arial"));
		GetDlgItem(IDC_nHint)->SetFont(&font);


		if (room1_stage == 1) {

			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room1_1);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
			if (Caption1 == TRUE)
			{
				Caption1 = FALSE;
				
					bProgress = TRUE;
					m_progress.SetRange(0, 100);
					m_progress.SetPos(100);
					m_progress.SetState(PBST_NORMAL);
					SetTimer(100, 1800, NULL);
				
				Call_Dialog(_T("���Ⱑ �������� ħ���ΰ�?"), 170);
				Call_Dialog(_T("���⿡ �������� ���� �ܼ��� �������� ����."), 170);
				Call_Dialog(_T("�������� 3�еڿ� ���ôϱ�"), 170);
				Call_Dialog(_T("�� �ȿ� �� ã�� �����߰ھ�."), 170);
				
			}
				

		}
		else if (room1_stage == 2) {
			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room1_2);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
		}
		else if (room1_stage == 3) {
			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room1_3);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
		}
		else if (room1_stage == 4) {
			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room1_4);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
		}
		else if (room1_stage == 5 || room1_stage == 6) {
			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room1_5);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
		}
		else if (room1_stage == 7) {
			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room1_6);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
		}
		else if (room1_stage == 8) {
			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room1_7);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
		}
		else if (room1_stage == 9) {
			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room1_8);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
		}
		else if (room1_stage == 10) {
			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room1_9);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
		}
	}
	else if (room1_clear == TRUE) {
		(GetDlgItem(IDC_LIST1))->ShowWindow(FALSE);
		(GetDlgItem(IDC_HINT))->ShowWindow(FALSE);
		(GetDlgItem(IDC_nHint))->ShowWindow(FALSE);
		(GetDlgItem(IDC_PROGRESS1))->ShowWindow(FALSE);

		Print_Image(IDB_room1_clear, 0, 0);
		Wait(1200);
		room1_clear = FALSE;
		room2 = TRUE;
		Invalidate();
	}
	else if (room2 == TRUE) {
		CFont font;
		font.CreatePointFont(200, _T("Arial"));
		GetDlgItem(IDC_nHint)->SetFont(&font);

		str.Format(_T("%d"), 3 - nHint);
		m_nHint.SetWindowText(str);
		if (room2_stage == 0) {
			(GetDlgItem(IDC_LIST1))->ShowWindow(TRUE);
			(GetDlgItem(IDC_HINT))->ShowWindow(TRUE);
			(GetDlgItem(IDC_nHint))->ShowWindow(TRUE);
			(GetDlgItem(IDC_PROGRESS1))->ShowWindow(TRUE);
			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room2_dark);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
			if (Caption2 == TRUE)
			{
				Caption2 = FALSE;
				Call_Dialog(_T("�������� ����� �̾����±���."), 170);
				Call_Dialog(_T("�������� ���ô� ���ǵ��� ���� ���캼��?"), 170);
				Call_Dialog(_T("�Ƹ� �������� �ְ���."), 170);
			}
		}
		else if (room2_stage == 8) {
			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room2_to_room3);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
		}
		else if (room2_stage == 5) {
			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room2_desk);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
		}
		else if (room2_stage == 6 || room2_stage == 7) {
			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room2_nokey);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
		}
		else {
			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room2);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
		}
	}
	else if (room2_clear == TRUE) {
		(GetDlgItem(IDC_LIST1))->ShowWindow(FALSE);
		(GetDlgItem(IDC_HINT))->ShowWindow(FALSE);
		(GetDlgItem(IDC_nHint))->ShowWindow(FALSE);
		(GetDlgItem(IDC_PROGRESS1))->ShowWindow(FALSE);
		Print_Image(IDB_room2_clear, 0, 0);
		Wait(1200);
		room2_clear = FALSE;
		room3 = TRUE;
		Invalidate();
	}
	else if (room3 == TRUE) {
		(GetDlgItem(IDC_LIST1))->ShowWindow(TRUE);
		(GetDlgItem(IDC_HINT))->ShowWindow(TRUE);
		(GetDlgItem(IDC_nHint))->ShowWindow(TRUE);
		(GetDlgItem(IDC_PROGRESS1))->ShowWindow(TRUE);

		CFont font;
		font.CreatePointFont(200, _T("Arial"));
		GetDlgItem(IDC_nHint)->SetFont(&font);
		if (room3_stage == 0) {
			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room3_glassbook);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
		}
		else if (room3_stage == 1) {
			CClientDC dc(this);
			CBitmap bitmap;
			bitmap.LoadBitmap(IDB_room3_book);
			BITMAP bmpinfo;
			bitmap.GetBitmap(&bmpinfo);

			CDC dcmem;
			dcmem.CreateCompatibleDC(&dc);
			dcmem.SelectObject(&bitmap);

			dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
		}
	}
	else if (room3_clear == TRUE) {
		CClientDC dc(this);
		CBitmap bitmap;
		bitmap.LoadBitmap(IDB_room3_clear);
		BITMAP bmpinfo;
		bitmap.GetBitmap(&bmpinfo);

		CDC dcmem;
		dcmem.CreateCompatibleDC(&dc);
		dcmem.SelectObject(&bitmap);

		dc.BitBlt(0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);

	}
	
}


void CbtnimageView::OnLButtonDown(UINT nFlags, CPoint point)
{
	bCheck_Lbutton = TRUE;
	//���� ������ �ѱ��
	if ((bScene_Done == TRUE) && (iStart_SceneNumber < iStart_SceneMax))
	{
		iStart_SceneNumber++;
		Invalidate();
	}
	if (room1 == TRUE) {
		CClientDC dc(this);
		CRgn rgn_picture, rgn_box, rgn_key, rgn_door, rgn_bed, rgn_pillow,
			rgn_light, rgn_paper, rgn_ground,rgn_other;

		rgn_picture.CreateRectRgn(166, 84, 307, 192);
		rgn_box.CreateRectRgn(204, 114, 283, 165);
		rgn_key.CreateRectRgn(230, 146, 260, 164);
		rgn_door.CreateRectRgn(591, 81, 659, 295);
		rgn_bed.CreateRectRgn(365, 325, 665, 350);
		rgn_pillow.CreateRectRgn(135, 259, 258, 297);
		rgn_light.CreateRectRgn(470, 175, 520, 200);
		rgn_paper.CreateRectRgn(492, 272, 521, 292);
		rgn_ground.CreateRectRgn(10, 406, 293, 459);
		rgn_other.CreateRectRgn(0,0,728,475);

		if (room1_stage == 1) {
			if (rgn_picture.PtInRegion(point)) {
				room1_stage = 2;
				Call_Dialog(_T("���ڸ� �����, �ݰ������� ����."), 170);
				Invalidate();
			}
			else if (rgn_door.PtInRegion(point))
				Call_Dialog(_T("����ִ°� ����."), 170);
			else if (rgn_bed.PtInRegion(point))
				Call_Dialog(_T("ħ�� ��Ʈ���� ���̿� ���� ���� ������?"), 170);
			else if (rgn_pillow.PtInRegion(point))
				Call_Dialog(_T("ǫ��ǫ���� ������."), 170);
			else if (rgn_light.PtInRegion(point))
				Call_Dialog(_T("���� �鿭�� ������."), 170);
			else if (rgn_ground.PtInRegion(point))
				Call_Dialog(_T("�Ҹ��� ���� �ٸ��Ͱ���. �Ʒ� ���� ��������?"), 170);
			else if(rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);
		}
		else if (room1_stage == 2) {
			CRoom1_2 dlg;
			if (rgn_box.PtInRegion(point)) {
				dlg.DoModal();
				if (dlg.box == TRUE) {
					room1_stage = 3;
					Invalidate();
				}
			}
			else if (rgn_door.PtInRegion(point))
				Call_Dialog(_T("����ִ°� ����."), 170);
			else if (rgn_bed.PtInRegion(point))
				Call_Dialog(_T("ħ�� ��Ʈ���� ���̿� ���� ���� ������?"), 170);
			else if (rgn_pillow.PtInRegion(point))
				Call_Dialog(_T("ǫ��ǫ���� ������."), 170);
			else if (rgn_light.PtInRegion(point))
				Call_Dialog(_T("���� �鿭�� ������."), 170);
			else if (rgn_ground.PtInRegion(point))
				Call_Dialog(_T("�Ҹ��� ���� �ٸ��Ͱ���. �Ʒ� ���� ��������?"), 170);
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);
		}
		else if (room1_stage == 3) {
			if (rgn_key.PtInRegion(point)) {
				int count = m_item.GetCount();
				m_item.SetCurSel(count - 1);
				m_item.AddString(_T("����"));
				Call_Dialog(_T("'����'�� �߰��߾�. ��� ���̴°���?"), 170);
				room1_stage = 4;
				Invalidate();
			}
			else if (rgn_door.PtInRegion(point))
				Call_Dialog(_T("����ִ°� ����."), 170);
			else if (rgn_bed.PtInRegion(point))
				Call_Dialog(_T("ħ�� ��Ʈ���� ���̿� ���� ���� ������?"), 170);
			else if (rgn_pillow.PtInRegion(point))
				Call_Dialog(_T("ǫ��ǫ���� ������."), 170);
			else if (rgn_light.PtInRegion(point))
				Call_Dialog(_T("���� �鿭�� ������."), 170);
			else if (rgn_ground.PtInRegion(point))
				Call_Dialog(_T("�Ҹ��� ���� �ٸ��Ͱ���. �Ʒ� ���� ��������?"), 170);
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);
		}
		else if (room1_stage == 4) {
			int nIndex = m_item.GetCurSel();
			m_item.GetText(nIndex, str);
			if (rgn_door.PtInRegion(point) && str == _T("����")) {
				room1_stage = 5;
				Invalidate();
				Call_Dialog(_T("����� ���� ���Ⱦ�."), 170);
				int count = m_item.GetCount();
				m_item.SetCurSel(count - 1);
				m_item.AddString(_T("�� �����"));
				Call_Dialog(_T("�� ����⸦ �߰��ߴ�. ��� ���� ��������?"), 170);
			}
			else if (rgn_door.PtInRegion(point))
				Call_Dialog(_T("��� �� ����. ���𰡷� �� �� ����������?"), 170);
			else if (rgn_bed.PtInRegion(point))
				Call_Dialog(_T("ħ�� ��Ʈ���� ���̿� ���� ���� ������?"), 170);
			else if (rgn_pillow.PtInRegion(point))
				Call_Dialog(_T("ǫ��ǫ���� ������."), 170);
			else if (rgn_light.PtInRegion(point))
				Call_Dialog(_T("���� �鿭�� ������."), 170);
			else if (rgn_ground.PtInRegion(point))
				Call_Dialog(_T("�Ҹ��� ���� �ٸ��Ͱ���. �Ʒ� ���� ��������?"), 170);
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);
		}
		else if (room1_stage == 5) {
			int nIndex = m_item.GetCurSel();
			m_item.GetText(nIndex, str);
			if (rgn_bed.PtInRegion(point) && str == _T("�� �����")) {
				int count = m_item.GetCount();
				m_item.SetCurSel(count - 1);
				m_item.AddString(_T("Ŀ��Į"));
				Call_Dialog(_T("��Ʈ���� ���̿��� 'Ŀ��Į'�� �ֿ���."), 170);
				Call_Dialog(_T("�̰� �� ���⿡ ����...?"), 170);
				room1_stage = 6;
				Invalidate();
			}
			else if (rgn_bed.PtInRegion(point))
			{
				Call_Dialog(_T("����� ���� �ִ� �� ����."), 170);
				Call_Dialog(_T("������ ������ ���� ���� �ʾ�..."), 170);

			}
			else if (rgn_pillow.PtInRegion(point))
				Call_Dialog(_T("ǫ��ǫ���� ������."), 170);
			else if (rgn_light.PtInRegion(point))
				Call_Dialog(_T("���� �鿭�� ������."), 170);
			else if (rgn_ground.PtInRegion(point))
				Call_Dialog(_T("�Ҹ��� ���� �ٸ��Ͱ���. �Ʒ� ���� ��������?"), 170);
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);
		}
		else if (room1_stage == 6) {
			int nIndex = m_item.GetCurSel();
			m_item.GetText(nIndex, str);
			if (rgn_pillow.PtInRegion(point)) {
				if (str == _T("Ŀ��Į")) {
					int count = m_item.GetCount();
					m_item.SetCurSel(count - 1);
					m_item.AddString(_T("���� ��ġ"));
					Call_Dialog(_T("���� �ȿ��� '���� ��ġ'�� �߰��ߴ�."), 170);
					Call_Dialog(_T("������ �νð� ������."), 170);
					room1_stage = 7;
					Invalidate();
				}
				else
				{
					Call_Dialog(_T("ǫ���ϴ�."), 170);
					Call_Dialog(_T("�ȿ� ������ ���������?"), 170);
				}
			}
			else if (rgn_ground.PtInRegion(point))
				Call_Dialog(_T("�Ҹ��� ���� �ٸ��Ͱ���. �Ʒ� ���� ��������?"), 170);
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);
		}
		else if (room1_stage == 7 && rgn_light.PtInRegion(point)) {
			int nIndex = m_item.GetCurSel();
			m_item.GetText(nIndex, str);
			if (rgn_light.PtInRegion(point)) {
				if (str == _T("���� ��ġ")) {
					room1_stage = 8;
					Invalidate();
					Call_Dialog(_T("������ �μ̴�. ��ο��� �� ������ �ʾ�."), 170);
				}
				else
					Call_Dialog(_T("�ʹ� �߰ſ��� ������ ���� �� ����."), 170);
			}
			else if (rgn_ground.PtInRegion(point))
				Call_Dialog(_T("�Ҹ��� ���� �ٸ��Ͱ���. �Ʒ� ���� ��������?"), 170);
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);
		}
		else if (room1_stage == 8) {
			if (rgn_paper.PtInRegion(point)) {
				room1_stage = 9;
				int count = m_item.GetCount();
				m_item.SetCurSel(count - 1);
				m_item.AddString(_T("����"));
				Call_Dialog(_T("'����'�� �ֿ���. � ������ ���������?"), 170);
				Invalidate();
			}
			else if (rgn_ground.PtInRegion(point))
				Call_Dialog(_T("�Ҹ��� ���� �ٸ��Ͱ���. �Ʒ� ���� ��������?"), 170);
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);
		}
		else if (room1_stage == 9 && rgn_ground.PtInRegion(point)) {
			CRoom1_9 dlg;
			dlg.DoModal();
			if (dlg.door == TRUE) {
				room1_stage = 10;
				Invalidate();
			}
		}
		else if (room1_stage == 10 && rgn_ground.PtInRegion(point)) {
			room1 = FALSE;
			room1_clear = TRUE;
			Invalidate();
			
		}
	}

	else if (room2 == TRUE) {
		CClientDC dc(this);
		CString str;
		int count;
		CRgn rgn_light, rgn_violin, rgn_pendulum, rgn_bookdoor,
			rgn_keyboard, rgn_desk, rgn_key, rgn_picture,rgn_other;

		//rgn_light.CreateEllipticRgn(458, 14, 520, 36);
		rgn_violin.CreateEllipticRgn(107, 258, 193, 281);
		rgn_pendulum.CreateEllipticRgn(683, 220, 705, 240);
		rgn_bookdoor.CreateEllipticRgn(207, 87, 283, 350);
		rgn_keyboard.CreateRectRgn(427, 248, 513, 290);
		rgn_desk.CreateRectRgn(566, 352, 578, 372);
		rgn_key.CreateEllipticRgn(505, 327, 533, 348);
		rgn_picture.CreateRectRgn(466, 189, 496, 209);
		rgn_other.CreateRectRgn(0, 0, 728, 475);


		if (room2_stage == 1) {
			if (rgn_violin.PtInRegion(point)) {
				CRoom2_1 dlg;
				dlg.DoModal();
				if (dlg.room2_1 == TRUE)
					room2_stage = 2;
			}
			else if (rgn_pendulum.PtInRegion(point))
				Call_Dialog(_T("�ð��� �ؿ� �����ΰ� �ִ� �� ����."), 170);
			else if (rgn_bookdoor.PtInRegion(point))
				Call_Dialog(_T("���ӿ��� �� å�尰���� �ڿ� ������ �ִ���."), 170);
			else if (rgn_keyboard.PtInRegion(point))
				Call_Dialog(_T("������ Ÿ�ڱ��. �ѹ� �ĺ��� �;�."), 170);
			else if (rgn_desk.PtInRegion(point))
				Call_Dialog(_T("������ ����־�."), 170);
			else if (rgn_picture.PtInRegion(point))
				Call_Dialog(_T("���ڿ� ���� �����ִ°� ������.. �̵��� �ٽ� ����"), 170);
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);
		}
		else if (room2_stage == 2) {
			if (rgn_pendulum.PtInRegion(point)) {
				Call_Dialog(_T("��� ���� �ϴ� Ʋ���׸� ã���ΰ�?"), 170);
				Call_Dialog(_T("�������ϱ� 3������ ã�ƾ���."), 170);
				CRoom2_2 dlg;
				dlg.DoModal();
				if (dlg.room2_2 == TRUE) {
					int count = m_item.GetCount();
					m_item.SetCurSel(count - 1);
					m_item.AddString(_T("����"));
					Call_Dialog(_T("�ð��� �ؿ��� '����'�� �߰��ߴ�."), 170);
					room2_stage = 3;
				}
			}
			else if (rgn_keyboard.PtInRegion(point))
				Call_Dialog(_T("������ Ÿ�ڱ��. �ѹ� �ĺ��� �;�."), 170);
			else if (rgn_desk.PtInRegion(point))
				Call_Dialog(_T("������ ����־�."), 170);
			else if (rgn_picture.PtInRegion(point))
				Call_Dialog(_T("���ڿ� ���� �����ִ°� ������.. �̵��� �ٽ� ����"), 170);
			else if (rgn_bookdoor.PtInRegion(point))
				Call_Dialog(_T("���ӿ��� �� å�尰���� �ڿ� ������ �ִ���.."), 170);
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);
		}
		else if (room2_stage == 3) {
			if (rgn_keyboard.PtInRegion(point)) {
				int nIndex = m_item.GetCurSel();
				m_item.GetText(nIndex, str);
				if (str == _T("����")) {
					CRoom2_3 dlg;
					dlg.DoModal();
					if (dlg.room2_3 == TRUE) {
						int count = m_item.GetCount();
						m_item.SetCurSel(count - 1);
						m_item.AddString(_T("���� ����������"));
						Call_Dialog(_T("Ÿ�ڱ� ġ�� ������ �ʹ��� ������."), 170);
						Call_Dialog(_T("'���� ������ ����'�� ȹ���ߴ�."), 170);
						room2_stage = 4;
					}
				}
				else {
					Call_Dialog(_T("�������� ������� ���� �ʿ�����??"), 170);
				}
			}
			else if (rgn_desk.PtInRegion(point))
				Call_Dialog(_T("������ ����־�."), 170);
			else if (rgn_picture.PtInRegion(point))
				Call_Dialog(_T("���ڿ� ���� �����ִ°� ������.. �̵��� �ٽ� ����"), 170);
			else if (rgn_bookdoor.PtInRegion(point))
				Call_Dialog(_T("���ӿ��� �� å�尰���� �ڿ� ������ �ִ���.."), 170);
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);
		}
		else if (room2_stage == 4) {
			if (rgn_desk.PtInRegion(point)) {   //���� ����   
				CRoom2_3to4 dlg;
				dlg.DoModal();
				if (dlg.room2_3to4 == TRUE) {
					room2_stage = 5;
					Invalidate();
				}
			}
			else if (rgn_picture.PtInRegion(point))
				Call_Dialog(_T("���ڿ� ���� �����ִ°� ������.. �̵��� �ٽ� ����"), 170);
			else if (rgn_bookdoor.PtInRegion(point))
				Call_Dialog(_T("���ӿ��� �� å�尰���� �ڿ� ������ �ִ���.."), 170);
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);

		}
		else if (room2_stage == 5) {
			if (rgn_key.PtInRegion(point)) {   //Ű�߰�
				count = m_item.GetCount();
				m_item.SetCurSel(count - 1);
				m_item.AddString(_T("masterkey"));
				Call_Dialog(_T("�������� 'masterkey'�� �߰��ߴ٤�"), 170);
				room2_stage = 6;
				Invalidate();
			}
			else if (rgn_picture.PtInRegion(point))
				Call_Dialog(_T("���ڿ� ���� �����ִ°� ������.. �̵��� �ٽ� ����"), 170);
			else if (rgn_bookdoor.PtInRegion(point))
				Call_Dialog(_T("���ӿ��� �� å�尰���� �ڿ� ������ �ִ���.."), 170);
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);
		}
		else if (room2_stage == 6 ) {
			if (rgn_picture.PtInRegion(point)) {
				CRoom2_5 dlg;
				dlg.DoModal();
				if (dlg.room2_5 == TRUE)
					room2_stage = 7;
			}
			else if (rgn_bookdoor.PtInRegion(point))
				Call_Dialog(_T("���ӿ��� �� å�尰���� �ڿ� ������ �ִ���.."), 170);
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);
		}
		else if (room2_stage == 7 ) {
			if (rgn_bookdoor.PtInRegion(point)) {
				room2_stage = 8;
				Invalidate();
				Call_Dialog(_T("��?? ���ο� �������� �̾����� ���̾�."), 170);
				Call_Dialog(_T("��¼�� ���� �������� ����"), 170);
			}
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);
		}
		else if (room2_stage == 8 && rgn_bookdoor.PtInRegion(point)) {
			room2 = FALSE;
			room2_clear = TRUE;
			Invalidate();
		}
	}
	else if (room3 == TRUE) {
		CClientDC dc(this);
		CRgn rgn_glassbook,rgn_book,rgn_other;

		rgn_glassbook.CreateRectRgn(276, 103, 385, 220);
		rgn_book.CreateRectRgn(301,140,361,219);
		rgn_other.CreateRectRgn(0, 0, 728, 475);

		if (room3_stage == 0  ) {
			if(rgn_glassbook.PtInRegion(point)){
				int nIndex = m_item.GetCurSel();
				m_item.GetText(nIndex, str);
				if (str == _T("masterkey")) {
					room3_stage = 1;
					Invalidate();
					Call_Dialog(_T("����. ������ ������."), 170);
				}
				else {
					Call_Dialog(_T("���谡 �ʿ��Ѱ� ������?"), 170);
				}
			}
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("���� �ƹ��͵� ���� �� ����. �ٸ����� ã�ƺ���."), 170);
		}
		else if (room3_stage == 1 ) {
			if (rgn_book.PtInRegion(point)) {
				room3 = FALSE;
				room3_clear = TRUE;
				Invalidate();
				(GetDlgItem(IDC_LIST1))->ShowWindow(FALSE);
				(GetDlgItem(IDC_HINT))->ShowWindow(FALSE);
				(GetDlgItem(IDC_nHint))->ShowWindow(FALSE);
				(GetDlgItem(IDC_PROGRESS1))->ShowWindow(FALSE);
				KillTimer(100);
				Call_Dialog(_T("���� �������� �տ� �־���."), 170);
				Call_Dialog(_T("�̰Ÿ� �⸻��� 100�� ���� �� �ְڴ�.��"), 170);
				Call_Dialog(_T("� �������� ������ ����������."), 170);
				Call_Dialog(_T("�׷��� �� ������ �ֳ�..?"), 170);
				CClientDC dc(this);
				CRect rect;
				GetClientRect(&rect);
				dc.SelectStockObject(BLACK_BRUSH);
				dc.SetBkColor(TRANSPARENT);
				dc.Rectangle(&rect);
				Call_Dialog(_T("..."), 170);
				Call_Dialog(_T("������ �������� �տ� �־��� ���ڿ���.."), 170);
				Call_Dialog(_T("�ڳ� �� �׷��� �ִ°�?"), 170);
				Print_Image(IDB_Score, 250, 50);
				Call_Dialog(_T("Ȥ�� �߰���縦 �� ���� ���߳�?"), 170);
				Print_Image(IDB_MAPO, 200, 50);
				Call_Dialog(_T("�׷��� �λ��� ������ �������� �߾���??"), 170);
				dc.Rectangle(&rect);
				Call_Dialog(_T("�׷��� ���Գ�."), 170);
				Call_Dialog(_T("�ڳ� Ȥ�� �װ� �ƴ°�..?"), 170);
				Call_Dialog(_T("������ �ߺ��� ����� �������� ������,"), 170);
				Call_Dialog(_T("������ ����� �翬�� �����ϴ� ���̶��.."), 170);
				Call_Dialog(_T("����� ��� ��鼭 �Ź� ������ �ߺ��ڳ�?"), 170);
				Call_Dialog(_T("�� �ѹ��� ���� �������� ��� �� �λ��� ���� �������� ���Գ�.."), 170);
				Call_Dialog(_T("�׷� �⸻��� ������ ����ϰڳ�!"), 170);
				Call_Dialog(_T("'...'"), 170);
				Call_Dialog(_T("'�׷� �¾�...'"), 170);
				Call_Dialog(_T("'�⸻��� �ѹ� �ߺ����� ������ ���� �дٴ�.. �ٺ�����..'"), 170);
				Call_Dialog(_T("'������ ���� �����ؾ߰ڴ�.'"), 170);
				Call_Dialog(_T("'�⸻��簡 �� ���� �ʾҾ�!'"), 170);
				Print_Image(IDB_ENDING, 0, 0);
			}
			else if (rgn_other.PtInRegion(point))
				Call_Dialog(_T("�ð��� �󸶾���. ������ ������ ������."), 170);
		}
	}

}


void CbtnimageView::OnBnClickedHint()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	static int lastHint = 0;
	if (room1 == TRUE) {
		if (nHint < 3 || (nHint == 3 && lastHint == room1_stage)) {
			if (lastHint != room1_stage && nHint != 3)
				nHint++;
			CFont font;
			font.CreatePointFont(200, _T("Arial"));
			GetDlgItem(IDC_nHint)->SetFont(&font);
			str.Format(_T("%d"), 3-nHint);
			m_nHint.SetWindowText(str);
			if (room1_stage == 1)
				Call_Dialog(_T("���� �ɸ��� ����?"), 170);
			else if (room1_stage == 2)
				Call_Dialog(_T("���� �ݰ��ΰ�?"), 170);
			else if (room1_stage == 3)
				Call_Dialog(_T("���谡 �ִ°� ����."), 170);
			else if (room1_stage == 4)
				Call_Dialog(_T("���踦 �Ẹ��."), 170);
			else if (room1_stage == 5)
				Call_Dialog(_T("�� ������ ����� �ִ� ������ ���� �� ���� ������?"), 170);
			else if (room1_stage == 6)
				Call_Dialog(_T("Ŀ��Į�� �����?"), 170);
			else if (room1_stage == 7)
				Call_Dialog(_T("���� ��ġ�� �� �� �� ����?"), 170);
			else if (room1_stage == 8)
				Call_Dialog(_T("������ ��������."), 170);
			else if (room1_stage == 9)
				Call_Dialog(_T("���� ������ Ǯ��� ���ٵ�.."), 170);
			lastHint = room1_stage;
		}
		else
			Call_Dialog(_T("��Ʈ�� ���̻� ����."), 170);
	}

	else if (room2 == TRUE) {
		if (nHint < 3 || (nHint == 3 && lastHint == room2_stage)) {
			if (lastHint != room2_stage && nHint != 3)
				nHint++;
			CFont font;
			font.CreatePointFont(200, _T("Arial"));
			GetDlgItem(IDC_nHint)->SetFont(&font);
			str.Format(_T("%d"), 3 - nHint);
			m_nHint.SetWindowText(str);
			if (room2_stage == 0)	//���� ��Ʈ
				Call_Dialog(_T("�ʹ� ��Ӵ�..�������� ����?"), 170);
			else if (room2_stage == 1)	//���̿ø� ��Ʈ
				Call_Dialog(_T("��! ������ ��̰� ���̿ø��̷��µ�.."), 170);
			else if (room2_stage == 2)	//�ð���
				Call_Dialog(_T("�ٷ� �� ������ ���� ���� ��������?"), 170);
			else if (room2_stage == 3)	//Ÿ�ڱ�
				Call_Dialog(_T("���蹮���� ���� ��������? ���̴� �ִµ�.."), 170);
			else if (room2_stage == 4)	//å��
				Call_Dialog(_T("���̿� ���� �����ִ��� ����??"), 170);
			else if (room2_stage == 5)	//Ű
				Call_Dialog(_T("Ű�� ���ݾ�? �ϴ� �����ۿ� �־��?"), 170);
			else if (room2_stage == 6)	//����
				Call_Dialog(_T("���ڰ� ������ ������..Ȥ�� �ܼ��ΰ�?"), 170);
			else if (room2_stage == 7)	//å��
				Call_Dialog(_T("��Ʈ�� ���ܰ迡�� �־�����."), 170);
			lastHint = room2_stage;
		}
		else
			Call_Dialog(_T("��Ʈ�� ���̻� ����."), 170);
	}
	else if (room3 == TRUE) {
		if (nHint < 3 || (nHint == 3 && lastHint == room2_stage)) {
			if (lastHint != room2_stage && nHint != 3)
				nHint++;
			CFont font;
			font.CreatePointFont(200, _T("Arial"));
			GetDlgItem(IDC_nHint)->SetFont(&font);
			str.Format(_T("%d"), 3 - nHint);
			m_nHint.SetWindowText(str);
			if (room3_stage == 0)	//���� ��Ʈ
				Call_Dialog(_T("�����ӿ� �����ִµ�..���� ����� ����?!"),170);
			lastHint = room3_stage;
		}
		else
			Call_Dialog(_T("��Ʈ�� ���̻� ����."), 170);
	}
}


void CbtnimageView::OnLbnDblclkList1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nIndex = m_item.GetCurSel();
	m_item.GetText(nIndex, str);
	if (room2 == TRUE && nIndex != LB_ERR && room2_stage == 0 && str == _T("light")) {
		room2_stage = 1;
		Invalidate();
		Call_Dialog(_T("������ ���� �� ���̴±�."), 170);
	}
	else if (str == _T("����")) {
		AfxMessageBox(_T("'I n D I T \\n I U D I I' -> 0 0 0 0 "));
		Invalidate();
	}
	else if (str == _T("���� ����������")) {
		CRoom2_paper dlg;
		dlg.DoModal();
	}
}


void CbtnimageView::Wait(DWORD dwMillisecond)
{
	MSG msg;
	DWORD dwStart;
	dwStart = GetTickCount();

	while (GetTickCount() - dwStart < dwMillisecond)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}



int CbtnimageView::Call_Dialog(CString str_Caption, int height)
{
	
	CRect rect;
	GetClientRect(&rect);
	ClientToScreen(&rect);
	NomalDialog pDlg = new NomalDialog();
	pDlg.str_Caption = str_Caption;
	pDlg.view = this;
	pDlg.x_Pos = rect.left;
	pDlg.y_Pos = rect.bottom - height;
	pDlg.width = rect.Width();
	pDlg.height = height;
	int result = pDlg.DoModal();

	return result;
}


void CbtnimageView::OnBnClickedStart()
{
	bStart = TRUE;
	GetDlgItem(IDC_START)->ShowWindow(FALSE);
	GetDlgItem(IDC_START)->EnableWindow(FALSE);
}

void CbtnimageView::Print_Image(int Image_ID, int x_Pos, int y_Pos)
{
	CBitmap Myimage;
	CClientDC dc(this);
	Myimage.LoadBitmap(Image_ID);
	BITMAP bmpinfo;
	Myimage.GetBitmap(&bmpinfo);

	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&Myimage);
	dc.StretchBlt(x_Pos, y_Pos, bmpinfo.bmWidth, bmpinfo.bmHeight - 50, &dcmem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY | DT_CENTER);

	dcmem.DeleteDC();
}

BOOL CbtnimageView::OnEraseBkgnd(CDC* pDC)
{
	if (room1 == TRUE)
	{
		CRect rect;
		GetClientRect(rect);
		pDC->FillSolidRect(rect, RGB(0,0, 0));

		return TRUE;
	}
}


HBRUSH CbtnimageView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);

	UINT nID = pWnd->GetDlgCtrlID();

	if (nID == IDC_nHint)
	{
		pDC->SetBkColor(RGB(0, 0, 0));
		pDC->SetTextColor(RGB(255, 255, 255));
		hbr = ::CreateSolidBrush(RGB(0, 0, 0));
	}
	if (nID == IDC_LIST1)
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->SetBkColor(RGB(213, 213, 213));
		pDC->SetTextColor(RGB(0, 0, 0));
		hbr = ::CreateSolidBrush(RGB(213, 213, 213));


	}
	return hbr;
}


void CbtnimageView::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 100)
	{
		if (room1_clear != TRUE || room2_clear != TRUE){
			if (m_progress.GetPos() > 0)
			{
				if (m_progress.GetPos() > 20 && m_progress.GetPos() <= 50)
				{
					m_progress.SetState(PBST_PAUSED);
				}
				if (m_progress.GetPos() <= 20)
				{
					m_progress.SetState(PBST_ERROR);
				}
				m_progress.OffsetPos(-1);
			}
			else if(m_progress.GetPos()==0){

				KillTimer(nIDEvent);
				bProgress = FALSE;
				gameover = TRUE;
				CClientDC dc(this);
				CRect rect;
				GetClientRect(&rect);
				dc.SelectStockObject(BLACK_BRUSH);
				dc.Rectangle(&rect);
				dc.SetTextColor(RGB(255, 255, 255));

				room1 = FALSE;
				room1_clear = FALSE;
				room2 = FALSE;
				room2_clear = FALSE;
				room3 = FALSE;
				bStart, bFinish, bCheck_Lbutton, bScene_Done = FALSE;
				
				//OnClose();
				Invalidate();

			}
		}
	}
}


void CbtnimageView::Restart()
{
	bCover = TRUE;
	GetDlgItem(IDC_START)->ShowWindow(TRUE);
	GetDlgItem(IDC_START)->EnableWindow(TRUE);
	room1 = FALSE;
	room1_clear = FALSE;
	room2 = FALSE;
	room2_clear = FALSE;
	room3 = FALSE;
	Caption1 = TRUE;
	Caption2 = TRUE;
	bProgress = FALSE;
	gameover = FALSE;
	bStart, bFinish, bCheck_Lbutton, bScene_Done = FALSE;
	Invalidate();
	
}

