
// btnimage.h : btnimage ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CbtnimageApp:
// �� Ŭ������ ������ ���ؼ��� btnimage.cpp�� �����Ͻʽÿ�.
//

class CbtnimageApp : public CWinApp
{
public:
	CbtnimageApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CbtnimageApp theApp;