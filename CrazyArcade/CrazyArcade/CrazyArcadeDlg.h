
// CrazyArcadeDlg.h : ��� ����
//

#pragma once
#include "MyGame.h"

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
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
private:
	MyGame m_Game;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
