
// CrazyArcadeDlg.h : ��� ����
//

#pragma once
#include "GameHandler.h"

// CCrazyArcadeDlg ��ȭ ����
class CCrazyArcadeDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CCrazyArcadeDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_CRAZYARCADE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
private:
	GameHandler m_game;

protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
