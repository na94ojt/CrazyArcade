
// CrazyArcade.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCrazyArcadeApp:
// �� Ŭ������ ������ ���ؼ��� CrazyArcade.cpp�� �����Ͻʽÿ�.
//

class CCrazyArcadeApp : public CWinApp
{
public:
	CCrazyArcadeApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCrazyArcadeApp theApp;