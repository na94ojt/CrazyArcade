
// CrazyArcadeDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CrazyArcade.h"
#include "CrazyArcadeDlg.h"
#include "afxdialogex.h"
#include "MyGameGlobal.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCrazyArcadeDlg ��ȭ ����

HINSTANCE hInst;

CCrazyArcadeDlg::CCrazyArcadeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCrazyArcadeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCrazyArcadeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCrazyArcadeDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CCrazyArcadeDlg �޽��� ó����

BOOL CCrazyArcadeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	RECT rect;

	GetClientRect(&rect);

	hInst = AfxGetInstanceHandle();

	this->m_game.InitGame(::GetDC(this->m_hWnd), hInst, rect);		//���� ȭ�� �� �������� �ʱ�ȭ
	srand(time(NULL));

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CCrazyArcadeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		this->m_game.Paint();		//���� �׸�
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CCrazyArcadeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



int CCrazyArcadeDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	LONG style = ::GetWindowLong(this->m_hWnd, GWL_STYLE);
	::ShowWindow(this->m_hWnd, SW_MAXIMIZE);
	style = ::GetWindowLong(this->m_hWnd, GWL_STYLE);
	style &= ~(WS_DLGFRAME | WS_THICKFRAME);
	::SetWindowLong(this->m_hWnd, GWL_STYLE, style);

	return 0;
}
